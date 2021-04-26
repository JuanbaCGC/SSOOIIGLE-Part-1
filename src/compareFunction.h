/************************************************************************
* Project			: Practica 2 de Sistemas Operativos II
*
* Program name			: compareFunction.h
*
* Author			: Juan Bautista Castaño García-Cervigón
*
* Date created:		: 29/03/2021
*
* Purpose			: Class that is going to be used to order
*				  the priority queue.		
*
* Revision History :
*
* Date		Author		Ref		Revision
*
*
/************************************************************************/

#include <iostream>
#include <stdlib.h>
#include "CSearch.h"
#ifndef compareFunction_H
#define compareFunction_H

class compareFunction{
	public:
		/* Method that is going to order the CSearch instances of the priority queue */ 
		int operator() (CSearch &a,CSearch &b);
};

#endif
