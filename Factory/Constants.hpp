/*
 * Constants.hpp
 *
 *  Created on: Feb 13, 2018
 *      Author: lfani
 */

#ifndef FACTORY_CONSTANTS_HPP_
#define FACTORY_CONSTANTS_HPP_

#define null (0U)

//Time defines
#define TIME_1_MICROSECOND (1U)
#define TIME_10_MICROSECONDS (10U)
#define TIME_100_MICROSECONDS (100U)
#define TIME_1_MILLISECOND (1000U)
#define TIME_500_MILLISECONDS (500000U)
#define TIME_1_SECOND (10000000U)

enum GPIO_BANK{A, B, C, D, E, F};
enum STATES_GLOBAL{CREATED, INPUT, OUTPUT, CONFIGURED, DELETED};

#endif /* FACTORY_CONSTANTS_HPP_ */
