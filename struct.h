#ifndef STRUCT_H
#define STRUCT_H

//Importacion de librerias
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
//#include <math.h>
#include <sys/stat.h>
#include <fcntl.h>

//Variables globales
float** matrizImagen;
float** matrizZoomIn;
//float** matrizSuavizado;

//Estructura datos de entrada
struct datos{
    char *imagenEntrada;                //Nombre de la imagen de entrada
    char *imagenZoom;                   //Nombre de la imagen resultante del zoom-in
    char *imagenSuavizada;              //Nombre de la imagen resultante del suavizado
    int filasImagen;                    //Numero de filas de la imagen
    int columnasImagen;                 //Numero de columnas de la imagen
    int factor;                         //Factor de replicacion para zoom-in
    int bandera;                        //bandera que indica si se entregan resultados por consola (0 o 1)
};

struct datosZoom{
    int filasZoom;                      //Numero de filas de la imagen con el Zoom aplicado
    int columnasZoom;                   //Numero de columnas de la imagen con el Zoom aplicado
};

#endif