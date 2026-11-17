/**
 * @file    canr_cfg.h
 *
 * @author  yousefian
 *
 * @date    12.17.2020 (date of creation)
 *
 * @ingroup CFG
 *
 * @prefix  canb_cfg
 *
 * @brief   can config header file
 *
 *
 */
#ifndef CANR_CFG_H
#define CANR_CFG_H

/*================== Includes ===============================================*/
#include "include_cfg_lib/std_types.h"
#include "include_driver_lib/can.h"
#include "include_cfg_lib/can_cfg.h"
/*================== Macros and Definitions =================================*/
/*===========================================================================*/
/*================== configuration mailbox for send data ====================*/
/*===========================================================================*/
#define CANB_TX_START_MAILBOX_ID (2U)         /*Start mailbox for send data*/
#define CANB_TX_END_MAILBOX_ID   (12U)        /*End mailbox for send data*/
/*===========================================================================*/
/*================== configuration mailbox for send data ====================*/
/*===========================================================================*/
#define CANB_RX_NUMBER_MAILBOX   (32U)        /*End mailbox for send data*/
/*data type for can fault*/
typedef struct
{
    uint8_t CANB_PARITY_ERORR ;
    uint8_t CANB_BUS_OFF_STATUS ;
    uint8_t CANB_WARNING_STATUS ;
    uint8_t CANB_PASSIVE_ERROR ;
    uint8_t CANB_LLC_STUFF_ERROR ;
    uint8_t CANB_LLC_FORM_ERROR ;
    uint8_t CANB_LLC_ACK_ERROR ;
    uint8_t CANB_LLC_BIT0_ERROR ;
    uint8_t CANB_LLC_BIT1_ERROR ;
    uint8_t CANB_LLC_CRC_ERROR ;
    uint8_t CANB_GLOBAL_FAULT;

}CAN_CFG_CANB_ERROR_STATUS_s;
/*data type for argument receive data from can*/
typedef enum
{
    can_cfg_canb_update_flg_unset = 0,
    can_cfg_canb_update_flg_set = 1
}CAN_CFG_CANB_UPDATE_FLG_STATUS_e;

/*================== Extern Constant and Variable Declarations ==============*/
/*================== Extern Function Prototypes =============================*/
void can_cfg_canb(void);
void can_cfg_canb_write(CAN_CFG_CAN_WRITE_PARAMETERS_s* can_write_parameter);
CAN_CFG_CANB_ERROR_STATUS_s* can_cfg_canb_get_fault(void);
void can_cfg_canb_set_fault(CAN_CFG_CANB_ERROR_STATUS_s* fault);
#endif
