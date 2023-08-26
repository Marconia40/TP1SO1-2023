#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    FILE    *archivo;
    char    *contenido = NULL;
    char    lectura[40];
    size_t  long_total = 0;

    archivo = fopen("/proc/version", "r");
    if (archivo == NULL)
        printf("%s", "No es posible abrir el archivo /proc/meminfo.\n"); 
    else
        printf("%s","El archivo /proc/meminfo se abrio correctamente.\n\n");
    

    while(fgets(lectura, sizeof(lectura), archivo) != NULL){
        size_t  long_lectura = strlen(lectura);
        contenido = realloc(contenido, long_total + long_lectura + 1);

        if(contenido == NULL){
            printf("Error de asignacion de memoria.");
            return 1;
        }

        strcpy(contenido + long_total, lectura);
        long_total += long_lectura;
    }

    fclose(archivo);

    printf("El tamanio de contenido es: %ld \n", sizeof(contenido));
    printf("Contenido de archivo /prc/version: \n %s \n", contenido);

    free(contenido);
    printf("El tamanio de contenido es: %ld \n", sizeof(contenido));
    
    return 0;
}