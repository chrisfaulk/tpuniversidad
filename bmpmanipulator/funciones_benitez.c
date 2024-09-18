#include "funciones_benitez.h"

void imagenNegativo(SARCHIVO img, S_color mat[img.alto][img.ancho])
{
    int posicion=0,cantidad_pixeles=img.ancho*3;//porque los colores ocupan 3 bytes;
    for (int y=0;y<img.alto;y++)
    {
        for(int x=0;x<img.ancho;x++)
        {
            posicion=y * cantidad_pixeles + x * 3; //x*3 para saber el desplazamiento
            (mat[y][x]).azul = 255 - (int) &img.pixel[posicion].azul;
            (mat[y][x]).verde = 255 - (int) &img.pixel[posicion].verde;
            (mat[y][x]).rojo = 255 - (int) &img.pixel[posicion].rojo;
        }
    }
}

void espejarVertical(SARCHIVO img, S_color mat[img.alto][img.ancho])
{
    S_color aux;
    int ff=img.alto-1;//ultima fila
    for(int f=0;f<img.alto;f++)
    {
        for(int c=0;c<img.ancho;c++)
        {
            aux=mat[f][c];
            mat[f][c]=mat[ff-f][c];
            mat[ff-f][c]=aux;
        }
    }
}

void aumentarContraste(SARCHIVO img, S_color mat[img.alto][img.ancho], float cAumento)
{
    float aumento=cAumento/100;
    int nuevoA,nuevoV,nuevoR, f, c;
    for (f = 0;f < img.alto;f++)
    {
        for(c=0;c<img.ancho;c++)
        {
            nuevoA=aumento*(mat[f][c].azul-128)+128;
            //se le resta 128 porq es el valor intermedio y dsp se suma para volver a la escala org
            //verifico que no este fuera de rango (0 a 255)
            if(nuevoA<0)
            {
                nuevoA=0;
            }
            if(nuevoA>255)
            {
                nuevoA=255;
            }
            nuevoV=aumento*(mat[f][c].verde-128)+128;
            //se le resta 128 porq es el valor intermedio y dsp se suma para volver a la escala org
            //verifico que no este fuera de rango (0 a 255)
            if(nuevoV<0)
            {
                nuevoV=0;
            }
            if(nuevoV>255)
            {
                nuevoV=255;
            }
            nuevoR=aumento*(mat[f][c].rojo-128)+128;
            //se le resta 128 porq es el valor intermedio y dsp se suma para volver a la escala org
            //verifico que no este fuera de rango (0 a 255)
            if(nuevoR<0)
            {
                nuevoR=0;
            }
            if(nuevoR>255)
            {
                nuevoR=255;
            }

            mat[f][c].azul = nuevoA;
            mat[f][c].verde = nuevoV;
            mat[f][c].rojo = nuevoR;
        }
    }
}


void tonalidadAzul(SARCHIVO img,S_color mat[img.alto][img.ancho],float cAumento)
{
    float aumento = cAumento/100;
    for(int f=0;f<img.alto;f++)
    {
        for(int c=0;c<img.ancho;c++)
        {
            mat[f][c].azul=mat[f][c].azul+(mat[f][c].azul*aumento);
            if (mat[f][c].azul > 255){
                mat[f][c].azul = 255;
            }
            if (mat[f][c].azul < 0){
                mat[f][c].azul = 0;
            }
        }
    }
}


void concatenarHorizontal(SARCHIVO img1,SARCHIVO img2, SARCHIVO *img3, S_color mat1[img1.alto][img1.ancho], S_color mat2[img2.alto][img2.ancho], int nuevoAlto, int nuevoAncho, S_color nuevaImagen[nuevoAlto][nuevoAncho])
{
    int f, c;

    //inicializo la nueva matriz con un fondo
    for (f=0;f<nuevoAlto;f++)
    {
        for(c=0;c<nuevoAncho;c++)
        {
            if((f/50)%2==0)
            {
                nuevaImagen[f][c].azul=255;
                nuevaImagen[f][c].verde=0;
                nuevaImagen[f][c].rojo=0;
            }
            else
            {
                nuevaImagen[f][c].azul=0;
                nuevaImagen[f][c].verde=255;
                nuevaImagen[f][c].rojo=255;
            }
            //lo hice de boquita :)
        }
    }
    //copio la primera imagen
    for(f=0;f<img1.alto;f++)
    {
        for(c=0;c<img1.ancho;c++)
        {
            nuevaImagen[f][c]=mat1[f][c];
        }
    }
    //copio la segunda imagen
    for (f=0;f<img2.alto;f++)
    {
        for(int c=img1.ancho;c<nuevoAncho;c++)
        {
            nuevaImagen[f][c]=mat2[f][c-img1.ancho];
        }
    }
    memcpy(img3->bm, img1.bm,sizeof(img1.bm));
    img3->reservado=img1.reservado;
    img3->tamanioMetadatos=40;
    img3->desplazamiento=14+img3->tamanioMetadatos;
    img3->tamanioImagen=((nuevoAncho*3+3)&~3)*nuevoAlto;
    img3->tamanioArchivo=img3->desplazamiento+img3->tamanioImagen;
    img3->ancho=nuevoAncho;
    img3->alto=nuevoAlto;
    img3->numeroPlanos=img1.numeroPlanos;
    img3->tamPixel=img1.tamPixel;
    img3->tipoCompresion=img1.tipoCompresion;
    img3->pxmh=img1.pxmh;
    img3->pxmv=img1.pxmv;
    img3->coloresUsados=img1.coloresUsados;
    img3->coloresImportantes=img1.coloresImportantes;
}

