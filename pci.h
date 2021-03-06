#ifndef PCI_H__
#define PCI_H__
/*
 * Code to search the PCI bus and find devices
 */
#include "types.h"

// 32 PCI devices per bus
#define MAX_DEV_PER_PCI_BUS 32

// Configure a PCI device by writing the device's register address into CONFIG_ADDRESS
// Write the device data into CONFIG_DATA
#define PCI_CONF_ADDR_IOPORT 0xCF8
#define PCI_CONF_DATA_IOPORT 0xCFC

struct pcifunc;

typedef struct {
    struct pcifunc * pntbrdg;
    uint32_t busnum;
} pcibus;

typedef struct {
    pcibus * bus;
    
    uint32_t dev;
    uint32_t func;
    uint32_t devid;
    uint32_t devcls;
    uint32_t regbase[6];
    uint32_t regsize[6];
    uint8_t irqline;
    uint8_t irqpin;
} pcifunc;

typedef struct {
    uint32_t key0, key1;
    int (* atchfunc)(pcifunc * pcif);
} pcidrvr;

int pciinit(void);
#endif