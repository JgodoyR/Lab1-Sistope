/*
Autor: Jordan Godoy
*/

#include "struct.h"
#include "funciones.h"
#include "io.h"

//Funcion principal
int main(int argc, char** argv){

    int c;

    //Se le asigna memoria a las estructuras
    struct datos *dato = (struct datos*)calloc(1, sizeof(struct datos));
    struct datosZoom *dz = (struct datosZoom*)calloc(1, sizeof(struct datosZoom));

    if(argc > 14){
        printf("\nLa cantidad de parametros de entrada ingresados excede la cantidad solicitada.\n");
        return 0;
    }
    else if(argc < 12){
        printf("\nLa cantidad de parametros de entrada ingresados es menor a la cantidad solicitada.\n");
        return 0;
    }

    //getopt
    else{
        while((c = getopt(argc, argv, "I:Z:S:M:N:r:b")) != -1){
            switch(c){
                case 'I':
                    dato->imagenEntrada = optarg;
                    break;
                case 'Z':
                    dato->imagenZoom = optarg;
                    break;
                case 'S':
                    dato->imagenSuavizada = optarg;
                    break;
                case 'M':
                    dato->filasImagen = atoi(optarg);
                    if(dato->filasImagen <= 0){
                        printf("\nLa cantidad de filas de la imagen debe ser mayor a 0.\n");
                        exit(0);
                    }
                    break;
                case 'N':
                    dato->columnasImagen = atoi(optarg);
                    if(dato->columnasImagen <= 0){
                        printf("\nLa cantidad de columnas de la imagen debe ser mayor a 0.\n");
                        exit(0);
                    }
                    break;
                case 'r':
                    dato->factor = atoi(optarg);
                    if(dato->factor <= 0){
                        printf("\nEl factor debe ser mayor a 0.\n");
                        exit(0);
                    }
                    break;
                case 'b':
                    dato->bandera = 1;
                    break;
                case '?':
                    if(optopt == 'b'){
                        fprintf(stderr, "La opcion -%c requiere un argumento.\n", optopt);
                    }
                    else if(isprint (optopt)){
                        fprintf(stderr, "La opcion '-%c' requiere un argumento.\n", optopt);
                    }
                    else{
                        fprintf(stderr, "Opcion con caracter desconocido '\\x%x'.\n", optopt);
                    }   
                    return 1;
                default:
                    abort();
            }
        }
    }

    //Se calcula las nuevas dimensiones de la imagen con zoom
    dz->filasZoom = dato->filasImagen * dato->factor;

    dz->columnasZoom = dato->columnasImagen * dato->factor;

    //Se lee la imagen de entrada
    leerImagen(dato->imagenEntrada, dato->filasImagen, dato->columnasImagen);

    //Se hace el zoom a la imagen
    zoomInImagen(matrizImagen, dato->filasImagen, dato->columnasImagen, dato->factor);

    //Se libera la memoria de la matriz inicial
    liberarMemoria(matrizImagen, dato->filasImagen);

    //Se realiza el suavizado de la imagen
    suavizarImagen(matrizZoomIn, dz->filasZoom, dz->columnasZoom);

    //Se escriben los resultados
    escribirResultados(dato->imagenZoom, matrizZoomIn, dz->filasZoom, dz->columnasZoom, dato->bandera);

    return 0;

}