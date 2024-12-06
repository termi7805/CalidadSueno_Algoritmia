all: CalidadSueño listaEstudiantes listaordenadavecinos main

CalidadSueño: CalidadSueño.c
	gcc -Wall -c CalidadSueño.c

listaEstudiantes: listaEstudiantes.c
	gcc -Wall -c listaEstudiantes.c
	
listaordenadavecinos: listaordenadavecinos.c
	gcc -Wall -c listaordenadavecinos.c

algoritmoWilson: algoritmoWilson.c
	gcc -Wall -c algoritmoWilson.c

main: manejador.c CalidadSueño.o listaEstudiantes.o listaordenadavecinos.o
	gcc -Wall -o manejador manejador.c CalidadSueño.o listaEstudiantes.o listaordenadavecinos.o -lm
