/**
 * @file     pwm_cfg.h
 * @author   yousefian
 * @date    12.17.2020 (date of creation)
 * @ingroup CFG
 * @prefix  pwma_cfg
 *
 * @brief   pwm config header file
 *
 *
 */
#ifndef PWM_CFG_H
#define PWM_CFG_H

/*================== Includes ===============================================*/
#include <stdint.h>
/*================== Macros and Definitions =================================*/
#define EPWM1_ENABLE 0
#define EPWM1_OUTPUT_A_ENABLE 0
#define EPWM1_OUTPUT_B_ENABLE 0
#define EPWM1_INTERRUPT_ENABLE 1
#define EPWM2_ENABLE 1
#define EPWM2_OUTPUT_A_ENABLE 0
#define EPWM2_OUTPUT_B_ENABLE 0
#define EPWM2_INTERRUPT_ENABLE 1
#define EPWM3_ENABLE 0
#define EPWM3_OUTPUT_A_ENABLE 1
#define EPWM3_OUTPUT_B_ENABLE 1
#define EPWM3_INTERRUPT_ENABLE 1
#define EPWM4_ENABLE 0
#define EPWM4_OUTPUT_A_ENABLE 1
#define EPWM4_OUTPUT_B_ENABLE 0
#define EPWM4_INTERRUPT_ENABLE 1
#define EPWM5_ENABLE 0
#define EPWM5_OUTPUT_A_ENABLE 1
#define EPWM5_OUTPUT_B_ENABLE 1
#define EPWM5_INTERRUPT_ENABLE 0
#define EPWM6_ENABLE 1
#define EPWM6_OUTPUT_A_ENABLE 1
#define EPWM6_OUTPUT_B_ENABLE 0
#define EPWM6_INTERRUPT_ENABLE 0
#define EPWM7_ENABLE 0
#define EPWM7_OUTPUT_A_ENABLE 1
#define EPWM7_OUTPUT_B_ENABLE 1
#define EPWM7_INTERRUPT_ENABLE 0
#define EPWM8_ENABLE 0
#define EPWM8_OUTPUT_A_ENABLE 0
#define EPWM8_OUTPUT_B_ENABLE 0
#define EPWM8_INTERRUPT_ENABLE 0
#define EPWM9_ENABLE 0
#define EPWM9_OUTPUT_A_ENABLE 0
#define EPWM9_OUTPUT_B_ENABLE 1
#define EPWM9_INTERRUPT_ENABLE 0
#define EPWM10_ENABLE 0
#define EPWM10_OUTPUT_A_ENABLE 0
#define EPWM10_OUTPUT_B_ENABLE 0
#define EPWM10_INTERRUPT_ENABLE 0
#define EPWM11_ENABLE 0
#define EPWM11_OUTPUT_A_ENABLE 0
#define EPWM11_OUTPUT_B_ENABLE 0
#define EPWM11_INTERRUPT_ENABLE 0
#define EPWM12_ENABLE 0
#define EPWM12_OUTPUT_A_ENABLE 0
#define EPWM12_OUTPUT_B_ENABLE 0
#define EPWM12_INTERRUPT_ENABLE 0
#define PWM_CFG_PWM6_TBCLK 100E6
#define PWM_CFG_MAX_TIME_BASE_PERIOD_REG   0xFFFFU
#define PWM_CFG_MAX_COUNTER_COMPARE_A_REG  0xFFFFU
/*================== Extern Constant and Variable Declarations ==============*/

