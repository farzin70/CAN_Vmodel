/**
 * @file    system_cfg.c
 *
 * @author  yousefian
 *
 * @date    12.17.2020 (date of creation)
 *
 * @ingroup CFG
 *
 * @prefix  system_cfg
 *
 * @brief   system configuration
 */
/*================== Includes ===============================================*/
#include "include_app/configuration/system_cfg.h"
#include "include_cfg_lib/can_cfg.h"
#include "include_cfg_lib/canr_cfg.h"
#include "include_cfg_lib/gpio_cfg.h"
#include "include_cfg_lib/timer_cfg.h"
#include "device/device.h"
#include "include_app/configuration/init.h"
/*================== Macros and Definitions =================================*/
/*================== Static Constant and Variable Definitions ===============*/
/*================== Extern Constant and Variable Definitions ===============*/
/*================== Static Function Prototypes =============================*/
/*================== Static Function Implementation =========================*/
/*================== Extern Function Implementations ========================*/
/**
 * @brief   Config System
 *
 * @details This function is used to configuration System.
 *
 * @param   void
 *
 * @return  void
 */
void system_cfg_config(void)
{
    Device_init();
    Device_initGPIO();
    Interrupt_initModule();
    Interrupt_initVectorTable();

    can_cfg_cana();
    can_cfg_canb();
    timer_cfg_timer();
    EINT;
    ERTM;
    DEVICE_DELAY_US(8000);
}

