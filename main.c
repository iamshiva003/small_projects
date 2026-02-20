#include <stdio.h>
#include "bms.h"

int main()
{
    bms_proc_t status;

    if(bms_init())
    {
        status = bms_exec();
    }

}