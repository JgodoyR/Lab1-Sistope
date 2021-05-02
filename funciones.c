#include "struct.h"
#include "funciones.h"
#include "io.h"

/*
Entradas: Matriz de la imagen x Matriz vacia para almacenar la nueva matriz x Filas de la imagen x 
        Columnas de la imagen x Factor de replicacion de la imagen
Funcionamiento:
Salida: No tiene
*/
void zoomInImagen(float** matriz, float** matrizConZoom, int filas, int columnas, int factorReplicacion){

    matrizZoomIn = (float **)malloc(filas * sizeof(float*));
    for(int i = 0; i < filas; i++){
        matrizZoomIn[i] = (float *)malloc(columnas * sizeof(float));
    }

}

/*
Entradas: Matriz x Filas de la imagen x Columnas de la imagen
Funcionamiento: Funcion que libera memoria
Salida: No tiene
*/
void liberarMemoria(float **matriz, int filas, int columnas){

    for(int i = 0; i < filas; i++){
        for(int j = 0; j < columnas; j++){
            free(matriz[i]);
        }
    }

}
