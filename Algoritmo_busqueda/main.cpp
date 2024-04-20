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
        }
        if ( *ini == key ) {
            pos = ini;
            return true;
        }
        if ( *fin == key ) {
            pos = ini;
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
    int a[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
                 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    int *p;
    while (true) {
    // comprobación de encontrar lo buscado
    int x;
    int check;

    cout << "Ingresar numero a buscar en la lista del 1-20" << endl << "NUMERO :";
    cin >> x;
    if (bin_search(a, a + 19, p, x)) {
        cout << *p << endl;
        cout << p << endl;
    } else {
        cout << "No encontrado";
    }

    cout << "Desea salir? (N/n) :";
    cin >> check;
    }
}