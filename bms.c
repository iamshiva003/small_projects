#include "bms.h"


bms_proc_t bms_init()
{
    bms_proc_t ret_status = bms_proc_success;

    return ret_status;
}

bms_proc_t bms_exec()
{
    static int run_flag = 1;

    bms_proc_t ret_status = bms_proc_success;
    void (*menu[])(customer_t *) = {deposit_menu, create_menu, withdraw_menu, account_deatils_menu, save_and_exit_menu};

    main_menu_opt_t main_menu_option;
    customer_t customer_data_holder;

    while(run_flag)
    {
        main_menu_option = main_menu();
        (main_menu_option == INVALID_MENU) ? printf("INVALID OPTION SELECTED\n") : (menu[main_menu_option])(&customer_data_holder);
    }
    
    return ret_status;
}