
/**
 * @file     dac_cfg.h
 *
 * @author   yousefian
 *
 * @date    09.04.2020 (date of creation)
 *
 * @ingroup CFG
 *
 * @prefix  dac_cfg
 *
 * @brief   DAC configuration header file
 *
 *
 */
#ifndef INCLUDE_CFG_LIB_DAC_CFG_H_
#define INCLUDE_CFG_LIB_DAC_CFG_H_
/*================== Includes ===============================================*/
#include <stdint.h>
/*================== Macros and Definitions =================================*/
#define DAC_CFG_DACA_ENABLE (1U) /* 1:DAC module A is enable , 0: DAC module A is disable*/
#define DAC_CFG_DACB_ENABLE (1U) /* 1:DAC module B is enable , 0: DAC module B is disable*/
#define DAC_CFG_DACC_ENABLE (0U) /* 1:DAC module B is enable , 0: DAC module C is disable*/
/*================== Extern Constant and Variable Declarations ==============*/
/*================== Extern Function Prototypes =============================*/
#if DAC_CFG_DACA_ENABLE
void dac_cfg_daca_config();
boolean_t dac_cfg_daca_value(float32_t value);
#endif
#if DAC_CFG_DACB_ENABLE
void dac_cfg_dacb_config();
boolean_t dac_cfg_dacb_value(float32_t value);
#endif
#if DAC_CFG_DACC_ENABLE
void dac_cfg_dacc_config();
uint16_t dac_cfg_dacc_value(float32_t value);
#endif
#endif /* INCLUDE_CFG_LIB_DAC_CFG_H_ */
/*================== END MODULE =============================================*/
