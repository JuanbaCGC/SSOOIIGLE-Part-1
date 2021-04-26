/************************************************************************
* Project			: Practica 2 de Sistemas Operativos II
*
* Program name			: CSearch.h
*
* Author			: Juan Bautista Castaño García-Cervigón
*
* Date created:		: 29/03/2021
*
* Purpose			: Class where the information of the coincidence
*				  will be stored and showed.
*				  			
* Revision History :
*
* Date		Author		Ref		Revision
*
*
/************************************************************************/

#include <iostream>
#include <stdlib.h>
#include "CThread.h"
#ifndef CSearch_H
#define CSearch_H

using namespace std;

class CSearch{	
	private:
		int line_id;
		std::string text;
		int line_position;
		CThread c;
	public:
		/* Constructor method of CSearch */
		CSearch(int line_id, std::string text, int line_position,CThread c):line_id{line_id},text{text},line_position{line_position},c{c}{}
		
		/* Method that return the line_id */
		int getLine_id();
		
		/* Method that return the position of the found word in the line */
		int getLine_position();
		
		/* Method that return the CThread */
		CThread getThread();
		
		/* Method that show the information of the CSearch instance */
		void toString();
};

#endif
