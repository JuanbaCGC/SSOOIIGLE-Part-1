/************************************************************************
* Project			: Practica 2 de Sistemas Operativos II
*
* Program name			: practica2.cpp
*
* Author			: Juan Bautista Castaño García-Cervigón
*
* Date created:		: 22/03/2021
*
* Purpose			: The program will take: a file .txt, the word that
*				  that is going to be search along the .txt and the
*				  number of threads that are going to take part. 
*				  Finally the program will show the results of the
*				  coincidences.
*				
* Revision History :
*
* Date		Author		Ref		Revision
*
*
/************************************************************************/

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <thread>
#include <vector>
#include <functional>
#include <algorithm>
#include <queue>
#include <mutex>
#include <signal.h>
#include "searchLibrary.h"

/* Methods declared */
void parameterControl(int arguments);
void createThreads(int threads, string searched_word, std::vector<std::string> arrayLine, int size_task);
void installSignalHandler();
void signalHandler(int sig);

std::vector<std::thread> vthreads; /* Vector where the threads are going to be stored */

int main(int argc, char * argv[]){
	installSignalHandler();
	char *file= argv[1];
	char *word = argv[2];
	std::string searched_word(word);
	int threads = atoi(argv[3]), size_task;
	
	parameterControl(argc);

	std::vector<std::string> arrayLine = openFile(file);
	
	arrayLine.erase(arrayLine.end());			/* Delete the last line of the file */
	
	size_task = arrayLine.size() / threads;		
	createThreads(threads, searched_word, arrayLine, size_task);
	showPriorityQueue();
}

/* Method that control if the parameters are correct or not */
void parameterControl(int arguments){
	if(arguments != 4){
		std::cout << "\e[0;31mError, you have to introduce the file .txt, the searched word and the number of threads..." << std::endl;
		exit(-1);
	}
}

/* Method that create the threads that are going to "divide" the text */
void createThreads(int threads, std::string searched_word, std::vector<std::string> arrayLine, int size_task){
	if(size_task < 1){			/* If the number of threads is bigger than the number of lines... */
		size_task = 1;			/* The number of threads now are the number of lines */
		threads = arrayLine.size();
	}
	for(int i = 0; i < threads;i++){ 	/* We are going to create the threads */
		int begin = size_task*i;
		int end = (begin + size_task)-1;
		if( i == threads -1)
			end = arrayLine.size()-1;
		CThread c (i, begin, end);
		vthreads.push_back(std::thread(findLinesBetweenLimits, begin, end, arrayLine, searched_word,i+1));
	}
	std::for_each(vthreads.begin(), vthreads.end(), std::mem_fn(&std::thread::join)); /* Threads finalize  */
}

/* Method that install the signal handler */
void installSignalHandler(){
	if(signal(SIGINT,signalHandler) == SIG_ERR){
		std:: cout << "\e[0;31mError installing the signal handler" << std::endl;
	}
}

/* Method that capture the Ctrl+c signal */
void signalHandler(int sig){
	std::cout << std::endl << "\e[0;32mCtrl+c signal received" << std::endl;
	std::for_each(vthreads.begin(), vthreads.end(), std::mem_fn(&std::thread::detach));
	exit(-1);
}
