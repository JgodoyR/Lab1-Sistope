#ifndef IO_H
#define IO_H

int validarArchivoEntrada(char* entrada);  

int bandera(int band);

void leerImagen(char* entrada, int filas, int columnas);

void escribirResultados(char* nombre, float** matriz, int filas, int columnas);

#endif