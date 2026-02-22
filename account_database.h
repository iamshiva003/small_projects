#ifndef _ACCOUNT_DATABASE_H_
#define _ACCOUNT_DATABASE_H_
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "account_manage.h"
#include <string.h>

#define DB_SIGNATURE (0xDB10ADEDu)
#define DB_NAME "BMS.bdb"
#define DB_FAIL_MASK (0xf0000000u)


/*
DATABSE ENCRYPTION WITH MASTER KEY TO BE IMPLEMENTED
*/
typedef enum 
{
    DB_OPERATION_FAILED  = 0xf0000000,
    DB_OPERATION_SUCCESS = 0x00000000
} db_operation_status;

typedef struct 
{
    uint32_t db_signature;
    uint32_t account_count;
} __attribute__((packed)) account_databse_header;

extern account_databse_header db_header;

extern FILE *db_file_ptr;

db_operation_status load_databse();
db_operation_status save_databse();

#endif