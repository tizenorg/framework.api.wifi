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

#include <stdio.h>
#include <string.h>
#include <glib.h>
#include <vconf/vconf.h>
#include "net_wifi_private.h"

static bool is_init = false;
static wifi_rssi_level_changed_cb rssi_level_changed_cb = NULL;
static void *rssi_level_changed_user_data = NULL;


static void __rssi_level_changed_cb(keynode_t *node, void *user_data)
{
	int rssi_level = vconf_keynode_get_int(node);
	rssi_level_changed_cb(rssi_level, rssi_level_changed_user_data);
}

int wifi_initialize(void)
{
	if (is_init) {
		WIFI_LOG(WIFI_ERROR, "Already initialized\n");
		return WIFI_ERROR_INVALID_OPERATION;
	}

	if (_wifi_libnet_init() == false) {
		WIFI_LOG(WIFI_ERROR, "Init failed!\n");
		return WIFI_ERROR_OPERATION_FAILED;
	}

	is_init = true;

	return WIFI_ERROR_NONE;
}

int wifi_deinitialize(void)
{
	if (is_init == false) {
		WIFI_LOG(WIFI_ERROR, "Not initialized\n");
		return WIFI_ERROR_INVALID_OPERATION;
	}

	if (_wifi_libnet_deinit() == false) {
		WIFI_LOG(WIFI_ERROR, "Deinit failed!\n");
		return WIFI_ERROR_OPERATION_FAILED;
	}

	is_init = false;
	wifi_unset_rssi_level_changed_cb();

	return WIFI_ERROR_NONE;
}

int wifi_activate(void)
{
	int rv;

	if (is_init == false) {
		WIFI_LOG(WIFI_ERROR, "Not initialized\n");
		return WIFI_ERROR_INVALID_OPERATION;
	}

	rv = _wifi_activate();
	if (rv != WIFI_ERROR_NONE)
		WIFI_LOG(WIFI_ERROR, "Error!! Wi-Fi Activation failed.\n");

	return rv;
}

int wifi_deactivate(void)
{
	int rv;

	if (is_init == false) {
		WIFI_LOG(WIFI_ERROR, "Not initialized\n");
		return WIFI_ERROR_INVALID_OPERATION;
	}

	rv = _wifi_deactivate();
	if (rv != WIFI_ERROR_NONE)
		WIFI_LOG(WIFI_ERROR, "Error!! Wi-Fi Deactivation failed.\n");

	return rv;
}

int wifi_is_activated(bool* activated)
{
	int status = 0;

	if (activated == NULL) {
		WIFI_LOG(WIFI_ERROR, "Wrong Parameter Passed\n");
		return WIFI_ERROR_INVALID_PARAMETER;
	}

	if (!vconf_get_int(VCONFKEY_NETWORK_WIFI_STATE, &status)) {
		WIFI_LOG(WIFI_INFO, "WiFi = %d\n", status);
		if (status == VCONFKEY_NETWORK_WIFI_OFF)
			*activated = false;
		else
			*activated = true;
	} else {
		WIFI_LOG(WIFI_ERROR, "vconf_get_int Failed = %d\n", status);
		return WIFI_ERROR_OPERATION_FAILED;
	}

	return WIFI_ERROR_NONE;
}

int wifi_get_connection_state(wifi_connection_state_e* connection_state)
{
	if (connection_state == NULL) {
		WIFI_LOG(WIFI_ERROR, "Wrong Parameter Passed\n");
		return WIFI_ERROR_INVALID_PARAMETER;
	}

	if (_wifi_libnet_get_wifi_state(connection_state) == false)
		return WIFI_ERROR_OPERATION_FAILED;

	return WIFI_ERROR_NONE;
}

int wifi_get_mac_address(char** mac_address)
{
	if (mac_address == NULL) {
		WIFI_LOG(WIFI_ERROR, "Wrong Parameter Passed\n");
		return WIFI_ERROR_INVALID_PARAMETER;
	}

	*mac_address = vconf_get_str(VCONFKEY_WIFI_BSSID_ADDRESS);

	if (*mac_address == NULL) {
		WIFI_LOG(WIFI_ERROR, "vconf_get_str Failed\n");
		return WIFI_ERROR_OPERATION_FAILED;
	}

	WIFI_LOG(WIFI_INFO, "MAC Address %s\n", *mac_address);

	return WIFI_ERROR_NONE;
}

int wifi_get_network_interface_name(char** name)
{
	if (name == NULL) {
		WIFI_LOG(WIFI_ERROR, "Wrong Parameter Passed\n");
		return WIFI_ERROR_INVALID_PARAMETER;
	}

	return _wifi_libnet_get_intf_name(name);
}

int wifi_scan(wifi_scan_finished_cb callback, void* user_data)
{
	int rv;

	if (callback == NULL) {
		WIFI_LOG(WIFI_ERROR, "Wrong Parameter Passed\n");
		return WIFI_ERROR_INVALID_PARAMETER;
	}

	if (is_init == false) {
		WIFI_LOG(WIFI_ERROR, "Not initialized\n");
		return WIFI_ERROR_INVALID_OPERATION;
	}

	rv = _wifi_libnet_scan_request(callback, user_data);
	if (rv != WIFI_ERROR_NONE)
		WIFI_LOG(WIFI_ERROR, "Error!! Wi-Fi scan failed.\n");

	return rv;
}

