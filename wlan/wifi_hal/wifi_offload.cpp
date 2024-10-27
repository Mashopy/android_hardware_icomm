/*
 * Copyright (C) 2017 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include <stdint.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <netlink/genl/genl.h>
#include <netlink/genl/family.h>
#include <netlink/genl/ctrl.h>
#include <linux/rtnetlink.h>
#include <netpacket/packet.h>
#include <linux/filter.h>
#include <linux/errqueue.h>

#include <linux/pkt_sched.h>
#include <netlink/object-api.h>
#include <netlink/netlink.h>
#include <netlink/socket.h>

#include "nl80211_copy.h"
#include "sync.h"

#define LOG_TAG  "WifiHAL"

#include <utils/Log.h>
#include <log/log.h>
#include <hardware_legacy/wifi_hal.h>
#include "common.h"
#include "cpp_bindings.h"

//using namespace android;

typedef enum {
    WIFI_OFFLOAD_START_MKEEP_ALIVE = ANDROID_NL80211_SUBCMD_WIFI_OFFLOAD_RANGE_START,
    WIFI_OFFLOAD_STOP_MKEEP_ALIVE,
} WIFI_OFFLOAD_SUB_COMMAND;

typedef enum {
    MKEEP_ALIVE_ATTRIBUTE_INVALID		= 0,
    MKEEP_ALIVE_ATTRIBUTE_ID			= 1,
    MKEEP_ALIVE_ATTRIBUTE_IP_PKT		= 2,
    MKEEP_ALIVE_ATTRIBUTE_IP_PKT_LEN		= 3,
    MKEEP_ALIVE_ATTRIBUTE_SRC_MAC_ADDR		= 4,
    MKEEP_ALIVE_ATTRIBUTE_DST_MAC_ADDR		= 5,
    MKEEP_ALIVE_ATTRIBUTE_PERIOD_MSEC		= 6,
    MKEEP_ALIVE_ATTRIBUTE_ETHER_TYPE		= 7,
    /* Add new attributes just above this */
    MKEEP_ALIVE_ATTRIBUTE_MAX
} WIFI_MKEEP_ALIVE_ATTRIBUTE;

typedef enum {
    START_MKEEP_ALIVE,
    STOP_MKEEP_ALIVE,
} GetCmdType;

/* API to send specified mkeep_alive packet periodically. */
wifi_error wifi_start_sending_offloaded_packet(wifi_request_id index, wifi_interface_handle iface,
        u16 ether_type, u8 *ip_packet, u16 ip_packet_len, u8 *src_mac_addr, u8 *dst_mac_addr,
        u32 period_msec)
{
    return WIFI_SUCCESS;
}

/* API to stop sending mkeep_alive packet. */
wifi_error wifi_stop_sending_offloaded_packet(wifi_request_id index, wifi_interface_handle iface)
{
    ALOGE("army debug for wifi_stop_sending_offloaded_packet====");
    return WIFI_SUCCESS;
}
