/**
 * @file    can_exchange.c
 *
 * @author  Yousefian
 *
 * @date    04.07.2021 (date of creation)
 *
 * @ingroup SOURCE APP
 *
 * @prefix  can_exchange
 *
 * @brief   this module is used for can read.
 *
 * @details def
 */
/*================== Includes ===============================================*/
#include "include_app/can_transport/can_exchange.h"
#include "include_app/can_management/cana_rx_manage.h"
#include "include_app/can_management/cana_tx_manage.h"
#include "include_app/can_management/canb_tx_manage.h"
#include <string.h>
/*================== Macros and Definitions =================================*/
/*================== Static Constant and Variable Definitions ===============*/
/*================== Extern Constant and Variable Definitions ===============*/
/*================== Static Function Prototypes =============================*/
/*================== Static Function Implementations ========================*/
/*================== Extern Function Implementations ========================*/
/**
 * @brief  CAN exchange data
 *
 * @details this function is used for exchanging data between CAN buses.
 *
 * @param[in] TIME_t local_time
 *
 * @return void
 */
void can_exchange_all(uint32_t msg_id,uint16_t *msg_data)
{

}
/*================== END MODULE ==============================================*/
