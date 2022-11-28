#include <stdio.h>
#include <stdlib.h>
#include"F_Arbol_Binario.h"

int main()
{
    t_arbol arbol;
    t_info a={10,"Adrian"};
    t_info b={5,"Jose"};
    t_info c={30,"Maria"};
    t_info d={16,"Pepe"};
    t_info e={55,"Monica"};
    t_info f={58,"Nicolas"};
    t_info g={15,"Tomas"};
    t_info h={8,"Kaka"};
    t_info i={3,"Ronaldo"};
    t_info j={9,"Jorge"};

    t_arbol arbol2;
    t_info aa={10,"Adrian"};
    t_info bb={8,"Jose"};
    t_info cc={7,"Maria"};
    t_info dd={5,"Pepe"};
    t_info ee={4,"Monica"};
    t_info ff={2,"Nicolas"};
    t_info gg={1,"Tomas"};
    t_info hh={12,"Kaka"};
    t_info ii={11,"Ronaldo"};
    t_info jj={14,"Jorge"};
    t_info oo={-1,"Tomas"};
    size_t  nivel=3;
    size_t  hArbol,hArbol2;
    t_info busc;
    busc.numero=58;

    crearArbol(&arbol);

    ponerEnArbol(&arbol,&a,comparar);
    ponerEnArbol(&arbol,&b,comparar);
    ponerEnArbol(&arbol,&c,comparar);
    ponerEnArbol(&arbol,&d,comparar);
    ponerEnArbol(&arbol,&e,comparar);
    ponerEnArbol(&arbol,&f,comparar);
    ponerEnArbol(&arbol,&g,comparar);
    ponerEnArbol(&arbol,&h,comparar);
    ponerEnArbol(&arbol,&i,comparar);
    ponerEnArbol(&arbol,&j,comparar);

    crearArbol(&arbol2);
    ponerEnArbol(&arbol2,&aa,comparar);
    ponerEnArbol(&arbol2,&bb,comparar);
    ponerEnArbol(&arbol2,&cc,comparar);
    ponerEnArbol(&arbol2,&dd,comparar);
    ponerEnArbol(&arbol2,&ee,comparar);
    ponerEnArbol(&arbol2,&ff,comparar);
    ponerEnArbol(&arbol2,&gg,comparar);
    ponerEnArbol(&arbol2,&hh,comparar);
    ponerEnArbol(&arbol2,&ii,comparar);
    ponerEnArbol(&arbol2,&jj,comparar);
    ponerEnArbol(&arbol2,&oo,comparar);

    hArbol  = Altura(&arbol);
    hArbol2 = Altura(&arbol2);
    printf("\n-----------------------------ARBOLES CREADOS-----------------------------\n");
/**
    printf("\n\n");
    grafico_arbol(&arbol,hArbol);
    printf("\n\n");
    grafico_arbol(&arbol2,hArbol2);
**/
    printf("\nRecorrida en inorden (ARBOL 1): \n");
    inorden(&arbol);

    printf("\nRecorrida en inorden (ARBOL 2): \n");
    inorden(&arbol2);

    printf("\n-----------------------------ALTURAS-----------------------------\n");
    printf("\nAltura   de ARBOL 1  esperado 4: %d", hArbol);
    printf("\nAltura   de ARBOL 2  esperado 8: %d", hArbol2);

    printf("\n\n-----------------------------CONTADORES-----------------------------\n");
    printf("\nCantidad de NODOS en total (ARBOL 1) esperados 10: %d",Contar_Nodo(&arbol));
    printf("\nCantidad de NODOS en total hasta el nivel 3(ARBOL 1) esperados 7: %d\n",Contar_Nodo_Nievel(&arbol,nivel));

    printf("\nCantidad de NODOS en total (ARBOL 2) esperados 11: %d",Contar_Nodo(&arbol2));
    printf("\nCantidad de NODOS en total hasta el nivel 3(ARBOL 2) esperados 6: %d\n",Contar_Nodo_Nievel(&arbol2,nivel));

    printf("\nCantidad de NODOS en total con HI(ARBOL 1) esperados 4: %d",Contar_Nodos_ConHI(&arbol));
    printf("\nCantidad de NODOS en total con HD(ARBOL 1) esperados 5: %d\n",Contar_Nodos_ConHD(&arbol));

    printf("\nCantidad de NODOS en total con HI(ARBOL 2) esperados 8: %d",Contar_Nodos_ConHI(&arbol2));
    printf("\nCantidad de NODOS en total con HD(ARBOL 2) esperados 2: %d\n",Contar_Nodos_ConHD(&arbol2));

    printf("\nCantidad de HOJAS en total (ARBOL 1) esperados 4: %d",Contar_Hojas(&arbol));
    printf("\nCantidad de HOJAS hasta el nivel 3(ARBOL 1) esperados 1: %d\n",Contar_Hojas_Nivel(&arbol,nivel));

    printf("\nCantidad de HOJAS en total (ARBOL 2) esperados 3: %d",Contar_Hojas(&arbol2));
    printf("\nCantidad de HOJAS hasta el nivel 3(ARBOL 2) esperados 2: %d\n",Contar_Hojas_Nivel(&arbol2,nivel));

    printf("\n-----------------------------------ELIMINACION DE NODOS-----------------------------\n");
    printf("\nCantidad de NODOS eliminados a partir del nivel 3(ARBOL 1 Nodos: 3): %d",Podar_Arbol_y_Contar(&arbol,nivel));
    printf("\nCantidad de NODOS eliminados a partir del nivel 3(ARBOL 2 Nodos: 5): %d\n",Podar_Arbol_y_Contar(&arbol2,nivel));

    printf("\nRecorrida en INORDEN despues de la podada (ARBOL 1) : \n");
    inorden(&arbol);

    printf("\nRecorrida en INORDEN despues de la podada (ARBOL 2): \n");
    inorden(&arbol2);

    printf("\n\nCantidad de NODOS eliminados (ARBOL 1 Nodos: 7): %d",Eliminar_Arbol_y_Contar(&arbol));
    printf("\nCantidad de NODOS eliminados (ARBOL 2 Nodos: 6): %d\n",Eliminar_Arbol_y_Contar(&arbol2));

    printf("\nRecorrida en INORDEN despues de eliminar todo(ARBOL 1) : \n");
    inorden(&arbol);

    printf("\nRecorrida en INORDEN despues de eliminar todo (ARBOL 2): \n");
    inorden(&arbol2);


return 0;
}





