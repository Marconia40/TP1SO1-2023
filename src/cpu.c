#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(){

    FILE    *archivo;
    char    info[30];
    int     cont = 0;
    char    nameReg[6][20] = {"model","name","siblings","cpu","cores","power"};
    char    nameCpu[70];
    int     nroHilos;
    int     nroCore;

    archivo = fopen("/proc/cpuinfo", "r");
    if (archivo == NULL){
        printf("%s", "No es posible abrir el archivo /proc/meminfo.\n");
    }   
    else{
        printf("%s","El archivo /proc/meminfo se abrio correctamente.\n");
    }

    while (fscanf(archivo,"%s", info) == 1)
    {
        if(strcmp(info , nameReg[0]) == 0){
            fscanf(archivo,"%s", info);
            if(strcmp(info , nameReg[1]) == 0){
                fscanf(archivo,"%s", info);
                fscanf(archivo,"%s", info);
                strcpy(nameCpu, info);
                while(cont < 5){
                    fscanf(archivo,"%s", info);
                    strcat(nameCpu, info);
                    strcat(nameCpu, " ");
                    cont++;
                }
            }
        }
        else if(strcmp(info, nameReg[2]) == 0){
            fscanf(archivo,"%s", info);
            fscanf(archivo,"%d", &nroHilos);
        }
        else if(strcmp(info, nameReg[3]) == 0){
            fscanf(archivo,"%s", info);
            if(strcmp(info , nameReg[4]) == 0){
                fscanf(archivo,"%s", info);
                fscanf(archivo,"%d", &nroCore);
            }
        }
        else if(strcmp(info, nameReg[5]) == 0)
        break;
    }
    printf("Modelo de CPU: %s \n", nameCpu);
    printf("Cantidad de Cores: %d \n", nroCore);
    printf("Cantidad de thread por cores es igual a (Cant de Hilos %d)/(Cant de Cores %d): %d \n", nroHilos, nroCore, nroHilos/nroCore);


    /*
    for(int i=0;i<15;i++){
        fscanf(archivo,"%s",info);
        printf(". %s . \n", info);
    }*/

    fclose(archivo);
    return 0;
}