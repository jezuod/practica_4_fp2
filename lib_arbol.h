#ifndef LIB_ARBOL_H_INCLUDED
#define LIB_ARBOL_H_INCLUDED
// estructura nodo del arbol
typedef struct nodo_arbol
{
    int telefono; // campo tlf
    char *nombre; // campo nombre
    struct nodo_arbol *izq; // hij hacia la izquierda
    struct nodo_arbol *der; // hijo hacia la derecha
} NODO_ARBOL, *P_NODO_ARBOL, *ARBOL_BIN;


P_NODO_ARBOL crearArbol();
P_NODO_ARBOL encontrar (P_NODO_ARBOL arbol, int );
P_NODO_ARBOL insertar(P_NODO_ARBOL arbol, int, char *);
char *elemento_arbol(P_NODO_ARBOL a);
void mostrar_nombre (char *);
char *crear_nombre (char *);
void inOrder(P_NODO_ARBOL a,char * );
int esVacio(P_NODO_ARBOL a);
#endif // LIB_ARBOL_H_INCLUDED
