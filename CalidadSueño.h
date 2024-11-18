#include <stdio.h>
#include <stdbool.h>

typedef struct calidadDelSueño{

    int edad;
    char genero[10];
    int año_universidad;
    float horas_sueño;
    float horas_estudio;
    float horas_pantalla;
    float cafeina;
    int actividad_fisica;
    int calidad_sueño;
    float acostar_semana; // A que hora se acuesta durante la semana sin contar los findes
    float acostar_finde;  // A que hora se acuesta en el fin de semana
    float despertar_semana;
    float despertar_finde;
}calidadDelSueño;


calidadDelSueño nuevoEstudiante
(
                                int edad,
                                char * genero[10],
                                int año_universidad,
                                float horas_sueño,
                                float horas_estudio,
                                float horas_pantalla,
                                float cafeina,
                                int actividad_fisica,
                                int calidad_sueño,
                                float acostar_semana,
                                float acostar_finde,
                                float despertar_semana,
                                float despertar_finde
);


bool suelo(calidadDelSueño );

void cambiarCalidad(calidadDelSueño *, int );
