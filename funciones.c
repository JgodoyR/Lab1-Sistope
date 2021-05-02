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

    int aux1 = 0; 
    for(int i = 0; i < filas; i++){
        int aux2 = 0;
        for(int j = 0; j < columnas; j++){
            for(int k = aux1; k < (aux1+factorReplicacion); k++){
                for(int l = aux2; l < (aux2+factorReplicacion); l++){
                    matrizConZoom[k][l] = matriz[i][j];
                }
            }
            aux2 += factorReplicacion;
        }
        aux1 += factorReplicacion;
    }

    //liberarMemoria(matriz, filas);
/*
    for(int x = 0; x < filas*factorReplicacion; x++){
        for(int y = 0; y < columnas*factorReplicacion; y++){
            printf("%.2f , ", matrizConZoom[x][y]);
        }
    }
    printf("\n");*/

}

/*
Entradas: Matriz x Filas de la imagen x Columnas de la imagen
Funcionamiento: Funcion que suaviza la imagen
Salida: No tiene
*/
/*
void suavizarImagen(float** matrizConZoom, int filasZ, int columnasZ){

}*/


/*
Entradas: Matriz x Filas de la imagen x Columnas de la imagen
Funcionamiento: Funcion que libera memoria
Salida: No tiene
*/
void liberarMemoria(float **matriz, int filas){

    for(int i = 0; i < filas; i++){
            free(matriz[i]);
    }

    free(matriz);

}
