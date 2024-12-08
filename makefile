all: CalidadSueño listaEstudiantes listaordenadavecinos algoritmoWilson main

CalidadSueño: CalidadSueño.c
	gcc -Wall -c CalidadSueño.c

listaEstudiantes: listaEstudiantes.c
	gcc -Wall -c listaEstudiantes.c
	
listaordenadavecinos: listaordenadavecinos.c
	gcc -Wall -c listaordenadavecinos.c

algoritmoWilson: algoritmoWilson.c
	gcc -Wall -c algoritmoWilson.c

main: analizadorCalidad.c CalidadSueño.o listaEstudiantes.o listaordenadavecinos.o algoritmoWilson.o
	gcc -Wall -o analizadorCalidad analizadorCalidad.c CalidadSueño.o listaEstudiantes.o listaordenadavecinos.o algoritmoWilson.o -lm
