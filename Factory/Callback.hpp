/*
 * Callback.hpp
 *
 *  Created on: February 14, 2018
 *   Authors: Luis Anillo
 * 			  Guillaume Beaupré.
 *
 *   \brief	????????????????????
 */

#ifndef FACTORY_CALLBACK_HPP_
#define FACTORY_CALLBACK_HPP_

//Those two types are use to allow to use our certain
//object in their interrupt routine

typedef void (*callback)(void* p_Instance);
typedef void (*callback2)(void* p_Instance1, void* p_Instance2);

#endif /* FACTORY_CALLBACK_HPP_ */
