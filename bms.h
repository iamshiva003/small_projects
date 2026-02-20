#ifndef _BMS_H_
#define _BMS_H_
#include "menu.h"
#include <stdio.h>

typedef enum 
{
    bms_proc_success = 0x01,
    bms_proc_failed = 0x02,
} bms_proc_t;

bms_proc_t bms_init();
bms_proc_t bms_exec();

#endif