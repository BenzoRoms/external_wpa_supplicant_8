/*
 * wpa_supplicant Binder control interface
 * Copyright (c) 2016, Jouni Malinen <j@w1.fi>
 *
 * This software may be distributed under the terms of the BSD license.
 * See README for more details.
 */

#include <binder/IPCThreadState.h>
#include <binder/ProcessState.h>

extern "C" {
#include "utils/includes.h"
#include "utils/common.h"
#include "utils/eloop.h"
#include "binder_i.h"
#include "binder.h"
}

void wpas_binder_sock_handler(int sock, void *eloop_ctx, void *sock_ctx)
{
	struct wpa_global *global = (wpa_global *)eloop_ctx;
	struct wpas_binder_priv *priv = (wpas_binder_priv *)sock_ctx;

	wpa_printf(MSG_DEBUG, "Processing read on binder FD %d", priv->binder_fd);
	android::IPCThreadState::self()->handlePolledCommands();
}

struct wpas_binder_priv * wpas_binder_init(struct wpa_global *global)
{
	struct wpas_binder_priv *priv;

	priv = (wpas_binder_priv *)os_zalloc(sizeof(*priv));
	if (priv == NULL)
		return NULL;
	priv->global = global;

	android::ProcessState::self()->setThreadPoolMaxThreadCount(0);
	android::IPCThreadState::self()->disableBackgroundScheduling(true);
	android::IPCThreadState::self()->setupPolling(&priv->binder_fd);
	wpa_printf(MSG_DEBUG, "Got binder FD %d", priv->binder_fd);
	if (priv->binder_fd < 0) {
		wpas_binder_deinit(priv);
		return NULL;
	}
	// Look for read events from the binder socket in the eloop.
	if (eloop_register_read_sock(
				priv->binder_fd, wpas_binder_sock_handler, global, priv) < 0) {
		wpas_binder_deinit(priv);
		return NULL;
	}
	return priv;
}


void wpas_binder_deinit(struct wpas_binder_priv *priv)
{
	if (priv == NULL)
		return;

	eloop_unregister_read_sock(priv->binder_fd);
	android::IPCThreadState::shutdown();
}
