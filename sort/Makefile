#---------------#
# INSTRUCCIONES #
#---------------#

# "make run" ejecuta el programa.
# "make valgrind" ejecuta los test con valgrind.
# "make debug" ejecuta el programa con gdb.
# "make clean" elimina los *.o y el ejecutable.

#-----------#
# VARIABLES #
#-----------#

# CC es el compilador que vamos a usar.
# Tambien se podria usar el compilador "cclang" o algun otro.
CC = gcc

# CCFLAGS son los flags que usaremos para compilar el programa.
# Para eliminar los mensajes de debug usar "-DNDEBUG".
CCFLAGS = -Wall -Wextra -Werror -pedantic -std=c99 -g

#VFLAGS son los flags que usaremos para correr valgrind.
VFLAGS = --show-reachable=yes --leak-check=full --tool=memcheck --track-origins=yes

# Los archivos *.o necesarios para la cración del BINARY.
OBJECTS = array_helpers.o sort_helpers.o sort.o

# Estos HEADERS son los que se buscaran.
HEADERS = array_helpers.h sort_helpers.h sort.h

# El archivo BINARY va a ser el ejecutable.
BINARY = main

#-----------#
# OBJETIVOS #
#-----------#

# Si uno solo escribe "make", se ejecuta all, ya que es el primer objetivo que aparece en el Makefile.
all: clean $(BINARY)

# Todos los archivos *.o se crearan en la carpeta principal.
# Los archivos *.c los buscara en el directorio raiz.
# % es la forma que tiene el Makefile de hacer *, p.e. %.c es igual a *.c
# $? es una variable que en el momento que haga falta de reemplazara por %.c
%.o: %.c
	$(CC) $(CCFLAGS) -c $?

# $? funciona igual que antes, se reemplazara por main.c $(OBJECTS).
# $@ se reemplaza por el objetivo, en este caso "main".
main: main.c $(OBJECTS)
	$(CC) $(CCFLAGS) -o $@ $?

run: $(BINARY)
	./main $(filter-out $@, $(MAKECMDGOALS))

valgrind: $(BINARY)
	valgrind $(VFLAGS) ./main $(filter-out $@, $(MAKECMDGOALS))

debug: $(BINARY)
	gdb ./main $(filter-out $@, $(MAKECMDGOALS))

clean:
	rm -f $(BINARY) $(OBJECTS) *.gch *.gdb_history