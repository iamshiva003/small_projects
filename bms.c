#include "bms.h"
customer_t *account;

void wrapper(void (*ops_func_ptr[2])(customer_t *), customer_t *customer_data)
{
    ops_func_ptr[0](customer_data);
    ops_func_ptr[1](customer_data);
}

bms_proc_t bms_init()
{
    bms_proc_t ret_status = (load_databse()==DB_OPERATION_FAILED) ? bms_proc_failed : bms_proc_success;
    
    if(ret_status == bms_proc_failed)
    {   
        printf("FAILED TO LOAD DATABSE!\n");
    }
    return ret_status;
}

bms_proc_t bms_exec()
{
    static int run_flag = 1;

    bms_proc_t ret_status = bms_proc_success;

    // ORDER MATTERS ;-)
    void (*operation_func[4][2])(customer_t *) = {
        {create_menu, create_account},
        {deposit_menu, deposit_amount},
        {withdraw_menu, withdraw_amount},
        {account_deatils_menu, account_details}};

    main_menu_opt_t main_menu_option;
    customer_t customer_data_holder;

    while(run_flag)
    {
        if((main_menu_option = main_menu()) == SAVE_AND_EXIT)
        {
            run_flag = 0;
            save_and_exit_menu();
            bms_exit();
        }
        else
        {
            (main_menu_option == INVALID) ? printf("INVALID OPTION SELECTED\n") : wrapper(operation_func[main_menu_option], &customer_data_holder);
        }
    }
    
    return ret_status;
}

void bms_exit()
{
    save_databse();
}