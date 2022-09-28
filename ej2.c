#include "librerias.h"
#include "funciones.h"
#include "lib_arbol.h"
/*
[5 puntos]. EJERCICIO 2: Planificaci�n de rutas.
Se desea desarrollar un programa que asista a la planificaci�n de rutas en una empresa de
transportes. Al iniciar, el programa cargar� informaci�n del fichero �carreteras.txt�
(adjunta a esta hoja de ejercicios) que contiene informaci�n de ciudades y conexiones
existentes entre las mismas por carretera, as� como la distancia en kil�metros. Haciendo
uso de los distintos algoritmos estudiados en la asignatura para resoluci�n de problemas
sobre grafos, el programa ofrecer� un men� con las siguientes opciones:
a) Comprobar validez del fichero. El programa comprobar� que el fichero
�carreteras.txt� es correcto y que no existen ciudades aisladas o ciudades
inalcanzables partiendo de otra ciudad.
b) Obtener ruta m�s corta. El programa solicitar� el nombre de una ciudad origen y
otra destino, para calcular la ruta m�s corta (en kil�metros) que deber� seguirse
entre estas ciudades para hacer la entrega de una paquete en la ciudad destino.
NOTA. Se puede cambiar el formato del fichero, y si es as�, incluir el nuevo fichero en la
entrega de la tarea. Si no se entrega, el ejercicio no ser� no v�lido.

 */
int ejercicio2(void)
{
    int opcion;
    // fichero
    FILE *fp;
    // variables datos
    char nombre[50],aux[50],aux_1[50],aux_2[50],aux_3[50];
    int distancia;
    // guardar datos de las ciudades
    struct ciudad *ciudades;
    int conta_posicion=0;
    int conta_ruta=0;
    //warshall matriz de adyacencia sin peso
    bool *c_W;
    //floyd matriz de adyacencia con peso
    int *c_F;
    bool *a;
    int *P;
    unsigned int n_Nodos;
    int i,j;
    int posicion_1=0,posicion_2=0;
    // warshall
    while(opcion!=3)
    {
        puts("\n1- COMPROBAR VALIDEZ DEL FICHERO");
        puts("2- OBTENER LA RUTA MAS CORTAS");
        fflush(stdin);
        scanf("%d",&opcion);
        //validez
        if(opcion==1)
        {
            puts("Procedemos a comprobar si hay ciudades aisladas o inalcazables");
            printf("Introduzca el nombre del fichero con las ciudades(nodos): ");
            fflush(stdin); gets(nombre);
            //abrimos el fichero
            if((fp=fopen(nombre,"r"))!=NULL)
            {
                //lectura hasta el final del archivo
                while (!feof(fp))
                {
                    // el primer nodo lo registra correctamente, los dem�s dice que ya esta registrado. ?
                    fscanf(fp,"%s",&aux);
                    // pasamos la posici�n en la matriz y el nombre
                    ciudades=crear_ciudad(ciudades,&conta_posicion,&aux);

                }
                // comprobacion de que se guardo correctamente
                mostrar_ciudades(ciudades,conta_posicion);
                n_Nodos=conta_posicion;
                printf("\nEl num de nodos es %d:",n_Nodos);
                //warshall
                c_W = (bool *)malloc(sizeof(bool)*(n_Nodos * n_Nodos));
                P = (int *)malloc(sizeof(int)*(n_Nodos * n_Nodos));
                c_F = (int *)malloc(sizeof(int)*(n_Nodos * n_Nodos));
                a = (bool *)malloc(sizeof(bool)*(n_Nodos * n_Nodos));
            }//si se ha produciod un error
            else{printf("Error lectura del fichero de ciudades");
            }
            printf("\nIntroduzca el nombre del fichero con las carreteras(aristas): ");fflush(stdin); scanf("%s",&nombre);
            if((fp=fopen(nombre,"r"))!=NULL)
            {
                while (!feof(fp))
                {
                    fscanf(fp,"%s %s %i",&aux_2,&aux_3,&distancia);
                    //printf("---%s %s %i\n",aux_2,aux_3,distancia);
                    posicion_matriz(ciudades,&posicion_1,&posicion_2,conta_posicion,&aux_2,&aux_3);
                    // si se ha encontrado una carretera que conecta dos ciudades registradas
                    if((posicion_1>0)&&(posicion_2>0))
                    {
                        //posicion en el arraay unidimensional como si fuera multidimensional
                        c_W[posicion_1*n_Nodos+posicion_2]=true;
                        c_W[posicion_2*n_Nodos+posicion_1]=true;
                        c_F[posicion_1*n_Nodos+posicion_2]=distancia;
                        c_F[posicion_2*n_Nodos+posicion_1]=distancia;
                       //simetria : c_W[posicion_1+posicion_2*n_Nodos]=true;
                    }
                    else
                    {
                        //posicion en el arraay unidimensional como si fuera multidimensional
                        c_W[posicion_1*n_Nodos+posicion_2]=false;
                        c_W[posicion_2*n_Nodos+posicion_1]=false;
                        c_F[posicion_1*n_Nodos+posicion_2]=-1;
                        c_F[posicion_2*n_Nodos+posicion_1]=-1;
                        // simetria : c_W[posicion_1+posicion_2*n_Nodos]=false;
                    }
                   // rutas=crearRuta(rutas,&conta_ruta,posicion_1,posicion_2);

                }

                warshall (c_W,a,n_Nodos);
                puts("\nSi la siguiente matriz es todos unos, todas las ciudades estan conectadas");
                puts("\n-----\n");
                for (i=0;i<n_Nodos;i++)
                {
                    for (j=0;j<n_Nodos;j++)
                        printf("%d\t",a[i*n_Nodos+j]);
                    printf("\n");
                }
            }
            else{printf("Error lectura del fichero de carreteras");
            }


        }
        //ruta minima
        if(opcion==2)
        {
        //parece no funcionar correctamente
            mas_corto(c_F,a,P,n_Nodos);
            for (i=0;i<n_Nodos;i++)
                {
                    for (j=0;j<n_Nodos;j++)
                        printf("%d\t",a[i*n_Nodos+j]);
                    printf("\n");
                }

        }
    }

};
