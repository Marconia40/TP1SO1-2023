#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    FILE    *archivo;
    char    info[20];
    //char    Hola[5] = "hola";
    int     valor[3];
    char    MemT[15] = "MemTotal:";
    char    MemF[15] = "MemFree:";
    char    MemA[15] = "MemAvailable:";

    archivo = fopen("/proc/meminfo", "r");
    if (archivo == NULL){
        printf("%s", "No es posible abrir el archivo /proc/meminfo.\n");
    }   
    else{
        printf("%s","El archivo /proc/meminfo se abrio correctamente.\n");
    }

    while(fscanf(archivo,"%s", info) == 1){
        if(strcmp(info , MemT) == 0){
            fscanf(archivo, "%d", &valor[0]);
        }
        else if(strcmp(info , MemF) == 0){
            fscanf(archivo, "%d", &valor[1]);
        }
        else if(strcmp(info, MemA) == 0){
            fscanf(archivo, "%d", &valor[2]);
        }
    }

    
    printf("%s %d MB. \n", MemT,valor[0]/1000);
    printf("%s %d MB. \n", MemF,valor[1]/1000);
    printf("%s %d MB. \n", MemA,valor[2]/1000);
    
    fclose(archivo);
    return 0;
}