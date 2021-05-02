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

    matrizConZoom = (float **)malloc((filas*factorReplicacion) * sizeof(float*));
    for(int i = 0; i < filas*factorReplicacion; i++){
        matrizConZoom[i] = (float *)malloc((columnas*factorReplicacion) * sizeof(float));
    }

    int a = 0;
    int b = 0;

    for(int i = 0; i < filas; i++){
        //printf("\n1");
        for(int j = 0; j < columnas; j++){
            //printf("\n2");
            for(int k = a; k < a+factorReplicacion; k++){
                //printf("\n3");
                for(int l = b; l < b+factorReplicacion; l++){
                    //printf("\n4");
                    matrizConZoom[k][l] = matriz[i][j];
                }
            }
            b = b + factorReplicacion;
        }
        a = a + factorReplicacion;
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
