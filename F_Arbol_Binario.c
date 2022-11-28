#include <stdio.h>
#include <stdlib.h>
#include"F_Arbol_Binario.h"

void crearArbol(t_arbol*p){

    *p=NULL;
}

int comparar(const t_info *d1,const t_info *d2){

    return d1->numero-d2->numero;
}

int ponerEnArbol(t_arbol* pa,t_info* pd,int(*comp)(const t_info*,const t_info*)){

    if(*pa==NULL)
    {
        *pa=(t_nodo*)malloc(sizeof(t_nodo));///PIDO MEMORIA
        (*pa)->info = *pd;
        (*pa)->der  = NULL;
        (*pa)->izq  = NULL;
        return 1;

    }

    if(comp(pd, &(*pa)->info)==0)
        return 0;///REPETIDO

    if(comp(pd, &(*pa)->info) > 0)
        return ponerEnArbol(&(*pa)->der, pd, comp);
    else
        return ponerEnArbol(&(*pa)->izq,pd,comp);

}

void mostrarNodo (const t_info *d){

    printf(" %d ",d->numero);
    //printf("\n%s\n",d->nombre);
}

void preorden(t_arbol*p){

    if(*p)
    {
        mostrarNodo(&(*p)->info);
        preorden(&(*p)->izq);
        preorden(&(*p)->der);
    }
}

void inorden(t_arbol*p){

    if(*p)
    {
        inorden(&(*p)->izq);
        mostrarNodo(&(*p)->info);
        inorden(&(*p)->der);
    }
}

void posorden(t_arbol*p){

    if(*p)
    {
        posorden(&(*p)->izq);
        posorden(&(*p)->der);
        mostrarNodo(&(*p)->info);
    }
}

int buscarR(t_arbol*p,t_info*d,int(*cmp)(const t_info *d1,const t_info *d2)){

    if((*p)&& cmp(d,&(*p)->info)==0){
        *d=(*p)->info;
        return 1;
    }
    if(*p && cmp(d,&(*p)->info)>0)
        return buscarR(&(*p)->der,d,cmp);
    if(*p && cmp(d,&(*p)->info)<0)
        return buscarR(&(*p)->izq,d,cmp);
    return 0;
}

size_t Contar_Nodo (const t_arbol *pa){

    if(*pa==NULL)
        return 0;

    return  Contar_Nodo(&(*pa)->izq)
           +Contar_Nodo(&(*pa)->der)
           +1;///cuenta la visita

}

size_t Contar_Nodo_Nievel (const t_arbol *pa, int nivel){

    if ( *pa ==NULL|| nivel <= 0)
        return 0;

    return  Contar_Nodo_Nievel(&(*pa)->izq , nivel-1 )
           +Contar_Nodo_Nievel(&(*pa)->der , nivel-1 )
           +1;///Cuenta la visita
}

size_t Contar_Hojas (const t_arbol *pa){

    if (*pa==NULL)
        return 0;

    return  Contar_Hojas(&(*pa)->izq)
           +Contar_Hojas(&(*pa)->der)
           +((*pa)->izq == NULL && (*pa)->der ==NULL);
}

int Contar_Hojas_Nivel (const t_arbol *pa, int nivel){

    if(*pa==NULL||nivel<=0)
        return 0;

    return  Contar_Hojas_Nivel(&(*pa)->izq,nivel-1)
           +Contar_Hojas_Nivel(&(*pa)->der,nivel-1)
           +((*pa)->izq == NULL && (*pa)->der ==NULL);

}

size_t Altura (const t_arbol *pa){

    size_t altDer, altIzq;
    if(*pa==NULL)
        return 0;
    altDer = Altura(&(*pa)->der);
    altIzq = Altura(&(*pa)->izq);

    return altDer>altIzq?
           altDer+1
           :altIzq+1;
}

size_t Contar_Nodos_ConHI(const t_arbol *pa){

    if(*pa==NULL)
        return 0;

    return  Contar_Nodos_ConHI(&(*pa)->izq)
           +Contar_Nodos_ConHI(&(*pa)->der)
           +((*pa)->izq!=NULL);

}

size_t Contar_Nodos_ConHD(const t_arbol *pa){

    if (*pa==NULL)
        return 0;

    return  Contar_Nodos_ConHD(&(*pa)->izq)
           +Contar_Nodos_ConHD(&(*pa)->der)
           +((*pa)->der!=NULL);
}

