#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    FILE    *archivo;
    char    info[20];
    int     valor[5];
    char    NameReg[5][15] = {"MemTotal:","MemFree:","MemAvailable:","SwapTotal:","SwapFree:"};

    archivo = fopen("/proc/meminfo", "r");
    if (archivo == NULL){
        printf("%s", "No es posible abrir el archivo /proc/meminfo.\n");
    }   
    else{
        printf("%s","El archivo /proc/meminfo se abrio correctamente.\n");
    }

    while(fscanf(archivo,"%s", info) == 1){
        if(strcmp(info , NameReg[0]) == 0)            //Escanea el valor leido si es igual a MemTotal: y almacena el valor numerico de ese registro
            fscanf(archivo, "%d", &valor[0]);
        else if(strcmp(info , NameReg[1]) == 0)
            fscanf(archivo, "%d", &valor[1]);
        else if(strcmp(info, NameReg[2]) == 0)
            fscanf(archivo, "%d", &valor[2]);
        else if(strcmp(info, NameReg[3]) == 0)
            fscanf(archivo, "%d", &valor[3]);
        else if(strcmp(info, NameReg[4]) == 0)
            fscanf(archivo, "%d", &valor[4]);
    }

    for(int i=0; i<3; i++)
        printf("El registro %s %d MB. \n", NameReg[i],valor[i]/1000);
    
    printf("La Swap ocupada es %s %d MB - %s %d MB, que es igual a: %d MB. \n", NameReg[3], valor[3]/1000, NameReg[4], valor[4]/1000, (valor[3]-valor[4])/1000);

    fclose(archivo);
    return 0;
}