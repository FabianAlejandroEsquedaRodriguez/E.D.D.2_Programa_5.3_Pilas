/* Se define la plantilla de la clase Pila usando sobrecarga de
operadores en los métodos de inserción y eliminación. */
#ifndef PILA_H
#define PILA_H

#define MAX 10
#include <iostream>
using namespace std;

template <class T>
class Pila{
    public:
        Pila(); 
        void operator + (T);
        void operator - (T *);
        int PilaLlena();
        int PilaVacia();
    
    private: 
        T EspacioPila[MAX];
       int Tope;
};

#endif

/* Declaración del método constructor por omisión. Asigna el valor –1
al Tope, indicando que la pila está vacía. */
template <class T> 
Pila<T>::Pila():Tope(-1){

}

/* Método que evalúa si la pila está llena. Regresa 1 si todos los
espacios están ocupados y 0 en caso contrario. */
template <class T>
int Pila<T>::PilaLlena(){
    if (Tope == MAX-1){
        return 1;
    }
    else{
        return 0;
    }
}

/* Método que evalúa si la pila está vacía, regresando 1 si lo está y
0 en otro caso. */
template <class T>
int Pila<T>::PilaVacia(){
    if (Tope == -1){
        return 1;
    }
    else{
        return 0;
    }
}

/* El operador +, que normalmente indica la operación aritmética de
suma, se sobrecarga utilizándose para insertar un elemento en la pila.
Por lo tanto, el operador +, en este programa, tendrá asociadas dos
operaciones: suma de números e inserción de elementos en una pila. Se
verifica si la pila tiene espacio antes de invocar este método. Se
recibe como parámetro el dato a insertar. */
template <class T>
void Pila<T>::operator + (T Valor){
    Tope++;
    EspacioPila[Tope]= Valor; 
}

/* El operador –, que normalmente indica la operación aritmética de
resta, se sobrecarga utilizándose para eliminar un elemento de la pila.
Por lo tanto, el operador –, en este programa, tendrá asociadas dos
operaciones: resta de números y eliminación de elementos de una pila.
Se verifica que la pila no esté vacía antes de invocar este método. El
valor eliminado se pasa como parámetro por referencia. */
template <class T> 
void Pila<T>::operator - (T *Valor) 
{ 
    *Valor= EspacioPila[Tope]; 
    Tope--; 
}

/* Función que usa la sobrecarga de operadores definida en la clase
Pila. Se declara un objeto tipo Pila de enteros, luego se le insertan
MAX elementos y por último, mientras la pila no esté vacía, se quitan y
se imprimen cada uno de los valores almacenados en la misma. */ 
// int main(){
    
//     Pila <int> ObjPila;
//     int Indice;

// /* Si la pila está vacía se le agregan MAX elementos, usando el
// operador sobrecargado +. */
//     if (ObjPila.PilaVacia()){
//         for (Indice= 0; Indice < MAX; Indice++){
//             ObjPila + Indice*2;
//         }
//     }

// /* Mientras la pila no se vacíe, se quita un elemento, usando el
// operador – sobrecargado, y se imprime. */
//     while (!ObjPila.PilaVacia()){
//         ObjPila - &Indice;
//         cout<< '\n'<<Indice;
//     }
//     return 0;
// }