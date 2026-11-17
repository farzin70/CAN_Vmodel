/**
 * @file    timer_cfg.h
 * @author  yousefian
 * @date    12.17.2020 (date of creation)
 * @ingroup CFG
 * @prefix  timer_cfg
 *
 * @brief   timer config header file
 *
 *
 */
#ifndef INCLUDE_CFG_LIB_TIMER_CFG_H_
#define INCLUDE_CFG_LIB_TIMER_CFG_H_
/*================== Includes ===============================================*/
#include "include_bmodule_driver_lib/system_time.h"
/*================== Macros and Definitions =================================*/
#define TIMER0_ENABLE 1
#define TIMER1_ENABLE 0
#define TIMER2_ENABLE 1
/*================== Extern Constant and Variable Declarations ==============*/
/*================== Extern Function Prototypes =============================*/
#if (TIMER0_ENABLE || TIMER1_ENABLE || TIMER2_ENABLE)
void timer_cfg_timer(void);
uint32_t timer_cfg_get_timer_counter(uint32_t base);
uint32_t timer_cfg_diff_counter_ns(uint32_t counter_before, uint32_t counter_after);
uint32_t timer_cfg_diff_counter_ms(uint32_t counter_before, uint32_t counter_after);
#endif
#endif /* INCLUDE_CFG_LIB_TIMER_CFG_H_ */