/*================== Extern Function Prototypes =============================*/
#if EPWM1_ENABLE
void pwm_cfg_pwm1(void);
void pwm_cfg_pwm1_duty_cycle_update(float duty_cycle_a , float duty_cycle_b);
void pwm_cfg_pwm1_duty_cycle_getter(float * duty_cycle_a , float * duty_cycle_b);
void pwm_cfg_pwm1_frequecny_update(uint32_t pwm_frequecny);
void pwm_cfg_pwm1_frequecny_getter(uint32_t * pwm_frequecny);
void pwm_cfg_pwm1_isr_init(void (*pwm1_isr)(void));
uint16_t pwm_cfg_pwm1_get_time_base_counter_direction(void);
#endif
#if EPWM2_ENABLE
void pwm_cfg_pwm2(void);
void pwm_cfg_pwm2_duty_cycle_update(float duty_cycle_a , float duty_cycle_b);
void pwm_cfg_pwm2_duty_cycle_getter(float * duty_cycle_a , float * duty_cycle_b);
void pwm_cfg_pwm2_frequecny_update(uint32_t pwm_frequecny);
void pwm_cfg_pwm2_frequecny_getter(uint32_t * pwm_frequecny);
void pwm_cfg_pwm2_phase_shift_respect2_pwm1(uint16_t shift_phase_value);
void pwm_cfg_pwm2_isr_init(void (*pwm2_isr)(void));
uint16_t pwm_cfg_pwm2_get_time_base_counter_direction(void);
#endif
#if EPWM3_ENABLE
void pwm_cfg_pwm3(void);
void pwm_cfg_pwm3_duty_cycle_update(float duty_cycle_a , float duty_cycle_b);
void pwm_cfg_pwm3_phase_shift_respect2_pwm2(float shift_phase_value);
void pwm_cfg_pwm3_isr_init(void (*pwm3_isr)(void));
uint16_t pwm_cfg_pwm3_get_time_base_counter_direction(void);
#endif
#if EPWM4_ENABLE
void pwm_cfg_pwm4(void);
void pwm_cfg_pwm4_duty_cycle_update(float duty_cycle_a , float duty_cycle_b);
void pwm_cfg_pwm4_phase_shift_respect2_pwm3(float shift_phase_value);
void pwm_cfg_pwm4_isr_init(void (*pwm4_isr)(void));
uint16_t pwm_cfg_pwm4_get_time_base_counter_direction(void);
#endif
#if EPWM5_ENABLE
void pwm_cfg_pwm5(void);
void pwm_cfg_pwm5_duty_cycle_update(float duty_cycle_a , float duty_cycle_b);
void pwm_cfg_pwm5_phase_shift_respect2_pwm4(float shift_phase_value);
void pwm_cfg_pwm5_isr_init(void (*pwm5_isr)(void));
uint16_t pwm_cfg_pwm5_get_time_base_counter_direction(void);
#endif
#if EPWM6_ENABLE
void pwm_cfg_pwm6(void);
void pwm_cfg_pwm6_compare_a(uint16_t compa_value);
void pwm_cfg_pwm6_period(uint16_t period);
void pwm_cfg_pwm6_invert_polarity(uint16_t direction);
void pwm_cfg_pwm6_duty_cycle_update(float duty_cycle_a , float duty_cycle_b);
void pwm_cfg_pwm6_phase_shift_respect2_pwm5(float shift_phase_value);
void pwm_cfg_pwm6_isr_init(void (*pwm6_isr)(void));
uint16_t pwm_cfg_pwm6_get_time_base_counter_direction(void);
#endif
#if EPWM7_ENABLE
void pwm_cfg_pwm7(void);
void pwm_cfg_pwm7_duty_cycle_update(float duty_cycle_a , float duty_cycle_b);
void pwm_cfg_pwm7_phase_shift_respect2_pwm6(float shift_phase_value);
void pwm_cfg_pwm7_isr_init(void (*pwm7_isr)(void));
uint16_t pwm_cfg_pwm7_get_time_base_counter_direction(void);
#endif
#if EPWM8_ENABLE
void pwm_cfg_pwm8(void);
void pwm_cfg_pwm8_duty_cycle_update(float duty_cycle_a , float duty_cycle_b);
void pwm_cfg_pwm8_phase_shift_respect2_pwm7(float shift_phase_value);
void pwm_cfg_pwm8_isr_init(void (*pwm8_isr)(void));
uint16_t pwm_cfg_pwm8_get_time_base_counter_direction(void);
#endif
#if EPWM9_ENABLE
void pwm_cfg_pwm9(void);
void pwm_cfg_pwm9_duty_cycle_update(float32_t duty_cycle_a , float32_t duty_cycle_b);
void pwm_cfg_pwm9_phase_shift_respect2_pwm8(float32_t shift_phase_value);
void pwm_cfg_pwm9_isr_init(void (*pwm9_isr)(void));
uint16_t pwm_cfg_pwm9_get_time_base_counter_direction(void);
#endif
#if EPWM10_ENABLE
void pwm_cfg_pwm10(void);
void pwm_cfg_pwm10_duty_cycle_update(float duty_cycle_a , float duty_cycle_b);
void pwm_cfg_pwm10_phase_shift_respect2_pwm9(float shift_phase_value);
void pwm_cfg_pwm10_isr_init(void (*pwm10_isr)(void));
uint16_t pwm_cfg_pwm10_get_time_base_counter_direction(void);
#endif
#if EPWM11_ENABLE
void pwm_cfg_pwm11(void);
void pwm_cfg_pwm11_duty_cycle_update(float duty_cycle_a , float duty_cycle_b);
void pwm_cfg_pwm11_phase_shift_respect2_pwm10(float shift_phase_value);
void pwm_cfg_pwm11_isr_init(void (*pwm11_isr)(void));
uint16_t pwm_cfg_pwm11_get_time_base_counter_direction(void);
#endif
#if EPWM12_ENABLE
void pwm_cfg_pwm12(void);
void pwm_cfg_pwm12_duty_cycle_update(float duty_cycle_a , float duty_cycle_b);
void pwm_cfg_pwm12_phase_shift_respect2_pwm11(float shift_phase_value);
void pwm_cfg_pwm12_isr_init(void (*pwm12_isr)(void));
uint16_t pwm_cfg_pwm12_get_time_base_counter_direction(void);
#endif
#endif


