#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H

typedef struct {
    unsigned char azul;
    unsigned char verde;
    unsigned char rojo;
}S_color;

typedef struct {
    char bm[2];
    int tamanioArchivo;
    int reservado;
    int desplazamiento;
    int tamanioMetadatos;
    int ancho;
    int alto;
    short int numeroPlanos;
    short int tamPixel;
    int tipoCompresion;
    int tamanioImagen;
    int pxmh;
    int pxmv;
    int coloresUsados;
    int coloresImportantes;
    S_color *pixel;
}SARCHIVO;

#endif // ESTRUCTURAS_H

