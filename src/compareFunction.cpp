/************************************************************************
* Project			: Practica 2 de Sistemas Operativos II
*
* Program name			: compareFunction.cpp
*
* Author			: Juan Bautista Castaño García-Cervigón
*
* Date created:		: 29/03/2021
*
* Purpose			: Class that is going to be used to order
*				  the priority queue. First the instances
*				  of CSearch are going to be ordered by 
*				  the thread id, then by the line id and 
*				  finally by the position in the line.
*				  			
* Revision History :
*
* Date		Author		Ref		Revision
*
*
/************************************************************************/

#include <iostream>
#include <stdlib.h>
#include "compareFunction.h"

/* Method that is going to order the CSearch instances of the priority queue depending on the thread id, the line of the coincidence and the position of the found word on the line */ 
int compareFunction::operator() (CSearch &a,CSearch &b){
	if(a.getThread().getThread_id() == b.getThread().getThread_id()){     	/* If it's the same thread */
		if(a.getLine_id() == b.getLine_id())					/*  If it's the same line id... */	
			return a.getLine_position() > b.getLine_position();		/* The order is the first word in the line */
		else
			return a.getLine_id() > b.getLine_id();			/* Order by the line id */
	}
		return a.getThread().getThread_id() > b.getThread().getThread_id();	/* Order by the thread id */
}
