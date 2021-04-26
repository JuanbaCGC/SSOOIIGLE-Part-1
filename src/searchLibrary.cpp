/************************************************************************
* Project			: Practica 2 de Sistemas Operativos II
*
* Program name			: searchLibrary.cpp
*
* Author			: Juan Bautista Castaño García-Cervigón
*
* Date created:		: 13/04/2021
*
* Purpose			: File where the functions of the 
*				  searchLibrary are implemented.
*				  			
* Revision History :
*
* Date		Author		Ref		Revision
*
*
/************************************************************************/

#include <stdio.h>
#include <sstream>
#include <fstream>
#include <mutex>
#include "searchLibrary.h"

std::mutex access;					       /* Mutex that will allow to access to only a thread each time */
priority_queue<CSearch, vector<CSearch>,compareFunction> pq; /* Priority queue of CSearch's instances, where the threads will access to instert the CSearch objects */

/* Method that open the file and return a vector with all the lines of the text */
std::vector<std::string> openFile(char *file){	       
	ifstream ifs;
	std::vector<std::string> arrayLine;
	std::string line;
	ifs.open(file, ios::in);
	if(ifs.fail()){
		std::cout << "\e[0;31mEror, the file could not be open" << std::endl;
		exit(-1);
	}
	while(!ifs.eof()){
		getline(ifs, line);
		arrayLine.insert(arrayLine.end(), line);
	}
	return arrayLine;
}

/* Methot that convert the line in a string vector that each position is a word of the line */
std::vector<std::string> split(std::string str){	
	std::vector<std::string> string_vector;
	std::istringstream isstream(str);
	std::string palabra;
	while(isstream >> palabra){
		string_vector.push_back(palabra);
	}
	return string_vector;
}

/* Method that convert a string int the same string with upper case */
std::string convertString(std::string s){	
	for(int i = 0;i<s.length();i++){
		s[i]=toupper(s[i]);
	}
	return s;
}

/* Method that call findWordInLine for each line of each thread */
void findLinesBetweenLimits(int lower_limit, int upper_limit, std::vector<std::string> arrayLine, std::string word, int thread_id){	
	for(int i = lower_limit; i <= upper_limit; i++){
		findWordInLine(split(arrayLine[i]), word, i, thread_id, lower_limit, upper_limit);
	}
}

/* Method that compare all the words of a line */
void findWordInLine(vector<std::string> string_vector ,std::string searched_word, int id_linea, int thread_id, int lower_limit, int upper_limit){ 
	string text;
	searched_word = convertString(searched_word);
	for(int i = 0; i < string_vector.size();i++){
		if(compareWords(searched_word, string_vector[i]) == true) {	
			if(i == 0 && string_vector.size()>1){		/* If the found word is the first word of the line and the line has more than one word... */
				text = string_vector[i] + " " + string_vector[i+1] + " ...";
			}
			else if(string_vector.size() ==1)		/* If there is only a word in the line... */
				text = string_vector[i] + " ...";
			else if(i+1==string_vector.size())		/* If the found word is the last word of the line... */
				text = string_vector[i-1] + " " + string_vector[i] + " ...";
			else 						
				text = string_vector[i-1] + " " + string_vector[i] + " " + string_vector[i+1] + " ...";
			CThread cthread(thread_id, lower_limit, upper_limit);	
			CSearch search(id_linea+1, text, i, cthread);
			std::unique_lock<std::mutex> sem (access);	/* Block of the mutex */
			pq.push(search);
			sem.unlock();					/* Unblock of the mutex */
		}
	}
}

/* Function that compare two words and it return true if the words are the same */
bool compareWords(string word, std::string result){	
	bool coincidence_found = false;
	std::vector<std::string> symbols = {"!","¡","·","$","%","&","/","(",")","=","?","¿",",","^","]","[","-","_","@","*","|",">","<","#","+","{","}","¬",".", ";",":"};
	/* Vector with all the simbols that the searched word could have at the begining or at the end */	
	result = convertString(result);
	for(int i = 0; i < symbols.size() && coincidence_found == false;i++){
		if(result == word ||result == word + symbols[i] || result == symbols[i] + word)
			coincidence_found = true;
	}
	return coincidence_found;
}

/* Function that will show the content of the priority queue */
void showPriorityQueue(){	
	if(pq.empty()){
		std::cout << "\e[0;31mThe searched word is not in the .txt, you can try again with other file." << std::endl;
	}
	while(!pq.empty()){
		CSearch search = pq.top();
		search.toString();
		pq.pop();
	}
}
