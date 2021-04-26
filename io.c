#include "struct.h"

/*
Entradas: 
Funcionamiento:
Salida:
*/

int verificarEntrada(char* imagenEntrada){
    FILE* archivo;
    char* extension;
    archivo = fopen(imagenEntrada, "r");
    if(archivo != NULL){
        extension = strrchr(imagenEntrada, '.');
        if(strcmp(extension, ".raw") == 0){
            return 1;
        }
        else{
            printf("\nEl archivo no posee la extension adecuada.\n");
            return 0;
        }
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
void leerImagen(){

    FILE* archivo;
    archivo = fopen(imagenEntrada, "r");

    fclose(archivo);
}*/

/*
Entradas: 
Funcionamiento:
Salida:
*/
/*
void escribirResultados(){

    FILE *archivo = fopen();

    fclose(archivo);

}*/