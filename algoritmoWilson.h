#ifndef ALGORITMOWILSON_H
#define ALGORITMOWILSON_H

#include "listaEstudiantes.h"

void precisionAcierto(listaEstudiantes *, int); // -> Recorrer la lista y determinar en cuantos de ellos se ha acertado la calidad del sueño respecto a los datos del dataset

void algoritmoENN(listaEstudiantes *, int); // -> limpiar la lista de estudiantes eliminando aquellos cuya predicción de calidad del sueño no fue correcta, conservando solo aquellos  con predicciones correctas. De esta manera, la lista original se depura para que solo contenga los elementos más precisos.

#endif
