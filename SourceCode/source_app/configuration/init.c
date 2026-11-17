/**
 * @file    init.c
 *
 * @author  Yousefian
 *
 * @date    04.28.2021 (date of creation)
 *
 * @ingroup APP
 *
 * @prefix  BMS
 *
 * @brief   this file used for initialize system.
 *
 * @details def
 */
/*================== Includes ===============================================*/
#include "include_app/configuration/init.h""
#include "include_bmodule_driver_lib/crc_calc.h"
/*================== Macros and Definitions =================================*/
/*================== Static Constant and Variable Definitions ===============*/
/*================== Extern Constant and Variable Definitions ===============*/
/*================== Static Function Prototypes =============================*/
/*================== Static Function Implementations ========================*/
/*================== Extern Function Implementations ========================*/
void init(void)
{
    system_time_init();
}
/*================== END MODULE ==============================================*/
