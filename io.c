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
    int nombreImagen = open(entrada, O_RDONLY);
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

        matrizImagen = (float **)malloc(filas * sizeof(float*));
        for(int i = 0; i < filas; i++){
            matrizImagen[i] = (float *)malloc(columnas * sizeof(float));
        }

        FILE* archivo = fopen(entrada, "rb");

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
void escribirResultados(char* nombre, float** matriz, int filas, int columnas){

    printf("\n%s", nombre);
    printf("\n%d", filas);
    printf("\n%d", columnas);

    FILE *archivoZ = fopen(nombre, "wb");

    printf("\nHola");

    for(int i = 0; i < filas; i++){
        fwrite(matriz[i], sizeof(float), columnas, archivoZ);
    }

    fclose(archivoZ);

}