#ifndef __SYSTEM_CONF_H_
#define __SYSTEM_CONF_H_

/* LwIP stack configuration */
#include "lwipopts.h"

/* Ethernet MAC configuration */
#include "stm32f2x7_eth_conf.h"

/* StdPeriph Library configuration*/
#include "stm32f2xx_conf.h"


/* enable LCD  */
#define USE_LCD

/* enable DHCP, if disabled static address is used*/
//#define USE_DHCP
   
/* default serial port for printf */
#define SERIAL_PORT   COM2

/* default size of heap for malloc */
/* heap for FreeRTOS is in configTOTAL_HEAP_SIZE */
/* heap for LwIP is in MEM_SIZE */
#define MALLOC_HEAP_SIZE 4096
     

#define ST_MAC_ADDR0    0x00
#define ST_MAC_ADDR1    0x80
#define ST_MAC_ADDR2    0xE1

/* MAC ADDRESS */
/* all zeros mean use build in MAC address based on ST vendor 00:80:E1 */
#define MAC_ADDR0   0x00
#define MAC_ADDR1   0x00
#define MAC_ADDR2   0x00
#define MAC_ADDR3   0x00
#define MAC_ADDR4   0x00
#define MAC_ADDR5   0x00

/* Static IP ADDRESS */
#define IP_ADDR0   192
#define IP_ADDR1   168
#define IP_ADDR2   1
#define IP_ADDR3   0 /* zero means - use last number from MAC*/
   
/* NETMASK */
#define NETMASK_ADDR0   255
#define NETMASK_ADDR1   255
#define NETMASK_ADDR2   255
#define NETMASK_ADDR3   0

/* Gateway Address */
#define GW_ADDR0   192
#define GW_ADDR1   168
#define GW_ADDR2   1
#define GW_ADDR3   1  


#define HWADDR_LEN      6

struct _hwaddr_t {
    uint8_t len;
    uint8_t addr[HWADDR_LEN];
    uint8_t _reserved;
} __attribute__((packed));
typedef struct _hwaddr_t hwaddr_t;

#define IPADDR_LEN      4
struct _net_config_t {
    uint8_t addr[IPADDR_LEN];
    uint8_t gw[IPADDR_LEN];
    uint8_t mask[IPADDR_LEN];
} __attribute__((packed));
typedef struct _net_config_t net_config_t;

struct _config_t {
    uint32_t magic;
    
    hwaddr_t hwaddr;
    
    net_config_t net;
    
} __attribute__((packed));

typedef struct _config_t config_t;

extern config_t g_config;

#endif /* __SYSTEM_CONF_H_ */

