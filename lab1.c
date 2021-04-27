/*
Autor: Jordan Godoy
*/

#include "struct.h"

float **matrizImagen;

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
        /*printf("%s %d %d\n", entrada, filas, columnas);
        for(int i = 0; i < filas; i++){
            fread(matrizImagen[i], sizeof(int), columnas, archivo);
        }*/
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
/*
float** crearMatriz(int filas, int columnas){

    matriz = (float**)malloc(filas*sizeof(float));
    

}
*/


//Funcion principal
int main(int argc, char** argv){

    int c;
    struct datos *dato = (struct datos*)calloc(1, sizeof(struct datos));
    //struct datos *dato = (struct* dato) malloc(sizeof(struct*) * 1);

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

    printf("\nI = %s\nZ = %s\nS = %s\nM = %i\nN = %i\nr = %i\nb = %i\n", dato->imagenEntrada, dato->imagenZoom, dato->imagenSuavizada, dato->filasImagen, dato->columnasImagen, dato->factor, dato->bandera);

    //leerImagen(dato->imagenEntrada, dato->filasImagen, dato->columnasImagen);
    leerImagen(dato->imagenEntrada);

    return 0;

}