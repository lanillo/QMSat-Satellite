/*
 * IGPIO.hpp
 *
<<<<<<< HEAD
 *  Created on: 2018-02-14
 *      Author: Guillaume
=======
 *  Created on: Feb 13, 2018
 *      Author: lfani
>>>>>>> GPIO
 */

#ifndef INCLUDE_INTERFACE_IGPIO_HPP_
#define INCLUDE_INTERFACE_IGPIO_HPP_

class IGPIO
{
public:
	IGPIO() {};
	virtual ~IGPIO() {};

	virtual void turnOFF() = 0;
	virtual void turnON() = 0;
	virtual void toggle() = 0;
};

#endif /* INCLUDE_INTERFACE_IGPIO_HPP_ */
