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

    liberarMemoriaMatriz(matrizImagen, filas);

    //suavizarImagen(matrizZoomIn, filas*factorReplicacion, columnas*factorReplicacion);

}

/*
Entradas: Matriz x Filas de la imagen con zoom x Columnas de la imagen con zoom
Funcionamiento: Funcion que suaviza la imagen, cambiando el valor de un pixel por la media de su vecindario
Salida: No tiene
*/
void suavizarImagen(float** matrizConZoom, int filasZ, int columnasZ){

    //Se le asigna memoria a la matriz de suavizado
    matrizSuavizada = (float **)malloc(filasZ * sizeof(float*));
    for(int i = 0; i < filasZ; i++){
        matrizSuavizada[i] = (float *)malloc(columnasZ * sizeof(float));
    }

    //Se recorre la matriz zoom
    for(int i = 0; i < filasZ; i++){
        for(int j = 0; j < columnasZ; j++){

            //Casos bases (esquinas de la matriz)
            if((i == 0 && j == 0) || (i == filasZ-1 && j == 0) || (i == 0 && j == columnasZ-1) || (i == filasZ-1 && j == columnasZ-1)){

                //Esquinas de la matriz
                //Se suman los 3 elementos alrededor del pixel y se calcula su media, la cual equivaldra al pixel de la matriz suavizada

                //Esquina superior izquierda
                if(i == 0 && j == 0){
                    matrizSuavizada[i][j] = (matrizConZoom[i+1][j+1] + matrizConZoom[i][j+1] + matrizConZoom[i+1][j])/3;
                }
                //Esquina inferior izquierda
                else if(i == filasZ-1 && j == 0){
                    matrizSuavizada[i][j] = (matrizConZoom[i-1][j] + matrizConZoom[i-1][j+1] + matrizConZoom[i][j+1])/3;
                }
                //Esquina superior derecha
                else if(i == 0 && j == columnasZ-1){
                    matrizSuavizada[i][j] = (matrizConZoom[i+1][j-1] + matrizConZoom[i+1][j] + matrizConZoom[i][j-1])/3;
                }
                //Esquina inferior derecha
                else{
                    matrizSuavizada[i][j] = (matrizConZoom[i-1][j-1] + matrizConZoom[i-1][j] + matrizConZoom[i][j-1])/3;
                }
            }
            //Caso recursivo
            else{

                //bordes de la matriz
                //Se suman los 5 elementos alrededor del pixel y se calcula su media, la cual equivaldra al pixel de la matriz suavizada

                //Borde superior
                if(i == 0 && j != columnasZ-1 && j != 0){
                    matrizSuavizada[i][j] = (matrizConZoom[i][j-1] + matrizConZoom[i+1][j-1] + matrizConZoom[i+1][j] + matrizConZoom[i+1][j+1] + matrizConZoom[i][j+1])/5;
                }
                //Borde derecho
                else if(j == columnasZ-1 && i != filasZ-1 && i != 0){
                    matrizSuavizada[i][j] = (matrizConZoom[i-1][j] + matrizConZoom[i-1][j-1] + matrizConZoom[i][j-1] + matrizConZoom[i+1][j-1] + matrizConZoom[i+1][j])/5;
                }
                //Borde izquierdo
                else if(j == 0 && i != filasZ-1 && i != 0){
                    matrizSuavizada[i][j] = (matrizConZoom[i-1][j] + matrizConZoom[i-1][j+1] + matrizConZoom[i][j+1] + matrizConZoom[i+1][j+1] + matrizConZoom[i+1][j])/5;
                }
                //Borde inferior
                else if(i == filasZ-1 && j != columnasZ-1 && j != 0){
                    matrizSuavizada[i][j] = (matrizConZoom[i][j-1] + matrizConZoom[i-1][j-1] + matrizConZoom[i-1][j] + matrizConZoom[i-1][j+1] + matrizConZoom[i][j+1])/5;
                }

                //Centro de la matriz
                else{
                    //Se suman los 8 elementos alrededor del pixel y se calcula su media, la cual equivaldra al pixel de la matriz suavizada
                    matrizSuavizada[i][j] = (matrizConZoom[i-1][j-1] + matrizConZoom[i][j-1] + matrizConZoom[i+1][j-1] + matrizConZoom[i+1][j] + matrizConZoom[i+1][j+1] + matrizConZoom[i][j+1] + matrizConZoom[i-1][j+1] + matrizConZoom[i-1][j])/8;
                }
            }

        }
    }

    liberarMemoriaMatriz(matrizZoomIn, filasZ);

}

/*
Entradas: Matriz x Filas de la matriz
Funcionamiento: Funcion que libera memoria mediante la funcion free, se liberara el espacio de memoria de cada elemento de la matriz
                para finalmente liberar la memoria de la matriz entera.
Salida: No tiene
*/
void liberarMemoriaMatriz(float **matriz, int filas){

    //Se recorre toda la matriz liberando memoria de cada indice
    for(int i = 0; i < filas; i++){
            free(matriz[i]);
    }

    //Se libera la memoria de la matriz
    free(matriz);

}

/*
Entradas: Estructuras
Funcionamiento: Funcion que libera memoria mediante la funcion free, se liberara el espacio de memoria de cada elemento de la estructura
Salida: No tiene
*/
void liberarMemoria(struct datos *dato, struct datosZoom *dz){

    //Se libera la memoria de las estructuras
    free(dato);
    free(dz);

}
