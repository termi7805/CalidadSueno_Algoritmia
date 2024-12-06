#include "CalidadSueño.h"

void leerCalidadDelSueño(calidadDelSueño * CS)
{
    int horas, minutos;

    printf("Introduce su edad: ");
    scanf("%d",&CS -> edad);
    printf("\n");

    printf("Introduce su genero (Hombre = 0 || Mujer = 1 || Otro = 2): ");
    scanf("%d",&CS -> genero);
    printf("\n");

    printf("Introduce el año de universidad en el que se encuentra: ");
    scanf("%d", &CS -> año_universidad);
    printf("\n");

    printf("Introduce el numero de horas y minutos que has DORMIDO en este formato (horas minutos): ");
    scanf("%d %d", &horas, &minutos);
    minutos = ((minutos * 100) / 60) / 100;  // para pasar de minutos a la coma -> 30 mins = 0.50 horas
    CS -> horas_sueño = horas + minutos;
    printf("\n");

    printf("Introduce el numero de horas y minutos que has ESTUDIADO en este formato (horas minutos): ");
    scanf("%d %d", &horas, &minutos);
    minutos = ((minutos * 100) / 60) / 100;
    CS -> horas_estudio = horas + minutos;
    printf("\n");

    printf("Introduce el numero de horas y minutos que has estado MIRANDO PANTALLAS en este formato (horas minutos): ");
    scanf("%d %d", &horas, &minutos);
    minutos = ((minutos * 100) / 60) / 100;
    CS -> horas_pantalla = horas + minutos;
    printf("\n");

    printf("Introduce los gramos de cafeina que ha tomado sin decimales: ");
    scanf("%d", &CS -> cafeina);
    printf("\n");

    printf("Introduce cuanta actividad fisica ha hecho sin decimales (0 = Nada / 100 = Mucha): ");
    scanf("%d", &CS -> actividad_fisica);
    printf("\n");

    printf("Introduce a que hora te sueles acostar durante la semana (hora minutos). Ejemplo (21 84): ");
    scanf("%d %d", &horas, &minutos);
    minutos = ((minutos * 100) / 60) / 100;
    CS -> acostar_semana = horas + minutos;
    printf("\n");

    printf("Introduce a que hora te sueles acostar durante el fin de semana (hora minutos). Ejemplo (22 35): ");
    scanf("%d %d", &horas, &minutos);
    minutos = ((minutos * 100) / 60) / 100;
    CS -> acostar_finde = horas + minutos;
    printf("\n");

    printf("Introduce a que hora te sueles despertar durante la semana (hora minutos). Ejemplo (6 54): ");
    scanf("%d %d", &horas, &minutos);
    minutos = ((minutos * 100) / 60) / 100;
    CS -> despertar_semana = horas + minutos;
    printf("\n");

    printf("Introduce a que hora te sueles despertar durante el fin de semana (hora minutos). Ejemplo (8 93): ");
    scanf("%d %d", &horas, &minutos);
    minutos = ((minutos * 100) / 60) / 100;
    CS -> despertar_finde = horas + minutos;
    printf("\n");
}
