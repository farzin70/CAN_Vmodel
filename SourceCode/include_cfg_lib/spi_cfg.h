/**
 * @file     spi_cfg.h
 * @author   yousefian
 * @date    12.13.2020 (date of creation)
 * @ingroup CFG
 * @prefix  spi_cfg
 *
 * @brief   spi config header file
 *
 *
 */
#ifndef SPI_CFG_H
#define SPI_CFG_H

/*================== Includes ===============================================*/
#include <stdint.h>
#include "include_hw_lib/hw_ints.h"
#include "include_driver_lib/dma.h"
/*================== Macros and Definitions =================================*/
#define SPIA_ENABLE 1
#define SPIB_ENABLE 1
#define SPIC_ENABLE 1

typedef enum{
    cs_enable  = 0,
    cs_disable = 1
}SPI_CFG_CS_CONTROl_e;


#define SPIA_CS_FLASH_GPIO_PIN   (62U)  /* FLASH */
#define SPIA_CS_EEPROM_GPIO_PIN   (61U)  /* EEPROM */

typedef enum{
    spi_eeprom_cs = SPIA_CS_EEPROM_GPIO_PIN,
    spi_flash_cs = SPIA_CS_FLASH_GPIO_PIN
}SPI_CFG_CS_PIN_e;

#if SPIA_ENABLE
#define SPIA_TX_BUFFER_SIZE 260
#define SPIA_RX_BUFFER_SIZE 260
#endif
#if SPIB_ENABLE
#define SPIB_TX_BUFFER_SIZE 288
#define SPIB_RX_BUFFER_SIZE 288
#endif
#if SPIC_ENABLE
#define SPIC_TX_BUFFER_SIZE 24
#define SPIC_RX_BUFFER_SIZE 24
#endif
/*================== Extern Constant and Variable Declarations ==============*/
#if SPIA_ENABLE
extern uint16_t storage_write[SPIA_TX_BUFFER_SIZE];
extern uint16_t storage_read[SPIA_RX_BUFFER_SIZE];
#endif
#if SPIB_ENABLE
extern uint16_t spi_cfg_txb_buffer[SPIB_TX_BUFFER_SIZE];                         // Send data buffer
extern uint16_t spi_cfg_rxb_buffer[SPIB_RX_BUFFER_SIZE];

extern uint16_t g_spi_cfg_rxa_data_flg;
extern uint16_t spi_cfg_spib_rx_data[2];

#endif
#if SPIC_ENABLE
extern uint16_t g_spi_cfg_rxc_data_flg;
extern uint16_t spi_cfg_spic_rx_data[2];                        // Receive data buffer
#endif
/*================== Extern Function Prototypes =============================*/
#if SPIA_ENABLE
void spi_cfg_spia(void);
void spi_cfg_write_spia(uint16_t data);
uint16_t spi_cfg_read_spia(void);
void spi_cfg_cs_control_spia(SPI_CFG_CS_PIN_e cs_pin,SPI_CFG_CS_CONTROl_e cs_control_e);
#endif
#if SPIB_ENABLE
void spi_cfg_spib(void);
void spi_cfg_spib_tx(uint16_t data);
uint16_t spi_cfg_spib_rx(void);
uint16_t spi_cfg_read(uint32_t base);
void spi_cfg_write(uint32_t base,uint16_t data);
void spi_cfg_cs_control(uint32_t base, bool cs_control);
#endif
#if SPIC_ENABLE
void spi_cfg_spic(void);
#endif
#endif // SPI_CFG_H
