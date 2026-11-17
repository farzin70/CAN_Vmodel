/**
 * @file     cap_cfg.h
 *
 * @author   yousefian
 *
 * @date    12.15.2020 (date of creation)
 *
 * @ingroup CFG
 *
 * @prefix  adc_cfg
 *
 * @brief   capture configuration
 *
 *
 */
#ifndef INCLUDE_CFG_LIB_CAP_CFG_H_
#define INCLUDE_CFG_LIB_CAP_CFG_H_

/*================== Includes ===============================================*/
#include <stdint.h>
/*================== Macros and Definitions =================================*/
#define CAP1_ENABLE (1U) /* Enable capture module 1*/
#define CAP1_TIMER_STEP_TIME (5E9) /* Step time in capture module 1*/
/*================== Extern Constant and Variable Declarations ==============*/
/*================== Extern Function Prototypes =============================*/
#if CAP1_ENABLE
void cap_cfg_cap1(void);
uint32_t cap_cfg_cap1_get_capture_register_one(void);
uint32_t cap_cfg_cap1_get_capture_register_two(void);
uint32_t cap_cfg_cap1_get_capture_register_three(void);
uint32_t cap_cfg_cap1_get_capture_register_four(void);
#endif
#endif
/*================== END MODULE ==============================================*/
