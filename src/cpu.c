#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(){

    FILE    *archivo;
    char    info[30];
    int     cont = 0;
    //int     valor[2];
    char    nameReg[8][20] = {"model","name","stepping","siblings","cpu","cores",":","power"};
    char    nameCpu[70];

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
        else if(strcmp(info, nameReg[7]) == 0)
        break;
    }
    printf("nameCpu: %s \n", nameCpu);

    /*
    for(int i=0;i<15;i++){
        fscanf(archivo,"%s",info);
        printf(". %s . \n", info);
    }*/

    fclose(archivo);
    return 0;
}