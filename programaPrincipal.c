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
                printf("Se ha cargado la calidad del sueño\n\n");


        }


    }while(opcion != );



    return 0;
}



void leeNivelEstres(NivelEstres * CS)
{
    int horas, minutos;
    float tiempo;

    printf("Introduce su edad: ");
    scanf("%d",&CS -> edad);
    printf("\n");

    printf("Introduce su genero: ");
    scanf("%s",&CS -> genero);
    printf("\n");

    printf("Introduce el año de universidad en el que se encuentra: ");
    scanf("%d", &CS -> año_universidad);
    printf("\n");

    printf("Introduce el numero de horas y minutos que has DORMIDO en este formato (horas minutos): ");
    scanf("%d" "%d", &horas, &minutos);
    minutos = ((minutos * 100) / 60) / 100;  // para pasar de minutos a la coma -> 30 mins = 0.50 horas
    CS -> horas_sueño = horas + minutos;
    printf("\n");

    printf("Introduce el numero de horas y minutos que has ESTUDIADO en este formato (horas minutos): ");
    scanf("%d" "%d", &horas, &minutos);
    minutos = ((minutos * 100) / 60) / 100;
    CS -> horas_estudio = horas + minutos;
    printf("\n");

    printf("Introduce el numero de horas y minutos que has ESTADO MIRANDO PANTALLAS en este formato (horas minutos): ");
    scanf("%d" "%d", &horas, &minutos);
    minutos = ((minutos * 100) / 60) / 100;
    CS -> horas_pantalla = horas + minutos;
    printf("\n");

    printf("Introduce los gramos de cafeina que ha tomado: ");
    scanf("%f", &CS -> cafeina);
    printf("\n");

    printf("Introduce cuanta actividad fisica ha hecho (0 = Nada / 100 = Mucha): ")
    scanf("%d", &CS -> actividad_fisica);
    printf("\n");

    printf("Introduce a que hora te sueles acostar en la semana (hora minutos): ");
    scanf("%d" "%d", &horas, &minutos);
    minutos = ((minutos * 100) / 60) / 100;
    CS -> acostar_semana = horas + minutos;
    printf("\n");

    printf("Introduce a que hora te sueles acostar en el fin de semana (hora minutos): ");
    scanf("%d" "%d", &horas, &minutos);
    minutos = ((minutos * 100) / 60) / 100;
    CS -> acostar_finde = horas + minutos;
    printf("\n");

    printf("Introduce a que hora te sueles despertar en la semana (hora minutos): ");
    scanf("%d" "%d", &horas, &minutos);
    minutos = ((minutos * 100) / 60) / 100;
    CS -> despertar_semana = horas + minutos;
    printf("\n");

    printf("Introduce a que hora te sueles despertar en el fin de semana (hora minutos): ");
    scanf("%d" "%d", &horas, &minutos);
    minutos = ((minutos * 100) / 60) / 100;
    CS -> despertar_finde = horas + minutos;
    printf("\n");



}






