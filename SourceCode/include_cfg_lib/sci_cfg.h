/**
 * @file    sci_cfg.h
 * @author  safari.amirhossein
 * @date    17.5.2021 (date of creation)
 * @ingroup CFG
 * @prefix  sci_cfg
 *
 * @brief   sci config header file
 *
 *
 */
#ifndef SCI_CFG_H
#define SCI_CFG_H

/*================== Includes ===============================================*/
#include "include_driver_lib/sci.h"
/*================== Macros and Definitions =================================*/
#define SCIA_ENABLE 1
#define SCIB_ENABLE 0
#define SCIC_ENABLE 0
#define SCID_ENABLE 0

/*================== Extern Constant and Variable Declarations ==============*/
/*================== Extern Function Prototypes =============================*/
#if SCIA_ENABLE
void sci_cfg(uint32_t base);
uint16_t sci_cfg_write(const uint32_t base,const uint16_t *const array, uint16_t length, uint16_t start);
void sci_cfg_read(const uint32_t base,uint16_t * array, uint16_t length);
bool sci_cfg_is_transmitter_busy(uint32_t base);
#endif

#endif /* SCI_CFG_H */
