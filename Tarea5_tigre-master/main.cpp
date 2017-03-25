#include "NodoArbolBinario.h"
#include "Evaluador.h"
#include <iostream>       // std::cin, std::cout
#include <list>          // std::list
using namespace std;

//Devuelve la suma de todos los numeros del arbol con la raiz dada.
int suma(NodoArbolBinario* raiz)
{
    if(raiz==NULL)
    return 0;
    int suma_total = raiz->num;
    suma_total += suma(raiz->hijo_der) + suma(raiz->hijo_izq);
    return suma_total;
}

//Devuelve la cantidad de nodos que tiene el arbol con la raiz dada.
int cantidadNodos(NodoArbolBinario* raiz)
{
    int con =0;
    if(raiz==NULL)
    return 0;
    con++;
    con+= cantidadNodos(raiz->hijo_der)+cantidadNodos(raiz->hijo_izq);
    return con;
}

//Devuelve el promedio de los numeros que tiene el arbol con la raiz dada.
int promedio(NodoArbolBinario* raiz)
{
    return suma(raiz)/cantidadNodos(raiz);
}

//Devuelve la cantidad de pasos que tiene que dar el algoritmo para llegar a un numero dado.
//Ejemplo: http://www.comp.nus.edu.sg/~stevenha/visualization/bst.html
//Para llegar al nodo 7 se ocupan 3 pasos (15,6,7)
//Para llegar al nodo 5 se ocupan 4 pasos (15,6,4,5)
//Para llegar al nodo 15 se ocupa 1 paso (15)
int cuantosPasos(NodoArbolBinario* raiz,int num)
{
    int con =1;
    if(raiz==NULL)
    return con;
    if(raiz->num == num)
        return con;
    if(num>raiz->num)
        con += cuantosPasos(raiz->hijo_der,num);
    if(num<raiz->num)
        con += cuantosPasos(raiz->hijo_izq,num);
    return con;
}

//Devuelve la cantidad de hojas que tiene el arbol con la raiz dada
int sumaHojas(NodoArbolBinario* raiz)
{
     if (raiz==NULL)
    {
        return 0;
    }
    if ((raiz->hijo_der ==NULL)&&(raiz->hijo_izq== NULL))

        return 1;

    else

    return sumaHojas(raiz->hijo_izq)+ sumaHojas(raiz->hijo_der);

}


int main ()
{
    //Funcion evaluadora
    evaluar();
    return 1;
}
