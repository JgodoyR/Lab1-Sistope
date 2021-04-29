/*
Autor: Jordan Godoy
*/

#include "struct.h"

float** matrizImagen;

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
        return 1;
    }
}

//int leerImagen(char* entrada, int filas, int columnas){
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
                //printf("\nPENE\n");
                //read(archivo, matrizImagen[i], columnas);
                fread(matrizImagen[i], sizeof(float), columnas, archivo);
                //matrizImagen[i][j] = read(archivo, matrizImagen[i], columnas);
                //matrizImagen[i] = read(archivo, matrizImagen, columnas);
            //}
        }

        int cont = 0;
        for(int i = 0; i < filas; i++){
            for(int j = 0; j < columnas; j++){
                printf("%.2f ", matrizImagen[i][j]);
                cont += 1;
            }
        }
        printf("\n%d\n", cont);

        //fclose(archivo);
    }

}
    /*FILE* archivo;
    archivo = fopen(entrada, "rb");

    if(archivo != NULL){
        printf("\nLEYENDOOOOOOOOO\n");
        printf("%s %d %d\n", entrada, filas, columnas);
        for(int i = 0; i < filas; i++){
            fread(matrizImagen[i], sizeof(int), columnas, archivo);
        }
        return 1;
    }
    else{
        printf("\nNo existe el archivo o se encuenta en otra ubicacion.\n");
        exit(-1);
    }

    fclose(archivo);*/

void escribirResultados(char* nombre, int filas, int columnas){

    FILE* archivo = fopen(nombre, "wb");

    for(int i = 0; i < filas; i++){
        fwrite(matrizImagen[i], sizeof(float), columnas, archivo);
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

    leerImagen(dato->imagenEntrada, dato->filasImagen, dato->columnasImagen);
    //leerImagen(dato->imagenEntrada);

    escribirResultados(dato->imagenZoom, dato->filasImagen, dato->columnasImagen);

    return 0;

}