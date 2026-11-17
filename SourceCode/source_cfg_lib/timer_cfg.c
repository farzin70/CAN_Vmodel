/**
 * @file    timer_cfg.c
 * @author  yousefian
 * @date    12.17.2020 (date of creation)
 * @ingroup CFG
 * @prefix  timer_cfg
 *
 * @brief   timer configuration
 *
 *
 */
/*================== Includes ===============================================*/
#include "device/device.h"
#include "include_driver_lib/cputimer.h"
#include "include_driver_lib/interrupt.h"
#include "include_cfg_lib/timer_cfg.h"
/*================== Macros and Definitions =================================*/
#define TIMER0_PERIOD 1E3
#define TIMER1_PERIOD 10E3
#define TIMER2_PERIOD 21474836.475
/*================== Static Constant and Variable Definitions ===============*/
/*================== Extern Constant and Variable Definitions ===============*/
/*================== Static Function Prototypes =============================*/
#if TIMER0_ENABLE
__interrupt void timer_cfg_timer0_isr(void);
#endif
#if TIMER1_ENABLE
__interrupt void timer_cfg_timer1_isr(void);
#endif
#if TIMER2_ENABLE
__interrupt void timer_cfg_timer2_isr(void);
#endif
static void timer_cfg_init(void);
static void timer_cfg_set(uint32_t, float, float);
/*================== Static Function Implementation =========================*/
/**
 * @brief   CPU TIME INIT
 *
 * @details This function is used to initialize cpu timer
 *
 * @param   void
 *
 * @return  void
 */
static void timer_cfg_init(void)
{
#if TIMER0_ENABLE
	CPUTimer_setPeriod(CPUTIMER0_BASE, 0xFFFFFFFF);
	CPUTimer_setPreScaler(CPUTIMER0_BASE, 0);
	CPUTimer_stopTimer(CPUTIMER0_BASE);
	CPUTimer_reloadTimerCounter(CPUTIMER0_BASE);
#endif
#if TIMER1_ENABLE
	CPUTimer_setPeriod(CPUTIMER1_BASE, 0xFFFFFFFF);
	CPUTimer_setPreScaler(CPUTIMER1_BASE, 0);
	CPUTimer_stopTimer(CPUTIMER1_BASE);
	CPUTimer_reloadTimerCounter(CPUTIMER1_BASE);
#endif
#if TIMER2_ENABLE
	CPUTimer_setPeriod(CPUTIMER2_BASE, 0xFFFFFFFF);
	CPUTimer_setPreScaler(CPUTIMER2_BASE, 0);
	CPUTimer_stopTimer(CPUTIMER2_BASE);
	CPUTimer_reloadTimerCounter(CPUTIMER2_BASE);
#endif

}

/**
 * @brief   CPU TIMER SET PERIOD
 *
 * @details configCPUTimer - This function initializes the selected timer to the period specified by the "freq" and "period" parameters. The "freq" is
 * entered as Hz and the period in uSeconds. The timer is held in the stopped state after configuration
 *
 * @param   uint32_t cpuTimer, float freq, float period
 *
 * @return  void
 */
static void timer_cfg_set(uint32_t cpuTimer, float freq, float period)
{
	uint32_t temp;
	temp = (uint32_t)(freq / 1000000 * period);
	CPUTimer_setPeriod(cpuTimer, temp);
	CPUTimer_setPreScaler(cpuTimer, 0);
	CPUTimer_stopTimer(cpuTimer);
	CPUTimer_reloadTimerCounter(cpuTimer);
	CPUTimer_setEmulationMode(cpuTimer, CPUTIMER_EMULATIONMODE_RUNFREE);
	CPUTimer_enableInterrupt(cpuTimer);
}

#if TIMER0_ENABLE
/**
 * @brief  ISR CPU TIMER0
 *
 * @details This function is used to isr cpu timr0
 *
 * @param   void
 *
 * @return  void
 */
__interrupt void timer_cfg_timer0_isr(void)
{
	system_time_update();
	Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP1);
}
#endif
#if TIMER1_ENABLE
/**
 * @brief  ISR CPU TIMER1
 *
 * @details This function is used to isr cpu timr1
 *
 * @param   void
 *
 * @return  void
 */
