#ifndef CALIDAD_SUEÑO_H
#define CALIDAD_SUEÑO_H

#include <stdio.h>
#include <stdbool.h>

typedef struct calidadDelSueño
{
    int id; //numero de dato
    int año_universidad;
    int edad;
    int genero;
    int actividad_fisica;
    int calidad_sueño;
    float acostar_semana; // A que hora se acuesta durante la semana sin contar los findes
    float acostar_finde;  // A que hora se acuesta en el fin de semana
    float despertar_semana;
    float despertar_finde;
    float horas_sueño;
    float horas_estudio;
    float horas_pantalla;
    int cafeina; //cafeina tomada
} calidadDelSueño;

void leerCalidadDelSueño(calidadDelSueño *);


#endif
