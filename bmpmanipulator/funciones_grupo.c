#include "funciones_grupo.h"


int solucion(int argc, char* argv[])
{
    SARCHIVO imagen1, imagen2, imagen3;
    int valor, indiceImg1 = 0, cantImagenes = 0;
    char nombre[TAM_MAX];
    char nombreImagen[TAM_MAX];
    encontrarImagen(argc, argv, &imagen1, &indiceImg1,&cantImagenes);
    strcpy(nombreImagen, argv[indiceImg1]);
    S_color matriz1[imagen1.alto][imagen1.ancho];
    llenarMatriz(imagen1, matriz1);
    char *funcionesUsadas[16];
    int cantFuncionesUsadas=0;
    for (int i=1;i<argc;i++){
        if (i != (int) indiceImg1){
            llamarFuncion(argv[i],nombre,&valor);
            if (valor<0 || valor > 100){
                printf("El valor introducido en la funcion %s es invalido, por lo que no se pudo ejecutar la funci�n.", nombre);
            }
            else{
                float porcentaje = valor/100;
                if(buscarSiSeUso(16,funcionesUsadas,nombre)==0){
                    funcionesUsadas[cantFuncionesUsadas] = nombre;
                    cantFuncionesUsadas++;
                    char nombreArchivo[TAM_MAX];
                    if (strcmpi(nombre,"--negativo")==0){
                        imagenNegativo(imagen1,matriz1);
                        snprintf(nombreArchivo, TAM_MAX, "AUSTROLOPITECO_negativo_%s", nombreImagen);
                        guardarImagen(&imagen1,matriz1,nombreArchivo);
                        printf("aca");
                    }
                    else if (strcmpi(nombre,"--escala-de-grises")==0){
                        aplicarEscalaDeGrises((S_color *)matriz1,imagen1.alto, imagen1.ancho);
                        snprintf(nombreArchivo, TAM_MAX, "AUSTROLOPITECO_escala-de-grises_%s", nombreImagen);
                        guardarImagen(&imagen1,matriz1,nombreArchivo);
                    }
                    else if (strcmpi(nombre,"--espejar-horizontal")==0){
                        espejarHorizontal((S_color *)matriz1, imagen1.alto, imagen2.ancho);
                        snprintf(nombreArchivo, TAM_MAX, "AUSTROLOPITECO_espejar-horizontal_%s", nombreImagen);
                        guardarImagen(&imagen1,matriz1,nombreArchivo);
                    }
                    else if (strcmpi(nombre,"--espejar-vertical")==0){
                        espejarVertical(imagen1,matriz1);
                        snprintf(nombreArchivo, TAM_MAX, "AUSTROLOPITECO_espejar-vertical_%s", nombreImagen);
                        guardarImagen(&imagen1,matriz1,nombreArchivo);
                    }
                    else if (strcmpi(nombre,"--aumentar-contraste")==0){
                        aumentarContraste(imagen1,matriz1,(float) valor);
                        snprintf(nombreArchivo, TAM_MAX, "AUSTROLOPITECO_aumentar-contraste_%s", nombreImagen);
                        guardarImagen(&imagen1,matriz1,nombreArchivo);
                    }
                    else if (strcmpi(nombre,"--reducir-contraste")==0){
                        reducirContraste((S_color *)matriz1, imagen1.alto, imagen2.alto, valor);
                        snprintf(nombreArchivo, TAM_MAX, "AUSTROLOPITECO_reducir-contraste_%s", nombreImagen);
                        guardarImagen(&imagen1,matriz1,nombreArchivo);
                    }
                    else if (strcmpi(nombre,"--tonalidad-azul")==0){
                        tonalidadAzul(imagen1,matriz1,valor);
                        snprintf(nombreArchivo, TAM_MAX, "AUSTROLOPITECO_tonalidad-azul_%s", nombreImagen);
                        guardarImagen(&imagen1,matriz1,nombreArchivo);
                    }
                    else if (strcmpi(nombre,"--tonalidad-verde")==0){
                        tonalidadVerde(imagen1,matriz1, porcentaje);
                        snprintf(nombreArchivo, TAM_MAX, "AUSTROLOPITECO_tonalidad-verde_%s", nombreImagen);
                        guardarImagen(&imagen1,matriz1,nombreArchivo);
                    }
                    else if (strcmpi(nombre,"--tonalidad-roja")==0){
                        aumentarTonalidadRoja((S_color *)matriz1, imagen1.alto, imagen2.ancho, (float) valor);
                        snprintf(nombreArchivo, TAM_MAX, "AUSTROLOPITECO_tonalidad-roja_%s", nombreImagen);
                        guardarImagen(&imagen1, matriz1, nombreArchivo);
                    }
                    else if (strcmpi(nombre,"--recortar")==0){
                        int nuevoAlto = imagen1.alto - (imagen1.alto*porcentaje);
                        int nuevoAncho = imagen1.ancho - (imagen1.ancho*porcentaje);
                        S_color matriz2[nuevoAlto][nuevoAncho];
                        recortar(imagen1, matriz1,nuevoAlto, nuevoAncho, matriz2);
                        snprintf(nombreArchivo, TAM_MAX, "AUSTROLOPITECO_recortar_%s", nombreImagen);
                        guardarImagen(&imagen1, matriz1, nombreArchivo);
                    }
                    else if (strcmpi(nombre,"--achicar")==0){
                        achicarImagen((S_color *)matriz1, imagen1.alto, imagen1.ancho, (float) valor);
                        snprintf(nombreArchivo, TAM_MAX, "AUSTROLOPITECO_achicar_%s", nombreImagen);
                        guardarImagen(&imagen1, matriz1,nombreArchivo);
                    }
                    else if (strcmpi(nombre,"--rotar-derecha")==0){
                        rotar(imagen1, matriz1, 0);
                        snprintf(nombreArchivo, TAM_MAX, "AUSTROLOPITECO_rotar-derecha_%s", nombreImagen);
                        guardarImagen(&imagen1, matriz1, nombreArchivo);
                    }
                    else if (strcmpi(nombre,"--rotar-izquierda")==0){
                        rotar(imagen1, matriz1, 1);
                        snprintf(nombreArchivo, TAM_MAX, "AUSTROLOPITECO_rotar-izquierda_%s", nombreImagen);
                        guardarImagen(&imagen1, matriz1,nombreArchivo);
                    }
                    else if (strcmpi(nombre,"--concatenar-horizontal")==0){
                        encontrarImagen(argc,argv,&imagen2,&indiceImg1,&cantImagenes);
                        if (cantImagenes > 2){
                            S_color matriz2[imagen2.alto][imagen2.ancho];
                            int nuevoAlto = mayor(imagen1.alto, imagen2.alto);
                            int nuevoAncho = imagen1.ancho + imagen2.ancho;
                            S_color matriz3[nuevoAlto][nuevoAncho];
                            concatenarHorizontal(imagen1,imagen2, &imagen3, matriz1, matriz2, nuevoAlto, nuevoAncho, matriz3);
                            snprintf(nombreArchivo, TAM_MAX, "AUSTROLOPITECO_concatenar-horizontal_%s", nombreImagen);
                            guardarImagen(&imagen3,matriz3,nombreArchivo);
                        }
                        else {
                            printf("La funcion concatenar-horizontal no pudo ejecutarse porque necesita dos imagenes y solo se envio una. ");
                        }
                }
                    else if (strcmpi(nombre,"--concatenar-vertical")==0){
                        encontrarImagen(argc,argv,&imagen2,&indiceImg1,&cantImagenes);
                        if (cantImagenes > 2){
                            S_color matriz2[imagen2.alto][imagen2.ancho];
                            int nuevoAlto = imagen1.alto + imagen2.alto;
                            int nuevoAncho = mayor(imagen1.ancho, imagen2.ancho);
                            S_color matriz3[nuevoAlto][nuevoAncho];
                            concatenarVertical(imagen1, imagen2, &imagen3, matriz1, matriz2, nuevoAlto, nuevoAncho, matriz3);
                            snprintf(nombreArchivo, TAM_MAX, "AUSTROLOPITECO_concatenar-vertical_%s", nombreImagen);
                            guardarImagen(&imagen3, matriz3, nombreArchivo);
                        }
                        else {
                            printf("La funcion concatenar-vertical no pudo ejecutarse porque necesita dos imagenes y solo se envio una. ");
                        }
                    }
                    else if (strcmpi(nombre,"--comodin")==0){

                    }
                    else {
                        printf("La funcion  %s no existe.\n", argv[i]);
                        cantFuncionesUsadas--;
                    }
                }
            else {
                printf("\n La funcion %s ya se utilizo en este llamado y solo sera aplicada una vez. ", nombre);
            }
            }
        }
    }
    return 0;
}

void encontrarImagen(int argc, char *argv[], SARCHIVO* imagen1, int* indiceImg1, int* cantImagenes) {
    const char* buscado = ".bmp";

    for (int i = 1; i < argc; ++i) { // Empieza en 1 para omitir el nombre del programa
        if (strstr(argv[i], buscado) != NULL) {
            if (i != (int) indiceImg1) {
                *imagen1 = cargarDatos(argv[i]);
                *indiceImg1 = i;
                (*cantImagenes)++;
            }
        }
    }

    if (*cantImagenes == 0) {
        fprintf(stderr, "No se recibio ninguna imagen\n");
        exit(EXIT_FAILURE);
    }
}

SARCHIVO cargarDatos(char archivo[])
{
    FILE* f;
    SARCHIVO imagen;
    f = fopen(archivo, "rb");
    if(!f)
    {
        printf("La imagen no se pudo encontrar");
        getch();
        exit(1);
    }
    fread(&imagen.bm, sizeof(short), 1, f);
    fread(&imagen.tamanioArchivo, sizeof(int), 1, f);
    fread(&imagen.reservado, sizeof(int), 1, f);
    fread(&imagen.desplazamiento, sizeof(int), 1, f);
    fread(&imagen.tamanioMetadatos, sizeof(int), 1, f);
    fread(&imagen.ancho, sizeof(int), 1, f);
    fread(&imagen.alto, sizeof(int), 1, f);
    fread(&imagen.numeroPlanos, sizeof(short), 1, f);
    fread(&imagen.tamPixel, sizeof(short), 1, f);
    fread(&imagen.tipoCompresion, sizeof(int), 1, f);
    fread(&imagen.tamanioImagen, sizeof(int), 1, f);
    fread(&imagen.pxmh, sizeof(int), 1, f);
    fread(&imagen.pxmv, sizeof(int), 1, f);
    fread(&imagen.coloresUsados, sizeof(int), 1, f);
    fread(&imagen.coloresImportantes, sizeof(int), 1, f);


    if(imagen.tamPixel != 24)
    {
        printf("\nError: Solo se soportan archivos de 24 bits por pixel");
        fclose(f);
        getch();
        exit(1);
    }

    fseek(f,imagen.desplazamiento,SEEK_SET);
    fread(&imagen.pixel,sizeof(char),imagen.tamanioImagen,f);


    fclose(f);
    return imagen;
}

void llenarMatriz(SARCHIVO const imagen, S_color mat[imagen.alto][imagen.ancho])
{
    int f,c;
    unsigned long desplazamiento=0,desplazamiento_con_relleno=0;
    desplazamiento = imagen.ancho * 3;//obtenemos los bytes (B=1byte,G=1byte,R=byte)
    desplazamiento_con_relleno=(desplazamiento+3)&(~3); //redondea a multiplos de 4 para que no se rompa la imagen :)
    for(f=0;f<imagen.alto;f++)
    {
        for(c=0;c<imagen.ancho;c++)
        {
            int indice = f*desplazamiento_con_relleno + c*3;
            mat[f][c].azul = (int) &imagen.pixel[indice].azul;
            mat[f][c].verde = (int) &imagen.pixel[indice].verde;
            mat[f][c].rojo = (int) &imagen.pixel[indice].rojo;
        }
    }
}

void llamarFuncion(const char *cadena, char *nombre, int *valor){
    char *posIgual;
    char val[10];

    posIgual = strchr(cadena, '=');
    if (posIgual != NULL){
        size_t largoNombre = posIgual - cadena;
        strncpy(nombre,cadena,largoNombre);
        nombre[largoNombre] = '\0';

        strncpy(val, posIgual+1, sizeof(val) - 1);
        val[sizeof(val) - 1] = '\0';

        *valor = atoi(val);
    }
    else {
        strcpy(nombre, cadena);
        *valor = 0;
    }
}

int buscarSiSeUso(int cant, char *vec[], const char *buscado) {
    for (int i = 0; i < cant; i++) {
        if (&vec[i] != NULL && strcmpi(&vec[i], buscado) == 0) {
            return 1;
        }
    }
    return 0;
}

int guardarImagen(SARCHIVO *imagen, S_color matriz[imagen->alto][imagen->ancho], char nombreArchivo[TAM_MAX])
{
    FILE* fi;
    fi = fopen(nombreArchivo, "wb");
    if(!fi)
    {
        printf("La imagen no se pudo crear\n");
        getch();
        exit(1);
    }

    unsigned long desplazamiento_con_relleno = (imagen->ancho * 3 + 3) & (~3);

    for (int f = 0; f < imagen->alto; f++) {
        for (int c = 0; c < imagen->ancho; c++) {
            indice = f*desplazamiento_con_relleno + c;
            imagen->pixel[indice].azul = matriz[f][c].azul;
            imagen->pixel[indice].verde = matriz[f][c].verde;
            imagen->pixel[indice].rojo = matriz[f][c].rojo;
        }
    }

    fwrite(&imagen->bm, sizeof(char), 1, fi);
    fwrite(&imagen->tamanioArchivo, sizeof(int), 1, fi);
    fwrite(&imagen->reservado, sizeof(int), 1, fi);
    fwrite(&imagen->desplazamiento, sizeof(int), 1, fi);
    fwrite(&imagen->tamanioMetadatos, sizeof(int), 1, fi);
    fwrite(&imagen->ancho, sizeof(int), 1, fi);
    fwrite(&imagen->alto, sizeof(int), 1, fi);
    fwrite(&imagen->numeroPlanos, sizeof(short), 1, fi);
    fwrite(&imagen->tamPixel, sizeof(short), 1, fi);
    fwrite(&imagen->tipoCompresion, sizeof(int), 1, fi);
    fwrite(&imagen->tamanioImagen, sizeof(int), 1, fi);
    fwrite(&imagen->pxmh, sizeof(int), 1, fi);
    fwrite(&imagen->pxmv, sizeof(int), 1, fi);
    fwrite(&imagen->coloresUsados, sizeof(int), 1, fi);
    fwrite(&imagen->coloresImportantes, sizeof(int), 1, fi);

    fwrite(imagen->pixel, sizeof(S_color), imagen->tamanioImagen, fi);


    fclose(fi);

    printf("\n El archivo %s se creo correctamente. \n",nombreArchivo);

    return 1;
}

