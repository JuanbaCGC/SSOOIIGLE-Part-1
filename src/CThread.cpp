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
*				  is shown.
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

/* Method of the constructor of CThread */
CThread::CThread(int thread_id, int begin, int end){
	this->thread_id = thread_id;
	this->begin = begin;
	this->end = end;
}
		
/* ToString function that shows the information of the CThread */
void CThread::toString(){
	std::cout << "[Hilo " << this->thread_id << " inicio:" << this->begin << " -- final: " << this->end << std::endl;
}

/* Method that return the thread id */		
int CThread::getThread_id(){
	return this->thread_id;
}

/* Method that return the first line that the thread will search */		
int CThread::getBegin(){
	return this->begin;
}
		
/* Method that return the last line that the thread will search */	
int CThread::getEnd(){
	return this->end;
}


