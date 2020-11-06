/*
 * Copyright (c) 2006-2020, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2020-11-06     18983       the first version
 */
#include <string.h>
#include "test.h"

#define WIFI_SSID       "TP-LINK_FSZX"
#define WIFI_PASSWORD   "fszx8888"

void test_app(void)
{
    struct rt_wlan_scan_result *scan_result = RT_NULL;
    struct rt_wlan_info *info = RT_NULL;

    rt_thread_mdelay(4000);

    /* clean scan result */
    rt_wlan_scan_result_clean();
    /* scan ap info */
    scan_result = rt_wlan_scan_with_info(info);

    if(scan_result != RT_NULL)
    {
        uint16_t index;

        for(index = 0; index < scan_result->num; index++)
        {
            if(0 == strcmp((const char *)scan_result->info->ssid.val, WIFI_SSID))
            {
                if(rt_wlan_connect(WIFI_SSID, WIFI_PASSWORD) != RT_EOK)
                {
                    rt_kprintf("wifi connect fail!\n");
                }
            }
        }
    }
    else
    {
        rt_kprintf("scan wifi err!\n");
    }

}
