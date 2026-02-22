#ifndef _ACCOUNT_MANAGE_H_
#define _ACCOUNT_MANAGE_H_
#include <stdint.h>

#define CHAR_FIELD_LENGTH (20u)
#define MAX_ALLOWED_ACCOUNT (64u)

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
}__attribute__((packed)) db_customer_t;

typedef struct{
    uint32_t count;
    customer_t *entry;
} account_entry_t;

extern account_entry_t account_entry;

#endif