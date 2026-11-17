/**
 * @file    gpio_cfg.h
 * @author  yousefian
 * @date    12.17.2020 (date of creation)
 * @ingroup CFG
 * @prefix  gpio_cfg
 *
 * @brief   gpio config header file
 *
 *
 */
#ifndef INCLUDE_CFG_LIB_GPIO_CFG_H_
#define INCLUDE_CFG_LIB_GPIO_CFG_H_
/*================== Includes ===============================================*/
#include "include_driver_lib/gpio.h"
/*================== Macros and Definitions =================================*/
/*================== Extern Constant and Variable Declarations ==============*/
/*================== Extern Function Prototypes =============================*/
 void gpio_cfg_config(void);

 void gpio_cfg_set_pin_config(uint32_t pin_config);

 void gpio_cfg_set_pad_config(uint32_t pin_number , uint32_t pin_type);

 void gpio_cfg_set_direction_mode(uint32_t pin_number , GPIO_Direction pin_io);

 void gpio_cfg_set_master_core(uint32_t pin_number , GPIO_CoreSelect core);

 void gpio_cfg_write_pin(uint32_t pin, uint32_t output_value);

 void gpio_cfg_toggle_pin(uint32_t pin);

 uint32_t gpio_cfg_read_pin(uint32_t pin);
 uint32_t gpio_cfg_read_port(GPIO_Port port);

#endif /* INCLUDE_CFG_LIB_GPIO_CFG_H_ */
