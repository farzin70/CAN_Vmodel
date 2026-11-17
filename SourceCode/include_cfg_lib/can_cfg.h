/**
 * @file    can_cfg.h
 *
 * @author  yousefian
 *
 * @date    12.17.2020 (date of creation)
 *
 * @ingroup CFG
 *
 * @prefix  cana_cfg
 *
 * @brief   can config header file
 *
 *
 */
#ifndef CAN_CFG_H
#define CAN_CFG_H

/*================== Includes ===============================================*/
#include "include_cfg_lib/std_types.h"
#include "include_driver_lib/can.h"
/*================== Macros and Definitions =================================*/
/*===========================================================================*/
/*================== configuration mailbox for send data ====================*/
/*===========================================================================*/
#define CANA_TX_START_MAILBOX_ID (2U)         /*Start mailbox for send data*/
#define CANA_TX_END_MAILBOX_ID   (16U)        /*End mailbox for send data*/
/*===========================================================================*/
/*================== configuration mailbox for send data ====================*/
/*===========================================================================*/
#define CANA_RX_NUMBER_MAILBOX   (32U)        /*End mailbox for send data*/
/*data type for argument write data from can*/
typedef struct
{
     boolean_t  high_priority;
     uint16_t data_len;
     uint16_t msgData[8];
     uint32_t message_id ;
     boolean_t data_ack;
     CAN_MsgFrameType msg_fram_type_extend_or_std;

}CAN_CFG_CAN_WRITE_PARAMETERS_s;
/*data type for can fault*/
typedef struct
{
    uint8_t CANA_PARITY_ERORR ;
    uint8_t CANA_BUS_OFF_STATUS ;
    uint8_t CANA_WARNING_STATUS ;
    uint8_t CANA_PASSIVE_ERROR ;
    uint8_t CANA_LLC_STUFF_ERROR ;
    uint8_t CANA_LLC_FORM_ERROR ;
    uint8_t CANA_LLC_ACK_ERROR ;
    uint8_t CANA_LLC_BIT0_ERROR ;
    uint8_t CANA_LLC_BIT1_ERROR ;
    uint8_t CANA_LLC_CRC_ERROR ;
    uint8_t CANA_GLOBAL_FAULT;

}CAN_CFG_CANA_ERROR_STATUS_s;
/*data type for argument receive data from can*/
typedef enum
{
    can_cfg_update_flg_unset = 0,
    can_cfg_update_flg_set = 1
}CAN_CFG_UPDATE_FLG_STATUS_e;
/*data type for argument receive data from can*/
typedef enum
{
    can_cfg_cana_bus = 0,
    can_cfg_canb_bus = 1
}CAN_CFG_CAN_BUS_e;
typedef struct
{
     uint8_t  massage_box_number;
     uint8_t  data_length;
     uint32_t message_id;
     uint16_t data[8];
     CAN_CFG_UPDATE_FLG_STATUS_e  update_flg;
     CAN_MsgFrameType frame_type;
     CAN_CFG_CAN_BUS_e can_bus_id;
}CAN_CFG_CAN_DATA_s;
/*================== Extern Constant and Variable Declarations ==============*/
/*================== Extern Function Prototypes =============================*/
void can_cfg_cana(void);
//boolean_t can_cfg_cana_is_mailbox_empty(CAN_CFG_CAN_WRITE_PARAMETERS_s* can_write_parameter);
void can_cfg_cana_write(CAN_CFG_CAN_WRITE_PARAMETERS_s* can_write_parameter);
CAN_CFG_CANA_ERROR_STATUS_s* can_cfg_cana_get_fault(void);
void can_cfg_cana_set_fault(CAN_CFG_CANA_ERROR_STATUS_s* fault);
#endif
