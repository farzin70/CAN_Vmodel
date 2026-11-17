/**
 * @file     dma_cfg.h
 * @author   yousefian
 * @date    12.15.2020 (date of creation)
 * @ingroup CFG
 * @prefix  dma_cfg
 *
 * @brief   dma config header file
 *
 *
 */

#ifndef INCLUDE_CFG_LIB_DMA_CFG_H_
#define INCLUDE_CFG_LIB_DMA_CFG_H_
/*================== Includes ===============================================*/
#include <stdint.h>
#include "include_cfg_lib/std_types.h"
/*================== Macros and Definitions =================================*/
#define DMACH1_ENABLE 0
#define DMACH2_ENABLE 0
#define DMACH3_ENABLE 1
#define DMACH4_ENABLE 1
#define DMACH5_ENABLE 0
#define DMACH6_ENABLE 0
/*================== Extern Constant and Variable Declarations ==============*/
extern uint16_t dma_flg;
/*================== Extern Function Prototypes =============================*/
#if DMACH1_ENABLE
void dma_cfg_dma1_cfg(void);
#endif
#if DMACH2_ENABLE
void dma_cfg_dma2_cfg(void);
#endif
#if DMACH3_ENABLE
void dma_cfg_dma3_channel_start(void);
void dma_cfg_dma3_channel_stop(void);
void dma_cfg_dma3_cfg(void);
void dma_cfg_dma3_config_burst(uint16_t size, int16_t srcStep,int16_t destSte);
void dma_cfg_dma3_config_transfer(uint16_t size, int16_t srcStep, int16_t destStep);
boolean_t* dma_cfg_dma3_busy_status_get(void);
#endif
#if DMACH4_ENABLE
void dma_cfg_dma4_channel_start(void);
void dma_cfg_dma4_channel_stop(void);
void dma_cfg_dma4_cfg(void);
void dma_cfg_dma4_config_burst(uint16_t size, int16_t srcStep,int16_t destSte);
void dma_cfg_dma4_config_transfer(uint16_t size, int16_t srcStep, int16_t destStep);
#endif
#if DMACH5_ENABLE
void dma_cfg_dma5_cfg(void);
void dma_cfg_dma_channel_start(void);           //DMA channel 5 used SPIA TX then trigger by user.
void dma_cfg_dma_channel_stop(void);
void dma_cfg_dma5_config_burst(uint16_t size, int16_t srcStep,int16_t destSte);
void dma_cfg_dma5_config_transfer(uint16_t size, int16_t srcStep, int16_t destStep);
#endif
#if DMACH6_ENABLE
void dma_cfg_dma6_cfg(void);
void dma_cfg_dma6_config_burst(uint16_t size, int16_t srcStep,int16_t destSte);
void dma_cfg_dma6_config_transfer(uint16_t size, int16_t srcStep, int16_t destStep);
#endif
#endif /* INCLUDE_CFG_LIB_DMA_CFG_H_ */
