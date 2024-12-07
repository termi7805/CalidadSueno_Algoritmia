#include "CalidadSueño.h"

void leerCalidadDelSueño(calidadDelSueño * CS)
{
    printf("Introduce su edad: ");
    scanf("%d",&CS -> edad);
    printf("\n");

    printf("Introduce su genero (Hombre = 0 || Mujer = 1 || Otro = 2): ");
    scanf("%d",&CS -> genero);
    printf("\n");

    printf("Introduce el año de universidad en el que se encuentra: ");
    scanf("%d", &CS -> año_universidad);
    printf("\n");

    printf("Introduce el numero de horas y minutos que has DORMIDO en este formato (horas.minutos): ");
    scanf("%f", &CS -> horas_sueño);
    printf("\n");

    printf("Introduce el numero de horas y minutos que has ESTUDIADO en este formato (horas minutos): ");
    scanf("%f", &CS -> horas_estudio);
    printf("\n");

    printf("Introduce el numero de horas y minutos que has estado MIRANDO PANTALLAS en este formato (horas.minutos): ");
    scanf("%f", &CS -> horas_pantalla);
    printf("\n");

    printf("Introduce los gramos de cafeina que ha tomado sin decimales: ");
    scanf("%d", &CS -> cafeina);
    printf("\n");

    printf("Introduce cuanta actividad fisica ha hecho sin decimales (0 = Nada / 100 = Mucha): ");
    scanf("%d", &CS -> actividad_fisica);
    printf("\n");

    printf("Introduce a que hora te sueles acostar durante la semana (hora.minutos): ");
    scanf("%f", &CS -> acostar_semana);
    printf("\n");

    printf("Introduce a que hora te sueles acostar durante el fin de semana (hora.minutos): ");
    scanf("%f", &CS -> acostar_finde);
    printf("\n");

    printf("Introduce a que hora te sueles despertar durante la semana (hora.minutos): ");
    scanf("%f", &CS -> despertar_semana);
    printf("\n");

    printf("Introduce a que hora te sueles despertar durante el fin de semana (hora.minutos): ");
    scanf("%f", &CS -> despertar_finde);
    printf("\n");
}
