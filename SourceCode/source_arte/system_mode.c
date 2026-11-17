/**
 * @file    system_mode.c
 *
 * @author  Allahmoradi
 *
 * @date    08.28.2023 (date of creation)
 *
 * @ingroup SOURCE APP
 *
 * @prefix  system_mode.
 *
 * @brief   this module used for system mode.
 *
 * @details def
 */
/*================== Includes ===============================================*/
#include "include_app/configuration/init.h"
#include "include_arte/system_mode.h"
#include "include_arte/system_task.h"
#include "include_app/configuration/system_cfg.h"

/*================== Macros and Definitions =================================*/
#define SYSTEM_MODE_INITIALIZATION_TIMEOUT  (0U)         /*sec*/
#define SYSTEM_MODE_CONFIGURATION_TIMEOUT   (4U)         /*sec*/
#define SYSTEM_MODE_WARMUP_TIMEOUT          (0U)         /*sec*/
#define SYSTEM_MODE_PREOPERATIONAL_WAITING  (1U)         /*sec*/
#define SYSTEM_MODE_REINIT_TIME             (60U)        /*sec*/
#define SYSTEM_MODE_REINIT_RETRY_LIMIT      (5U)         /*sec*/
/*================== Static Constant and Variable Definitions ===============*/
static SYSTEM_MODE_STATE_s g_system_mode = {.next = system_mode_initialisation_s};
/*================== Extern Constant and Variable Definitions ===============*/
/*================== Static Function Prototypes =============================*/
static SYSTEM_MODE_STATE_e system_mode_init_mode_state(TIME_t local_time , TIME_t *start_time);
static SYSTEM_MODE_STATE_e system_mode_configuration_mode_state(
        TIME_t local_time, TIME_t *start_time);
static SYSTEM_MODE_STATE_e system_mode_warmup_mode_state(TIME_t local_time,
                                                         TIME_t *start_time);
static SYSTEM_MODE_STATE_e system_mode_preoperational_state(TIME_t local_time,
                                                            TIME_t *start_time);
static SYSTEM_MODE_STATE_e system_mode_operational_state(TIME_t local_time,
                                                         TIME_t *start_time);
static SYSTEM_MODE_STATE_e system_mode_obd_mode_state(TIME_t local_time,
                                                      TIME_t *start_time);
static SYSTEM_MODE_STATE_e system_mode_degraded_mode_state(TIME_t local_time,
                                                           TIME_t *start_time);
static SYSTEM_MODE_STATE_e system_mode_secure_shutdown_mode_state(
        TIME_t local_time, TIME_t *start_time);
static SYSTEM_MODE_STATE_e system_mode_safe_mode_state(TIME_t local_time,
                                                       TIME_t *start_time);
/*================== Static Function Implementations ========================*/
/** @brif initialize system mode.
 *
 *  @details this function used for initialize system mode status.
 *
 *  @param  TIME_t
 *
 *  @return SYSTEM_MODE_STATE_e
 */
static SYSTEM_MODE_STATE_e system_mode_init_mode_state(TIME_t local_time , TIME_t *start_time)
{

    SYSTEM_MODE_STATE_e system_mode = system_mode_configuration_s;
    return system_mode;

}
/** @brif configuration system mode.
 *
 *  @details this function used for configuration system mode status.
 *
 *  @param TIME_t
 *
 *  @param TIME_t *
 *
 *  @return SYSTEM_MODE_STATE_e
 */
static SYSTEM_MODE_STATE_e system_mode_configuration_mode_state(
        TIME_t local_time, TIME_t *start_time)
{
    SYSTEM_MODE_STATE_e system_mode = system_mode_warmup_s;
    return system_mode;

}
/**
 * @brief warm up system mode.
 *
 *  @details this function used for warm up system mode status.
 *
 *  @param TIME_t
 *
 *  @param TIME_t *
 *
 *  @return SYSTEM_MODE_STATE_e
 */
static SYSTEM_MODE_STATE_e system_mode_warmup_mode_state(TIME_t local_time,
                                                         TIME_t *start_time)
{
    SYSTEM_MODE_STATE_e system_mode = system_mode_pre_operational_s;
    return system_mode;

}
/** @brif pre operational system mode.
 *
 *  @details this function used for pre operational system mode status.
 *
 *  @param TIME_t
 *
 *  @param TIME_t *
 *
 *  @return SYSTEM_MODE_STATE_e
 */
static SYSTEM_MODE_STATE_e system_mode_preoperational_state(TIME_t local_time,
                                                            TIME_t *start_time)
{

    SYSTEM_MODE_STATE_e system_mode = system_mode_operational_s;
    return system_mode;

}
/** @brif  operational system mode.
 *
 *  @details this function used for operational system mode status.
 *
 *  @param TIME_t
 *
 *  @param TIME_t *
 *
 *  @return SYSTEM_MODE_STATE_e
 */
static SYSTEM_MODE_STATE_e system_mode_operational_state(TIME_t local_time,
                                                         TIME_t *start_time)
{

    SYSTEM_MODE_STATE_e system_mode = system_mode_operational_s;
    return system_mode;
}
/** @brif  OBD system mode.
 *
 *  @details this function used for OBD system mode status.
 *
 *  @param TIME_t local_time
 *
 *  @param TIME_t * start_time
 *
 *  @return SYSTEM_MODE_STATE_e system_mode
 */
