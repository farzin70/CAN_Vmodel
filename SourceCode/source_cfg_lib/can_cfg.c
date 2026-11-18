/**
 * @file    can_cfg.c
 *
 * @author  yousefian
 *
 * @date    12.1.2020 (date of creation)
 *
 * @ingroup CFG
 *
 * @prefix  can_cfg
 *
 * @brief   can configuration. RX whit interrupt and TX without interrupt.
 */
/*================== Includes ===============================================*/
#include "include_app/can_management/cana_rx_manage.h"
#include "include_driver_lib/can.h"
#include "include_driver_lib/interrupt.h"
#include "include_driver_lib/gpio.h"
#include "include_driver_lib/pin_map.h"
#include "include_hw_lib/hw_can.h"
#include "include_cfg_lib/can_cfg.h"
/*================== Macros and Definitions =================================*/
/*===========================================================================*/
/*================== Constant parameter =====================================*/
/*===========================================================================*/
#define DEVICE_SYSCLK_FREQ 200E6    /*Core frequency*/
#define CANA_BAUDRATE 500000U         /*Can baud rate set by external crystal*/
#define CAN_MSG_BOX_TYPE_RX 2       /*Don't change*/
#define CAN_MSG_BOX_TYPE_TX 0       /*Don't change*/
/*===========================================================================*/
/*================== configuration mailbox for receive data =================*/
/*===========================================================================*/
/*===========================================================================*/
/*================== configuration mailbox1 for receive data ================*/
/*===========================================================================*/
/*Don't use .this mailbox used for boot from can bus*/
#define CANA_MSG_BOX1_ENABLE 0
#if CANA_MSG_BOX1_ENABLE
#define CANA_MSG_BOX1_MSG_ID 1                                  /*Message Identifier*/
#define CANA_MSG_BOX1_TYPE CAN_MSG_BOX_TYPE_RX                  /*Message Type: RX*/
#define CANA_MSG_BOX1_FRAME CAN_MSG_FRAME_STD                   /*Message Frame: Extended*/
#define CANA_MSG_BOX1_ID_MASK 0                                 /*Message ID Mask: 0x0*/
#define CANA_MSG_BOX1_INT CAN_MSG_OBJ_RX_INT_ENABLE             /*Message Object Flags: Transmit Interrupt*/
#define CANA_MSG_BOX1_DATA_LENGTH 8                             /*Message Data Length: 8 Bytes*/
#endif
/*===========================================================================*/
/*================== configuration mailbox2 for receive data ================*/
/*===========================================================================*/
/*Don't use .this mailbox used for boot from can bus*/
#define CANA_MSG_BOX2_ENABLE 0
#if CANA_MSG_BOX2_ENABLE
#define CANA_MSG_BOX2_MSG_ID 2
#define CANA_MSG_BOX2_TYPE CAN_MSG_BOX_TYPE_RX
#define CANA_MSG_BOX2_FRAME CAN_MSG_FRAME_STD
#define CANA_MSG_BOX2_ID_MASK 0
#define CANA_MSG_BOX2_INT CAN_MSG_OBJ_RX_INT_ENABLE
#define CANA_MSG_BOX2_DATA_LENGTH 8
#endif
/*===========================================================================*/
/*================== configuration mailbox3 for receive data ================*/
/*===========================================================================*/
#define CANA_MSG_BOX3_ENABLE 0
#if CANA_MSG_BOX3_ENABLE
#define CANA_MSG_BOX3_MSG_ID 3
#define CANA_MSG_BOX3_TYPE CAN_MSG_BOX_TYPE_RX
#define CANA_MSG_BOX3_FRAME CAN_MSG_FRAME_STD
#define CANA_MSG_BOX3_ID_MASK 0
#define CANA_MSG_BOX3_INT CAN_MSG_OBJ_RX_INT_ENABLE
#define CANA_MSG_BOX3_DATA_LENGTH 8
#endif
/*===========================================================================*/
/*================== configuration mailbox4 for receive data ================*/
/*===========================================================================*/
#define CANA_MSG_BOX4_ENABLE 0
#if CANA_MSG_BOX4_ENABLE
#define CANA_MSG_BOX4_MSG_ID 4
#define CANA_MSG_BOX4_TYPE CAN_MSG_BOX_TYPE_RX
#define CANA_MSG_BOX4_FRAME CAN_MSG_FRAME_STD
#define CANA_MSG_BOX4_ID_MASK 0
#define CANA_MSG_BOX4_INT CAN_MSG_OBJ_RX_INT_ENABLE
#define CANA_MSG_BOX4_DATA_LENGTH 8
#endif
/*===========================================================================*/
/*================== configuration mailbox5 for receive data ================*/
/*===========================================================================*/
#define CANA_MSG_BOX5_ENABLE 0
#if CANA_MSG_BOX5_ENABLE
#define CANA_MSG_BOX5_MSG_ID 5
#define CANA_MSG_BOX5_TYPE CAN_MSG_BOX_TYPE_RX
#define CANA_MSG_BOX5_FRAME CAN_MSG_FRAME_STD
#define CANA_MSG_BOX5_ID_MASK 0
#define CANA_MSG_BOX5_INT (CAN_MSG_OBJ_RX_INT_ENABLE | CAN_MSG_OBJ_USE_ID_FILTER)
#define CANA_MSG_BOX5_DATA_LENGTH 8
#endif
/*===========================================================================*/
/*================== configuration mailbox6 for receive data ================*/
/*===========================================================================*/
#define CANA_MSG_BOX6_ENABLE 0
#if CANA_MSG_BOX6_ENABLE
#define CANA_MSG_BOX6_MSG_ID 6
#define CANA_MSG_BOX6_TYPE CAN_MSG_BOX_TYPE_RX
#define CANA_MSG_BOX6_FRAME CAN_MSG_FRAME_STD
#define CANA_MSG_BOX6_ID_MASK 0
#define CANA_MSG_BOX6_INT (CAN_MSG_OBJ_RX_INT_ENABLE | CAN_MSG_OBJ_USE_ID_FILTER)
#define CANA_MSG_BOX6_DATA_LENGTH 8
#endif
/*===========================================================================*/
/*================== configuration mailbox7 for receive data ================*/
/*===========================================================================*/
#define CANA_MSG_BOX7_ENABLE 0
#if CANA_MSG_BOX7_ENABLE
#define CANA_MSG_BOX7_MSG_ID 7
#define CANA_MSG_BOX7_TYPE CAN_MSG_BOX_TYPE_RX
#define CANA_MSG_BOX7_FRAME CAN_MSG_FRAME_STD
#define CANA_MSG_BOX7_ID_MASK 0
#define CANA_MSG_BOX7_INT (CAN_MSG_OBJ_RX_INT_ENABLE | CAN_MSG_OBJ_USE_ID_FILTER)
#define CANA_MSG_BOX7_DATA_LENGTH 8
#endif
/*===========================================================================*/
/*================== configuration mailbox8 for receive data ================*/
/*===========================================================================*/
#define CANA_MSG_BOX8_ENABLE 0
#if CANA_MSG_BOX8_ENABLE
#define CANA_MSG_BOX8_MSG_ID 8
#define CANA_MSG_BOX8_TYPE CAN_MSG_BOX_TYPE_RX
#define CANA_MSG_BOX8_FRAME CAN_MSG_FRAME_STD
#define CANA_MSG_BOX8_ID_MASK 0
#define CANA_MSG_BOX8_INT (CAN_MSG_OBJ_RX_INT_ENABLE | CAN_MSG_OBJ_USE_ID_FILTER)
#define CANA_MSG_BOX8_DATA_LENGTH 8
#endif
/*===========================================================================*/
/*================== configuration mailbox9 for receive data ================*/
/*===========================================================================*/
#define CANA_MSG_BOX9_ENABLE 0
#if CANA_MSG_BOX9_ENABLE
#define CANA_MSG_BOX9_MSG_ID 9
#define CANA_MSG_BOX9_TYPE CAN_MSG_BOX_TYPE_RX
#define CANA_MSG_BOX9_FRAME CAN_MSG_FRAME_STD
#define CANA_MSG_BOX9_ID_MASK 0
#define CANA_MSG_BOX9_INT (CAN_MSG_OBJ_RX_INT_ENABLE | CAN_MSG_OBJ_USE_ID_FILTER)
#define CANA_MSG_BOX9_DATA_LENGTH 8
#endif
/*===========================================================================*/
/*================== configuration mailbox10 for receive data ===============*/
/*===========================================================================*/
#define CANA_MSG_BOX10_ENABLE 0
#if CANA_MSG_BOX10_ENABLE
#define CANA_MSG_BOX10_MSG_ID 10
#define CANA_MSG_BOX10_TYPE CAN_MSG_BOX_TYPE_RX
#define CANA_MSG_BOX10_FRAME CAN_MSG_FRAME_STD
#define CANA_MSG_BOX10_ID_MASK 0
#define CANA_MSG_BOX10_INT (CAN_MSG_OBJ_RX_INT_ENABLE | CAN_MSG_OBJ_USE_ID_FILTER)
#define CANA_MSG_BOX10_DATA_LENGTH 8
#endif
/*===========================================================================*/
/*================== configuration mailbox11 for receive data ===============*/
/*===========================================================================*/
#define CANA_MSG_BOX11_ENABLE 0
#if CANA_MSG_BOX11_ENABLE
#define CANA_MSG_BOX11_MSG_ID 11
#define CANA_MSG_BOX11_TYPE CAN_MSG_BOX_TYPE_RX
#define CANA_MSG_BOX11_FRAME CAN_MSG_FRAME_STD
#define CANA_MSG_BOX11_ID_MASK 0
#define CANA_MSG_BOX11_INT (CAN_MSG_OBJ_RX_INT_ENABLE | CAN_MSG_OBJ_USE_ID_FILTER)
#define CANA_MSG_BOX11_DATA_LENGTH 8
#endif
/*===========================================================================*/
/*================== configuration mailbox12 for receive data ===============*/
/*===========================================================================*/
#define CANA_MSG_BOX12_ENABLE 0
#if CANA_MSG_BOX12_ENABLE
#define CANA_MSG_BOX12_MSG_ID 12
#define CANA_MSG_BOX12_TYPE CAN_MSG_BOX_TYPE_RX
#define CANA_MSG_BOX12_FRAME CAN_MSG_FRAME_STD
#define CANA_MSG_BOX12_ID_MASK 0
#define CANA_MSG_BOX12_INT (CAN_MSG_OBJ_RX_INT_ENABLE | CAN_MSG_OBJ_USE_ID_FILTER)
#define CANA_MSG_BOX12_DATA_LENGTH 8
#endif
/*===========================================================================*/
/*================== configuration mailbox13 for receive data ===============*/
/*===========================================================================*/
#define CANA_MSG_BOX13_ENABLE 0
#if CANA_MSG_BOX13_ENABLE
#define CANA_MSG_BOX13_MSG_ID 13
#define CANA_MSG_BOX13_TYPE CAN_MSG_BOX_TYPE_RX
#define CANA_MSG_BOX13_FRAME CAN_MSG_FRAME_STD
#define CANA_MSG_BOX13_ID_MASK 0
#define CANA_MSG_BOX13_INT (CAN_MSG_OBJ_RX_INT_ENABLE | CAN_MSG_OBJ_USE_ID_FILTER)
#define CANA_MSG_BOX13_DATA_LENGTH 8
#endif
/*===========================================================================*/
/*================== configuration mailbox14 for receive data ===============*/
/*===========================================================================*/
#define CANA_MSG_BOX14_ENABLE 0
#if CANA_MSG_BOX14_ENABLE
#define CANA_MSG_BOX14_MSG_ID 14
#define CANA_MSG_BOX14_TYPE CAN_MSG_BOX_TYPE_RX
#define CANA_MSG_BOX14_FRAME CAN_MSG_FRAME_STD
#define CANA_MSG_BOX14_ID_MASK 0
#define CANA_MSG_BOX14_INT (CAN_MSG_OBJ_RX_INT_ENABLE | CAN_MSG_OBJ_USE_ID_FILTER)
#define CANA_MSG_BOX14_DATA_LENGTH 8
#endif
/*===========================================================================*/
/*================== configuration mailbox15 for receive data ===============*/
/*===========================================================================*/
#define CANA_MSG_BOX15_ENABLE 0
#if CANA_MSG_BOX15_ENABLE
#define CANA_MSG_BOX15_MSG_ID 15
#define CANA_MSG_BOX15_TYPE CAN_MSG_BOX_TYPE_RX
#define CANA_MSG_BOX15_FRAME CAN_MSG_FRAME_STD
#define CANA_MSG_BOX15_ID_MASK 0
#define CANA_MSG_BOX15_INT (CAN_MSG_OBJ_RX_INT_ENABLE | CAN_MSG_OBJ_USE_ID_FILTER)
#define CANA_MSG_BOX15_DATA_LENGTH 8
#endif
/*===========================================================================*/
/*================== configuration mailbox16 for receive data ===============*/
/*===========================================================================*/
#define CANA_MSG_BOX16_ENABLE 0
#if CANA_MSG_BOX16_ENABLE
#define CANA_MSG_BOX16_MSG_ID 16
#define CANA_MSG_BOX16_TYPE CAN_MSG_BOX_TYPE_RX
#define CANA_MSG_BOX16_FRAME CAN_MSG_FRAME_STD
#define CANA_MSG_BOX16_ID_MASK 0
#define CANA_MSG_BOX16_INT (CAN_MSG_OBJ_RX_INT_ENABLE | CAN_MSG_OBJ_USE_ID_FILTER)
#define CANA_MSG_BOX16_DATA_LENGTH 8
#endif
/*===========================================================================*/
/*================== configuration mailbox17 for receive data ===============*/
/*===========================================================================*/
#define CANA_MSG_BOX17_ENABLE 1
#if CANA_MSG_BOX17_ENABLE
#define CANA_MSG_BOX17_MSG_ID 17
#define CANA_MSG_BOX17_TYPE CAN_MSG_BOX_TYPE_RX
#define CANA_MSG_BOX17_FRAME CAN_MSG_FRAME_EXT
#define CANA_MSG_BOX17_ID_MASK 0
#define CANA_MSG_BOX17_INT (CAN_MSG_OBJ_RX_INT_ENABLE | CAN_MSG_OBJ_USE_ID_FILTER)
#define CANA_MSG_BOX17_DATA_LENGTH 8
#endif
/*===========================================================================*/
/*================== configuration mailbox18 for receive data ===============*/
/*===========================================================================*/
#define CANA_MSG_BOX18_ENABLE 1
#if CANA_MSG_BOX18_ENABLE
#define CANA_MSG_BOX18_MSG_ID 18
#define CANA_MSG_BOX18_TYPE CAN_MSG_BOX_TYPE_RX
#define CANA_MSG_BOX18_FRAME CAN_MSG_FRAME_STD
#define CANA_MSG_BOX18_ID_MASK 0
#define CANA_MSG_BOX18_INT (CAN_MSG_OBJ_RX_INT_ENABLE | CAN_MSG_OBJ_USE_ID_FILTER)
#define CANA_MSG_BOX18_DATA_LENGTH 8
#endif
/*===========================================================================*/
/*================== configuration mailbox19 for receive data ===============*/
/*===========================================================================*/
#define CANA_MSG_BOX19_ENABLE 1
#if CANA_MSG_BOX19_ENABLE
#define CANA_MSG_BOX19_MSG_ID 19
#define CANA_MSG_BOX19_TYPE CAN_MSG_BOX_TYPE_RX
#define CANA_MSG_BOX19_FRAME CAN_MSG_FRAME_STD
#define CANA_MSG_BOX19_ID_MASK 0
#define CANA_MSG_BOX19_INT (CAN_MSG_OBJ_RX_INT_ENABLE | CAN_MSG_OBJ_USE_ID_FILTER)
#define CANA_MSG_BOX19_DATA_LENGTH 8
#endif
/*===========================================================================*/
/*================== configuration mailbox20 for receive data ===============*/
/*===========================================================================*/
#define CANA_MSG_BOX20_ENABLE 1
#if CANA_MSG_BOX20_ENABLE
#define CANA_MSG_BOX20_MSG_ID 20
#define CANA_MSG_BOX20_TYPE CAN_MSG_BOX_TYPE_RX
#define CANA_MSG_BOX20_FRAME CAN_MSG_FRAME_STD
#define CANA_MSG_BOX20_ID_MASK 0
#define CANA_MSG_BOX20_INT (CAN_MSG_OBJ_RX_INT_ENABLE | CAN_MSG_OBJ_USE_ID_FILTER)
#define CANA_MSG_BOX20_DATA_LENGTH 8
#endif
/*===========================================================================*/
/*================== configuration mailbox21 for receive data ===============*/
/*===========================================================================*/
#define CANA_MSG_BOX21_ENABLE 1
#if CANA_MSG_BOX21_ENABLE
#define CANA_MSG_BOX21_MSG_ID 21
#define CANA_MSG_BOX21_TYPE CAN_MSG_BOX_TYPE_RX
#define CANA_MSG_BOX21_FRAME CAN_MSG_FRAME_STD
#define CANA_MSG_BOX21_ID_MASK 0
#define CANA_MSG_BOX21_INT (CAN_MSG_OBJ_RX_INT_ENABLE | CAN_MSG_OBJ_USE_ID_FILTER)
#define CANA_MSG_BOX21_DATA_LENGTH 8
#endif
/*===========================================================================*/
/*================== configuration mailbox22 for receive data ===============*/
/*===========================================================================*/
#define CANA_MSG_BOX22_ENABLE 0
#if CANA_MSG_BOX22_ENABLE
#define CANA_MSG_BOX22_MSG_ID 22
#define CANA_MSG_BOX22_TYPE CAN_MSG_BOX_TYPE_RX
#define CANA_MSG_BOX22_FRAME CAN_MSG_FRAME_STD
#define CANA_MSG_BOX22_ID_MASK 0
#define CANA_MSG_BOX22_INT (CAN_MSG_OBJ_RX_INT_ENABLE | CAN_MSG_OBJ_USE_ID_FILTER)
#define CANA_MSG_BOX22_DATA_LENGTH 8
#endif
/*===========================================================================*/
/*================== configuration mailbox23 for receive data ===============*/
/*===========================================================================*/
#define CANA_MSG_BOX23_ENABLE 0
#if CANA_MSG_BOX23_ENABLE
#define CANA_MSG_BOX23_MSG_ID 23
#define CANA_MSG_BOX23_TYPE CAN_MSG_BOX_TYPE_RX
#define CANA_MSG_BOX23_FRAME CAN_MSG_FRAME_STD
#define CANA_MSG_BOX23_ID_MASK 0
#define CANA_MSG_BOX23_INT (CAN_MSG_OBJ_RX_INT_ENABLE | CAN_MSG_OBJ_USE_ID_FILTER)
#define CANA_MSG_BOX23_DATA_LENGTH 8
#endif
/*===========================================================================*/
/*================== configuration mailbox24 for receive data ===============*/
/*===========================================================================*/
#define CANA_MSG_BOX24_ENABLE 0
#if CANA_MSG_BOX24_ENABLE
#define CANA_MSG_BOX24_MSG_ID 24
#define CANA_MSG_BOX24_TYPE CAN_MSG_BOX_TYPE_RX
#define CANA_MSG_BOX24_FRAME CAN_MSG_FRAME_STD
#define CANA_MSG_BOX24_ID_MASK 0
#define CANA_MSG_BOX24_INT (CAN_MSG_OBJ_RX_INT_ENABLE | CAN_MSG_OBJ_USE_ID_FILTER)
#define CANA_MSG_BOX24_DATA_LENGTH 8
#endif
/*===========================================================================*/
/*================== configuration mailbox25 for receive data ===============*/
/*===========================================================================*/
#define CANA_MSG_BOX25_ENABLE 1
#if CANA_MSG_BOX25_ENABLE
#define CANA_MSG_BOX25_MSG_ID 25
#define CANA_MSG_BOX25_TYPE CAN_MSG_BOX_TYPE_RX
#define CANA_MSG_BOX25_FRAME CAN_MSG_FRAME_STD
#define CANA_MSG_BOX25_ID_MASK 0
#define CANA_MSG_BOX25_INT (CAN_MSG_OBJ_RX_INT_ENABLE | CAN_MSG_OBJ_USE_ID_FILTER)
#define CANA_MSG_BOX25_DATA_LENGTH (8U)
#endif
/*===========================================================================*/
/*================== configuration mailbox26 for receive data ===============*/
/*===========================================================================*/
#define CANA_MSG_BOX26_ENABLE 1
#if CANA_MSG_BOX26_ENABLE
#define CANA_MSG_BOX26_MSG_ID 26
#define CANA_MSG_BOX26_TYPE CAN_MSG_BOX_TYPE_RX
#define CANA_MSG_BOX26_FRAME CAN_MSG_FRAME_STD
#define CANA_MSG_BOX26_ID_MASK 0
#define CANA_MSG_BOX26_INT (CAN_MSG_OBJ_RX_INT_ENABLE | CAN_MSG_OBJ_USE_ID_FILTER)
#define CANA_MSG_BOX26_DATA_LENGTH (8U)
#endif
/*===========================================================================*/
/*================== configuration mailbox27 for receive data ===============*/
/*===========================================================================*/
#define CANA_MSG_BOX27_ENABLE 1
#if CANA_MSG_BOX27_ENABLE
#define CANA_MSG_BOX27_MSG_ID 27
#define CANA_MSG_BOX27_TYPE CAN_MSG_BOX_TYPE_RX
#define CANA_MSG_BOX27_FRAME CAN_MSG_FRAME_STD
#define CANA_MSG_BOX27_ID_MASK 0
#define CANA_MSG_BOX27_INT (CAN_MSG_OBJ_RX_INT_ENABLE | CAN_MSG_OBJ_USE_ID_FILTER)
#define CANA_MSG_BOX27_DATA_LENGTH (8U)
#endif
/*===========================================================================*/
/*================== configuration mailbox28 for receive data ===============*/
/*===========================================================================*/
#define CANA_MSG_BOX28_ENABLE 1
#if CANA_MSG_BOX28_ENABLE
#define CANA_MSG_BOX28_MSG_ID 28
#define CANA_MSG_BOX28_TYPE CAN_MSG_BOX_TYPE_RX
#define CANA_MSG_BOX28_FRAME CAN_MSG_FRAME_STD
#define CANA_MSG_BOX28_ID_MASK 0
#define CANA_MSG_BOX28_INT (CAN_MSG_OBJ_RX_INT_ENABLE | CAN_MSG_OBJ_USE_ID_FILTER)
#define CANA_MSG_BOX28_DATA_LENGTH (8U)
#endif
/*===========================================================================*/
/*================== configuration mailbox29 for receive data ===============*/
/*===========================================================================*/
#define CANA_MSG_BOX29_ENABLE 1
#if CANA_MSG_BOX29_ENABLE
#define CANA_MSG_BOX29_MSG_ID 29
#define CANA_MSG_BOX29_TYPE CAN_MSG_BOX_TYPE_RX
#define CANA_MSG_BOX29_FRAME CAN_MSG_FRAME_STD
#define CANA_MSG_BOX29_ID_MASK 0
#define CANA_MSG_BOX29_INT (CAN_MSG_OBJ_RX_INT_ENABLE | CAN_MSG_OBJ_USE_ID_FILTER)
#define CANA_MSG_BOX29_DATA_LENGTH (8U)
#endif
/*===========================================================================*/
/*================== configuration mailbox30 for receive data ===============*/
/*===========================================================================*/
#define CANA_MSG_BOX30_ENABLE 1
#if CANA_MSG_BOX30_ENABLE
#define CANA_MSG_BOX30_MSG_ID 30
#define CANA_MSG_BOX30_TYPE CAN_MSG_BOX_TYPE_RX
#define CANA_MSG_BOX30_FRAME CAN_MSG_FRAME_STD
#define CANA_MSG_BOX30_ID_MASK 0
#define CANA_MSG_BOX30_INT (CAN_MSG_OBJ_RX_INT_ENABLE | CAN_MSG_OBJ_USE_ID_FILTER)
#define CANA_MSG_BOX30_DATA_LENGTH (8U)
#endif
/*===========================================================================*/
/*================== configuration mailbox31 for receive data ===============*/
/*===========================================================================*/
#define CANA_MSG_BOX31_ENABLE 1
#if CANA_MSG_BOX31_ENABLE
#define CANA_MSG_BOX31_MSG_ID 31
#define CANA_MSG_BOX31_TYPE CAN_MSG_BOX_TYPE_RX
#define CANA_MSG_BOX31_FRAME CAN_MSG_FRAME_STD
#define CANA_MSG_BOX31_ID_MASK 0
#define CANA_MSG_BOX31_INT (CAN_MSG_OBJ_RX_INT_ENABLE | CAN_MSG_OBJ_USE_ID_FILTER)
#define CANA_MSG_BOX31_DATA_LENGTH (8U)
#endif
/*===========================================================================*/
/*================== configuration mailbox32 for receive data ===============*/
/*===========================================================================*/
#define CANA_MSG_BOX32_ENABLE 1
#if CANA_MSG_BOX32_ENABLE
#define CANA_MSG_BOX32_MSG_ID 32
#define CANA_MSG_BOX32_TYPE CAN_MSG_BOX_TYPE_RX
#define CANA_MSG_BOX32_FRAME CAN_MSG_FRAME_STD
#define CANA_MSG_BOX32_ID_MASK 0
#define CANA_MSG_BOX32_INT (CAN_MSG_OBJ_RX_INT_ENABLE | CAN_MSG_OBJ_USE_ID_FILTER)
#define CANA_MSG_BOX32_DATA_LENGTH (8U)
#endif
/*===========================================================================*/
/*==================  mailbox ID  ===========================================*/
/*===========================================================================*/
#define CANA_MSG_BOX1_ID 1U
#define CANA_MSG_BOX2_ID 2U
#define CANA_MSG_BOX3_ID 3U
#define CANA_MSG_BOX4_ID 4U
#define CANA_MSG_BOX5_ID 5U
#define CANA_MSG_BOX6_ID 6U
#define CANA_MSG_BOX7_ID 7U
#define CANA_MSG_BOX8_ID 8U
#define CANA_MSG_BOX9_ID 9U
#define CANA_MSG_BOX10_ID 10U
#define CANA_MSG_BOX11_ID 11U
#define CANA_MSG_BOX12_ID 12U
#define CANA_MSG_BOX13_ID 13U
#define CANA_MSG_BOX14_ID 14U
#define CANA_MSG_BOX15_ID 15U
#define CANA_MSG_BOX16_ID 16U
#define CANA_MSG_BOX17_ID 17U
#define CANA_MSG_BOX18_ID 18U
#define CANA_MSG_BOX19_ID 19U
#define CANA_MSG_BOX20_ID 20U
#define CANA_MSG_BOX21_ID 21U
#define CANA_MSG_BOX22_ID 22U
#define CANA_MSG_BOX23_ID 23U
#define CANA_MSG_BOX24_ID 24U
#define CANA_MSG_BOX25_ID 25U
#define CANA_MSG_BOX26_ID 26U
#define CANA_MSG_BOX27_ID 27U
#define CANA_MSG_BOX28_ID 28U
#define CANA_MSG_BOX29_ID 29U
#define CANA_MSG_BOX30_ID 30U
#define CANA_MSG_BOX31_ID 31U
#define CANA_MSG_BOX32_ID 32U
/*===========================================================================*/
/*==================  CAN FAULT  ============================================*/
/*===========================================================================*/
#define CANA_ES_REG_LLC        0x7U
#define CANA_ES_REG_PASS       0x20U
#define CANA_ES_REG_WARNING    0x40U
#define CANA_ES_REG_BUSOFF     0x80U
#define CANA_ES_REG_PARITY     0x100U
/*================== Static Constant and Variable Definitions ===============*/
static CAN_CFG_CANA_ERROR_STATUS_s g_cana_fault = { .CANA_BUS_OFF_STATUS = 0,
                                                    .CANA_LLC_ACK_ERROR = 0,
                                                    .CANA_LLC_BIT0_ERROR = 0,
                                                    .CANA_LLC_BIT1_ERROR = 0,
                                                    .CANA_LLC_CRC_ERROR = 0,
                                                    .CANA_LLC_FORM_ERROR = 0,
                                                    .CANA_LLC_STUFF_ERROR = 0,
                                                    .CANA_PARITY_ERORR = 0,
                                                    .CANA_PASSIVE_ERROR = 0,
                                                    .CANA_WARNING_STATUS = 0,
                                                    .CANA_GLOBAL_FAULT = 0 };