int esCompleto (const t_arbol *pa, int nivel){

    if(*pa==NULL)
        return nivel<=0;///devuelve una condicion

return  esCompleto(&(*pa)->izq,nivel-1)&&esCompleto(&(*pa)->der,nivel-1);
}

int Arbol_Completo (const t_arbol *pa){

    size_t alt = Altura(pa);

    return esCompleto(pa, alt);
}

int esBalanceado (const t_arbol *pa, int nivel){

    if(*pa==NULL)
        return nivel<=1;
    return  esBalanceado(&(*pa)->izq,nivel-1)&&esBalanceado(&(*pa)->der,nivel-1);
}

int Arbol_Balanceado (const t_arbol *pa){

    size_t alt=Altura(pa);
return esBalanceado(pa,alt);
}

int esAVL (const t_arbol *pa){

    if (*pa==NULL)
        return 1;

    if ( abs(Altura( &(*pa)->izq) - Altura(&(*pa)->der) ) > 1 )
        return 0;
    return  esAVL(&(*pa)->izq)
          &&esAVL(&(*pa)->der);
}

void Eliminar_Arbol(t_arbol *p){

    if (*p)
    {
        Eliminar_Arbol(&(*p)->izq);
        Eliminar_Arbol(&(*p)->der);
        free (*p);
        *p = NULL;
    }
}

size_t Eliminar_Arbol_y_Contar (t_arbol *p){

    if (*p)
    {
        size_t cant = Eliminar_Arbol_y_Contar(&(*p)->izq) +
                   Eliminar_Arbol_y_Contar(&(*p)->der);
        free (*p);
        *p = NULL;
        cant++;///sumo el nodo eliminado
        return cant;
    }
    return 0;
}

void Podar_Arbol(t_arbol* pa,int h){

    if(!*pa)
        return;

    Podar_Arbol(&(*pa)->izq,h-1);
    Podar_Arbol(&(*pa)->der,h-1);
    if(h<=0)
    {
        free(*pa);
        *pa=NULL;
    }
}

int Podar_Arbol_y_Contar(t_arbol* pa,int h){

    int c=0;
    if(!*pa)
        return 0;

    c+=Podar_Arbol_y_Contar(&(*pa)->izq,h-1);
    c+=Podar_Arbol_y_Contar(&(*pa)->der,h-1);
    if(h<=0)
    {
        free(*pa);
        *pa=NULL;
        c++;
        return c;
    }
    return c;
}

void crearArbolCompleto(t_arbol* pa){

    int dato=9;
    crearArbol(pa);
    ponerEnArbol(pa,&dato,comparar);
    dato=11;
    ponerEnArbol(pa,&dato,comparar);
    dato=10;
    ponerEnArbol(pa,&dato,comparar);
    dato=12;
    ponerEnArbol(pa,&dato,comparar);
    dato=6;
    ponerEnArbol(pa,&dato,comparar);
    dato=5;
    ponerEnArbol(pa,&dato,comparar);
    dato=7;
    ponerEnArbol(pa,&dato,comparar);
}

void crearArbolBalanceado(t_arbol *pa){

   int dato=9;
    crearArbol(pa);
    ponerEnArbol(pa,&dato,comparar);
    dato=11;
    ponerEnArbol(pa,&dato,comparar);
    dato=12;
    ponerEnArbol(pa,&dato,comparar);
    dato=6;
    ponerEnArbol(pa,&dato,comparar);
    dato=5;
    ponerEnArbol(pa,&dato,comparar);


}

void crearArbolAVl(t_arbol* pa){

  int dato=9;
    crearArbol(pa);
    ponerEnArbol(pa,&dato,comparar);
    dato=6;
    ponerEnArbol(pa,&dato,comparar);
    dato=5;
    ponerEnArbol(pa,&dato,comparar);
    dato=10;
    ponerEnArbol(pa,&dato,comparar);

}

void grafico_arbol(t_arbol *pa, int nivel){

    if (!*pa)
        return;

    grafico_arbol(&(*pa)->der,nivel+1);
    int nivel_aux = nivel;
    while (nivel > 0)
    {
        printf("\t");
        nivel--;
    }
    printf ("%d\n", (*pa)->info);
    grafico_arbol(&(*pa)->izq,nivel_aux+1);
}

int Tipo_Arbol (t_arbol *pa){///NO AND BIEN

    if(esAVL(pa)==1)
        return 6;
    else
    {
        if(Arbol_Balanceado(pa)==1)
            return 5;

        else
        {
            if(Arbol_Completo(pa)==1)
                return 4;
            else
                return 0;
        }
    }


}

