#include "funciones_menendez.h"

S_color* aplicarEscalaDeGrises(S_color *mat, int alto, int ancho){
    for (int i = 0; i < alto; i++) {
        for (int j = 0; j < ancho; j++) {
            // Accedemos al pixel directamente usando los índices i y j
            S_color *pixel = &mat[i * ancho + j];

            // Promediamos los valores de los tres canales RGB
            unsigned char gris = (pixel->rojo + pixel->verde + pixel->azul) / 3;

            // Asignamos el mismo valor a los tres canales para crear el gris
            pixel->rojo = gris;
            pixel->verde = gris;
            pixel->azul = gris;
        }
    }
    // Retorna la matriz modificada
    return mat;
}

S_color* espejarHorizontal(S_color *mat, int alto, int ancho){
    for (int i = 0; i < alto; i++) {
        // Iteramos solo hasta la mitad de la fila, ya que vamos intercambiando los extremos
        for (int j = 0; j < ancho / 2; j++) {
            // Accedemos a los píxeles de los extremos que vamos a intercambiar
            S_color *pixelIzq = &mat[i * ancho + j];               // Píxel izquierdo
            S_color *pixelDer = &mat[i * ancho + (ancho - j - 1)]; // Píxel derecho

            // Intercambiamos los píxeles
            S_color temp = *pixelIzq;  // Guardamos el valor temporalmente
            *pixelIzq = *pixelDer;     // Asignamos el píxel derecho al izquierdo
            *pixelDer = temp;          // Asignamos el píxel temporal (izquierdo) al derecho
        }
    }
    // Retorna la matriz modificada
    return mat;
}

S_color* achicarImagen(S_color *mat, int alto, int ancho, float porcentaje){
    // Calculamos las nuevas dimensiones en base al porcentaje
    int nuevoAncho = ancho * (porcentaje / 100);
    int nuevoAlto = alto * (porcentaje / 100);

    // Recorremos la imagen reducida
    for (int i = 0; i < nuevoAlto; i++) {
        for (int j = 0; j < nuevoAncho; j++) {
            // Determinamos el píxel correspondiente en la imagen original
            int originalI = i * alto / nuevoAlto;
            int originalJ = j * ancho / nuevoAncho;

            // Sobreescribimos los valores de la matriz original con los valores de la imagen reducida
            mat[i * nuevoAncho + j] = mat[originalI * ancho + originalJ];
        }
    }

    // Retorna la matriz modificada (reducida)
    return mat;
}

S_color* aumentarTonalidadRoja(S_color *mat, int alto, int ancho, float porcentaje){
    for (int i = 0; i < alto; i++) {
        for (int j = 0; j < ancho; j++) {
            // Accedemos al píxel directamente usando los índices i y j
            S_color *pixel = &mat[i * ancho + j];

            // Aumentamos el valor del canal rojo en el porcentaje especificado
            int nuevoRed = pixel->rojo + (pixel->rojo * porcentaje / 100);

            // Nos aseguramos de que no sobrepase el valor máximo permitido (255)
            if (nuevoRed > 255) {
                nuevoRed = 255;
            }
            if (nuevoRed < 0) {
                nuevoRed = 0;
            }

            // Asignamos el nuevo valor del canal rojo
            pixel->rojo = (unsigned char)nuevoRed;
        }
    }
    // Retorna la matriz modificada
    return mat;
}

S_color* reducirContraste(S_color *mat, int alto, int ancho, float porcentaje){
    // Factor de ajuste de contraste (1 - porcentaje)
    float factor = 1 - (porcentaje / 100);

    for (int i = 0; i < alto; i++) {
        for (int j = 0; j < ancho; j++) {
            S_color *pixel = &mat[i * ancho + j];

            // Reducimos el contraste para el canal rojo
            int r = (int)((pixel->rojo - 127) * factor + 127);
            if (r < 0) {
                r = 0;
            } else if (r > 255) {
                r = 255;
            }
            pixel->rojo = (unsigned char)r;

            // Reducimos el contraste para el canal verde
            int g = (int)((pixel->verde - 127) * factor + 127);
            if (g < 0) {
                g = 0;
            } else if (g > 255) {
                g = 255;
            }
            pixel->verde = (unsigned char)g;

            // Reducimos el contraste para el canal azul
            int b = (int)((pixel->azul - 127) * factor + 127);
            if (b < 0) {
                b = 0;
            } else if (b > 255) {
                b = 255;
            }
            pixel->azul = (unsigned char)b;
        }
    }

    // Retorna la matriz modificada
    return mat;
}

