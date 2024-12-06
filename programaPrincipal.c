#include "listaordenadavecinos.h"
#include <stdlib.h>


void leerCalidadDelSueño(calidadDelSueño *);
void determinarCalidadSueño(listaOrdenadaVecinos , calidadDelSueño *);
void imprimirResultados(calidadDelSueño, listaOrdenadaVecinos);
void compruebaDatos(listaEstudiantes *,int );
//void depuraListaEstudiantes(listaEstudiantes*,int);


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
        printf("\t3 - Introducir/cambiar el numero de vecinos\n");
        printf("\t4 - Comprobar calidad del Sueño\n");
        printf("\t5 - Introducir calidad del sueño al dataset\n");
        printf("\t6 - Comprobar efectividad del dataset\n");
        printf("\t7 - Depurar lista\n");
        printf("\t8 - Imprimir dataset\n");
        printf("\t9 - Salir.\n");

        printf("Escoja una opcion: ");
        scanf("%d",&opcion);

		switch(opcion)
        {
            case 1:
                char fichero[100];
                printf("Por favor introduce el nombre del dataset: ");
                scanf ("%s", fichero);
                FILE *fd;
                while ((fd = fopen(fichero, "r")) == NULL)
                {
                    printf("Error al abrir el fichero, introduce el nombre correctamente: ");
                    scanf("%s", fichero);
                }
                lista = cargarDatos(fd);
                printf("El dataset ha sido cargado correctamente\n\n");

                break;

            case 2:
                leerCalidadDelSueño(&CalidadDelSueño);
                printf("Se ha cargado la calidad del sueño\n\n");

                //Una vez se han cargado todos los datos los normalizados automaticamente
                normalizar(&lista, &CalidadDelSueño);
                printf("Datos normalizados\n\n");

                break;

            case 3:
                printf("Introduce un valor para k (k > 0) que representa el numero de vecinos: \n");
                scanf("%d", &numVecinos_K);

                while(numVecinos_K <= 0)
                {
                    printf("ERROR - Introduce un valor mayor que 0: ");
                    scanf("%d",&numVecinos_K);
                }

                printf("\n\n");

                break;

            case 4:
                iniciarListaVecinos(&listaVecinos);
                listaVecinos = distanciaMinima(CalidadDelSueño, lista, numVecinos_K);
                determinarCalidadSueño(listaVecinos, &CalidadDelSueño);
                imprimirResultados(CalidadDelSueño, listaVecinos);

                printf("\n\n");

                break;

            case 5:
                añadirDato(&lista, CalidadDelSueño);

                printf("\n\n");

                break;

            /*case 6:
                compruebaDatos(&lista,numVecinos_K);
                printf("\n\n");

                break; */

            /*case 7:
                depuraListaEstudiantes(&lista,numVecinos_K);
                printf("\n\n");

                break; */

            case 8:
                imprimeListaEntera(lista);
                printf("\n\n");

                break;

            case 9:
                printf("\n\tSaliendo del programa\n");
                /*celdaEstudiantes *borrar;
                borrar = lista.primero;
                while (borrar != NULL)
                {
                    desencolar (&lista);
                    borrar = borrar->siguiente;
                }

                celdaVecino *vecinito;

                while (!estavacia(listaVecinos))
                {
                    vecinito = listaVecinos.primero;
                    listaVecinos.primero = listaVecinos.primero->siguiente;
                    free(vecinito);
                }
                */
				break;

            default:
                printf("\nERROR: La opcion seleccionada no esta entre las opciones, vuelva a intentarlo.\n");
        }

    } while(opcion != 9);

    return 0;
}


void leerCalidadDelSueño(calidadDelSueño * CS)
{
    int horas, minutos;

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

    printf("Introduce el numero de horas y minutos que has estado MIRANDO PANTALLAS en este formato (horas minutos): ");
    scanf("%d" "%d", &horas, &minutos);
    minutos = ((minutos * 100) / 60) / 100;
    CS -> horas_pantalla = horas + minutos;
    printf("\n");

    printf("Introduce los gramos de cafeina que ha tomado: ");
    scanf("%d", &CS -> cafeina);
    printf("\n");

    printf("Introduce cuanta actividad fisica ha hecho (0 = Nada / 100 = Mucha): ");
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
    celdaVecino * auxiliar;
    auxiliar = l.primero;
    int i = 1;
    while (auxiliar != NULL){
        printf("La distancia a la calidad de sueño %d mas cercano ha sido %f y en el dataset pertenece a la posicion %d: \n", i, auxiliar->distancia,  auxiliar ->id);
        imprimeDato(auxiliar->estudiante->dato);
        auxiliar = auxiliar -> siguiente;
        i++;
        printf ("----------------------------------------------------------------------------------\n");
    }

}


