#ifndef F_ARBOL_BINARIO_H_INCLUDED
#define F_ARBOL_BINARIO_H_INCLUDED

typedef struct
{
    int numero;
    char nombre[10];
}t_info;

typedef struct snodo
{
    t_info info;
    struct snodo *izq,
                 *der;
}t_nodo, *t_arbol;


void crearArbol(t_arbol*p);
int comparar(const t_info *d1,const t_info *d2);
int ponerEnArbol(t_arbol* pa,t_info* pd,int(*comp)(const t_info*,const t_info*));
void mostrarNodo (const t_info *d);
void preorden(t_arbol*p);
void inorden(t_arbol*p);
void posorden(t_arbol*p);
int buscarR(t_arbol*p,t_info*d,int(*cmp)(const t_info *d1,const t_info *d2));
size_t Contar_Nodo (const t_arbol *pa);
size_t Contar_Nodo_Nievel (const t_arbol *pa,int nivel);
size_t Contar_Hojas (const t_arbol *pa);
int Contar_Hojas_Nivel (const t_arbol *pa, int nivel);
size_t Altura (const t_arbol *pa);
size_t Contar_Nodos_ConHI(const t_arbol *pa);
size_t Contar_Nodos_ConHD(const t_arbol *pa);
int esCompleto (const t_arbol *pa, int nivel);
int Arbol_Completo (const t_arbol *pa);
int esBalanceado (const t_arbol *pa, int nivel);
int Arbol_Balanceado (const t_arbol *pa);
int esAVL (const t_arbol *pa);
void Eliminar_Arbol(t_arbol *p);
size_t Eliminar_Arbol_y_Contar (t_arbol *p);
void Podar_Arbol(t_arbol* pa,int h);
int Podar_Arbol_y_Contar(t_arbol* pa,int h);
void grafico_arbol(t_arbol *pa, int nivel);
#endif // F_ARBOL_BINARIO_H_INCLUDED
