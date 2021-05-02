#include "struct.h"

/*
Entradas: 
Funcionamiento:
Salida:
*/
//int leerImagen(char* entrada, int filas, int columnas){
int leerImagen(char* entrada){
    FILE* archivo;
    archivo = fopen(entrada, "rb");

    if(archivo != NULL){
        printf("\nLEYENDOOOOOOOOO\n");
        return 1;
    }
    else{
        printf("\nNo existe el archivo o se encuenta en otra ubicacion.\n");
        return 0;
    }

    fclose(archivo);
}

/*
Entradas: 
Funcionamiento:
Salida:
*/

int verificarEntrada(char* imagenEntrada){
    FILE* archivo;
    char* extension;
    archivo = fopen(imagenEntrada, "r");
    if(archivo != NULL){
        extension = strrchr(imagenEntrada, '.');
        if(strcmp(extension, ".raw") == 0){
            return 1;
        }
        else{
            printf("\nEl archivo no posee la extension adecuada.\n");
            return 0;
        }
    }
    else{
        printf("\nNo existe el archivo o se encuenta en otra ubicacion.\n");
        return 0;
    }

    fclose(archivo);

}

/*
Entradas: 
Funcionamiento:
Salida:
*/
int validarArchivoEntrada(char* entrada){  
    int archivo = open(entrada, O_RDONLY);
    if(archivo == -1){
        printf("\nNo existe el archivo o se encuenta en otra ubicacion.\n");
        exit(-1);
    }
    else{

        //probando

        extension = strrchr(imagenEntrada, '.');
        if(strcmp(extension, ".raw") == 0){
            return 1;
        }
        else{
            printf("\nEl archivo no posee la extension adecuada.\n");
            return 0;
        }

        return 1;
    }
}

/*
Entradas: 
Funcionamiento:
Salida:
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
Entradas: 
Funcionamiento:
Salida:
*/
void escribirResultados(char* nombre, float** matrizImagen, int filas, int columnas){

    FILE* archivo = fopen(nombre, "wb");

    for(int i = 0; i < filas; i++){
        fwrite(matriz[i], sizeof(float), columnas, archivo);
    }

    fclose(archivo);

}