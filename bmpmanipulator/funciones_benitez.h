#ifndef FUNCIONES_BENITEZ_H_INCLUDED
#define FUNCIONES_BENITEZ_H_INCLUDED
#define TAM 1000
#define mayor(a,b) ((a)>(b)?(a):(b))
#include "estructuras.h"
#include <string.h>

void imagenNegativo(SARCHIVO,S_color[][TAM]);
void espejarVertical(SARCHIVO ,S_color [][TAM]);
void aumentarContraste(SARCHIVO ,S_color [][TAM],float);
void tonalidadAzul(SARCHIVO ,S_color [][TAM],float);
void concatenarHorizontal(SARCHIVO, SARCHIVO, SARCHIVO*, S_color [][TAM], S_color [][TAM], int, int, S_color[][TAM]);


#endif // FUNCIONES_BENITEZ_H_INCLUDED


