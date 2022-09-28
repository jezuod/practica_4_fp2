#include "librerias.h"
#include "funciones.h"
#include "lib_arbol.h"
/* [5 puntos]. EJERCICIO 1: El programa que adivina
Desarrollar una agenda telefónica mediante la estructura de datos de árboles binarios. Se
pide que la agenda telefónica realice las siguientes funciones:
a) Insertar un nuevo contacto. Para cada nuevo contacto que se quiera guardar, se
piden los siguientes datos: Nombre del nuevo contacto y su número de teléfono.
Para que la estructura de datos sea eficiente los contactos deben de estar
ordenados por el teléfono, según orden de inserción. Por ejemplo si se insertan los
siguientes contactos (Óscar, 611222444), (Juan, 600555111), (María, 609689691),
(Rosa, 698969696) y (Pepe, 685898585).
b) Buscar un contacto. Dado el nombre de un contacto, que introducirá el usuario por
pantalla, se pide devolver el número de teléfono asociado a dicho nombre. */
int ejercicio1(void)
{
    int opcion;
    char *nombre;
    P_NODO_ARBOL a = NULL;
    //reservamos memoria
    char *buffer =(char *)malloc(sizeof(char)*255);
    int telefono;
    while(opcion!=3)
    {
        puts("1- INSERTAR UN NUEVO CONTACTO");
        puts("2- BUSCAR CONTACTO");
        puts("3- SALIR");
        fflush(stdin);
        scanf("%d",&opcion);
        //insertar un nuevo contacto
        if(opcion==1)
        {
            printf("\nTlf:");
            fflush(stdin); scanf("%d",&telefono);
            nombre=crear_nombre(nombre);
            //insertamos el el arbol el nombre y el tlf
            a = insertar(a, telefono,nombre);
            printf("\nElemento insertado\n");
        }
        //buscar, por nombre y mostrar tlf
        if(opcion==2)
        {
            fflush(stdin);
            printf("\nCual es el nombre de la persona que queremos su tlf: ");
            //cogemos nombre
            gets(buffer);
            //recorremos todo el arbol y solo mostramos el tlf de nodo que coincide el nombre
            inOrder(a,buffer);
        }

    }


};
