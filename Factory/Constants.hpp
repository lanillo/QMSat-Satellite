/*
 * Constants.hpp
 *
 *  Created on: Feb 13, 2018
 *      Author: lfani
 */

#ifndef FACTORY_CONSTANTS_HPP_
#define FACTORY_CONSTANTS_HPP_

enum GPIO_BANK{A, B, C, D, E, F};

class Constants
{
public:
	enum GPIO_BANK{A, B, C, D, E, F};
	enum STATES_GLOBAL{CREATED, INPUT, OUTPUT, CONFIGURED, DELETED};

	Constants();
	~Constants();

private:
	int null;
};



#endif /* FACTORY_CONSTANTS_HPP_ */
