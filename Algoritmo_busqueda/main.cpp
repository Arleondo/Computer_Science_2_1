/*
Bool bin_search(int *ini, int *fin, int *&pos, int key)
Hacer un buscador que encuentre en que memory storage está el key.
En otras palabras retorna pos, por eso mismo tiene que pasar como referencia
*/
#include <iostream>
using namespace std;


bool bin_search (int *ini, int *fin , int *&pos , int key){

    while (true) {
        int *mid = ini + (fin - ini) / 2;

        if ( *mid == key ){
            pos = mid;
            return true;
        }

        //búsqueda entre el puntero del fin y del ini

        if (*ini < key && key < *mid) {
            fin = mid;
        }
        else if ( *mid < key && key < *fin ){
            ini = mid;
        }
        else {
            return false;
        }
    }
}

int main (){
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    int *p;

    // comprobacion de encontrar lo buscado

    if (bin_search(a,a+9,p,4)){
        cout << *p << endl;
        cout << p << endl;
    } else {
        cout << "No encontrado";
    }
}