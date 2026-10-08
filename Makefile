CC = gcc
CFLAGS = -Wall -Wextra -Iinclude
LIBS = -lSDL2

TARGET = morpion

SRC = src/main.c src/morpion.c src/affichage.c
OBJ = src/main.o src/morpion.o src/affichage.o

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET) $(LIBS)

src/main.o: src/main.c include/morpion.h include/affichage.h
	$(CC) $(CFLAGS) -c src/main.c -o src/main.o

src/morpion.o: src/morpion.c include/morpion.h
	$(CC) $(CFLAGS) -c src/morpion.c -o src/morpion.o

src/affichage.o: src/affichage.c include/affichage.h include/morpion.h
	$(CC) $(CFLAGS) -c src/affichage.c -o src/affichage.o

clean:
	rm -f $(OBJ) $(TARGET)
