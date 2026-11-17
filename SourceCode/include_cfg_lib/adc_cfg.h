/**
 * @file     adc_cfg.h
 * @author   yousefian
 * @date    12.15.2020 (date of creation)
 * @ingroup CFG
 * @prefix  adc_cfg
 *
 * @brief   sdc config header file
 *
 *
 */
#ifndef ADC_CFG_H
#define ADC_CFG_H

/*================== Includes ===============================================*/
#include <include_cfg_lib/std_types.h>
/*================== Macros and Definitions =================================*/
#define ADCA_ENABLE 1

#define ADCB_ENABLE 1
#define ADCC_ENABLE 1
#define ADCD_ENABLE 1

#define ADC_CFG_ADC_RESOLUTION_12BIT 4096U
#define ADC_CFG_ADC_RESOLUTION_12BIT_MASK 0xFFFU
#define ADC_CFG_ADC_REFRENCE_VOLTAGE 2.5f
/*================== Extern Constant and Variable Declarations ==============*/
/*================== Extern Function Prototypes =============================*/
#if ADCA_ENABLE
void adc_cfg_adca(void);
void adc_cfg_adca_start(void);
uint16_t adc_cfg_adca_channel_0_result(void);
uint16_t adc_cfg_adca_channel_1_result(void);
uint16_t adc_cfg_adca_channel_2_result(void);
uint16_t adc_cfg_adca_channel_3_result(void);
uint16_t adc_cfg_adca_channel_4_result(void);
uint16_t adc_cfg_adca_channel_5_result(void);
uint16_t adc_cfg_adca_channel_13_result(void);

#endif
#if ADCB_ENABLE
void adc_cfg_adcb(void);
void adc_cfg_adcb_start(void);
uint16_t adc_cfg_adcb_channel_0_result(void);
uint16_t adc_cfg_adcb_channel_1_result(void);
uint16_t adc_cfg_adcb_channel_2_result(void);
uint16_t adc_cfg_adcb_channel_3_result(void);
uint16_t adc_cfg_adcb_channel_4_result(void);
uint16_t adc_cfg_adcb_channel_5_result(void);
#endif
#if ADCC_ENABLE
void adc_cfg_adcc(void);
void adc_cfg_adcc_start(void);
uint16_t adc_cfg_adcc_channel_0_result(void);
uint16_t adc_cfg_adcc_channel_2_result(void);
uint16_t adc_cfg_adcc_channel_3_result(void);
uint16_t adc_cfg_adcc_channel_4_result(void);
uint16_t adc_cfg_adcc_channel_5_result(void);
uint16_t adc_cfg_adcc_channel_13_result(void);
uint16_t adc_cfg_adcc_channel_14_result(void);
uint16_t adc_cfg_adcc_channel_15_result(void);
#endif
#if ADCD_ENABLE
void adc_cfg_adcd(void);
void adc_cfg_adcd_start(void);
uint16_t adc_cfg_adcd_channel_0_result(void);
uint16_t adc_cfg_adcd_channel_1_result(void);
uint16_t adc_cfg_adcd_channel_2_result(void);
uint16_t adc_cfg_adcd_channel_3_result(void);
uint16_t adc_cfg_adcd_channel_4_result(void);
uint16_t adc_cfg_adcd_channel_5_result(void);
#endif
#endif
int16_t adc_cfg_get_tempc(uint16_t tempResult, float32_t vref);