static SYSTEM_MODE_STATE_e system_mode_obd_mode_state(TIME_t local_time,
                                                      TIME_t *start_time)
{
    SYSTEM_MODE_STATE_e system_mode = system_mode_operational_s;
    return system_mode;
}
/**
 *  @brif degraded system mode.
 *
 *  @details this function used for degraded system mode status.
 *
 *  @param TIME_t local_time
 *
 *  @param TIME_t * start_time
 *
 *  @return SYSTEM_MODE_STATE_e system_mode
 */
static SYSTEM_MODE_STATE_e system_mode_degraded_mode_state(TIME_t local_time,
                                                           TIME_t *start_time)
{
    SYSTEM_MODE_STATE_e system_mode = system_mode_operational_s;
    return system_mode;
}
/**
 *  @brif secure shutdown system mode.
 *
 *  @details this function used for secure shutdown system mode status.
 *
 *  @param TIME_t local_time
 *
 *  @param TIME_t * start_time
 *
 *  @return SYSTEM_MODE_STATE_e system_mode
 */
static SYSTEM_MODE_STATE_e system_mode_secure_shutdown_mode_state(
        TIME_t local_time, TIME_t *start_time)
{
    SYSTEM_MODE_STATE_e system_mode = system_mode_operational_s;
    return system_mode;
}
/** @brif  safe system mode.
 *
 *  @details this function used for safe system mode status.
 *
 *  @param TIME_t
 *
 *  @param TIME_t *
 *
 *  @return SYSTEM_MODE_STATE_e
 */
static SYSTEM_MODE_STATE_e system_mode_safe_mode_state(TIME_t local_time,
                                                       TIME_t *start_time)
{
    SYSTEM_MODE_STATE_e system_mode = system_mode_operational_s;
    return system_mode;
}

/*================== Extern Function Implementations ========================*/
/**
 *  @brif system mode task.
 *
 *  @details this function used for system mode.
 *
 *  @param TIME_t
 *
 *  @return SYSTEM_MODE_STATE_e
 */
SYSTEM_MODE_STATE_e system_mode_task(TIME_t local_time)
{

    static TIME_t start_time = { .up_time_ms = 0U, .sec = 0U };
    switch (g_system_mode.next)
    {
    case system_mode_initialisation_s:
        g_system_mode.next = system_mode_init_mode_state(local_time, &start_time);
        g_system_mode.sys_ready = FALSE;
        break;
    case system_mode_configuration_s:
        g_system_mode.next = system_mode_configuration_mode_state(local_time,
                                                                  &start_time);
        g_system_mode.sys_ready = FALSE;
        break;
    case system_mode_warmup_s:
        g_system_mode.next = system_mode_warmup_mode_state(local_time,
                                                           &start_time);
        g_system_mode.sys_ready = FALSE;
        break;
    case system_mode_pre_operational_s:
        g_system_mode.next = system_mode_preoperational_state(local_time,
                                                              &start_time);
        g_system_mode.sys_ready = FALSE;
        break;
    case system_mode_operational_s:
        g_system_mode.next = system_mode_operational_state(local_time,
                                                           &start_time);
        g_system_mode.sys_ready = TRUE;
        break;
    case system_mode_obd_s:
        g_system_mode.next = system_mode_obd_mode_state(local_time,
                                                        &start_time);
        g_system_mode.sys_ready = TRUE;
        break;
    case system_mode_degraded_s:
        g_system_mode.next = system_mode_degraded_mode_state(local_time,
                                                             &start_time);
        g_system_mode.sys_ready = TRUE;
        break;
    case system_mode_secure_shutdown_s:
        g_system_mode.next = system_mode_secure_shutdown_mode_state(
                local_time, &start_time);
        g_system_mode.sys_ready = TRUE;
        break;
    case system_mode_safe_s:
        g_system_mode.next = system_mode_safe_mode_state(local_time,
                                                         &start_time);
        g_system_mode.sys_ready = TRUE;
        break;
    default:
        /* Nothing to do*/
        break;

    }
    return g_system_mode.next;
}
/**
 *  @brif init system mode.
 *
 *  @details this function used for initialize system mode.
 *
 *  @param void
 *
 *  @return void
 */
void system_mode_init(void)
{
    g_system_mode.next = system_mode_sna_s;
    g_system_mode.sys_ready  = FALSE;
}
/**
 *  @brif configuration system mode.
 *
 *  @details this function used for configuration system mode.
 *
 *  @param void
 *
 *  @return void
 */
void system_mode_cfg(void)
{
    g_system_mode.next = system_mode_initialisation_s;
}
/**
 *  @brif get system mode.
 *
 *  @details this function used for get system mode.
 *
 *  @param void
 *
 *  @return SYSTEM_MODE_STATE_e *
 */
SYSTEM_MODE_STATE_s* system_mode_get(void)
{
    return &g_system_mode;
}
/*================== END MODULE ==============================================*/
