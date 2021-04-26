DIROBJ := obj/
DIREXE := exec/
DIRHEA := include/
DIRSRC := src/

CFLAGS := -I$(DIRHEA) -pthread -std=c++11
FILES := $(DIRSRC)CThread.cpp $(DIRSRC)CSearch.cpp $(DIRSRC)compareFunction.cpp $(DIRSRC)searchLibrary.cpp
CC := g++

all: dirs SSOOIIGLE main execute1

dirs:
	mkdir -p $(DIREXE) $(DIROBJ)

SSOOIIGLE:
	$(CC)  $(DIRSRC)SSOOIIGLE.cpp -o $(DIROBJ)SOOIIGLE.o $(FILES) $(CFLAGS)  

main:
	$(CC) -o $(DIREXE)SSOOIIGLE $(DIRSRC)SSOOIIGLE.cpp $(FILES) -pthread -std=c++11	
	
execute1:
	$(DIREXE)SSOOIIGLE 17-LEYES-DEL-TRABJO-EN-EQUIPO.txt ley 200

execute2:
	$(DIREXE)SSOOIIGLE VIVE-TU-SUEÑO.txt preguntas 50
	
clean:
	rm -r $(DIREXE) $(DIROBJ)