static CAN_CFG_CAN_DATA_s g_cana_rx[CANA_RX_NUMBER_MAILBOX];
/*================== Extern Constant and Variable Definitions ===============*/
/*================== Static Function Prototypes =============================*/
__interrupt void int_cana_isr_(void);
static void can_cfg_cana_read_mailbox(void);
static void can_cfg_cana_init(void);
static void can_cfg_cana_isr(uint32_t);
static void can_cfg_cana_intterupt_enbale(void);
/*================== Static Function Implementation =============================*/
/**
 * @brief   Initialize GPIO CANA
 *
 * @details This function is used to initialize GPIO CANA module A.
 *
 * @param   void
 *
 * @return  void
 */
static void can_cfg_gpio_cana_init(void)
{

    GPIO_setPinConfig(GPIO_71_CANTXA);
    GPIO_setPadConfig(71, GPIO_PIN_TYPE_STD);
    GPIO_setQualificationMode(71, GPIO_QUAL_ASYNC);

    GPIO_setPinConfig(GPIO_70_CANRXA);
    GPIO_setPadConfig(70, GPIO_PIN_TYPE_STD);
    GPIO_setQualificationMode(70, GPIO_QUAL_ASYNC);
}
/**
 * @brief   Initialize  CANA
 *
 * @details This function is used to initialize  CANA module A.
 *
 * @param   void
 *
 * @return  void
 */
