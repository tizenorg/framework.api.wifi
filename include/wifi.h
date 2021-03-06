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

#ifndef __TIZEN_NETWORK_WIFI_H__
#define __TIZEN_NETWORK_WIFI_H__

#include <tizen.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
* @addtogroup CAPI_NETWORK_WIFI_MODULE
* @{
*/

/**
* @brief The Wi-Fi error type
*/
typedef enum
{
    WIFI_ERROR_NONE = TIZEN_ERROR_NONE, /**< Successful */
    WIFI_ERROR_INVALID_PARAMETER = TIZEN_ERROR_INVALID_PARAMETER, /**< Invalid parameter */
    WIFI_ERROR_OUT_OF_MEMORY = TIZEN_ERROR_OUT_OF_MEMORY, /**< Out of memory error */
    WIFI_ERROR_INVALID_OPERATION = TIZEN_ERROR_INVALID_OPERATION, /**< Invalid operation */
    WIFI_ERROR_ADDRESS_FAMILY_NOT_SUPPORTED = TIZEN_ERROR_ADDRESS_FAMILY_NOT_SUPPORTED, /**< Address family not supported */
    WIFI_ERROR_OPERATION_FAILED = TIZEN_ERROR_NETWORK_CLASS|0x0301, /**< Operation failed */
    WIFI_ERROR_NO_CONNECTION = TIZEN_ERROR_NETWORK_CLASS|0x0302, /**< There is no connected AP */
} wifi_error_e;

/**
* @brief The state of Wi-Fi connection
*/
typedef enum
{
    WIFI_CONNECTION_STATE_CONNECTING = 0,  /**< Trying to connect(association/configuration) */
    WIFI_CONNECTION_STATE_CONNECTED = 1,  /**< Wi-Fi is connected to an AP(ready/online) */
    WIFI_CONNECTION_STATE_DISCONNECTING = 2,  /**< Trying to disconnect(connected, but disconnecting process is on going) */
    WIFI_CONNECTION_STATE_DISCONNECTED = 3,  /**< Wi-Fi is disconnected */
} wifi_connection_state_e;

/**
* @brief The WPS(Wi-Fi Protected Setup) type
*/
typedef enum
{
    WIFI_WPS_TYPE_PBC = 0,  /**< PBC */
    WIFI_WPS_TYPE_PIN = 1,   /**< PIN */
} wifi_wps_type_e;

/**
* @brief The state of Wi-Fi device
*/
typedef enum
{
    WIFI_DEVICE_STATE_DEACTIVATED = 0,  /**< Wi-Fi is Deactivated */
    WIFI_DEVICE_STATE_ACTIVATED = 1,  /**< Wi-Fi is activated */
} wifi_device_state_e;

/**
* @brief The RSSI level
*/
typedef enum
{
    WIFI_RSSI_LEVEL_0 = 0,  /**< level 0 */
    WIFI_RSSI_LEVEL_1 = 1,  /**< level 1 */
    WIFI_RSSI_LEVEL_2 = 2,  /**< level 2 */
    WIFI_RSSI_LEVEL_3 = 3,  /**< level 3 */
    WIFI_RSSI_LEVEL_4 = 4,  /**< level 4 */
} wifi_rssi_level_e;

/**
* @}
*/


/**
* @addtogroup CAPI_NETWORK_WIFI_AP_NETWORK_MODULE
* @{
*/

/**
* @brief Net IP configuration Type
*/
typedef enum
{
    WIFI_IP_CONFIG_TYPE_NONE = 0,  /**< Not defined */
    WIFI_IP_CONFIG_TYPE_STATIC  = 1,  /**< Manual IP configuration */
    WIFI_IP_CONFIG_TYPE_DYNAMIC = 2,  /**< Config IP using DHCP client*/
    WIFI_IP_CONFIG_TYPE_AUTO = 3,  /**< Config IP from Auto IP pool (169.254/16). Later with DHCP client, if available */
    WIFI_IP_CONFIG_TYPE_FIXED = 4,  /**< Indicates an IP address that can not be modified */
} wifi_ip_config_type_e;

/**
* @brief Address type
*/
typedef enum
{
    WIFI_ADDRESS_FAMILY_IPV4 = 0,  /**< IPV4 Address family */
    WIFI_ADDRESS_FAMILY_IPV6 = 1,  /**< IPV6 Address family */
} wifi_address_family_e;

/**
* @brief This enumeration defines the proxy method type.
*/
typedef enum
{
    WIFI_PROXY_TYPE_DIRECT = 0, /**< Direct connection */
    WIFI_PROXY_TYPE_AUTO = 1, /**< Auto configuration(Use PAC file). If URL property is not set, DHCP/WPAD auto-discover will be tried */
    WIFI_PROXY_TYPE_MANUAL  = 2  /**< Manual configuration */
} wifi_proxy_type_e;

/**
* @}
*/


/**
* @addtogroup CAPI_NETWORK_WIFI_AP_SECURITY_MODULE
* @{
*/

/**
* @brief Below security modes are used in infrastructure and ad-hoc mode
* For now all EAP security mechanisms are provided only in infrastructure mode
*/
typedef enum
{
    WIFI_SECURITY_TYPE_NONE = 0,  /**< Security disabled */
    WIFI_SECURITY_TYPE_WEP = 1,  /**< WEP */
    WIFI_SECURITY_TYPE_WPA_PSK = 2,  /**< WPA-PSK */
    WIFI_SECURITY_TYPE_WPA2_PSK = 3,  /**< WPA2-PSK */
    WIFI_SECURITY_TYPE_EAP = 4,  /**< EAP */
} wifi_security_type_e;

/**
* @brief Below encryption modes are used in infrastructure and ad-hoc mode
*/
typedef enum
{
    WIFI_ENCRYPTION_TYPE_NONE = 0,  /**< Encryption disabled */
    WIFI_ENCRYPTION_TYPE_WEP = 1,  /**< WEP */
    WIFI_ENCRYPTION_TYPE_TKIP = 2,  /**< TKIP */
    WIFI_ENCRYPTION_TYPE_AES = 3,  /**< AES */
    WIFI_ENCRYPTION_TYPE_TKIP_AES_MIXED = 4,  /**< TKIP and AES are both supported */
} wifi_encryption_type_e;

/**
* @}
*/


/**
* @addtogroup CAPI_NETWORK_WIFI_AP_SECURITY_EAP_MODULE
* @{
*/

/**
* @brief EAP type
*/
typedef enum
{
    WIFI_EAP_TYPE_PEAP = 0,  /**< EAP PEAP type */
    WIFI_EAP_TYPE_TLS = 1,  /**< EAP TLS type */
    WIFI_EAP_TYPE_TTLS = 2,  /**< EAP TTLS type */
    WIFI_EAP_TYPE_SIM = 3,  /**< EAP SIM type */
    WIFI_EAP_TYPE_AKA = 4,  /**< EAP AKA type */
} wifi_eap_type_e;

/**
* @brief EAP phase2 authentication type
*/
typedef enum
{
    WIFI_EAP_AUTH_TYPE_NONE = 0,  /**< EAP phase2 authentication none */
    WIFI_EAP_AUTH_TYPE_PAP = 1,  /**< EAP phase2 authentication PAP */
    WIFI_EAP_AUTH_TYPE_MSCHAP = 2,  /**< EAP phase2 authentication MSCHAP */
    WIFI_EAP_AUTH_TYPE_MSCHAPV2 = 3,  /**< EAP phase2 authentication MSCHAPv2 */
    WIFI_EAP_AUTH_TYPE_GTC = 4,  /**< EAP phase2 authentication GTC */
    WIFI_EAP_AUTH_TYPE_MD5 = 5,  /**< EAP phase2 authentication MD5 */
} wifi_eap_auth_type_e;

/**
* @}
*/


/**
* @addtogroup CAPI_NETWORK_WIFI_AP_MODULE
* @{
*/

/**
* @brief  The handle for Wi-Fi access point.
*/
typedef void* wifi_ap_h;

/**
* @}
*/


/**
* @addtogroup CAPI_NETWORK_WIFI_MODULE
* @{
*/

/**
* @brief Called when you get the found access point repeatedly.
* @remarks  @a ap is valid only in this function. In order to use the ap outside this function, you must copy the ap with wifi_ap_clone().
* @param[in]  ap  The access point
* @param[in]  user_data  The user data passed from the request function
* @return  @c true to continue with the next iteration of the loop, \n @c false to break out of the loop
* @pre  wifi_foreach_found_aps() will invoke this callback.
* @see  wifi_foreach_found_aps()
*/
typedef bool(*wifi_found_ap_cb)(wifi_ap_h ap, void* user_data);

/**
* @brief Called when the device state is changed.
* @param[in] error_code  The error code
* @param[in] state  The device state
* @param[in] is_requested  Indicates whether this change is requested by you
* @param[in] user_data The user data passed from the callback registration function
* @see wifi_set_device_state_changed_cb()
* @see wifi_unset_device_state_changed_cb()
*/
typedef void(*wifi_device_state_changed_cb)(wifi_error_e error_code, wifi_device_state_e state, bool is_requested, void* user_data);

/**
* @brief Called when the scan is finished.
* @param[in] error_code  The error code
* @param[in] user_data The user data passed from the callback registration function
* @see wifi_scan()
* @see wifi_set_background_scan_cb()
* @see wifi_unset_background_scan_cb()
*/
typedef void(*wifi_scan_finished_cb)(wifi_error_e error_code, void* user_data);

/**
* @brief Called when the connection state is changed.
* @param[in] error_code  The error code
* @param[in] state  The connection state
* @param[in] ap  The access point
* @param[in] is_requested  Indicates whether this change is requested by you
* @param[in] user_data The user data passed from the callback registration function
* @see wifi_set_connection_state_changed_cb()
* @see wifi_unset_connection_state_changed_cb()
*/
typedef void(*wifi_connection_state_changed_cb)(wifi_error_e error_code, wifi_connection_state_e state, wifi_ap_h ap, bool is_requested, void* user_data);

/**
* @brief Called when the RSSI of connected Wi-Fi changed.
* @param[in] rssi_level  The level of RSSI
* @param[in] user_data The user data passed from the callback registration function
* @see wifi_set_rssi_level_changed_cb()
* @see wifi_unset_rssi_level_changed_cb()
*/
typedef void(*wifi_rssi_level_changed_cb)(wifi_rssi_level_e rssi_level, void* user_data);

/**
* @brief Initializes Wi-Fi
* @return 0 on success, otherwise negative error value.
* @retval #WIFI_ERROR_NONE  Successful
* @retval #WIFI_ERROR_INVALID_OPERATION  Invalid operation
* @retval #WIFI_ERROR_OPERATION_FAILED  Operation failed
*/
int wifi_initialize(void);

/**
* @brief Deinitializes Wi-Fi
* @return 0 on success, otherwise negative error value.
* @retval #WIFI_ERROR_NONE  Successful
* @retval #WIFI_ERROR_INVALID_OPERATION  Invalid operation
* @retval #WIFI_ERROR_OPERATION_FAILED  Operation failed
*/
int wifi_deinitialize(void);

/**
* @brief Activates Wi-Fi, asynchronously.
* @return 0 on success, otherwise negative error value.
* @retval #WIFI_ERROR_NONE  Successful
* @retval #WIFI_ERROR_INVALID_OPERATION  Invalid operation
* @retval #WIFI_ERROR_OPERATION_FAILED  Operation failed
*/
int wifi_activate(void);

/**
* @brief Deactivates Wi-Fi, asynchronously.
* @return 0 on success, otherwise negative error value.
* @retval #WIFI_ERROR_NONE  Successful
* @retval #WIFI_ERROR_INVALID_OPERATION  Invalid operation
* @retval #WIFI_ERROR_OPERATION_FAILED  Operation failed
*/
int wifi_deactivate(void);

/**
* @brief Check whether Wi-Fi is activated
* @param[out] is_requested  Indicates whether wifi is activated or not
* @return 0 on success, otherwise negative error value.
* @retval #WIFI_ERROR_NONE  Successful
* @retval #WIFI_ERROR_INVALID_PARAMETER  Invalid parameter
* @retval #WIFI_ERROR_OPERATION_FAILED  Operation failed
*/
int wifi_is_activated(bool* activated);

/**
* @brief Gets connection state
* @param[out] connection_state  The connection state
* @return 0 on success, otherwise negative error value.
* @retval #WIFI_ERROR_NONE  Successful
* @retval #WIFI_ERROR_INVALID_PARAMETER  Invalid parameter
* @retval #WIFI_ERROR_OPERATION_FAILED  Operation failed
*/
int wifi_get_connection_state(wifi_connection_state_e* connection_state);

/**
* @brief Gets the local MAC address.
* @remarks @a mac_address must be released with free() by you.
* @param[out] mac_address  The mac address
* @return 0 on success, otherwise negative error value.
* @retval #WIFI_ERROR_NONE  Successful
* @retval #WIFI_ERROR_INVALID_PARAMETER  Invalid parameter
* @retval #WIFI_ERROR_OPERATION_FAILED  Operation failed
*/
int wifi_get_mac_address(char** mac_address);

/**
* @brief Gets the name of network interface.
* @remarks @a name must be released with free() by you.
* @param[out] name  The name of network interface
* @return 0 on success, otherwise negative error value.
* @retval #WIFI_ERROR_NONE  Successful
* @retval #WIFI_ERROR_INVALID_PARAMETER  Invalid parameter
* @retval #WIFI_ERROR_OUT_OF_MEMORY  Out of memory
* @retval #WIFI_ERROR_OPERATION_FAILED  Operation failed
*/
int wifi_get_network_interface_name(char** name);

/**
* @brief Starts scan, asynchronously.
* @param[in] callback  The callback function to be called
* @param[in] user_data The user data passed to the callback function
* @return 0 on success, otherwise negative error value.
* @retval #WIFI_ERROR_NONE  Successful
* @retval #WIFI_ERROR_INVALID_PARAMETER  Invalid parameter
* @retval #WIFI_ERROR_INVALID_OPERATION  Invalid operation
* @retval #WIFI_ERROR_OPERATION_FAILED  Operation failed
* @post This function invokes wifi_scan_finished_cb().
*/
int wifi_scan(wifi_scan_finished_cb callback, void* user_data);

/**
* @brief Gets the handle of connected access point.
* @remarks @a handle must be released with wifi_ap_destroy().
* @param[out] ap  The handle of access point
* @return 0 on success, otherwise negative error value.
* @retval #WIFI_ERROR_NONE  Successful
* @retval #WIFI_ERROR_INVALID_PARAMETER  Invalid parameter
* @retval #WIFI_ERROR_OUT_OF_MEMORY  Out of memory
* @retval #WIFI_ERROR_NO_CONNECTION  There is no connected AP
*/
int wifi_get_connected_ap(wifi_ap_h* ap);

/**
* @brief Gets the result of scan.
* @param[in] callback  The callback to be called
* @param[in] user_data The user data passed to the callback function
* @return 0 on success, otherwise negative error value.
* @retval #WIFI_ERROR_NONE  Successful
* @retval #WIFI_ERROR_INVALID_PARAMETER  Invalid parameter
* @retval #WIFI_ERROR_OPERATION_FAILED  Operation failed
* @post This function invokes wifi_found_ap_cb().
*/
int wifi_foreach_found_aps(wifi_found_ap_cb callback, void* user_data);

/**
* @brief Connects the access point, asynchronously.
* @param[in] ap  The handle of access point
* @return 0 on success, otherwise negative error value.
* @retval #WIFI_ERROR_NONE  Successful
* @retval #WIFI_ERROR_INVALID_OPERATION  Invalid operation
* @retval #WIFI_ERROR_INVALID_PARAMETER  Invalid parameter
* @retval #WIFI_ERROR_OPERATION_FAILED  Operation failed
* @post This function invokes wifi_connection_state_changed_cb().
*/
int wifi_connect(wifi_ap_h ap);

/**
* @brief Disconnects the access point, asynchronously.
* @param[in] ap  The handle of access point
* @return 0 on success, otherwise negative error value.
* @retval #WIFI_ERROR_NONE  Successful
* @retval #WIFI_ERROR_INVALID_OPERATION  Invalid operation
* @retval #WIFI_ERROR_INVALID_PARAMETER  Invalid parameter
* @retval #WIFI_ERROR_OPERATION_FAILED  Operation failed
* @post This function invokes wifi_connection_state_changed_cb().
*/
int wifi_disconnect(wifi_ap_h ap);

/**
* @brief Connects the access point with WPS, asynchronously.
* @param[in] ap  The handle of access point
* @param[in] type  The type of WPS
* @param[in] pin  The pin value, which is valid only when type is WIFI_WPS_TYPE_PIN.
* @return 0 on success, otherwise negative error value.
* @retval #WIFI_ERROR_NONE  Successful
* @retval #WIFI_ERROR_INVALID_OPERATION  Invalid operation
* @retval #WIFI_ERROR_INVALID_PARAMETER  Invalid parameter
* @retval #WIFI_ERROR_OPERATION_FAILED  Operation failed
* @post This function invokes wifi_connection_state_changed_cb().
*/
int wifi_connect_with_wps(wifi_ap_h ap, wifi_wps_type_e type, const char* pin);

/**
* @brief Deletes the information of stored access point.
* @details If an AP is connected, then connection information will be stored.
* This information is used when a connection to that AP is established automatically.
* @param[in] ap  The handle of access point
* @return 0 on success, otherwise negative error value.
* @retval #WIFI_ERROR_NONE  Successful
* @retval #WIFI_ERROR_INVALID_OPERATION  Invalid operation
* @retval #WIFI_ERROR_INVALID_PARAMETER  Invalid parameter
* @retval #WIFI_ERROR_OPERATION_FAILED  Operation failed
*/
int wifi_forget_ap(wifi_ap_h ap);

/**
* @brief Registers the callback called when the device state is changed.
* @param[in] callback  The callback function to be called
* @param[in] user_data The user data passed to the callback function
* @return 0 on success, otherwise negative error value.
* @retval #WIFI_ERROR_NONE  Successful
* @retval #WIFI_ERROR_INVALID_OPERATION  Invalid operation
* @retval #WIFI_ERROR_INVALID_PARAMETER   Invalid parameter
*/
int wifi_set_device_state_changed_cb(wifi_device_state_changed_cb callback, void* user_data);

/**
* @brief Unregisters the callback called when the device state is changed.
* @return 0 on success, otherwise negative error value.
* @retval #WIFI_ERROR_NONE  Successful
* @retval #WIFI_ERROR_INVALID_OPERATION  Invalid operation
*/
int wifi_unset_device_state_changed_cb(void);

/**
* @brief Registers the callback called when the background scan is finished periodically.
* @param[in] callback  The callback function to be called
* @param[in] user_data The user data passed to the callback function
* @return 0 on success, otherwise negative error value.
* @retval #WIFI_ERROR_NONE  Successful
* @retval #WIFI_ERROR_INVALID_OPERATION  Invalid operation
* @retval #WIFI_ERROR_INVALID_PARAMETER   Invalid parameter
*/
int wifi_set_background_scan_cb(wifi_scan_finished_cb callback, void* user_data);

/**
* @brief Unregisters the callback called when the scan is finished periodically.
* @return 0 on success, otherwise negative error value.
* @retval #WIFI_ERROR_NONE  Successful
* @retval #WIFI_ERROR_INVALID_OPERATION  Invalid operation
*/
int wifi_unset_background_scan_cb(void);

/**
* @brief Registers the callback called when the connection state is changed.
* @param[in] callback  The callback function to be called
* @param[in] user_data The user data passed to the callback function
* @return 0 on success, otherwise negative error value.
* @retval #WIFI_ERROR_NONE  Successful
* @retval #WIFI_ERROR_INVALID_OPERATION  Invalid operation
* @retval #WIFI_ERROR_INVALID_PARAMETER   Invalid parameter
*/
int wifi_set_connection_state_changed_cb(wifi_connection_state_changed_cb callback, void* user_data);

/**
* @brief Unregisters the callback called when the connection state is changed.
* @return 0 on success, otherwise negative error value.
* @retval #WIFI_ERROR_NONE  Successful
* @retval #WIFI_ERROR_INVALID_OPERATION  Invalid operation
*/
int wifi_unset_connection_state_changed_cb(void);

/**
* @brief Registers callback called when the RSSI of connected Wi-Fi changed.
* @param[in] callback  The callback function to be called
* @param[in] user_data The user data passed to the callback function
* @return 0 on success, otherwise negative error value.
* @retval #WIFI_ERROR_NONE  Successful
* @retval #WIFI_ERROR_INVALID_OPERATION  Invalid operation
* @retval #WIFI_ERROR_INVALID_PARAMETER   Invalid parameter
*/
int wifi_set_rssi_level_changed_cb(wifi_rssi_level_changed_cb callback, void* user_data);

/**
* @brief Unregisters callback called when the RSSI of connected Wi-Fi changed.
* @return 0 on success, otherwise negative error value.
* @retval #WIFI_ERROR_NONE  Successful
* @retval #WIFI_ERROR_INVALID_OPERATION  Invalid operation
*/
int wifi_unset_rssi_level_changed_cb(void);

/**
* @}
*/


/**
* @addtogroup CAPI_NETWORK_WIFI_AP_MODULE
* @{
*/

/**
* @brief Creates the handle of access point.
* @remarks @a ap must be released with wifi_ap_destroy().
* @param[in] essid  The ESSID(Extended Service Set Identifier)
* @param[out] ap  The handle of access point
* @return 0 on success, otherwise negative error value.
* @retval #WIFI_ERROR_NONE  Successful
* @retval #WIFI_ERROR_INVALID_PARAMETER  Invalid parameter
* @retval #WIFI_ERROR_OUT_OF_MEMORY  Out of memory
* @see wifi_ap_destroy()
*/
int wifi_ap_create(const char* essid, wifi_ap_h* ap);

/**
* @brief Destroys the handle of access point.
* @param[in] ap  The handle of access point
* @return 0 on success, otherwise negative error value.
* @retval #WIFI_ERROR_NONE  Successful
* @retval #WIFI_ERROR_INVALID_PARAMETER  Invalid parameter
* @see wifi_ap_create()
*/
int wifi_ap_destroy(wifi_ap_h ap);

/**
* @brief Clons the handle of access point.
* @remarks @a cloned_ap must be released with wifi_ap_destroy().
* @param[out] cloned_ap  The handle of cloned access point
* @param[in] origin  The handle of origin access point
* @return 0 on success, otherwise negative error value.
* @retval #WIFI_ERROR_NONE  Successful
* @retval #WIFI_ERROR_INVALID_PARAMETER  Invalid parameter
* @retval #WIFI_ERROR_OUT_OF_MEMORY  Out of memory
* @see wifi_ap_destroy()
*/
int wifi_ap_clone(wifi_ap_h* cloned_ap, wifi_ap_h origin);

/**
* @}
*/


/**
* @addtogroup CAPI_NETWORK_WIFI_AP_NETWORK_MODULE
* @{
*/

/**
* @brief Gets ESSID(Extended Service Set Identifier).
* @remarks @a essid must be released with free() by you.
* @param[in] ap  The handle of access point
* @param[out] essid  The ESSID
* @return 0 on success, otherwise negative error value.
* @retval #WIFI_ERROR_NONE  Successful
* @retval #WIFI_ERROR_INVALID_PARAMETER  Invalid parameter
* @retval #WIFI_ERROR_OUT_OF_MEMORY  Out of memory
*/
int wifi_ap_get_essid(wifi_ap_h ap, char** essid);

/**
* @brief Gets BSSID(Basic Service Set Identifier).
* @remarks @a bssid must be released with free() by you.
* @param[in] ap  The handle of access point
* @param[out] bssid  The BSSID
* @return 0 on success, otherwise negative error value.
* @retval #WIFI_ERROR_NONE  Successful
* @retval #WIFI_ERROR_INVALID_PARAMETER  Invalid parameter
* @retval #WIFI_ERROR_OUT_OF_MEMORY  Out of memory
*/
int wifi_ap_get_bssid(wifi_ap_h ap, char** bssid);

/**
* @brief Gets the RSSI.
* @param[in] ap  The handle of access point
* @param[out] rssi  The RSSI
* @return 0 on success, otherwise negative error value.
* @retval #WIFI_ERROR_NONE  Successful
* @retval #WIFI_ERROR_INVALID_PARAMETER  Invalid parameter
* @retval #WIFI_ERROR_OPERATION_FAILED  Operation failed
*/
int wifi_ap_get_rssi(wifi_ap_h ap, int* rssi);

/**
* @brief Gets the Frequency band (MHz).
* @param[in] ap  The handle of access point
* @param[out] frequency  The frequency
* @return 0 on success, otherwise negative error value.
* @retval #WIFI_ERROR_NONE  Successful
* @retval #WIFI_ERROR_INVALID_PARAMETER  Invalid parameter
* @retval #WIFI_ERROR_OPERATION_FAILED  Operation failed
*/
int wifi_ap_get_frequency(wifi_ap_h ap, int* frequency);

/**
* @brief Gets the max speed (Mbps).
* @param[in] ap  The handle of access point
* @param[out] max_speed  The max speed
* @return 0 on success, otherwise negative error value.
* @retval #WIFI_ERROR_NONE  Successful
* @retval #WIFI_ERROR_INVALID_PARAMETER  Invalid parameter
* @retval #WIFI_ERROR_OPERATION_FAILED  Operation failed
*/
int wifi_ap_get_max_speed(wifi_ap_h ap, int* max_speed);

/**
* @brief Indicates whether the access point is favorite or not.
* @param[in] ap  The handle of access point
* @param[out] favourite  Indicates whether access point is favorite or not.
* @return 0 on success, otherwise negative error value.
* @retval #WIFI_ERROR_NONE  Successful
* @retval #WIFI_ERROR_INVALID_PARAMETER  Invalid parameter
* @retval #WIFI_ERROR_OPERATION_FAILED  Operation failed
*/
int wifi_ap_is_favorite(wifi_ap_h ap, bool* favorite);

/**
* @brief Gets the connection state.
* @param[in] ap  The handle of access point
* @param[out] state  The connection state
* @return 0 on success, otherwise negative error value.
* @retval #WIFI_ERROR_NONE  Successful
* @retval #WIFI_ERROR_INVALID_PARAMETER  Invalid parameter
* @retval #WIFI_ERROR_OPERATION_FAILED  Operation failed
*/
int wifi_ap_get_connection_state(wifi_ap_h ap, wifi_connection_state_e* state);

/**
* @brief Gets the config type of IP.
* @param[in] ap  The handle of access point
* @param[in] address_family  The address family
* @param[out] type  The type of IP config
* @return 0 on success, otherwise negative error value.
* @retval #WIFI_ERROR_NONE  Successful
* @retval #WIFI_ERROR_INVALID_PARAMETER  Invalid parameter
* @retval #WIFI_ERROR_OPERATION_FAILED  Operation failed
* @retval #WIFI_ERROR_ADDRESS_FAMILY_NOT_SUPPORTED  Address family not supported
*/
int wifi_ap_get_ip_config_type(wifi_ap_h ap, wifi_address_family_e address_family, wifi_ip_config_type_e* type);

/**
* @brief Sets the config type of IP.
* @param[in] ap  The handle of access point
* @param[in] address_family  The address family
* @param[in] type  The type of IP config
* @return 0 on success, otherwise negative error value.
* @retval #WIFI_ERROR_NONE  Successful
* @retval #WIFI_ERROR_INVALID_PARAMETER  Invalid parameter
* @retval #WIFI_ERROR_OPERATION_FAILED  Operation failed
* @retval #WIFI_ERROR_ADDRESS_FAMILY_NOT_SUPPORTED  Address family not supported
*/
int wifi_ap_set_ip_config_type(wifi_ap_h ap, wifi_address_family_e address_family, wifi_ip_config_type_e type);

/**
* @brief Gets the IP address.
* @remarks @a ip_address must be released with free() by you.
* @param[in] ap  The handle of access point
* @param[in] address_family  The address family
* @param[out] ip_address  The IP address
* @return 0 on success, otherwise negative error value.
* @retval #WIFI_ERROR_NONE  Successful
* @retval #WIFI_ERROR_INVALID_PARAMETER  Invalid parameter
* @retval #WIFI_ERROR_OUT_OF_MEMORY  Out of memory
* @retval #WIFI_ERROR_ADDRESS_FAMILY_NOT_SUPPORTED  Address family not supported
*/
int wifi_ap_get_ip_address(wifi_ap_h ap, wifi_address_family_e address_family, char** ip_address);

/**
* @brief Sets the IP address.
* @param[in] ap  The handle of access point
* @param[in] address_family  The address family
* @param[in] ip_address  The IP address
* @return 0 on success, otherwise negative error value.
* @retval #WIFI_ERROR_NONE  Successful
* @retval #WIFI_ERROR_INVALID_PARAMETER  Invalid parameter
* @retval #WIFI_ERROR_OPERATION_FAILED  Operation failed
* @retval #WIFI_ERROR_ADDRESS_FAMILY_NOT_SUPPORTED  Address family not supported
*/
int wifi_ap_set_ip_address(wifi_ap_h ap, wifi_address_family_e address_family, const char* ip_address);

/**
* @brief Gets the subnet mask.
* @remarks @a subnet_mask must be released with free() by you.
* @param[in] ap  The handle of access point
* @param[in] address_family  The address family
* @param[out] subnet_mask  The subnet mask
* @return 0 on success, otherwise negative error value.
* @retval #WIFI_ERROR_NONE  Successful
* @retval #WIFI_ERROR_INVALID_PARAMETER  Invalid parameter
* @retval #WIFI_ERROR_OUT_OF_MEMORY  Out of memory
* @retval #WIFI_ERROR_ADDRESS_FAMILY_NOT_SUPPORTED  Address family not supported
*/
int wifi_ap_get_subnet_mask(wifi_ap_h ap, wifi_address_family_e address_family, char** subnet_mask);

/**
* @brief Sets the subnet mask.
* @param[in] ap  The handle of access point
* @param[in] address_family  The address family
* @param[in] subnet_mask  The subnet mask
* @return 0 on success, otherwise negative error value.
* @retval #WIFI_ERROR_NONE  Successful
* @retval #WIFI_ERROR_INVALID_PARAMETER  Invalid parameter
* @retval #WIFI_ERROR_OPERATION_FAILED  Operation failed
* @retval #WIFI_ERROR_ADDRESS_FAMILY_NOT_SUPPORTED  Address family not supported
*/
int wifi_ap_set_subnet_mask(wifi_ap_h ap, wifi_address_family_e address_family, const char* subnet_mask);

/**
* @brief Gets the gateway address.
* @remarks @a gateway_address must be released with free() by you.
* @param[in] ap  The handle of access point
* @param[in] address_family  The address family
* @param[out] gateway_address  The gateway address
* @return 0 on success, otherwise negative error value.
* @retval #WIFI_ERROR_NONE  Successful
* @retval #WIFI_ERROR_INVALID_PARAMETER  Invalid parameter
* @retval #WIFI_ERROR_OUT_OF_MEMORY  Out of memory
* @retval #WIFI_ERROR_ADDRESS_FAMILY_NOT_SUPPORTED  Address family not supported
*/
int wifi_ap_get_gateway_address(wifi_ap_h ap, wifi_address_family_e address_family, char** gateway_address);

/**
* @brief Sets the gateway address.
* @param[in] ap  The handle of access point
* @param[in] address_family  The address family
* @param[in] gateway_address  The gateway address
* @return 0 on success, otherwise negative error value.
* @retval #WIFI_ERROR_NONE  Successful
* @retval #WIFI_ERROR_INVALID_PARAMETER  Invalid parameter
* @retval #WIFI_ERROR_OPERATION_FAILED  Operation failed
* @retval #WIFI_ERROR_ADDRESS_FAMILY_NOT_SUPPORTED  Address family not supported
*/
int wifi_ap_set_gateway_address(wifi_ap_h ap, wifi_address_family_e address_family, const char* gateway_address);

/**
* @brief Gets the proxy address.
* @remarks @a proxy_address must be released with free() by you.
* @param[in] ap  The handle of access point
* @param[in] address_family  The address family
* @param[out] proxy_address  The proxy address
* @return 0 on success, otherwise negative error value.
* @retval #WIFI_ERROR_NONE  Successful
* @retval #WIFI_ERROR_INVALID_PARAMETER  Invalid parameter
* @retval #WIFI_ERROR_OUT_OF_MEMORY  Out of memory
* @retval #WIFI_ERROR_ADDRESS_FAMILY_NOT_SUPPORTED  Address family not supported
*/
int wifi_ap_get_proxy_address(wifi_ap_h ap, wifi_address_family_e address_family, char** proxy_address);

/**
* @brief Sets the proxy address.
* @param[in] ap  The handle of access point
* @param[in] address_family  The address family
* @param[in] proxy_address  The proxy address
* @return 0 on success, otherwise negative error value.
* @retval #WIFI_ERROR_NONE  Successful
* @retval #WIFI_ERROR_INVALID_PARAMETER  Invalid parameter
* @retval #WIFI_ERROR_OPERATION_FAILED  Operation failed
* @retval #WIFI_ERROR_ADDRESS_FAMILY_NOT_SUPPORTED  Address family not supported
*/
int wifi_ap_set_proxy_address(wifi_ap_h ap, wifi_address_family_e address_family, const char* proxy_address);

/**
* @brief Gets the Proxy type.
* @param[in] ap  The handle of access point
* @param[out] type  The type of proxy
* @return 0 on success, otherwise negative error value.
* @retval #WIFI_ERROR_NONE  Successful
* @retval #WIFI_ERROR_INVALID_PARAMETER  Invalid parameter
* @retval #WIFI_ERROR_OPERATION_FAILED  Operation failed
*/
int wifi_ap_get_proxy_type(wifi_ap_h ap, wifi_proxy_type_e* type);

/**
* @brief Sets the Proxy address.
* @param[in] ap  The handle of access point
* @param[in] type  The type of proxy
* @return 0 on success, otherwise negative error value.
* @retval #WIFI_ERROR_NONE  Successful
* @retval #WIFI_ERROR_INVALID_PARAMETER  Invalid parameter
* @retval #WIFI_ERROR_OPERATION_FAILED  Operation failed
*/
int wifi_ap_set_proxy_type(wifi_ap_h ap, wifi_proxy_type_e proxy_type);

/**
* @brief Gets the DNS address.
* @remarks The allowance of DNS address is 2. @a dns_address must be released with free() by you.
* @param[in] ap  The handle of access point
* @param[in] order  The order of DNS address. It starts from 1, which means first DNS address.
* @param[in] address_family  The address family
* @param[out] dns_address  The DNS address
* @return 0 on success, otherwise negative error value.
* @retval #WIFI_ERROR_NONE  Successful
* @retval #WIFI_ERROR_INVALID_PARAMETER  Invalid parameter
* @retval #WIFI_ERROR_OUT_OF_MEMORY  Out of memory
* @retval #WIFI_ERROR_ADDRESS_FAMILY_NOT_SUPPORTED  Address family not supported
*/
int wifi_ap_get_dns_address(wifi_ap_h ap, int order, wifi_address_family_e address_family, char** dns_address);

/**
* @brief Sets the DNS address.
* @remarks The allowance of DNS address is 2.
* @param[in] ap  The handle of access point
* @param[in] order  The order of DNS address. It starts from 1, which means first DNS address.
* @param[in] address_family  The address family
* @param[in] dns_address  The DNS address
* @return 0 on success, otherwise negative error value.
* @retval #WIFI_ERROR_NONE  Successful
* @retval #WIFI_ERROR_INVALID_PARAMETER  Invalid parameter
* @retval #WIFI_ERROR_OPERATION_FAILED  Operation failed
* @retval #WIFI_ERROR_ADDRESS_FAMILY_NOT_SUPPORTED  Address family not supported
*/
int wifi_ap_set_dns_address(wifi_ap_h ap, int order, wifi_address_family_e address_family, const char* dns_address);

/**
* @}
*/


/**
* @addtogroup CAPI_NETWORK_WIFI_AP_SECURITY_MODULE
* @{
*/

/**
* @brief Gets the security mode of Wi-Fi.
* @param[in] ap  The handle of access point
* @param[out] type  The type of Wi-Fi security
* @return 0 on success, otherwise negative error value.
* @retval #WIFI_ERROR_NONE  Successful
* @retval #WIFI_ERROR_INVALID_PARAMETER  Invalid parameter
* @retval #WIFI_ERROR_OPERATION_FAILED  Operation failed
*/
int wifi_ap_get_security_type(wifi_ap_h ap, wifi_security_type_e* type);

/**
* @brief Sets the security mode of Wi-Fi.
* @param[in] ap  The handle of access point
* @param[in] type  The type of Wi-Fi security
* @return 0 on success, otherwise negative error value.
* @retval #WIFI_ERROR_NONE  Successful
* @retval #WIFI_ERROR_INVALID_PARAMETER  Invalid parameter
* @retval #WIFI_ERROR_OPERATION_FAILED  Operation failed
*/
int wifi_ap_set_security_type(wifi_ap_h ap, wifi_security_type_e type);

/**
* @brief Gets the encryption type of Wi-Fi.
* @param[in] ap  The handle of access point
* @param[out] type  The type of Wi-Fi encryption
* @return 0 on success, otherwise negative error value.
* @retval #WIFI_ERROR_NONE  Successful
* @retval #WIFI_ERROR_INVALID_PARAMETER  Invalid parameter
* @retval #WIFI_ERROR_OPERATION_FAILED  Operation failed
*/
int wifi_ap_get_encryption_type(wifi_ap_h ap, wifi_encryption_type_e* type);

/**
* @brief Sets the encryption type of Wi-Fi.
* @param[in] ap  The handle of access point
* @param[in] type  The type of Wi-Fi encryption
* @return 0 on success, otherwise negative error value.
* @retval #WIFI_ERROR_NONE  Successful
* @retval #WIFI_ERROR_INVALID_PARAMETER  Invalid parameter
* @retval #WIFI_ERROR_OPERATION_FAILED  Operation failed
*/
int wifi_ap_set_encryption_type(wifi_ap_h ap, wifi_encryption_type_e type);

/**
* @brief Indicates whether the passphrase is required or not.
* @param[in] ap  The handle of access point
* @param[out] required  Indicates whether passphrase is required or not
* @return 0 on success, otherwise negative error value.
* @retval #WIFI_ERROR_NONE  Successful
* @retval #WIFI_ERROR_INVALID_PARAMETER  Invalid parameter
* @retval #WIFI_ERROR_OPERATION_FAILED  Operation failed
*/
int wifi_ap_is_passphrase_required(wifi_ap_h ap, bool* required);

/**
* @brief Sets the passphrase.
* @param[in] ap  The handle of access point
* @param[in] passphrase  The passphrase of access point
* @return 0 on success, otherwise negative error value.
* @retval #WIFI_ERROR_NONE  Successful
* @retval #WIFI_ERROR_INVALID_PARAMETER  Invalid parameter
* @retval #WIFI_ERROR_OPERATION_FAILED  Operation failed
*/
int wifi_ap_set_passphrase(wifi_ap_h ap, const char* passphrase);

/**
* @brief Indicates whether the WPS is supported or not.
* @param[in] ap  The handle of access point
* @param[out] supported  Indicates whether WPS is supported or not
* @return 0 on success, otherwise negative error value.
* @retval #WIFI_ERROR_NONE  Successful
* @retval #WIFI_ERROR_INVALID_PARAMETER  Invalid parameter
* @retval #WIFI_ERROR_OPERATION_FAILED  Operation failed
*/
int wifi_ap_is_wps_supported(wifi_ap_h ap, bool* supported);

/**
* @}
*/


/**
* @addtogroup CAPI_NETWORK_WIFI_AP_SECURITY_EAP_MODULE
* @{
*/

/**
* @brief Sets the passphrase of EAP.
* @param[in] ap  The handle of access point
* @param[in] user_name  The user name
* @param[in] password  The password
* @return 0 on success, otherwise negative error value.
* @retval #WIFI_ERROR_NONE  Successful
* @retval #WIFI_ERROR_INVALID_PARAMETER  Invalid parameter
* @retval #WIFI_ERROR_INVALID_OPERATION  Invalid operation
*/
int wifi_ap_set_eap_passphrase(wifi_ap_h ap, const char* user_name, const char* password);

/**
* @brief Gets the CA Certificate of EAP.
* @remarks @a file must be released with free() by you.
* @param[in] ap  The handle of access point
* @param[out] file  The file path of CA Certificate
* @return 0 on success, otherwise negative error value.
* @retval #WIFI_ERROR_NONE  Successful
* @retval #WIFI_ERROR_INVALID_PARAMETER  Invalid parameter
* @retval #WIFI_ERROR_OUT_OF_MEMORY  Out of memory
* @retval #WIFI_ERROR_INVALID_OPERATION  Invalid operation
*/
int wifi_ap_get_eap_ca_cert_file(wifi_ap_h ap, char** file);

/**
* @brief Sets the CA Certificate of EAP.
* @param[in] ap  The handle of access point
* @param[in] file  The file path of CA Certificate
* @return 0 on success, otherwise negative error value.
* @retval #WIFI_ERROR_NONE  Successful
* @retval #WIFI_ERROR_INVALID_PARAMETER  Invalid parameter
* @retval #WIFI_ERROR_INVALID_OPERATION  Invalid operation
*/
int wifi_ap_set_eap_ca_cert_file(wifi_ap_h ap, const char* file);

/**
* @brief Gets the Client Certificate of EAP.
* @remarks @a file must be released with free() by you.
* @param[in] ap  The handle of access point
* @param[out] file  The file path of Client Certificate
* @return 0 on success, otherwise negative error value.
* @retval #WIFI_ERROR_NONE  Successful
* @retval #WIFI_ERROR_INVALID_PARAMETER  Invalid parameter
* @retval #WIFI_ERROR_OUT_OF_MEMORY  Out of memory
* @retval #WIFI_ERROR_INVALID_OPERATION  Invalid operation
*/
int wifi_ap_get_eap_client_cert_file(wifi_ap_h ap, char** file);

/**
* @brief Sets the CA Certificate of EAP.
* @param[in] ap  The handle of access point
* @param[in] file  The file path of Client Certificate
* @return 0 on success, otherwise negative error value.
* @retval #WIFI_ERROR_NONE  Successful
* @retval #WIFI_ERROR_INVALID_PARAMETER  Invalid parameter
* @retval #WIFI_ERROR_INVALID_OPERATION  Invalid operation
*/
int wifi_ap_set_eap_client_cert_file(wifi_ap_h ap, const char* file);

/**
* @brief Gets the private key file of EAP.
* @remarks @a file must be released with free() by you.
* @param[in] ap  The handle of access point
* @param[out] file  The file path of private key
* @return 0 on success, otherwise negative error value.
* @retval #WIFI_ERROR_NONE  Successful
* @retval #WIFI_ERROR_INVALID_PARAMETER  Invalid parameter
* @retval #WIFI_ERROR_OUT_OF_MEMORY  Out of memory
* @retval #WIFI_ERROR_INVALID_OPERATION  Invalid operation
*/
int wifi_ap_get_eap_private_key_file(wifi_ap_h ap, char** file);

/**
* @brief Sets the private key information of EAP.
* @param[in] ap  The handle of access point
* @param[in] file  The file path of private key
* @param[in] password  The password
* @return 0 on success, otherwise negative error value.
* @retval #WIFI_ERROR_NONE  Successful
* @retval #WIFI_ERROR_INVALID_PARAMETER  Invalid parameter
* @retval #WIFI_ERROR_INVALID_OPERATION  Invalid operation
*/
int wifi_ap_set_eap_private_key_info(wifi_ap_h ap, const char* file, const char* password);

/**
* @brief Gets the EAP type of Wi-Fi.
* @param[in] ap  The handle of access point
* @param[out] type  The type of EAP
* @return 0 on success, otherwise negative error value.
* @retval #WIFI_ERROR_NONE  Successful
* @retval #WIFI_ERROR_INVALID_PARAMETER  Invalid parameter
* @retval #WIFI_ERROR_INVALID_OPERATION  Invalid operation
* @retval #WIFI_ERROR_OPERATION_FAILED  Operation failed
*/
int wifi_ap_get_eap_type(wifi_ap_h ap, wifi_eap_type_e* type);

/**
* @brief Sets the EAP type of Wi-Fi.
* @param[in] ap  The handle of access point
* @param[in] type  The type of EAP
* @return 0 on success, otherwise negative error value.
* @retval #WIFI_ERROR_NONE  Successful
* @retval #WIFI_ERROR_INVALID_PARAMETER  Invalid parameter
* @retval #WIFI_ERROR_INVALID_OPERATION  Invalid operation
*/
int wifi_ap_set_eap_type(wifi_ap_h ap, wifi_eap_type_e type);

/**
* @brief Gets the type of EAP phase2 authentication of Wi-Fi.
* @param[in] ap  The handle of access point
* @param[out] type  The type of EAP phase2 authentication
* @return 0 on success, otherwise negative error value.
* @retval #WIFI_ERROR_NONE  Successful
* @retval #WIFI_ERROR_INVALID_PARAMETER  Invalid parameter
* @retval #WIFI_ERROR_INVALID_OPERATION  Invalid operation
* @retval #WIFI_ERROR_OPERATION_FAILED  Operation failed
*/
int wifi_ap_get_eap_auth_type(wifi_ap_h ap, wifi_eap_auth_type_e* type);

/**
* @brief Sets the type of EAP phase2 authentication of Wi-Fi.
* @param[in] ap  The handle of access point
* @param[in] type  The type of EAP phase2 authentication
* @return 0 on success, otherwise negative error value.
* @retval #WIFI_ERROR_NONE  Successful
* @retval #WIFI_ERROR_INVALID_PARAMETER  Invalid parameter
* @retval #WIFI_ERROR_INVALID_OPERATION  Invalid operation
*/
int wifi_ap_set_eap_auth_type(wifi_ap_h ap, wifi_eap_auth_type_e type);

/**
* @}
*/


#ifdef __cplusplus
}
#endif

#endif /* __TIZEN_NETWORK_WIFI_H__ */
