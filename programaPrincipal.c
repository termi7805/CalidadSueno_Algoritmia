#include <stdio.h>

#include "CalidadSueño.h"
#include "listaEstudiantes.h"
#include "listaordenadavecinos.h"


void leerCalidadDelSueño(calidadDelSueño *);

int main(void)
{
    calidadDelSueño CalidadDelSueño;
    listaEstudiantes lista;
    listaOrdenadaVecinos listaVecinos;

    int opcion;


    do
    {
        printf("------------MENU------------\n");
        printf("\t1 - Cargar dataset\n");
        printf("\t2 - Introducir la calidad del sueño\n");


        printf("Escoja una opcion: ");
        scanf("%d",&opcion);

		switch(opcion)
        {
            case 1:
                printf("Por favor introduce el nombre del dataset\n");  //acabado en txt ¿?
				lista = cargarDatos();
                printf("El dataset ha sido cargado correctamente\n\n");


            case 2:
                leerCalidadDelSueño(&calidadDelSueño);
                printf("Se ha cargado la calidad del sueño\n\n;);


        }


    }while(opcion != );



    return 0;
}



void leeNivelEstres(NivelEstres * CS)
{
    printf("introduzca su edad: ");
    scanf("%d",&CS -> edad);
    printf("\n");

    printf("Introduca su genero: ");
    scanf("%s",&CS -> genero);


    printf("Introduca );



}






