#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    FILE    *archivo;



    archivo = fopen("/proc/meminfo", "r");
    if (archivo == NULL){
        printf("%s", "No es posible abrir el archivo /proc/meminfo.\n");
    }   
    else{
        printf("%s","El archivo /proc/meminfo se abrio correctamente.\n");
    }


    fclose(archivo);
    return 0;
}