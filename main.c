#include <stdio.h>
#include "bms.h"

int main()
{

    if(bms_init() != bms_proc_failed)
    {
        bms_exec();
    }

}