#include "librerias.h"
#include "funciones.h"
#include "lib_arbol.h"
// comprobacion de que se guardo correctamente
 struct ciudad *crear_ciudad(struct ciudad *c,int *conta_posicion,char *nombre_ciudad)
{
         /**< char buffer[255] */
    char *buffer = (char *)malloc(sizeof(char)*255);
    if  (*conta_posicion == 0)
    {
        c = (struct ciudad *)malloc(sizeof(struct ciudad));
    }
    /**< ARRAY DINAMICO CON CIUDADES YA REGISTRADAS */
    else
    {
        c = (struct ciudad *)realloc(c,sizeof(struct ciudad)*((*conta_posicion)+1));
    }

    strcpy(buffer,nombre_ciudad);
    c[*conta_posicion].nombre = (char *)malloc(sizeof(char)*(strlen(buffer)+1));
    strcpy(c[*conta_posicion].nombre,buffer);

    c[*conta_posicion].num=*conta_posicion;


    (*conta_posicion) = (*conta_posicion) + 1;
    free(buffer);
    return c;

};
// comprobacion de que se guardo correctamente
void mostrar_ciudades(struct ciudad *c,int conta_posicion)
{
    for(int i=0;i<conta_posicion;i++)
    {
        printf("\nNombre Ciudad : ");puts((c+i)->nombre);
        printf("Posicion Matriz: ");printf("%d",(c+i)->num);
    }
    return 0;
};


 void posicion_matriz(struct ciudad *c,int *p1,int *p2,int conta_posicion,char *n1,char *n2)
 {
    int a=0,i=0;
    *p1=0;
    *p2=0;
    printf("\n\nCiudad 1: %s",n1);printf("\nCiudad 2: %s",n2);
    while(i!=conta_posicion)
    {

       if((strcmp((n1),(c[i].nombre))==0)||(strcmp((n2),(c[i].nombre))==0))
       {
           if(a==1)
           {
               (*p2)=i;
               ++a;
           }
           if(a==0)
           {
               (*p1)=i;
               ++a;
           }


       }
       i++;
    }
    if(a==2)
    {
        printf("\nCarretera entre nodo %d y %d",*p1,*p2);
    }
    else
        {
            puts("Error. Carretera no encontrada");
        }

        return 0;
 };

 //algo.warshall
void warshall (bool *c, bool *a, unsigned int nNodos)
{
    int i,j,k;
    for (i = 0; i < nNodos; i++)
        for (j=0; j< nNodos; j++)
            //A[i][j] = C[i][j];
            a[(i*nNodos)+j] = c[(i*nNodos)+j];

        for (k = 0; k < nNodos; k++)
            for (i = 0; i < nNodos; i++)
                for (j=0; j< nNodos; j++)
                    //A[i][j] = A[i][j] || A[i][k] && A[k][j]; //Si hay un camino de ‘i’ a ‘j’ o si hay //un camino de ‘i’ a ‘j’ pasando por ‘k’
                    a[(i*nNodos)+j] = a[(i*nNodos)+j] || a[(i*nNodos)+k] && a[(k*nNodos)+j]; //Si hay un camino de ‘i’ a ‘j’ o si hay //un camino de ‘i’ a ‘j’ pasando por ‘k’

return 0;
}
//floyd
void mas_corto( int *C,  int *A, int *P,  int nNodos)
{
    int i,j,k;
    for (i = 0; i < nNodos; i++)
    {
            for(j=0; j < nNodos; j++)
            {
                // Inicializamos con el coste de los caminos directos
                A[i*nNodos+j] = C[i*nNodos+j]; P[i*nNodos+j] = -1;
            }
    }
    for (k = 0; k < nNodos; k++)
        for (i = 0; i < nNodos; i++)
            for (j=0; j< nNodos; j++)
                if (A[i*nNodos+k]+A[k*nNodos+j] < A[i*nNodos+j])
                {
                    A[i*nNodos+j] = A[i*nNodos+k] + A[k*nNodos+j];
                    P[i*nNodos+j] = k;
                }
return 0;
}