static void can_cfg_cana_init(void)
{
    can_cfg_gpio_cana_init();
    CAN_initModule(CANA_BASE);
    CAN_selectClockSource(CANA_BASE, CAN_CLOCK_SOURCE_SYS);
    CAN_setBitRate(CANA_BASE, 200000000U, CANA_BAUDRATE, 20);
    CAN_enableInterrupt(CANA_BASE,
    CAN_INT_IE0 | CAN_INT_ERROR | CAN_INT_STATUS);
    CAN_enableAutoBusOn(CANA_BASE);
}
/**
 * @brief   CONFIG ISR CANA
 *
 * @details This function is used to ASSIN ISR TO CANA INT0
 *
 * @param   void
 *
 * @return  void
 */
static void can_cfg_cana_isr_(void)
{
    EALLOW;
    Interrupt_register(INT_CANA0, &int_cana_isr_);
    EDIS;
}
/**
 * @brief   ISR CANA
 *
 * @details This function is used to Interrupt Service Routine .
 *
 * @param   void
 *
 * @return  void
 */
__interrupt void int_cana_isr_(void)
{
    uint32_t status;
    status = CAN_getInterruptCause(CANA_BASE);
    can_cfg_cana_isr(status);
    CAN_clearGlobalInterruptStatus(CANA_BASE, CAN_GLOBAL_INT_CANINT0);
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP9);
}

