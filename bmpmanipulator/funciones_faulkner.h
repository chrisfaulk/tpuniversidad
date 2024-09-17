#ifndef FUNCIONES_FAULKNER_H_INCLUDED
#define FUNCIONES_FAULKNER_H_INCLUDED
#define DEFAULT 2500
#include "estructuras.h"
#include <stdio.h>
#include <string.h>

void rotar(SARCHIVO, S_color[][DEFAULT], int);
void recortar(SARCHIVO, S_color[][DEFAULT], int, int, S_color[][DEFAULT]);
void concatenarVertical(SARCHIVO, SARCHIVO, SARCHIVO*, S_color[][DEFAULT], S_color[][DEFAULT], int, int, S_color[][DEFAULT]);
void tonalidadVerde(SARCHIVO, S_color[][DEFAULT],float);
#endif // FUNCIONS_FAULKNER_H_INCLUDED

