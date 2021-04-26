/************************************************************************
* Project			: Practica 2 de Sistemas Operativos II
*
* Program name			: CThread.c
*
* Author			: Juan Bautista Castaño García-Cervigón
*
* Date created:		: 29/03/2021
*
* Purpose			: Class where the information of the thread
*				  that find the coincidenceis going to be 
*				  stored.
*				  		
* Revision History :
*
* Date		Author		Ref		Revision
*
*
/************************************************************************/

#include <iostream>
#include <stdlib.h>
#ifndef CThread_H
#define CThread_H

using namespace std;

class CThread{
	private:
		int thread_id;
		int begin;
		int end;
	public:
		/* Method of the constructor of CThread */
		CThread(int thread_id, int begin, int end);
		
		/* ToString functioin that shows the information of the CThread */
		void toString();
		
		/* Method that return the thread id */
		int getThread_id();
		
		/* Method that return the first line that the thread will search */
		int getBegin();
		
		/* Method that return the last line that the thread will search */
		int getEnd();
};

#endif