/**
 * @brief  ENABLE CANA INT0
 *
 * @details This function is used to Enable CANA INT0;
 *
 * @param   void
 *
 * @return  void
 */
static void can_cfg_cana_intterupt_enbale(void)
{
    EALLOW;
    Interrupt_enable(INT_CANA0);
    CAN_enableGlobalInterrupt(CANA_BASE, CAN_GLOBAL_INT_CANINT0);
    EDIS;

}
/**
 * @brief  CONFIGURATION CANA MAILBOX
 *
 * @details This function is used to initialize  CANA mailbox;
 *
 * @param   void
 *
 * @return  void
 */
static void can_cfg_cana_read_mailbox(void)
{
#if CANA_MSG_BOX1_ENABLE
CAN_setupMessageObject(CANA_BASE, CANA_MSG_BOX1_ID, CANA_MSG_BOX1_MSG_ID,(CAN_MsgFrameType)CANA_MSG_BOX1_FRAME,
                           (CAN_MsgObjType)CANA_MSG_BOX1_TYPE, CANA_MSG_BOX1_ID_MASK, CANA_MSG_BOX1_INT,
                           CANA_MSG_BOX1_DATA_LENGTH);
#endif
#if CANA_MSG_BOX2_ENABLE
CAN_setupMessageObject(CANA_BASE, CANA_MSG_BOX2_ID, CANA_MSG_BOX2_MSG_ID,(CAN_MsgFrameType)CANA_MSG_BOX2_FRAME,
                           (CAN_MsgObjType)CANA_MSG_BOX2_TYPE, CANA_MSG_BOX2_ID_MASK, CANA_MSG_BOX2_INT,
                           CANA_MSG_BOX2_DATA_LENGTH);
#endif
#if CANA_MSG_BOX3_ENABLE
CAN_setupMessageObject(CANA_BASE, CANA_MSG_BOX3_ID, CANA_MSG_BOX3_MSG_ID,(CAN_MsgFrameType)CANA_MSG_BOX3_FRAME,
                           (CAN_MsgObjType)CANA_MSG_BOX3_TYPE, CANA_MSG_BOX3_ID_MASK, CANA_MSG_BOX3_INT,
                           CANA_MSG_BOX3_DATA_LENGTH);
#endif
#if CANA_MSG_BOX4_ENABLE
CAN_setupMessageObject(CANA_BASE, CANA_MSG_BOX4_ID, CANA_MSG_BOX4_MSG_ID,(CAN_MsgFrameType)CANA_MSG_BOX4_FRAME,
                           (CAN_MsgObjType)CANA_MSG_BOX4_TYPE, CANA_MSG_BOX4_ID_MASK, CANA_MSG_BOX4_INT,
                           CANA_MSG_BOX4_DATA_LENGTH);
#endif
#if CANA_MSG_BOX5_ENABLE
CAN_setupMessageObject(CANA_BASE, CANA_MSG_BOX5_ID, CANA_MSG_BOX5_MSG_ID,(CAN_MsgFrameType)CANA_MSG_BOX5_FRAME,
                           (CAN_MsgObjType)CANA_MSG_BOX5_TYPE, CANA_MSG_BOX5_ID_MASK, CANA_MSG_BOX5_INT,
                           CANA_MSG_BOX5_DATA_LENGTH);
#endif
#if CANA_MSG_BOX6_ENABLE
CAN_setupMessageObject(CANA_BASE, CANA_MSG_BOX6_ID, CANA_MSG_BOX6_MSG_ID,(CAN_MsgFrameType)CANA_MSG_BOX6_FRAME,
                           (CAN_MsgObjType)CANA_MSG_BOX6_TYPE, CANA_MSG_BOX6_ID_MASK, CANA_MSG_BOX6_INT,
                           CANA_MSG_BOX6_DATA_LENGTH);
#endif
#if CANA_MSG_BOX7_ENABLE
CAN_setupMessageObject(CANA_BASE, CANA_MSG_BOX7_ID, CANA_MSG_BOX7_MSG_ID,(CAN_MsgFrameType)CANA_MSG_BOX7_FRAME,
                           (CAN_MsgObjType)CANA_MSG_BOX7_TYPE, CANA_MSG_BOX7_ID_MASK, CANA_MSG_BOX7_INT,
                           CANA_MSG_BOX7_DATA_LENGTH);
#endif
#if CANA_MSG_BOX8_ENABLE
CAN_setupMessageObject(CANA_BASE, CANA_MSG_BOX8_ID, CANA_MSG_BOX8_MSG_ID,(CAN_MsgFrameType)CANA_MSG_BOX8_FRAME,
                           (CAN_MsgObjType)CANA_MSG_BOX8_TYPE, CANA_MSG_BOX8_ID_MASK, CANA_MSG_BOX8_INT,
                           CANA_MSG_BOX8_DATA_LENGTH);
#endif
#if CANA_MSG_BOX9_ENABLE
CAN_setupMessageObject(CANA_BASE, CANA_MSG_BOX9_ID, CANA_MSG_BOX9_MSG_ID,(CAN_MsgFrameType)CANA_MSG_BOX9_FRAME,
                           (CAN_MsgObjType)CANA_MSG_BOX9_TYPE, CANA_MSG_BOX9_ID_MASK, CANA_MSG_BOX9_INT,
                           CANA_MSG_BOX9_DATA_LENGTH);
#endif
#if CANA_MSG_BOX10_ENABLE
CAN_setupMessageObject(CANA_BASE, CANA_MSG_BOX10_ID, CANA_MSG_BOX10_MSG_ID,(CAN_MsgFrameType)CANA_MSG_BOX10_FRAME,
                           (CAN_MsgObjType)CANA_MSG_BOX10_TYPE, CANA_MSG_BOX10_ID_MASK, CANA_MSG_BOX10_INT,
                           CANA_MSG_BOX10_DATA_LENGTH);
#endif
#if CANA_MSG_BOX11_ENABLE
CAN_setupMessageObject(CANA_BASE, CANA_MSG_BOX11_ID, CANA_MSG_BOX11_MSG_ID,(CAN_MsgFrameType)CANA_MSG_BOX11_FRAME,
                           (CAN_MsgObjType)CANA_MSG_BOX11_TYPE, CANA_MSG_BOX11_ID_MASK, CANA_MSG_BOX11_INT,
                           CANA_MSG_BOX11_DATA_LENGTH);
#endif
#if CANA_MSG_BOX12_ENABLE
CAN_setupMessageObject(CANA_BASE, CANA_MSG_BOX12_ID, CANA_MSG_BOX12_MSG_ID,(CAN_MsgFrameType)CANA_MSG_BOX12_FRAME,
                           (CAN_MsgObjType)CANA_MSG_BOX12_TYPE, CANA_MSG_BOX12_ID_MASK, CANA_MSG_BOX12_INT,
                           CANA_MSG_BOX12_DATA_LENGTH);
#endif
#if CANA_MSG_BOX13_ENABLE
CAN_setupMessageObject(CANA_BASE, CANA_MSG_BOX13_ID, CANA_MSG_BOX13_MSG_ID,(CAN_MsgFrameType)CANA_MSG_BOX13_FRAME,
                           (CAN_MsgObjType)CANA_MSG_BOX13_TYPE, CANA_MSG_BOX13_ID_MASK, CANA_MSG_BOX13_INT,
                           CANA_MSG_BOX13_DATA_LENGTH);
#endif
#if CANA_MSG_BOX14_ENABLE
CAN_setupMessageObject(CANA_BASE, CANA_MSG_BOX14_ID, CANA_MSG_BOX14_MSG_ID,(CAN_MsgFrameType)CANA_MSG_BOX14_FRAME,
                           (CAN_MsgObjType)CANA_MSG_BOX14_TYPE, CANA_MSG_BOX14_ID_MASK, CANA_MSG_BOX14_INT,
                           CANA_MSG_BOX14_DATA_LENGTH);
#endif
#if CANA_MSG_BOX15_ENABLE
CAN_setupMessageObject(CANA_BASE, CANA_MSG_BOX15_ID, CANA_MSG_BOX15_MSG_ID,(CAN_MsgFrameType)CANA_MSG_BOX15_FRAME,
                           (CAN_MsgObjType)CANA_MSG_BOX15_TYPE, CANA_MSG_BOX15_ID_MASK, CANA_MSG_BOX15_INT,
                           CANA_MSG_BOX15_DATA_LENGTH);
#endif
#if CANA_MSG_BOX16_ENABLE
CAN_setupMessageObject(CANA_BASE, CANA_MSG_BOX16_ID, CANA_MSG_BOX16_MSG_ID,(CAN_MsgFrameType)CANA_MSG_BOX16_FRAME,
                           (CAN_MsgObjType)CANA_MSG_BOX16_TYPE, CANA_MSG_BOX16_ID_MASK, CANA_MSG_BOX16_INT,
                           CANA_MSG_BOX16_DATA_LENGTH);
#endif
#if CANA_MSG_BOX17_ENABLE
CAN_setupMessageObject(CANA_BASE, CANA_MSG_BOX17_ID, CANA_MSG_BOX17_MSG_ID,(CAN_MsgFrameType)CANA_MSG_BOX17_FRAME,
                           (CAN_MsgObjType)CANA_MSG_BOX17_TYPE, CANA_MSG_BOX17_ID_MASK, CANA_MSG_BOX17_INT,
                           CANA_MSG_BOX17_DATA_LENGTH);
#endif
#if CANA_MSG_BOX18_ENABLE
CAN_setupMessageObject(CANA_BASE, CANA_MSG_BOX18_ID, CANA_MSG_BOX18_MSG_ID,(CAN_MsgFrameType)CANA_MSG_BOX18_FRAME,
                           (CAN_MsgObjType)CANA_MSG_BOX18_TYPE, CANA_MSG_BOX18_ID_MASK, CANA_MSG_BOX18_INT,
                           CANA_MSG_BOX18_DATA_LENGTH);
#endif
#if CANA_MSG_BOX19_ENABLE
    CAN_setupMessageObject(CANA_BASE, CANA_MSG_BOX19_ID, CANA_MSG_BOX19_MSG_ID,
                           (CAN_MsgFrameType) CANA_MSG_BOX19_FRAME,
                           (CAN_MsgObjType) CANA_MSG_BOX19_TYPE,
                           CANA_MSG_BOX19_ID_MASK, CANA_MSG_BOX19_INT,
                           CANA_MSG_BOX19_DATA_LENGTH);
#endif
#if CANA_MSG_BOX20_ENABLE
    CAN_setupMessageObject(CANA_BASE, CANA_MSG_BOX20_ID, CANA_MSG_BOX20_MSG_ID,
                           (CAN_MsgFrameType) CANA_MSG_BOX20_FRAME,
                           (CAN_MsgObjType) CANA_MSG_BOX20_TYPE,
                           CANA_MSG_BOX20_ID_MASK, CANA_MSG_BOX20_INT,
                           CANA_MSG_BOX20_DATA_LENGTH);
#endif
#if CANA_MSG_BOX21_ENABLE
    CAN_setupMessageObject(CANA_BASE, CANA_MSG_BOX21_ID, CANA_MSG_BOX21_MSG_ID,
                           (CAN_MsgFrameType) CANA_MSG_BOX21_FRAME,
                           (CAN_MsgObjType) CANA_MSG_BOX21_TYPE,
                           CANA_MSG_BOX21_ID_MASK, CANA_MSG_BOX21_INT,
                           CANA_MSG_BOX21_DATA_LENGTH);
#endif
#if CANA_MSG_BOX22_ENABLE
    CAN_setupMessageObject(CANA_BASE, CANA_MSG_BOX22_ID, CANA_MSG_BOX22_MSG_ID,
                           (CAN_MsgFrameType) CANA_MSG_BOX22_FRAME,
                           (CAN_MsgObjType) CANA_MSG_BOX22_TYPE,
                           CANA_MSG_BOX22_ID_MASK, CANA_MSG_BOX22_INT,
                           CANA_MSG_BOX22_DATA_LENGTH);
#endif
#if CANA_MSG_BOX23_ENABLE
    CAN_setupMessageObject(CANA_BASE, CANA_MSG_BOX23_ID, CANA_MSG_BOX23_MSG_ID,
                           (CAN_MsgFrameType) CANA_MSG_BOX23_FRAME,
                           (CAN_MsgObjType) CANA_MSG_BOX23_TYPE,
                           CANA_MSG_BOX23_ID_MASK, CANA_MSG_BOX23_INT,
                           CANA_MSG_BOX23_DATA_LENGTH);
#endif
#if CANA_MSG_BOX24_ENABLE
    CAN_setupMessageObject(CANA_BASE, CANA_MSG_BOX24_ID, CANA_MSG_BOX24_MSG_ID,
                           (CAN_MsgFrameType) CANA_MSG_BOX24_FRAME,
                           (CAN_MsgObjType) CANA_MSG_BOX24_TYPE,
                           CANA_MSG_BOX24_ID_MASK, CANA_MSG_BOX24_INT,
                           CANA_MSG_BOX24_DATA_LENGTH);
#endif
#if CANA_MSG_BOX25_ENABLE
    CAN_setupMessageObject(CANA_BASE, CANA_MSG_BOX25_ID, CANA_MSG_BOX25_MSG_ID,
                           (CAN_MsgFrameType) CANA_MSG_BOX25_FRAME,
                           (CAN_MsgObjType) CANA_MSG_BOX25_TYPE,
                           CANA_MSG_BOX25_ID_MASK, CANA_MSG_BOX25_INT,
                           CANA_MSG_BOX25_DATA_LENGTH);
#endif
#if CANA_MSG_BOX26_ENABLE
    CAN_setupMessageObject(CANA_BASE, CANA_MSG_BOX26_ID, CANA_MSG_BOX26_MSG_ID,
                           (CAN_MsgFrameType) CANA_MSG_BOX26_FRAME,
                           (CAN_MsgObjType) CANA_MSG_BOX26_TYPE,
                           CANA_MSG_BOX26_ID_MASK,
                           CANA_MSG_BOX26_INT,
                           CANA_MSG_BOX26_DATA_LENGTH);
#endif
#if CANA_MSG_BOX27_ENABLE
    CAN_setupMessageObject(CANA_BASE, CANA_MSG_BOX27_ID, CANA_MSG_BOX27_MSG_ID,
                           (CAN_MsgFrameType) CANA_MSG_BOX27_FRAME,
                           (CAN_MsgObjType) CANA_MSG_BOX27_TYPE,
                           CANA_MSG_BOX27_ID_MASK,
                           CANA_MSG_BOX27_INT,
                           CANA_MSG_BOX27_DATA_LENGTH);
#endif
#if CANA_MSG_BOX28_ENABLE
    CAN_setupMessageObject(CANA_BASE, CANA_MSG_BOX28_ID, CANA_MSG_BOX28_MSG_ID,
                           (CAN_MsgFrameType) CANA_MSG_BOX28_FRAME,
                           (CAN_MsgObjType) CANA_MSG_BOX28_TYPE,
                           CANA_MSG_BOX28_ID_MASK,
                           CANA_MSG_BOX28_INT,
                           CANA_MSG_BOX28_DATA_LENGTH);
#endif
#if CANA_MSG_BOX29_ENABLE
    CAN_setupMessageObject(CANA_BASE, CANA_MSG_BOX29_ID, CANA_MSG_BOX29_MSG_ID,
                           (CAN_MsgFrameType) CANA_MSG_BOX29_FRAME,
                           (CAN_MsgObjType) CANA_MSG_BOX29_TYPE,
                           CANA_MSG_BOX29_ID_MASK,
                           CANA_MSG_BOX29_INT,
                           CANA_MSG_BOX29_DATA_LENGTH);
#endif
#if CANA_MSG_BOX30_ENABLE
    CAN_setupMessageObject(CANA_BASE, CANA_MSG_BOX30_ID, CANA_MSG_BOX30_MSG_ID,
                           (CAN_MsgFrameType) CANA_MSG_BOX30_FRAME,
                           (CAN_MsgObjType) CANA_MSG_BOX30_TYPE,
                           CANA_MSG_BOX30_ID_MASK,
                           CANA_MSG_BOX30_INT,
                           CANA_MSG_BOX30_DATA_LENGTH);
#endif
#if CANA_MSG_BOX31_ENABLE
    CAN_setupMessageObject(CANA_BASE, CANA_MSG_BOX31_ID, CANA_MSG_BOX31_MSG_ID,
                           (CAN_MsgFrameType) CANA_MSG_BOX31_FRAME,
                           (CAN_MsgObjType) CANA_MSG_BOX31_TYPE,
                           CANA_MSG_BOX31_ID_MASK,
                           CANA_MSG_BOX31_INT,
                           CANA_MSG_BOX31_DATA_LENGTH);
#endif
#if CANA_MSG_BOX32_ENABLE
    CAN_setupMessageObject(CANA_BASE, CANA_MSG_BOX32_ID, CANA_MSG_BOX32_MSG_ID,
                           (CAN_MsgFrameType) CANA_MSG_BOX32_FRAME,
                           (CAN_MsgObjType) CANA_MSG_BOX32_TYPE,
                           CANA_MSG_BOX32_ID_MASK,
                           CANA_MSG_BOX32_INT,
                           CANA_MSG_BOX32_DATA_LENGTH);
#endif
}
static void can_cfg_cana_fault_detection(void)
{

    uint32_t status = (0U);
    status = CAN_getStatus(CANA_BASE);
    g_cana_fault.CANA_GLOBAL_FAULT = 0U;
    if ((status & CANA_ES_REG_LLC) == 1U)
    {
        g_cana_fault.CANA_LLC_STUFF_ERROR = 1U;
        g_cana_fault.CANA_GLOBAL_FAULT = 1U;
    }
    else
    {
        g_cana_fault.CANA_LLC_STUFF_ERROR = 0U;
    }
    if ((status & CANA_ES_REG_LLC) == 2U)
    {
        g_cana_fault.CANA_LLC_FORM_ERROR = 1U;
        g_cana_fault.CANA_GLOBAL_FAULT = 1U;
    }
    else
    {
        g_cana_fault.CANA_LLC_FORM_ERROR = 0U;
    }
    if ((status & CANA_ES_REG_LLC) == 3U)
    {
        g_cana_fault.CANA_LLC_ACK_ERROR = 1U;
        g_cana_fault.CANA_GLOBAL_FAULT = 1U;
    }
    else
    {
        g_cana_fault.CANA_LLC_ACK_ERROR = 0U;
    }
    if ((status & CANA_ES_REG_LLC) == 4U)
    {
        g_cana_fault.CANA_LLC_BIT1_ERROR = 1U;
        g_cana_fault.CANA_GLOBAL_FAULT = 1U;
    }
    else
    {
        g_cana_fault.CANA_LLC_BIT1_ERROR = 0U;
    }
    if ((status & CANA_ES_REG_LLC) == 5U)
    {
        g_cana_fault.CANA_LLC_BIT0_ERROR = 1U;
        g_cana_fault.CANA_GLOBAL_FAULT = 1U;
    }
    else
    {
        g_cana_fault.CANA_LLC_BIT0_ERROR = 0U;
    }
    if ((status & CANA_ES_REG_LLC) == 6U)
    {
        g_cana_fault.CANA_LLC_CRC_ERROR = 1U;
        g_cana_fault.CANA_GLOBAL_FAULT = 1U;
    }
    else
    {
        g_cana_fault.CANA_LLC_CRC_ERROR = 0U;
    }
    if ((status & CANA_ES_REG_PASS) != 0U)
    {
        g_cana_fault.CANA_PASSIVE_ERROR = 1U;
        g_cana_fault.CANA_GLOBAL_FAULT = 1U;
    }
    else
    {
        g_cana_fault.CANA_PASSIVE_ERROR = 0U;
    }
    if ((status & CANA_ES_REG_WARNING) != 0U)
    {
        g_cana_fault.CANA_WARNING_STATUS = 1U;
        g_cana_fault.CANA_GLOBAL_FAULT = 1U;
    }
    else
    {
        g_cana_fault.CANA_WARNING_STATUS = 0U;
    }
    if ((status & CANA_ES_REG_BUSOFF) != 0U)
    {
        g_cana_fault.CANA_BUS_OFF_STATUS = 1U;
        g_cana_fault.CANA_GLOBAL_FAULT = 1U;
        can_cfg_cana();
    }
    else
    {
        g_cana_fault.CANA_BUS_OFF_STATUS = 0U;
    }
    if ((status & CANA_ES_REG_PARITY) != 0U)
    {
        g_cana_fault.CANA_PARITY_ERORR = 1U;
        g_cana_fault.CANA_GLOBAL_FAULT = 1U;
    }
    else
    {
        g_cana_fault.CANA_PARITY_ERORR = 0U;
    }

}
/**
 * @brief  CANA ISR check mailbox data
 *
 * @details This function is used to check mailbox for data;
 *
 * @param   uint32_t msg_box_id,uint16_t msg_box_type
 *
 * @return  void
 */
