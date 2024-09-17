#include "funciones_faulkner.h"

void rotar(SARCHIVO imagen, S_color matriz[imagen.alto][imagen.ancho], int izqODer){
    S_color aux;
    int i, j, k;

    // Traspongo la matriz
    for (i=0;i<imagen.alto;i++){
        for (j=0;j<imagen.ancho;j++){
            aux = matriz[i][j];
            matriz[i][j] = matriz[j][i];
            matriz[j][i] = aux;
        }
    }

    // Invierto sus filas si se rota a la izquierda
    i = 0;
    if (izqODer){
        j = imagen.alto-1;
        while (j>i){
            for (k=0;k<imagen.ancho;k++){
                aux = matriz[i][k];
                matriz[i][k] = matriz[j][k];
                matriz[j][k] = aux;
            }
            i++;
            j--;
        }
    }

    // Invierto sus columnas si se rota a la derecha
    else {
        j = imagen.ancho-1;
        while (j>i){
            for (k=0;k<imagen.alto;k++){
                aux = matriz[k][i];
                matriz[k][i] = matriz[k][j];
                matriz[k][j] = aux;
            }
            i++;
            j--;
        }
    }

}

void recortar(SARCHIVO imagen, S_color matriz[imagen.alto][imagen.ancho], int nuevoAlto, int nuevoAncho, S_color matriz2[nuevoAlto][nuevoAncho]){
    int diferenciaAlto = imagen.alto - nuevoAlto;
    int diferenciaAncho = imagen.ancho - nuevoAncho;
    int i, j, y = 0, x = 0;

    for (i = diferenciaAlto/2;i<nuevoAlto+(diferenciaAlto/2);i++){
        for (j=diferenciaAncho/2;j<nuevoAncho+(diferenciaAncho/2);j++){
            matriz2[y][x] = matriz[i][j];
            x++;
        }
        x = 0;
        y++;
    }
}

void concatenarVertical(SARCHIVO imagen1, SARCHIVO imagen2, SARCHIVO *imagen3, S_color matriz1[imagen1.alto][imagen1.ancho], S_color matriz2[imagen2.alto][imagen2.ancho], int nuevoAlto, int nuevoAncho, S_color matriz3[nuevoAlto][nuevoAncho]){
    int i, j;

    for (i=0;i<nuevoAlto;i++){
        for (j=0;j<nuevoAncho;j++){
            matriz3[i][j].azul = 153;
            matriz3[i][j].verde = 204;
            matriz3[i][j].rojo = 255;
        }
    }

    for (i=0;i<imagen1.alto;i++){
        for (j=0;j<imagen1.ancho;j++){
            matriz3[i][j] = matriz1[i][j];
        }
    }

    for (i=imagen1.alto;j<nuevoAlto;i++){
        for (j=imagen1.ancho;j<nuevoAncho;j++){
            matriz3[i][j] = matriz2[i-imagen1.ancho][j];
            }
    }

    memcpy(imagen3->bm, imagen1.bm,sizeof(imagen1.bm));
    imagen3->reservado=imagen1.reservado;
    imagen3->tamanioMetadatos=40;
    imagen3->desplazamiento=14+imagen3->tamanioMetadatos;
    imagen3->tamanioImagen=((nuevoAncho*3+3)&~3)*nuevoAlto;
    imagen3->tamanioArchivo=imagen3->desplazamiento+imagen3->tamanioImagen;
    imagen3->ancho=nuevoAncho;
    imagen3->alto=nuevoAlto;
    imagen3->numeroPlanos=imagen1.numeroPlanos;
    imagen3->tamPixel=imagen1.tamPixel;
    imagen3->tipoCompresion=imagen1.tipoCompresion;
    imagen3->pxmh=imagen1.pxmh;
    imagen3->pxmv=imagen1.pxmv;
    imagen3->coloresUsados=imagen1.coloresUsados;
    imagen3->coloresImportantes=imagen1.coloresImportantes;
}

void tonalidadVerde(SARCHIVO imagen, S_color matriz[imagen.alto][imagen.ancho], float porcentaje){

    for (int i=0;i<imagen.alto;i++){
        for (int j=0;j<imagen.ancho;j++){
            matriz[i][j].verde += matriz[i][j].verde*porcentaje;
            if (matriz[i][j].verde > 255){
                matriz[i][j].verde = 255;
            }
            if (matriz[i][j].verde < 0){
                matriz[i][j].verde = 0;
            }
        }
    }
}

