#ifndef FUNCIONES_MENENDEZ_H_INCLUDED
#define FUNCIONES_MENENDEZ_H_INCLUDED
#include "estructuras.h"

S_color* aplicarEscalaDeGrises(S_color *mat, int alto, int ancho);
S_color* espejarHorizontal(S_color *mat, int alto, int ancho);
S_color* achicarImagen(S_color *mat, int alto, int ancho, float porcentaje);
S_color* aumentarTonalidadRoja(S_color *mat, int alto, int ancho, float porcentaje);
S_color* reducirContraste(S_color *mat, int alto, int ancho, float porcentaje);


#endif // FUNCIONES_MENENDEZ_H_INCLUDED