static void can_cfg_cana_check_mailbox(uint32_t msg_box_id,
                                       uint16_t msg_box_type)
{
    if (msg_box_type == CAN_MSG_BOX_TYPE_TX)
    {

        CAN_clearInterruptStatus(CANA_BASE, msg_box_id);

    }
    else if (msg_box_type == CAN_MSG_BOX_TYPE_RX)
    {
        g_cana_rx[msg_box_id - 1U].update_flg = can_cfg_update_flg_set;
        g_cana_rx[msg_box_id - 1U].massage_box_number = msg_box_id;
        CAN_readMessageWithID(CANA_BASE, msg_box_id,
                              &g_cana_rx[msg_box_id - 1].frame_type,
                              &g_cana_rx[msg_box_id - 1].message_id,
                              &g_cana_rx[msg_box_id - 1].data[0]);
        CAN_clearInterruptStatus(CANA_BASE, msg_box_id);
        cana_rx_manage_write(g_cana_rx[msg_box_id - 1]);
    }
}

/**
 * @brief  ISR CANA
 *
 * @details This function is used to Interrupt service routine CANA;
 *
 * @param   mailbox number
 *
 * @return  void
 */
static void can_cfg_cana_isr(uint32_t status)
{

    switch (status)
    {
    case CAN_INT_INT0ID_STATUS:
        can_cfg_cana_fault_detection();
        break;

#if CANA_MSG_BOX1_ENABLE
    case CANA_MSG_BOX1_ID :
        can_cfg_cana_check_mailbox(CANA_MSG_BOX1_ID, CANA_MSG_BOX1_TYPE);
     break;
#endif
#if CANA_MSG_BOX2_ENABLE
    case CANA_MSG_BOX2_ID :
        can_cfg_cana_check_mailbox(CANA_MSG_BOX2_ID, CANA_MSG_BOX2_TYPE);
     break;
#endif
#if CANA_MSG_BOX3_ENABLE
    case CANA_MSG_BOX3_ID :
        can_cfg_cana_check_mailbox(CANA_MSG_BOX3_ID, CANA_MSG_BOX3_TYPE);
     break;
#endif
#if CANA_MSG_BOX4_ENABLE
    case CANA_MSG_BOX4_ID :
        can_cfg_cana_check_mailbox(CANA_MSG_BOX4_ID, CANA_MSG_BOX4_TYPE);
     break;
#endif
#if CANA_MSG_BOX5_ENABLE
    case CANA_MSG_BOX5_ID :
        can_cfg_cana_check_mailbox(CANA_MSG_BOX5_ID, CANA_MSG_BOX5_TYPE);
     break;
#endif
#if CANA_MSG_BOX6_ENABLE
    case CANA_MSG_BOX6_ID :
        can_cfg_cana_check_mailbox(CANA_MSG_BOX6_ID, CANA_MSG_BOX6_TYPE);
     break;
#endif
#if CANA_MSG_BOX7_ENABLE
    case CANA_MSG_BOX7_ID :
        can_cfg_cana_check_mailbox(CANA_MSG_BOX7_ID, CANA_MSG_BOX7_TYPE);
     break;
#endif
#if CANA_MSG_BOX8_ENABLE
    case CANA_MSG_BOX8_ID :
        can_cfg_cana_check_mailbox(CANA_MSG_BOX8_ID, CANA_MSG_BOX8_TYPE);
     break;
#endif
#if CANA_MSG_BOX9_ENABLE
    case CANA_MSG_BOX9_ID :
        can_cfg_cana_check_mailbox(CANA_MSG_BOX9_ID, CANA_MSG_BOX9_TYPE);
     break;
#endif
#if CANA_MSG_BOX10_ENABLE
    case CANA_MSG_BOX10_ID :
        can_cfg_cana_check_mailbox(CANA_MSG_BOX10_ID, CANA_MSG_BOX10_TYPE);
     break;
#endif
#if CANA_MSG_BOX11_ENABLE
    case CANA_MSG_BOX11_ID :
        can_cfg_cana_check_mailbox(CANA_MSG_BOX11_ID, CANA_MSG_BOX11_TYPE);
     break;
#endif
#if CANA_MSG_BOX12_ENABLE
    case CANA_MSG_BOX12_ID :
        can_cfg_cana_check_mailbox(CANA_MSG_BOX12_ID, CANA_MSG_BOX12_TYPE);
     break;
#endif
#if CANA_MSG_BOX13_ENABLE
    case CANA_MSG_BOX13_ID :
        can_cfg_cana_check_mailbox(CANA_MSG_BOX13_ID, CANA_MSG_BOX13_TYPE);
     break;
#endif
#if CANA_MSG_BOX14_ENABLE
    case CANA_MSG_BOX14_ID :
        can_cfg_cana_check_mailbox(CANA_MSG_BOX14_ID, CANA_MSG_BOX14_TYPE);
     break;
#endif
#if CANA_MSG_BOX15_ENABLE
    case CANA_MSG_BOX15_ID :
        can_cfg_cana_check_mailbox(CANA_MSG_BOX15_ID, CANA_MSG_BOX15_TYPE);
     break;
#endif
#if CANA_MSG_BOX16_ENABLE
    case CANA_MSG_BOX16_ID :
        can_cfg_cana_check_mailbox(CANA_MSG_BOX16_ID, CANA_MSG_BOX16_TYPE);
     break;
#endif
#if CANA_MSG_BOX17_ENABLE
    case CANA_MSG_BOX17_ID :
        can_cfg_cana_check_mailbox(CANA_MSG_BOX17_ID, CANA_MSG_BOX17_TYPE);
     break;
#endif
#if CANA_MSG_BOX18_ENABLE
    case CANA_MSG_BOX18_ID :
        can_cfg_cana_check_mailbox(CANA_MSG_BOX18_ID, CANA_MSG_BOX18_TYPE);
     break;
#endif
#if CANA_MSG_BOX19_ENABLE
    case CANA_MSG_BOX19_ID:
        can_cfg_cana_check_mailbox(CANA_MSG_BOX19_ID, CANA_MSG_BOX19_TYPE);
        break;
#endif
#if CANA_MSG_BOX20_ENABLE
    case CANA_MSG_BOX20_ID:
        can_cfg_cana_check_mailbox(CANA_MSG_BOX20_ID, CANA_MSG_BOX20_TYPE);
        break;
#endif
#if CANA_MSG_BOX21_ENABLE
    case CANA_MSG_BOX21_ID:
        can_cfg_cana_check_mailbox(CANA_MSG_BOX21_ID, CANA_MSG_BOX21_TYPE);
        break;
#endif
#if CANA_MSG_BOX22_ENABLE
    case CANA_MSG_BOX22_ID:
        can_cfg_cana_check_mailbox(CANA_MSG_BOX22_ID, CANA_MSG_BOX22_TYPE);
        break;
#endif
#if CANA_MSG_BOX23_ENABLE
    case CANA_MSG_BOX23_ID:
        can_cfg_cana_check_mailbox(CANA_MSG_BOX23_ID, CANA_MSG_BOX23_TYPE);
        break;
#endif
#if CANA_MSG_BOX24_ENABLE
    case CANA_MSG_BOX24_ID:
        can_cfg_cana_check_mailbox(CANA_MSG_BOX24_ID, CANA_MSG_BOX24_TYPE);
        break;
#endif
#if CANA_MSG_BOX25_ENABLE
    case CANA_MSG_BOX25_ID:
        can_cfg_cana_check_mailbox(CANA_MSG_BOX25_ID, CANA_MSG_BOX25_TYPE);
        break;
#endif
#if CANA_MSG_BOX26_ENABLE
    case CANA_MSG_BOX26_ID:
        can_cfg_cana_check_mailbox(CANA_MSG_BOX26_ID, CANA_MSG_BOX26_TYPE);
        break;
#endif
#if CANA_MSG_BOX27_ENABLE
    case CANA_MSG_BOX27_ID:
        can_cfg_cana_check_mailbox(CANA_MSG_BOX27_ID, CANA_MSG_BOX27_TYPE);
        break;
#endif
#if CANA_MSG_BOX28_ENABLE
    case CANA_MSG_BOX28_ID:
        can_cfg_cana_check_mailbox(CANA_MSG_BOX28_ID, CANA_MSG_BOX28_TYPE);
        break;
#endif
#if CANA_MSG_BOX29_ENABLE
    case CANA_MSG_BOX29_ID:
        can_cfg_cana_check_mailbox(CANA_MSG_BOX29_ID, CANA_MSG_BOX29_TYPE);
        break;
#endif
#if CANA_MSG_BOX30_ENABLE
    case CANA_MSG_BOX30_ID:
        can_cfg_cana_check_mailbox(CANA_MSG_BOX30_ID, CANA_MSG_BOX30_TYPE);
        break;
#endif
#if CANA_MSG_BOX31_ENABLE
    case CANA_MSG_BOX31_ID:
        can_cfg_cana_check_mailbox(CANA_MSG_BOX31_ID, CANA_MSG_BOX31_TYPE);
        break;
#endif
#if CANA_MSG_BOX32_ENABLE
    case CANA_MSG_BOX32_ID:
        can_cfg_cana_check_mailbox(CANA_MSG_BOX32_ID, CANA_MSG_BOX32_TYPE);
        break;
#endif

    default:

        break;
    }
}
/*================== Extern Function Implementations ========================*/
/**
 * @brief   CONFIG CANA IN MAIN FUNCTIONcan_read_all
 *
 * @details This function is used to main function.
 *
 * @param   void
 *
 * @return  void
 */
