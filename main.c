#include "librerias.h"
#include "funciones.h"
#include "lib_arbol.h"
// redirije cada ejercicio
int main()
{
    int r;
    while(r!=3)
    {
        r=menu();
        if(r==1)
        {
            ejercicio1();
        }if(r==2)
        {
           ejercicio2();
        }
    }
    return 0;
}
