#include "librerias.h"
#include "funciones.h"
#include "lib_arbol.h"
// menu con las opciones del comienzo
int menu(void)
{
    int respuesta;
    puts("1- EJERCICIO 1");
    puts("2- EJERCICIO 2");
    puts("3- SALIR");
    printf("Respuesta: ");
    fflush(stdin);
    scanf("%d",&respuesta);
    return respuesta;
}
