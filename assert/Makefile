# on précise le compilateur à utiliser
CC = gcc

# on précise la liste des fichiers objets
OBJ = assertion.o

# on précise les options de compilation
CFLAGS = -std=c11 -Wall -Wextra -pedantic -ggdb
main: $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

# Règle implicite pour la génération des fichiers objet.
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY : clean
clean:
	rm -f main *.o	