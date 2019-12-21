CC=gcc
OBJECTS_MAIN_txt=txtfind.o
OBJECTS_LIB_txt=txtfindHelp.o
OBJECTS_MAIN_sort=isort.o
OBJECTS_LIB_sort=isortH.o
FLAGS= -Wall -g

all: txtfindHelpL txtfind isortHL isort

txtfind:  $(OBJECTS_MAIN_txt)
	$(CC) $(FLAGS) -o txtfind $(OBJECTS_MAIN_txt) ./libtxtfindHelp.so

txtfindHelpL: libtxtfindHelp.so

libtxtfindHelp.so: $(OBJECTS_LIB_txt)
	$(CC) -shared -o libtxtfindHelp.so $(OBJECTS_LIB_txt)    

txtfindHelp.o: txtfindHelp.c txtfindHelp.h
	$(CC) $(FLAGS) -fPIC -c txtfindHelp.c
txtfind.o: txtfind.c txtfindHelp.h
	$(CC) $(FLAGS) -c txtfind.c 

isort:  $(OBJECTS_MAIN_sort)
	$(CC) $(FLAGS) -o isort $(OBJECTS_MAIN_sort) ./libisortH.so

isortHL: libisortH.so

libisortH.so: $(OBJECTS_LIB_sort)
	$(CC) -shared -o libisortH.so $(OBJECTS_LIB_sort)    

isortH.o: isortH.c isortH.h
	$(CC) $(FLAGS) -fPIC -c isortH.c
isort.o: isort.c isortH.h
	$(CC) $(FLAGS) -c isort.c 


.PHONY: clean all

clean:
	rm -f *.o *.a *.so txtfind isort

