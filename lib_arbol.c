
#include "librerias.h"
#include "funciones.h"
#include "lib_arbol.h"

P_NODO_ARBOL crearArbol()
{
    return NULL;
}
P_NODO_ARBOL alojar_nodo_arbol()
{
    return((P_NODO_ARBOL)malloc(sizeof(NODO_ARBOL))); /* Reservamos memoria */
}


P_NODO_ARBOL encontrar (P_NODO_ARBOL arbol, int tlf)
/* Devuelve un apuntador al nodo del arbol "arbol" cuyo contenido es "i", o
 NULL en caso de que no se encuentre este valor */
{
    if (arbol == NULL)    /* Arbol vacÌo por tanto devuelve NULL */
        return (NULL);

    if (arbol->telefono == tlf)    /* Hemos encontrado el valor */
        return (arbol);
    else if (arbol->telefono > tlf)    /* El valor actual es mayor que ir por tanto
                                   vamos hacia la izquierda */
        return(encontrar(arbol->izq, tlf));
    else    /* "i" es mayor que el valor actual */
        return(encontrar(arbol->der, tlf));
}


P_NODO_ARBOL insertar(P_NODO_ARBOL arbol, int i,char *nombre)
/* Inserta el valor "i" en el ·arbol apuntado por "arbol" y devuelve un puntero
 a la raÌz del ·rbol resultado.  */
{
    P_NODO_ARBOL p;    /* Para no perder la cabeza del arbol */

    if (arbol == NULL)
    {
        p = alojar_nodo_arbol();             /* Reservamos memoria */
        p->izq = p->der = NULL;             /* Acabamos de crearlo */
        p->telefono = i;//guardamos el tlf
        p->nombre=nombre;//guardamos el nombre
        return (p);
    }

    if (arbol->telefono == i)    /* El valor ya existe. No hacemos nada porque no
                               permitimos valores duplicados */
        return (arbol);

    if (arbol->telefono > i) /* "i" es menor que el valor que analizo, por tanto,
                           inserto a la izquierda */
        arbol->izq = insertar(arbol->izq, i,nombre);
    else  /* "i" es mayor que el valor actual, entonces, inserto a la derecha */
        arbol->der = insertar(arbol->der, i,nombre);

    return (arbol);
}


void mostrar_nombre(char *p)
{
    printf("Nombre: %s\n",p); //impripimos nombre
};
char *crear_nombre (char *p)
{
    fflush(stdin);
    //reservamos memoria
    char *buffer = (char *)malloc(sizeof(char)*255);
    printf("Introduzca el nombre: ");gets(buffer);
    p = (char *)malloc(sizeof(char)*(strlen(buffer)+1));
    strcpy(p,buffer);
    free(buffer);
    return p;
}
char *elemento_arbol(P_NODO_ARBOL a)
{
    return (a->nombre);
}
/** Devuelve 1 si el arbol esta vacio*/
int esVacio(P_NODO_ARBOL a)
{
	return (a==NULL);
}

void inOrder(P_NODO_ARBOL a, char *nombre)//Simetrico
{
	if (!esVacio(a))
	{
  		inOrder(a->izq,nombre);
  		//si el nombre coincide, mostramos el tlf y el nombre
  		if(strcmp(nombre,a->nombre)==0)
        {
            printf("Telefono : %d \n", a->telefono);
            mostrar_nombre(elemento_arbol(a));
        }
  		inOrder(a->der,nombre);
	}
	return 0;
}