void can_cfg_cana(void)
{
    can_cfg_cana_init();
    can_cfg_cana_intterupt_enbale();
    can_cfg_cana_isr_();
    can_cfg_cana_read_mailbox();
    CAN_startModule(CANA_BASE);
}
/**
 * @brief   Write CANA
 *
 * @details This function is used to Write data CANA;
 *
 * @param   CAN_CFG_CANA_WRITE_PARAMETERS_s can_write_parameter
 *
 * @return  void
 */
void can_cfg_cana_write(CAN_CFG_CAN_WRITE_PARAMETERS_s *can_write_parameter)
{
    boolean_t box_status = FALSE;
    uint32_t mlbx_chng_counter = (0U);
    static uint32_t msg_box_id = CANA_TX_START_MAILBOX_ID;
    uint32_t txRequests = CAN_getTxRequests(CANA_BASE);

    if (can_write_parameter->high_priority == TRUE)
    {
        txRequests = txRequests & 0x01U;

        if (txRequests == 0U)
        {
            CAN_setupMessageObject(
                    CANA_BASE, (uint32_t) (1U),
                    (uint32_t) can_write_parameter->message_id,
                    can_write_parameter->msg_fram_type_extend_or_std,
                    CAN_MSG_OBJ_TYPE_TX, 0,
                    CAN_MSG_OBJ_NO_FLAGS,
                    can_write_parameter->data_len);
            CAN_sendMessage(CANA_BASE, (1U), can_write_parameter->data_len,
                            can_write_parameter->msgData);
            box_status = TRUE;
            can_write_parameter->data_ack = box_status;
            /* do nothing */
        }
        else
        {
            can_write_parameter->data_ack = box_status;
        }
    }
    else
    {
        /*Check empty mailbox status*/
        do
        {
            txRequests = (txRequests >> (msg_box_id - 1U)) & 0x01U;
            if (txRequests == 0U)
            {
                CAN_setupMessageObject(
                        CANA_BASE, (uint32_t) msg_box_id,
                        (uint32_t) can_write_parameter->message_id,
                        can_write_parameter->msg_fram_type_extend_or_std,
                        CAN_MSG_OBJ_TYPE_TX, 0,
                        CAN_MSG_OBJ_NO_FLAGS,
                        can_write_parameter->data_len);
                CAN_sendMessage(CANA_BASE, msg_box_id,
                                can_write_parameter->data_len,
                                can_write_parameter->msgData);
                box_status = TRUE;
                can_write_parameter->data_ack = box_status;

            }
            else
            {
                can_write_parameter->data_ack = box_status;
            }
            if (msg_box_id < CANA_TX_END_MAILBOX_ID)
            {
                msg_box_id = msg_box_id + (1U);
                mlbx_chng_counter++;
            }
            else
            {
                msg_box_id = CANA_TX_START_MAILBOX_ID;
            }
        }
        while ((box_status == FALSE)
                && (mlbx_chng_counter
                        < (CANA_TX_END_MAILBOX_ID - CANA_TX_START_MAILBOX_ID)));
    }

}
/**
 * @brief   Get CANA fault
 *
 * @details This function is used for set fault from CANA;
 *
 * @param   CAN_CFG_CANA_ERROR_STATUS_s
 *
 * @return  void
 */
CAN_CFG_CANA_ERROR_STATUS_s* can_cfg_cana_get_fault(void)
{
    return &g_cana_fault;
}
/**
 * @brief   Set CANA fault
 *
 * @details This function is used for set fault from CANA;
 *
 * @param   CAN_CFG_CANA_ERROR_STATUS_s
 *
 * @return  void
 */
void can_cfg_cana_set_fault(CAN_CFG_CANA_ERROR_STATUS_s *fault)
{
    g_cana_fault = *fault;
}
/*================== END MODULE ==============================================*/
