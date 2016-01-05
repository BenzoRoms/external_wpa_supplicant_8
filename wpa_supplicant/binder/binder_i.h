/*
 * wpa_supplicant Binder control interface
 * Copyright (c) 2016, Jouni Malinen <j@w1.fi>
 *
 * This software may be distributed under the terms of the BSD license.
 * See README for more details.
 */

#ifndef BINDER_I_H
#define BINDER_I_H

#ifdef _cplusplus
extern "C" {
#endif // _cplusplus

struct wpas_binder_priv {
	int binder_fd;
	struct wpa_global *global;
};

#ifdef _cplusplus
}
#endif // _cplusplus

#endif /* BINDER_I_H */
