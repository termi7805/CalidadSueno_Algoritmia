#include "CalidadSueño.h"
#include <string.h>


calidadDelSueño nuevoEstudiante
(
                                int edad,
                                char *genero[10],
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

)
{
    calidadDelSueño nuevo;
    nuevo.edad = edad;
    strcpy(nuevo.genero, genero[10]);
    nuevo.año_universidad = año_universidad;
    nuevo.horas_sueño = horas_sueño;
    nuevo.horas_estudio = horas_estudio;
    nuevo.horas_pantalla = horas_pantalla;
    nuevo.cafeina = cafeina;
    nuevo.actividad_fisica = actividad_fisica;
    nuevo.acostar_semana = acostar_semana;
    nuevo.acostar_finde = acostar_finde;
    nuevo.despertar_semana = despertar_semana;
    nuevo.despertar_finde = despertar_finde;
    return nuevo;
}



bool suelo(calidadDelSueño cs)
{
    return cs.calidad_sueño;
}
void cambiarCalidad(calidadDelSueño *cs, int calidad)
{
    cs->calidad_sueño = calidad;
}