__interrupt void timer_cfg_timer1_isr(void)
{

}
#endif
#if TIMER2_ENABLE
/**
 * @brief  ISR CPU TIMER2
 *
 * @details This function is used to isr cpu timr2
 *
 * @param   void
 *
 * @return  void
 */
__interrupt void timer_cfg_timer2_isr(void)
{
	Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP2);
}
#endif
/*================== Extern Function Implementations ========================*/
/**
 * @brief  CONFIG ALL CPU TIMER
 *
 * @details This function is used to configuration all CPU timer.
 *
 * @param   void
 *
 * @return  void
 */
void timer_cfg_timer(void)
{

#if TIMER0_ENABLE
	Interrupt_register(INT_TIMER0, &timer_cfg_timer0_isr);
#endif
#if TIMER1_ENABLE
	Interrupt_register(INT_TIMER1, &timer_cfg_timer1_isr);
#endif
#if TIMER2_ENABLE
	Interrupt_register(INT_TIMER2, &timer_cfg_timer2_isr);
#endif

	timer_cfg_init();

#if TIMER0_ENABLE
	timer_cfg_set(CPUTIMER0_BASE, DEVICE_SYSCLK_FREQ, TIMER0_PERIOD);
	CPUTimer_enableInterrupt(CPUTIMER0_BASE);
	Interrupt_enable(INT_TIMER0);
	CPUTimer_startTimer(CPUTIMER0_BASE);
#endif
#if TIMER1_ENABLE
	timer_cfg_set(CPUTIMER1_BASE, DEVICE_SYSCLK_FREQ, TIMER1_PERIOD);
	CPUTimer_enableInterrupt(CPUTIMER1_BASE);
	//      Interrupt_enable(INT_TIMER1);
	CPUTimer_startTimer(CPUTIMER1_BASE);
#endif
#if TIMER2_ENABLE
	timer_cfg_set(CPUTIMER2_BASE, DEVICE_SYSCLK_FREQ, TIMER2_PERIOD);
	CPUTimer_enableInterrupt(CPUTIMER2_BASE);
	Interrupt_enable(INT_TIMER2);
	CPUTimer_startTimer(CPUTIMER2_BASE);
#endif

}
/**
 * @brief  get timer counter
 *
 * @details This function is used to get timer counter
 *
 * @param   uint32_t base
 *
 * @return  uint32_t
 */
uint32_t timer_cfg_get_timer_counter(uint32_t base)
{

	return (0xFFFFFFFFU - CPUTimer_getTimerCount(base));
}
/**
 * @brief  get diff time
 *
 * @details This function is used to calculate time from counter value.
 *
 * @param   uint32_t counter_before
 * @param   uint32_t counter_after
 *
 * @return  uint32_t
 */
uint32_t timer_cfg_diff_counter_ns(uint32_t counter_before,
		uint32_t counter_after)
{

	uint32_t counter_diff = 0U;
	uint32_t result = 0U;
	uint32_t timer_per = 5U;	//1e9 / DEVICE_SYSCLK_FREQ

	if(counter_before < counter_after) {
		counter_diff = counter_after - counter_before;
	} else {
		counter_diff = (0xFFFFFFFFU - counter_before) + counter_after;

	}
	result = counter_diff * timer_per;

	return (result);
}
/**
 * @brief  get diff time
 *
 * @details This function is used to calculate time from counter value.
 *
 * @param   uint32_t counter_before
 * @param   uint32_t counter_after
 *
 * @return  uint32_t
 */
uint32_t timer_cfg_diff_counter_ms(uint32_t counter_before,
		uint32_t counter_after)
{

	uint32_t counter_diff = 0U;
	uint32_t result = 0U;
	float32_t timer_per = 1e3 / DEVICE_SYSCLK_FREQ;

	if(counter_before < counter_after) {
		counter_diff = counter_after - counter_before;
	} else {
		counter_diff = (0xFFFFFFFFU - counter_before) + counter_after;

	}
	counter_diff = (float32_t)counter_diff * timer_per;
	result = (uint32_t)counter_diff;

	return (result);
}
