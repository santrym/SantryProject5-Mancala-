CC	= g++


SantryProject5:  Board.o main.o
	$(CC) -o Exacuteit -g Board.o main.o


.cpp.o:	
	$(CC) -c $< -o $@

