#include "CalidadSueño.h"


calidadDelSueño nuevoEstudiante (int edad, int genero, int año_universidad, float horas_sueño, float horas_estudio, float horas_pantalla, float cafeina, int actividad_fisica, int calidad_sueño, float acostar_semana, float acostar_finde, float despertar_semana, float despertar_finde)
{
    calidadDelSueño nuevo;

    nuevo.edad = edad;
    nuevo.genero = genero;
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

//Revisar si se usa
bool sueño(calidadDelSueño calidadSueño)
{
    return calidadSueño.calidad_sueño;
}
//Revisar si se usa
void cambiarCalidad(calidadDelSueño *calidadSueño, int calidad)
{
    calidadSueño->calidad_sueño = calidad;
}

