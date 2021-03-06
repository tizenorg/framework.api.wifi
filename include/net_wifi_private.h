/*
 * Copyright (c) 2011 Samsung Electronics Co., Ltd All Rights Reserved
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */



#ifndef __NET_CONNECTION_PRIVATE_H__        /* To prevent inclusion of a header file twice */
#define __NET_CONNECTION_PRIVATE_H__

#include <dlog.h>
#include <network-cm-intf.h>
#include <network-wifi-intf.h>
#include "wifi.h"

#define TIZEN_NET_CONNECTION "net_wifi"

#define WIFI_INFO	LOG_VERBOSE
#define WIFI_ERROR	LOG_ERROR
#define WIFI_WARN	LOG_WARN

#define WIFI_LOG(log_level, format, args...) \
	SLOG(log_level,TIZEN_NET_CONNECTION, "[%s][Ln: %d] " format, __FILE__, __LINE__, ##args)

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


bool _wifi_libnet_init(void);
bool _wifi_libnet_deinit(void);
int _wifi_activate(void);
int _wifi_deactivate(void);

bool _wifi_libnet_check_ap_validity(wifi_ap_h ap_h);
void _wifi_libnet_add_to_ap_list(wifi_ap_h ap_h);
void _wifi_libnet_remove_from_ap_list(wifi_ap_h ap_h);
bool _wifi_libnet_check_profile_name_validity(const char *profile_name);

bool _wifi_libnet_get_wifi_state(wifi_connection_state_e* connection_state);
int _wifi_libnet_get_intf_name(char** name);
int _wifi_libnet_scan_request(wifi_scan_finished_cb callback, void* user_data);
int _wifi_libnet_get_connected_profile(wifi_ap_h *ap);
bool _wifi_libnet_foreach_found_aps(wifi_found_ap_cb callback, void *user_data);

int _wifi_libnet_open_profile(wifi_ap_h ap_h);
int _wifi_libnet_close_profile(wifi_ap_h ap_h);
int _wifi_libnet_connect_with_wps(wifi_ap_h ap_h, wifi_wps_type_e type, const char *pin);

int _wifi_set_power_on_off_cb(wifi_device_state_changed_cb callback, void *user_data);
int _wifi_unset_power_on_off_cb(void);
int _wifi_set_background_scan_cb(wifi_scan_finished_cb callback, void *user_data);
int _wifi_unset_background_scan_cb(void);
int _wifi_set_connection_state_cb(wifi_connection_state_changed_cb callback, void *user_data);
int _wifi_unset_connection_state_cb();

int _wifi_update_ap_info(net_profile_info_t *ap_info);
#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif
