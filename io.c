#include "struct.h"
#include "funciones.h"
#include "io.h"

//Variable global
int flag = 0;

/*
Entradas: Nombre de la imagen
Funcionamiento: Funcion que valida que exista la imagen en el directorio dado
Salida: Entero (0 o 1)
*/
int validarArchivoEntrada(char* entrada){  
    //char* extension;
    //Se abre el archivo de entrada
    int nombreImagen = open(entrada, O_RDONLY);

    //Se comprueba la existencia del archivo de entrada
    if(nombreImagen == -1){
        printf("\nNo existe el archivo o se encuenta en otra ubicacion.\n");
        exit(-1);
    }
    else{/*
        extension = strrchr(entrada, '.');
        if(strcmp(extension, ".raw") == 0){
            return 1;
        }
        else{
            printf("\nEl archivo no posee la extension adecuada.\n");
            return 0;
        }*/
        return 1;
    }
}

/*
Entradas: Bandera
Funcionamiento: Funcion que comprueba el valor de la bandera, y le asigna dicho valor a una variable global 
                llamada flag.
Salida: Entero (0 o 1)
*/
int bandera(int band){

    //Se comprueba que exista la bandera
    if(band){
        flag = 1;
    }

    return flag;

}

/*
Entradas: Nombre del archivo de entrada x Filas de la imagen x Columnas de la imagen
Funcionamiento: Funcion que lee una imagen en formato ".raw", le asigna memoria a una matriz  y
                almacena los datos de la imagen en dicha matriz.
Salida: No tiene
*/
void leerImagen(char* entrada, int filas, int columnas){

    if(validarArchivoEntrada(entrada) == 1){

        //Se asigna memoria a la matriz que contendra los elementos de la imagen
        matrizImagen = (float **)malloc(filas * sizeof(float*));
        for(int i = 0; i < filas; i++){
            matrizImagen[i] = (float *)malloc(columnas * sizeof(float));
        }

        //Se abre el archivo en modo lectura "rb", el cual abre archivos binarios
        FILE* archivo = fopen(entrada, "rb");

        //Se almacena todo el contenido de la imagen en una matriz
        for(int i = 0; i < filas; i++){
            fread(matrizImagen[i], sizeof(float), columnas, archivo);
        }

        fclose(archivo);
    }

}
    
/*
Entradas: Nombre del archivo de salida x Matriz a escribir x Filas de la imagen x Columnas de la imagen
Funcionamiento: Funcion que escribe un archivo en formato ".raw" con el contenido de una matriz
Salida: No tiene
*/
void escribirResultados(char* nombre, float** matrizConZoom, int filasZ, int columnasZ, int band){

    //Si existe la bandera, se imprime por pantalla el valor de las filas y columnas de la imagen con zoom
    if(bandera(band)){
        printf("\nLas filas con zoom son: %d", filasZ);
        printf("\nLas columnas con zoom son: %d\n", columnasZ);
    }

    FILE* archivo = fopen(nombre, "wb");

    //Se recorre la matriz y se escribe en un archivo binario el contenido de esta
    for(int z = 0; z < filasZ; z++){
        fwrite(matrizConZoom[z], sizeof(float), columnasZ, archivo);
    }

    fclose(archivo);

}