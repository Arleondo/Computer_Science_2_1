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

        if ( *mid == key ) {
            pos = mid;
            return true;
        }else if ( *ini == key ) {
            pos = ini;
            return true;
        }else if ( *fin == key ) {
            pos = fin;
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

int main () {
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
                 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    int *p;

    while (true) {
    // comprobación de encontrar lo buscado
    int x;
    string check;

    cout << "Ingresar numero a buscar en la lista del 1-20" << endl << "NUMERO :";
    cin >> x;
    if (bin_search(a, a + (sizeof(a)-1), p, x)) {
        cout << "Valor del puntero retornado :" << *p << endl;
        cout << "Direccion de memoria del punturo :" << p << endl;
        cout << "Direccion del elemento EN la lista :" << a+(x-1) << endl;
    } else {
        cout << "No encontrado" << endl;
    }

    cout << "Desea salir? (Y/y) :";
    cin >> check;
    if ( check=="Y" || check=="y"){
        break;
    }

    }
}