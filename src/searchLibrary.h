/************************************************************************
* Project			: Practica 2 de Sistemas Operativos II
*
* Program name			: searchLibrary.h
*
* Author			: Juan Bautista Castaño García-Cervigón
*
* Date created:		: 13/04/2021
*
* Purpose			: File where the functions of the 
*				  searchLibrary are showed. The methos will
*				  help to handle with the .txt and find the
*				  coincidences.
*				  			
* Revision History :
*
* Date		Author		Ref		Revision
*
*
/************************************************************************/

#include <stdio.h>
#include <string>
#include <queue>
#include "compareFunction.h"

/* Method that open the file and return a vector with all the lines of the text */
std::vector<std::string> openFile(char *file);

/* Methot that convert the line in a string vector that each position is a word of the line */
std::vector<std::string> split(std::string str);

/* Method that convert a string int the same string with upper case */
std::string convertString(std::string s);

/* Method that call findWordInLine for each line of each thread */
void findLinesBetweenLimits(int lower, int upper, std::vector<std::string> arrayLine, std::string word, int thread_id);

/* Method that compare all the words of a line */
void findWordInLine(vector<std::string> string_vector ,std::string palabra, int id_linea, int thread_id, int lower, int upper);

/* Function that compare two words and it return true if the words are the same */
bool compareWords(std::string word, std::string result);

/* Function that will show the content of the priority queue */
void showPriorityQueue();