int wifi_get_connected_ap(wifi_ap_h* ap)
{
	int rv;

	if (ap == NULL) {
		WIFI_LOG(WIFI_ERROR, "Wrong Parameter Passed\n");
		return WIFI_ERROR_INVALID_PARAMETER;
	}

	 rv = _wifi_libnet_get_connected_profile(ap);
	WIFI_LOG(WIFI_INFO, "Connected AP : %p, rv : %d\n", *ap, rv);

	return rv;
}

int wifi_foreach_found_aps(wifi_found_ap_cb callback, void* user_data)
{
	if (callback == NULL) {
		WIFI_LOG(WIFI_ERROR, "Wrong Parameter Passed\n");
		return WIFI_ERROR_INVALID_PARAMETER;
	}

	if (_wifi_libnet_foreach_found_aps(callback, user_data) == false)
		return WIFI_ERROR_OPERATION_FAILED;

	return WIFI_ERROR_NONE;
}

int wifi_connect(wifi_ap_h ap)
{
	if (_wifi_libnet_check_ap_validity(ap) == false) {
		WIFI_LOG(WIFI_ERROR, "Wrong Parameter Passed\n");
		return WIFI_ERROR_INVALID_PARAMETER;
	}

	if (is_init == false) {
		WIFI_LOG(WIFI_ERROR, "Not initialized\n");
		return WIFI_ERROR_INVALID_OPERATION;
	}

	return _wifi_libnet_open_profile(ap);
}

int wifi_disconnect(wifi_ap_h ap)
{
	if (_wifi_libnet_check_ap_validity(ap) == false) {
		WIFI_LOG(WIFI_ERROR, "Wrong Parameter Passed\n");
		return WIFI_ERROR_INVALID_PARAMETER;
	}

	if (is_init == false) {
		WIFI_LOG(WIFI_ERROR, "Not initialized\n");
		return WIFI_ERROR_INVALID_OPERATION;
	}

	return _wifi_libnet_close_profile(ap);
}

int wifi_connect_with_wps(wifi_ap_h ap, wifi_wps_type_e type, const char* pin)
{
	if (_wifi_libnet_check_ap_validity(ap) == false ||
	    (type != WIFI_WPS_TYPE_PBC && type != WIFI_WPS_TYPE_PIN) ||
	    (type == WIFI_WPS_TYPE_PIN && pin == NULL)) {
		WIFI_LOG(WIFI_ERROR, "Wrong Parameter Passed\n");
		return WIFI_ERROR_INVALID_PARAMETER;
	}

	if (is_init == false) {
		WIFI_LOG(WIFI_ERROR, "Not initialized\n");
		return WIFI_ERROR_INVALID_OPERATION;
	}

	return _wifi_libnet_connect_with_wps(ap, type, pin);
}

int wifi_set_device_state_changed_cb(wifi_device_state_changed_cb callback, void* user_data)
{
	if (callback == NULL) {
		WIFI_LOG(WIFI_ERROR, "Wrong Parameter Passed\n");
		return WIFI_ERROR_INVALID_PARAMETER;
	}

	if (is_init == false) {
		WIFI_LOG(WIFI_ERROR, "Not initialized\n");
		return WIFI_ERROR_INVALID_OPERATION;
	}

	return _wifi_set_power_on_off_cb(callback, user_data);
}

int wifi_unset_device_state_changed_cb(void)
{
	return _wifi_unset_power_on_off_cb();
}

int wifi_set_background_scan_cb(wifi_scan_finished_cb callback, void* user_data)
{
	if (callback == NULL) {
		WIFI_LOG(WIFI_ERROR, "Wrong Parameter Passed\n");
		return WIFI_ERROR_INVALID_PARAMETER;
	}

	if (is_init == false) {
		WIFI_LOG(WIFI_ERROR, "Not initialized\n");
		return WIFI_ERROR_INVALID_OPERATION;
	}

	return _wifi_set_background_scan_cb(callback, user_data);
}

int wifi_unset_background_scan_cb(void)
{
	return _wifi_unset_background_scan_cb();
}

int wifi_set_connection_state_changed_cb(wifi_connection_state_changed_cb callback, void* user_data)
{
	if (callback == NULL) {
		WIFI_LOG(WIFI_ERROR, "Wrong Parameter Passed\n");
		return WIFI_ERROR_INVALID_PARAMETER;
	}

	if (is_init == false) {
		WIFI_LOG(WIFI_ERROR, "Not initialized\n");
		return WIFI_ERROR_INVALID_OPERATION;
	}

	return _wifi_set_connection_state_cb(callback, user_data);
}

int wifi_unset_connection_state_changed_cb(void)
{
	return _wifi_unset_connection_state_cb();
}

int wifi_set_rssi_level_changed_cb(wifi_rssi_level_changed_cb callback, void* user_data)
{
	if (callback == NULL) {
		WIFI_LOG(WIFI_ERROR, "Wrong Parameter Passed\n");
		return WIFI_ERROR_INVALID_PARAMETER;
	}

	if (rssi_level_changed_cb == NULL)
		vconf_notify_key_changed(VCONFKEY_WIFI_STRENGTH, __rssi_level_changed_cb, NULL);
	else
		return WIFI_ERROR_INVALID_OPERATION;

	rssi_level_changed_cb = callback;
	rssi_level_changed_user_data = user_data;

	return WIFI_ERROR_NONE;
}

int wifi_unset_rssi_level_changed_cb(void)
{
	if (rssi_level_changed_cb != NULL)
		vconf_ignore_key_changed(VCONFKEY_WIFI_STRENGTH, __rssi_level_changed_cb);
	else
		return WIFI_ERROR_INVALID_OPERATION;

	rssi_level_changed_cb = NULL;
	rssi_level_changed_user_data = NULL;

	return WIFI_ERROR_NONE;
}

