#ifndef FUNCIONES_GRUPO_H_INCLUDED
#define FUNCIONES_GRUPO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define TAM_MAX 50
#define TAM_IMG 2000
#include "estructuras.h"

#include "funciones_benitez.h"
#include "funciones_menendez.h"
#include "funciones_faulkner.h"

int solucion(int argc, char* argv[]);

void encontrarImagen(int argc,char* argv[], SARCHIVO*, SARCHIVO*, int*, int*);

SARCHIVO cargarDatos(char[]);

void llenarMatriz(SARCHIVO, S_color[][TAM_MAX]);

void llamarFuncion(const char*, char*, int*);

int buscarSiSeUso (int, char*[], const char*);

int guardarImagen(SARCHIVO*, S_color[][TAM_MAX], char*);


#endif // FUNCIONES_GRUPO_H_INCLUDED
