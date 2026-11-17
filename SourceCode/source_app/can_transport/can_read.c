/**
 * @file    can_read.c
 *
 * @author  A.Salehi
 *
 * @date    May 6, 2024(date of creation)
 *
 * @ingroup SOURCE APP
 *
 * @prefix  can_read
 *
 * @brief   this module is used for can read.
 *
 * @details def
 */
/*================== Includes ===============================================*/
#include "include_app/can_transport/can_read.h"
#include "include_arte/system_mode.h"
#include "include_app/can_management/cana_rx_manage.h"
#include "include_app/can_transport/can_exchange.h"

/*================== Macros and Definitions =================================*/
/*================== Static Constant and Variable Definitions ===============*/
/*================== Extern Constant and Variable Definitions ===============*/
/*================== Static Function Prototypes =============================*/
/*================== Static Function Implementations ========================*/
/*================== Extern Function Implementations ========================*/
/**
 * @brief  CAN read.
 *
 * @details this function is used for reading CAN messages from CAN buffer.
 *
 * @param[in] TIME_t local_time
 *
 * @return void
 */
void can_read_all(TIME_t local_time)
{
    uint32_t last_time = MAX_uint16_t;
    SYSTEM_MODE_STATE_s *system_mode_p = system_mode_get();
    CANA_RX_MANAGE_DEQUEUED_RETURN_s can_read_data;

    /*==============================================================*/
    /*=================== Classic CAN ==============================*/
    /*==============================================================*/
    can_read_data = cana_rx_manage_read();
    if ((can_read_data.can_rx_buffer != NULL) &&
            (can_read_data.can_rx_buffer->update_flg == can_cfg_update_flg_set))
    {
        last_time = local_time.sec;
        can_read_data.can_rx_buffer->update_flg = can_cfg_update_flg_unset;
    }
    else
    {

    }


}
/*================== END MODULE ==============================================*/
