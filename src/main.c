#include <stdio.h>
#include "cpu.h"
#include "mem.h"


int main(){
    //Llamar a las funciones main de los distintos programas
    printf("Empezando a leer memoria: \n");
    main_mem();
    printf("\nTerminando de leer memoria. \n");
    printf("_________________________________________________\n");
    printf("Empezando a leer CPU: \n");
    main_cpu();
    printf("\nTerminando de leer CPU. \n");
    
    return 0;
}