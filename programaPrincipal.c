#include <stdio.h>

#include "CalidadSueño.h"
#include "listaEstudiantes.h"
#include "listaordenadavecinos.h"


void leerCalidadDelSueño(calidadDelSueño *);
void determinarCalidadSueño(listaOrdenadaVecinos , calidadDelSueño *);
void imprimirResultados(calidadDelSueño, listaOrdenadaVecinos);
void compruebaDatos(listaEstudiantes *,int );
void depuraListaEstudiantes(listaEstudiantes*,int);


int main(void)
{
    calidadDelSueño CalidadDelSueño;
    listaEstudiantes lista;
    listaOrdenadaVecinos listaVecinos;

    int opcion, numVecinos_K;


    do
    {
        printf("------------MENU------------\n");
        printf("\t1 - Cargar dataset\n");
        printf("\t2 - Introducir la calidad del sueño\n");
        printf("\t3 - Normalizar datos (Debe haberse realizado los pasos 1 y 2)\n");
        printf("\t4 - Introducir/cambiar el numero de vecinos\n");
        printf("\t5 - Comprobar calidad del Sueño\n");
        printf("\t6 - Introducir calidad del sueño al dataset\n");
        printf("\t7 - Comprobar efectividad del dataset\n");
        printf("\t8 - Depurar lista\n");
        printf("\t9 - Imprimir dataset\n");
        printf("\t10 - Salir.\n");




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

            case 3:
                normalizar(&lista, &calidadDelSueño);
                printf("Datos normalizados\n\n"):

            case 4:
                printf("Introduce un valor para k (k > 0) que representa el numero de vecinos: \n");
                scanf("%d", &numVecinos_K)

                while(numVecinos_K <= 0)
                {
                    printf("ERROR - Introduce un valor mayor que 0: ");
                    scanf("%d",&numVecinos_K);
                }

                printf("\n\n");

            case 5:
                iniciarlistavecinos(&listaVecinos);
                listaVecinos = distanciaminima(calidadDelSueño, lista, numVecinos_K);
                determinarCalidadSueño(&listaVecinos, &CalidadDelSueño);
                imprimirResultados(CalidadDelSueño, listaVecinos);

                printf("\n\n");

            case 6:
                añadirDato(&lista, &calidadDelSueño);

                printf("\n\n");

            case 7:
                compruebaDatos(&lista,numVecinos_K);
                printf("\n\n");

            case 8:
                depuraListaEstudiantes(&lista,numVecinos_K);
                printf("\n\n");

            case 9:
                imprimeListaEntera(lista);
                printf("\n\n");

            case 10:
                printf("\n\tSaliendo del programa\n");
                Nodo *borrar;
                borrar = lista.primero;
                while (borrar != NULL)
                {
                    desencolar (&lista);
                    borrar = borrar->siguiente;
                }

                celdavecino *vecinito;

                while (!estavacia(listaVecinos))
                {
                    vecinito = listaVecinos.primero;
                    listaVecinos.primero = listaVecinos.primero->siguiente;
                    free(vecinito);
                }

				break;



            default:
                printf("\nERROR: La opcion seleccionada no esta entre las opciones, vuelva a intentarlo.\n");


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

    printf("Introduce su genero (Mujer = 0 || Hombre = 1): ");
    scanf("%d",&CS -> genero);
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





void determinarCalidadSueño(listaOrdenadaVecinos l, calidadDelSueño *CS)
{
    CS -> calidad_sueño = mediaVecinos(l);
    printf("La calidad de sueño del estudiante es: %d\n", CS -> calidad_sueño);

    printf("\n");
}

void imprimirResultados(calidadDelSueño CS, listaOrdenadaVecinos l)
{
    printf("El nivel de calidad de sueño a comprobar ha resultado ser: %d\n", mediaVecinos(l));
    celdavecino * auxiliar;
    auxiliar = l.primero;
    int i = 1;
    while (auxiliar != NULL){
        printf("La distancia a la calidad de sueño %d mas cercano ha sido %f y en el dataset pertenece a la posicion %d: \n", i, auxiliar->distancia,  auxiliar ->id);
        imprimeDato(auxiliar->celdaEstudiantes->dato);
        auxiliar = auxiliar -> siguiente;
        i++;
        printf ("----------------------------------------------------------------------------------\n");
    }

}


void compruebaDatos(listaEstudiantes *l,int K)
{




}


void depuraListaEstudiantes(listaEstudiantes*,int)
{
    listaEstudiantes listaAuxiliar;
    listaOrdenadaVecinos vecinos;





}






