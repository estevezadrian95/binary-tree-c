#include "arbol.h"



void crearArbolCompleto(t_arbol* pa)
{
    int dato=9;
    crearArbol(pa);
    cargarArbol(pa,&dato,comparar);
    dato=11;
    cargarArbol(pa,&dato,comparar);
    dato=10;
    cargarArbol(pa,&dato,comparar);
    dato=12;
    cargarArbol(pa,&dato,comparar);
    dato=6;
    cargarArbol(pa,&dato,comparar);
    dato=5;
    cargarArbol(pa,&dato,comparar);
    dato=7;
    cargarArbol(pa,&dato,comparar);
}


void crearArbolBalanceado(t_arbol *pa)
{
   int dato=9;
    crearArbol(pa);
    cargarArbol(pa,&dato,comparar);
    dato=11;
    cargarArbol(pa,&dato,comparar);
    dato=12;
    cargarArbol(pa,&dato,comparar);
    dato=6;
    cargarArbol(pa,&dato,comparar);
    dato=5;
    cargarArbol(pa,&dato,comparar);


}

void crearArbolAVl(t_arbol* pa)
{
  int dato=9;
    crearArbol(pa);
    cargarArbol(pa,&dato,comparar);
    dato=6;
    cargarArbol(pa,&dato,comparar);
    dato=5;
    cargarArbol(pa,&dato,comparar);
    dato=10;
    cargarArbol(pa,&dato,comparar);

}



