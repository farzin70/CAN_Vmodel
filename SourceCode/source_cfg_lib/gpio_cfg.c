/**
 * @file    gpio_cfg.c
 * @author  yousefian
 * @date    12.17.2020 (date of creation)
 * @ingroup CFG
 * @prefix  gpio_cfg
 *
 * @brief   GPIO configuration
 *
 *
 */
/*================== Includes ===============================================*/
#include "device/driverlib.h"
#include "include_driver_lib/pin_map.h"
/*================== Macros and Definitions =================================*/
/*================== Static Constant and Variable Definitions ===============*/
/*================== Extern Constant and Variable Definitions ===============*/
/*================== Static Function Prototypes =============================*/
/*================== Static Function Implementation =========================*/
/*================== Extern Function Implementations ========================*/
/**
 * @brief   gpio pin set configuration
 *
 * @details This function is used to  set pin GPIO configuration .
 *
 * @param   int32_t pin_config
 *
 * @return  void
 */
 void gpio_cfg_set_pin_config(uint32_t pin_config)
{
    GPIO_setPinConfig(pin_config);
}
/**
 * @brief   gpio pad set configuration
 *
 * @details This function is used to set GPIO pad configuration .
 *
 * @param   int32_t pin_config
 *
 * *
 * @param   int32_t pin_type
 *
 * @return  void
 */
 void gpio_cfg_set_pad_config(uint32_t pin_number , uint32_t pin_type)
{
    GPIO_setPadConfig(pin_number , pin_type);
}
/**
 * @brief   set direction mode
 *
 * @details This function is used to set direction mode.
 *
 * @param   uint32_t pin_number
 *
 * @param   GPIO_Direction pin_io
 *
 * @return  void
 */
 void gpio_cfg_set_direction_mode(uint32_t pin_number , GPIO_Direction pin_io)
{
    GPIO_setDirectionMode(pin_number, pin_io);
}
/**
 * @brief   set master core
 *
 * @details This function is used to set master core.
 *
 * @param   uint32_t pin_number
 *
 * @param    GPIO_CoreSelect core
 *
 * @return  void
 */
 void gpio_cfg_set_master_core(uint32_t pin_number , GPIO_CoreSelect core)
{
    GPIO_setMasterCore(pin_number, core);
}
/**
 * @brief   digital output write
 *
 * @details This function is used to write to gpio.
 *
 * @param   uint32_t pin_number
 *
 * @param    GPIO_CoreSelect core
 *
 * @return  void
 */
 void gpio_cfg_write_pin(uint32_t pin, uint32_t output_value)
{
    GPIO_writePin(pin , output_value);
}
/**
 * @brief   digital output and input  read.
 *
 * @details This function is used to read to GPIO.
 *
 * @param   uint32_t pin
 *
 * @return  uint32_t
 */
 uint32_t gpio_cfg_read_pin(uint32_t pin)
{
    return(GPIO_readPin(pin));
}
 /**
  * @brief   digital toggle pin.
  *
  * @details This function is used to toggle pin.
  *
  * @param   uint32_t pin
  *
  * @return  uint32_t
  */
 void gpio_cfg_toggle_pin(uint32_t pin)
 {
     return(GPIO_togglePin(pin));
 }
 /**
  * @brief   read gpio port data.
  *
  * @details  read gpio port data.
  *
  * @param   GPIO_Port port
  *
  * @return  uint32_t
  */
 uint32_t gpio_cfg_read_port(GPIO_Port port)
 {
     return (GPIO_readPortData(port));
 }
/*================== END MODULE ==============================================*/
