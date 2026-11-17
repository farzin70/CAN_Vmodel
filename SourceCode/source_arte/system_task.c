/**
 * @file    system_task.c
 *
 * @author  yousefian
 *
 * @date    12.17.2020 (date of creation)
 *
 * @ingroup SOURCE APP
 *
 * @prefix  system_task.c
 *
 * @brief   this file used for system task scheduling
 */
/*================== Includes ===============================================*/
#include "include_arte/system_task.h"
#include "include_app/can_transport/can_read.h"
#include "include_app/can_management/cana_tx_manage.h"
#include "include_app/can_management/canb_tx_manage.h"
#include "include_cfg_lib/timer_cfg.h"
#include "include_arte/system_mode.h"
/*================== Macros and Definitions =================================*/
/*================== Static Constant and Variable Definitions ===============*/
static SYSTEM_TASK_INF_s g_task_info[TASK_NUMBER + 1];
/*================== Extern Constant and Variable Definitions ===============*/
/*================== Static Function Prototypes =============================*/
static void system_task_1m(TIME_t local_time);
static void system_task_4m(TIME_t local_time);
static void system_task_5m(TIME_t local_time);
static void system_task_8m(TIME_t local_time);
static void system_task_10m(TIME_t local_time);
static void system_task_100m(TIME_t local_time);
static void system_task_1s(TIME_t local_time);
/*================== Static Function Implementation =========================*/
/**
 * @brief   task scheduling Idle
 *
 * @details This function is used to task scheduling(1ms).
 *
 * @param   TIME_t time
 *
 * @return  void
 */
static void system_task_idle(TIME_t local_time)
{
    SYSTEM_MODE_STATE_s *system_mode = system_mode_get();
    system_time_check_update();
    (void) cana_tx_manage_task(local_time);
    (void) canb_tx_manage_task(local_time);
    can_read_all(local_time);

}
/**
 * @brief   task scheduling 1 ms
 *
 * @details This function is used to task scheduling(1ms).
 *
 * @param   TIME_t time
 *
 * @return  void
 */
static void system_task_1m(TIME_t local_time)
{
    SYSTEM_MODE_STATE_s *system_mode = system_mode_get();

}
/**
 * @brief   task scheduling 5 ms
 *
 * @details This function is used to task scheduling(5ms).
 *
 * @param   TIME_t time
 *
 * @return  void
 */
static void system_task_4m(TIME_t local_time)
{
    SYSTEM_MODE_STATE_s *system_mode = system_mode_get();

}
/**
 * @brief   task scheduling 5 ms
 *
 * @details This function is used to task scheduling(5ms).
 *
 * @param   TIME_t time
 *
 * @return  void
 */
static void system_task_5m(TIME_t local_time)
{
    SYSTEM_MODE_STATE_s *system_mode = system_mode_get();

}
/**
 * @brief   task scheduling 8 ms
 *
 * @details This function is used to task scheduling(8ms).
 *
 * @param   TIME_t time
 *
 * @return  void
 */
static void system_task_8m(TIME_t local_time)
{
    SYSTEM_MODE_STATE_s *system_mode = system_mode_get();

}
/**
 * @brief   task scheduling 10 ms
 *
 * @details This function is used to task scheduling(10ms).
 *
 * @param   TIME_t time
 *
 * @return  void
 */
static void system_task_10m(TIME_t local_time)
{
    SYSTEM_MODE_STATE_s *system_mode = system_mode_get();



}

/**
 * @brief   task scheduling 100 ms
 *
 * @details This function is used to task scheduling(100ms).
 *
 * @param   TIME_t time
 *
 * @return  void
 */
static void system_task_100m(TIME_t local_time)
{
    SYSTEM_MODE_STATE_s *system_mode = system_mode_get();

}
/**
 * @brief   task scheduling 500 ms
 *
 * @details This function is used to task scheduling(100ms).
 *
 * @param   TIME_t time
 *
 * @return  void
 */
static void system_task_1s(TIME_t local_time)
{
    SYSTEM_MODE_STATE_s *system_mode = system_mode_get();
}
/**
 * @brief   task scheduling 500 ms
 *
 * @details This function is used to task scheduling(100ms).
 *
 * @param   TIME_t time
 *
 * @return  void
 */
static void system_task_execute(void (*task)(TIME_t local_time), uint16_t task_num)
{
    TIME_t global_time = system_time_get_time();
    g_task_info[task_num].start_time_ns = timer_cfg_get_timer_counter(
            CPUTIMER2_BASE);
    task(global_time);
    g_task_info[task_num].execution_time_ns = timer_cfg_diff_counter_ns(
            g_task_info[task_num].start_time_ns,
            timer_cfg_get_timer_counter(CPUTIMER2_BASE));
}
/*================== Extern Function Implementations ========================*/
/**
 * @brief   task scheduling 100 ms
 *
 * @details This function is used to task scheduling(100ms).
 *
 * @param   void
 *
 * @return  void
 */
void system_task_scheduler(void)
{
    system_task_execute(system_task_idle, 0U);
    if (TIME1MS < TASK_001MS_TIME)
    {
        TASK_001MS_TIME = 0;
        system_task_execute(system_task_1m, 1U);
    }

    if (TIME4MS < TASK_004MS_TIME)
    {
        TASK_004MS_TIME = 0;
        system_task_execute(system_task_4m, 2U);
    }

    if (TIME5MS < TASK_005MS_TIME)
    {
        TASK_005MS_TIME = 0;
        system_task_execute(system_task_5m, 3U);
    }

    if (TIME8MS < TASK_008MS_TIME)
    {
        TASK_008MS_TIME = 0;
        system_task_execute(system_task_8m, 4U);
    }

    if (TIME10MS < TASK_010MS_TIME)
    {
        TASK_010MS_TIME = 0;
        system_task_execute(system_task_10m, 5U);
    }

    if (TIME100MS < TASK_100MS_TIME)
    {
        TASK_100MS_TIME = 0;
        system_task_execute(system_task_100m, 6U);
    }
    if (TIME1S < TASK_1S_TIME)
    {
        TASK_1S_TIME = 0;
        system_task_execute(system_task_1s, 7U);
    }

}
/**
 * @brief   system task get global
 *
 * @details This function is used to get system task info.
 *
 * @param   void
 *
 * @return  SYSTEM_TASK_INF_s
 */
void system_task_init(void)
{
    uint16_t index = 0U;
    for(index = 0U ; index <= 7U ;index++)
    {
        g_task_info[index].execution_time_ns = 0U;
        g_task_info[index].start_time_ns = 0U;
    }
}
/**
 * @brief   system task get global
 *
 * @details This function is used to get system task info.
 *
 * @param   void
 *
 * @return  SYSTEM_TASK_INF_s
 */
SYSTEM_TASK_INF_s *system_task_get(void)
{
    return (g_task_info);
}
/*================== END MODULE ==============================================*/
