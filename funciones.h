#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

int menu(void);
int ejercicio1(void);
int ejercicio2(void);
// por si interesa llevar un registro de las ciudades y donde esta colocada
struct ciudad
{
    int num; // posicion colummna en la matriz de adyacencia
    char *nombre; // campo nombre

};

struct ciudad *crear_ciudad(struct ciudad *c,int *conta_posicion,char *);
void mostrar_ciudades(struct ciudad *c,int conta_posicion);
void warshall (bool *c, bool *a, unsigned int nNodos);
void posicion_matriz(struct ciudad *c,int *p1,int *p2,int conta_posicion,char *n1,char *n2);
void mas_corto( int *c,  int *A, int *P,  int nNodos);

#endif // FUNCIONES_H_INCLUDED
