#ifndef _ACCOUNT_MANAGE_H_
#define _ACCOUNT_MANAGE_H_
#include <stdint.h>

#define CHAR_FIELD_LENGTH (20u)

//customer details
typedef struct 
{
    char first_name[CHAR_FIELD_LENGTH];
    char last_name[CHAR_FIELD_LENGTH];
    char father_name[CHAR_FIELD_LENGTH];   //father name
    int age;
    float cbalance;   // current balance
    uint64_t aadhar;
    char DOB[11];     // date of birth -> dd/mm/yyyy
    char place[CHAR_FIELD_LENGTH];
} customer_t;

#endif