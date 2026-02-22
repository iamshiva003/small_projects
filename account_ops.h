#ifndef _ACCOUNT_OPS_H_
#define _ACCOUNT_OPS_H_
#include <stdint.h>
#include "account_manage.h"
#include <string.h>

void create_account(customer_t *);
void deposit_amount(customer_t *);
void withdraw_amount(customer_t *);
void account_details(customer_t *);

int32_t search_by_aadhar(customer_t *);

#endif