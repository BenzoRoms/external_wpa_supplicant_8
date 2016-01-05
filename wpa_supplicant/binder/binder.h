/*
 * wpa_supplicant Binder control interface
 * Copyright (c) 2016, Jouni Malinen <j@w1.fi>
 *
 * This software may be distributed under the terms of the BSD license.
 * See README for more details.
 */

#ifndef BINDER_H
#define BINDER_H

#ifdef _cplusplus
extern "C" {
#endif // _cplusplus

struct wpas_binder_priv;
struct wpa_global;

struct wpas_binder_priv * wpas_binder_init(struct wpa_global *global);
void wpas_binder_deinit(struct wpas_binder_priv *priv);

#ifdef _cplusplus
}
#endif // _cplusplus

#endif /* BINDER_H */