/*void compruebaDatos(listaEstudiantes *l,int K) // -> mprobar si la predicción del nivel de calidad del sueño (basada en los vecinos más cercanos) es correcta en relación con los datos reales de cada estudiante
{
    listaEstudiantes listaAuxiliar;
    listaOrdenadaVecinos vecinos;
    celdaEstudiantes *aux, *ant;
    celdaVecino *vecinoAux;
    float cont = 0, cont2 = 0;
    int fin, calidadSueñoPredicha;

    // Obtener el ID del último elemento para controlar el ciclo
    fin = l->ultimo->id;

    iniciarListaEstudiantes(&listaAuxiliar);

    aux = l->primero;

    // Procesar todos los estudiantes
    while (aux != NULL && aux->id <= fin)
    {
        ant = aux;
        aux = aux->sig;

        // Calcular los vecinos más cercanos de `ant`
        vecinos = distanciaMinima(ant->dato, *l, K);

        // Predecir el nivel de calidad del sueño basado en la media de los vecinos
        calidadSueñoPredicha = mediaVecinos(vecinos);

        // Limpiar la lista de vecinos después de usarla
        while (!estavacia(vecinos))
        {
            vecinoAux = vecinos.primero;
            vecinos.primero = vecinos.primero->siguiente;
            free(vecinoAux);
        }

        // Verificar si la predicción coincide con el valor real
        if (calidadSueñoPredicha == ant->dato.calidad_sueño)
        {
            cont++;
        }

        // Añadir el elemento a ambas listas
        insertarEnLista(&listaAuxiliar, ant->dato);
        desencolar(l);
        cont2++;
    }

    // Mostrar resultados
    printf("\n");
    printf("------------------------------------------------------------\n");
    printf("Total de elementos en la lista: %.0f\n", cont2);
    printf("Se ha acertado en %.0f elementos\n", cont);
    printf("Porcentaje de efectividad: %.2f%%\n", (cont / cont2) * 100);
    printf("------------------------------------------------------------\n");

    // Reemplazar la lista original con la lista auxiliar
    *l = listaAuxiliar;

    // Confirmar que la lista original ha sido vaciada correctamente
    if (estavaciaListaEstudiantes(*l))
    {
        printf("Lista original vaciada correctamente\n");
        printf("Retornando lista original...\n");
    }
    else
    {
        printf("Error: la lista original no se vació correctamente\n");
    }
}



void depuraListaEstudiantes(listaEstudiantes *l, int K) // -> limpiar la lista de estudiantes eliminando aquellos cuya predicción de calidad del sueño no fue correcta, conservando solo aquellos  con predicciones correctas. De esta manera, la lista original se depura para que solo contenga los elementos más precisos.
{
    listaEstudiantes listaAuxiliar;
    listaOrdenadaVecinos vecinos;
    celdaEstudiantes *aux, *ant;
    celdaVecino *vecinoAux;
    float cont = 0;
    float cont2 = 0;
    int calidadSueñoPredicha;

    // Obtener el ID del último elemento para controlar el ciclo
    int fin = l->ultimo->id;

    // Iniciar la lista auxiliar
    iniciarListaEstudiantes(&listaAuxiliar);

    aux = l->primero;

    // Procesar todos los estudiantes
    while (aux != NULL && aux->id <= fin)
    {
        ant = aux;
        aux = aux->sig;

        // Calcular los vecinos más cercanos de `ant`
        vecinos = distanciaMinima(ant->dato, *l, K);

        // Predecir el nivel de calidad del sueño basado en la media de los vecinos
        calidadSueñoPredicha = mediaVecinos(vecinos);

        // Limpiar la lista de vecinos después de usarla
        while (!estavacia(vecinos))
        {
            vecinoAux = vecinos.primero;
            vecinos.primero = vecinos.primero->siguiente;
            free(vecinoAux);
        }

        // Si la predicción coincide, mantener el elemento
        if (calidadSueñoPredicha == ant->dato.calidad_sueño)
        {
            cont++;
            insertarEnLista(&listaAuxiliar, ant->dato); // Guardar en lista depurada
            insertarEnLista(l, ant->dato);             // Mantener en lista original
        }

        // Quitar el elemento actual de la lista original
        desencolar(l);
        cont2++;
    }

    // Mostrar estadísticas
    printf("\n");
    printf("------------------------------------------------------------\n");
    printf("Total de elementos procesados: %.0f\n", cont2);
    printf("Elementos guardados: %.0f\n", cont);
    printf("Elementos eliminados: %.0f\n", cont2 - cont);
    printf("Porcentaje de efectividad: %.2f%%\n", (cont / cont2) * 100);
    printf("------------------------------------------------------------\n");

    // Vaciar la lista original
    aux = l->primero;
    while (aux != NULL)
    {
        desencolar(l);
        aux = aux->sig;
    }

    // Confirmar que la lista original está vacía
    if (estavaciaListaEstudiantes(*l))
    {
        printf("Lista original vaciada correctamente\n");
        printf("Retornando lista depurada...\n");
    }
    else
    {
        printf("Error: la lista original no se vació correctamente\n");
    }

    // Reemplazar la lista original con la lista depurada
    *l = listaAuxiliar;
}
*/







