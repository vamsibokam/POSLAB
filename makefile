CC= g++
flags = -std=c++11 


main: main.o graphMat.o graph.o tree.o dynarray.o random.o
	$(CC) $(flags) -o main main.o graphMat.o graph.o tree.o dynarray.o random.o

main.o: main.cpp satellite.h tools.h 
	$(CC) $(flags) -c main.cpp satellite.h tools.h


graphMat.o: graphMat.h graphMat.cpp
	$(CC) $(flags) -c graphMat.cpp graphMat.h

graph.o: graph.h graph.cpp
	$(CC) $(flags) -c graph.cpp graph.h

dynarray.o: dynarray.cc dynarray.h
	$(CC) $(flags) -c  dynarray.cc dynarray.h

tree.o: tree.h tree.cc
	$(CC) $(flags) -c tree.cc tree.h

random.o: random.h random.c
	g++ -c random.c random.h

clean:
	rm *.o *.gch main