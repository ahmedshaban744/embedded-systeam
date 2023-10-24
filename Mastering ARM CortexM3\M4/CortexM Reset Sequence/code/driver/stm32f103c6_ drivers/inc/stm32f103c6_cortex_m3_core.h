/*
 * stm32f103c6_cortex_m3_core.h
 *
 *  Created on: Oct 24, 2023
 *      Author: Ahmed
 */

#ifndef INC_STM32F103C6_CORTEX_M3_CORE_H_
#define INC_STM32F103C6_CORTEX_M3_CORE_H_
enum  user_level {Privileged,UnPrivileged};
/*
 * =================================================================================
 * APIs Supported by
 * =================================================================================
 */
void swich_CPU_access_user_level(enum user_level level);
#endif /* INC_STM32F103C6_CORTEX_M3_CORE_H_ */
