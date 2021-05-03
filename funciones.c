#include "struct.h"
#include "funciones.h"
#include "io.h"

/*
Entradas: Matriz de la imagen x Filas de la imagen x Columnas de la imagen x Factor de replicacion de la imagen
Funcionamiento: Funcion que 
Salida: No tiene
*/
void zoomInImagen(float** matriz, int filas, int columnas, int factorReplicacion){

    //Se le asigna memoria a la matriz zoom in
    matrizZoomIn = (float **)malloc((filas*factorReplicacion) * sizeof(float*));
    for(int i = 0; i < filas*factorReplicacion; i++){
        matrizZoomIn[i] = (float *)malloc((columnas*factorReplicacion) * sizeof(float));
    }

    int aux1 = 0; 
    //Se recorren las filas de la matriz inicial
    for(int i = 0; i < filas; i++){
        //Se reinicia el contador de la columna
        int aux2 = 0;
        //Se recorren las columnas de la matriz inicial
        for(int j = 0; j < columnas; j++){
            //Se replica el pixel en las filas
            for(int k = aux1; k < (aux1+factorReplicacion); k++){
                //Se replica el pixel en las columnas
                for(int l = aux2; l < (aux2+factorReplicacion); l++){
                    //Se almacenan en la nueva matriz zoom in
                    matrizZoomIn[k][l] = matriz[i][j];
                }
            }
            //Se aumenta el contador de la columna
            aux2 += factorReplicacion;
        }
        //Se aumenta el contador de la fila
        aux1 += factorReplicacion;
    }

}

/*
void imprimirMatriz(float** matrizConZoom, int filasZ, int columnasZ){
    for(int x = 0; x < filasZ; x++){
        for(int y = 0; y < columnasZ; y++){
            printf("%.2f , ", matrizConZoom[x][y]);
        }
    }
    printf("\n");
}*/

/*
Entradas: Matriz x Filas de la imagen con zoom x Columnas de la imagen con zoom
Funcionamiento: Funcion que suaviza la imagen
Salida: No tiene
*/
void suavizarImagen(float** matrizConZoom, int filasZ, int columnasZ){

    //Se le asigna memoria a la matriz de suavizado
    matrizSuavizado = (float **)malloc(filasZ * sizeof(float*));
    for(int i = 0; i < filasZ; i++){
        matrizSuavizado[i] = (float *)malloc(columnasZ * sizeof(float));
    }



}

/*
Entradas: Matriz x Filas de la matriz
Funcionamiento: Funcion que libera memoria mediante la funcion free, se liberara el espacio de memoria de cada elemento de la matriz
                para finalmente liberar la memoria de la matriz entera.
Salida: No tiene
*/
void liberarMemoria(float **matriz, int filas){

    //Se recorre toda la matriz liberando memoria de cada indice
    for(int i = 0; i < filas; i++){
            free(matriz[i]);
    }

    //Se libera la memoria de la matriz
    free(matriz);

}
