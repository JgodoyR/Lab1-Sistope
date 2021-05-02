/*
Autor: Jordan Godoy
*/

#include "struct.h"

/*
Entradas: Nombre de la imagen
Funcionamiento: Funcion que valida que exista la imagen en el directorio dado
Salida: Entero (0 o 1)
*/
int validarArchivoEntrada(char* entrada){  
    int archivo = open(entrada, O_RDONLY);
    if(archivo == -1){
        printf("\nNo existe el archivo o se encuenta en otra ubicacion.\n");
        exit(-1);
    }
    else{
        return 1;
    }
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
        //int archivo = open(entrada, O_RDONLY);

        for(int i = 0; i < filas; i++){
            //for(int j = 0; j < columnas; j++){
                //read(archivo, matrizImagen[i], columnas);
                fread(matrizImagen[i], sizeof(float), columnas, archivo);
                //matrizImagen[i][j] = read(archivo, matrizImagen[i], columnas);
                //matrizImagen[i] = read(archivo, matrizImagen, columnas);
            //}
        }
/*
        int cont = 0;
        for(int i = 0; i < filas; i++){
            for(int j = 0; j < columnas; j++){
                printf("%.2f ", matrizImagen[i][j]);
                cont += 1;
            }
        }
        printf("\n%d\n", cont);
*/
        fclose(archivo);
    }

}
    
/*
Entradas: Nombre del archivo de salida x Matriz a escribir x Filas de la imagen x Columnas de la imagen
Funcionamiento: Funcion que escribe un archivo en formato ".raw" con el contenido de una matriz
Salida: No tiene
*/
void escribirResultados(char* nombre, float** matriz, int filas, int columnas){

    FILE* archivo = fopen(nombre, "wb");
/*
    for(int i = 0; i < filas; i++){
        fwrite(matrizImagen[i], sizeof(float), columnas, archivo);
    }
*/

    for(int i = 0; i < filas; i++){
        fwrite(matriz[i], sizeof(float), columnas, archivo);
    }

    fclose(archivo);

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

//Funcion principal
int main(int argc, char** argv){

    int c;
    struct datos *dato = (struct datos*)calloc(1, sizeof(struct datos));
    //struct datos *dato = (struct*)malloc(sizeof(struct) * 1);

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

    leerImagen(dato->imagenEntrada, dato->filasImagen, dato->columnasImagen);

    //escribirResultados(dato->imagenZoom, matrizImagen, dato->filasImagen, dato->columnasImagen);

    return 0;

}