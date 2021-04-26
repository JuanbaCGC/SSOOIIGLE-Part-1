# SSOOIIGLE-Part-1
Practice for the subject of Operating Systems II.

The objective of this practice is to create a word finder. The method to follow is to create as many threads as the user enters and each thread will search a part of the text. At the end, 
the program has to show the results of the coincidences. 

The user has to introduce 3 parameters, for example: ./executable wikipedia.txt hello 10. In this example the program will search the hello word in the wikipedia.txt and divide the search 
in 10 threads. The threads will have concurrency between them. Is so important that the txt file is in the same directory as the makefile, if it's not, the program will show an error.

This practice has some files in the src folder: SSOOIIGLE.cpp, CSearch (.h and .cpp), CThread (.h and .cpp), searchLibrary (.h and .cpp) and finally compareFunction (.h and .cpp).

Each file has it own function:

 -SSOOIIGLE: main file of the practice. It takes by parameter: a file .txt, the word that is going to be search along the .txt and the number of threads that are going to take part. 
	Finally the program will show the results of the coincidences. If the user introduces more threads than lines has the .txt, the threads will be the same as the number of lines.

 -CSearch: Class where the information of the coincidence will be stored and showed.

 -CThread: Class where the information of the thread that find the coincidenceis going to be stored.
	  
 -searchLibrary: File where the functions of the searchLibrary are showed. The methods will help to handle with the .txt and find the coincidences.

 -compareFunction: file that is going to be used to order the instances of CSearch in the priority queue.

Out of the folder there are other .txt files (to execute the program and find a word in this texts) and a Makefile. Let's explain what can this Makefile do.

How to execute the program? 🤔

I've created a Makefile do in order to divide the program in diferents directories: src, exec, obj... And facilitate the compilation and execution of the program.

The instructions of the make file are: 📖
   1. If you want to make all de directories, compile the program and execute it at the same time, you just have to put: make all. Then, the Makefile will do the rest.
   2. To create the directories, you only have to put: make dirs.
   3. To compile the program you have to insert: make SSOOIIGLE main
   4. To execute the program, you have two options to enter on the command line: make execute1 or make execute2. Each example of execution find differents words in differents .txt. To do this, the exec directory must have the executable (do "make SSOOIIGLE main" before).
   5. If you want to clean all the dirs, just insert: make clean.

Practice made by Juan Bautista Castaño García-Cervigón 👨‍🎓
