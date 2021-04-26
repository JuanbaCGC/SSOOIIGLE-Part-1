/************************************************************************
* Project			: Practica 2 de Sistemas Operativos II
*
* Program name			: CThread.cpp
*
* Author			: Juan Bautista Castaño García-Cervigón
*
* Date created:		: 29/03/2021
*
* Purpose			: Class where the information of the thread
*				  and the coincidence is shown.				  			
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

#define NC "\e[0m"	/* Defines to display the messages with colours */ 
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define CYN "\e[0;36m"

/* Method that return the line_id */
int CSearch::getLine_id(){
	return this->line_id;
}
		
/* Method that return the position of the found word in the line */
int CSearch::getLine_position(){
	return this->line_position;
}
		
/* Method that return the CThread */
CThread CSearch::getThread(){
	return this->c;
}
		
/* Method that show the information of the CSearch instance */
void CSearch::toString(){		/* Depending on the thread_id, the print will have a colour or other */
	int id = this->c.getThread_id();
	int colour = id%4;
	if(colour == 0){
		std::cout << NC;
	}else if(colour == 1){
		std::cout << RED;
	}else if(colour == 2){
		std::cout << GRN;
	}else if(colour == 3){
		std::cout << CYN;
	}
	std::cout << "[Hilo " << this->c.getThread_id() << " inicio:" << this->c.getBegin() << " -- final: " << this->c.getEnd() << "] :: línea " << this->line_id << " :: ... " << this->text << std::endl;
}

