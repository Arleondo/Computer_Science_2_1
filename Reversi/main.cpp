#include <iostream>
using namespace std;
//Hacer el reversi con una matriz de 8x8
//Solo verificar arriba,abajo,izq,der; (Diagonales para los shushas)
//De preferencia hacer que solo se pueda jugar en coordenadas adyacentes



void imprimir_tablero(int (*Tablero)[8]){

    int *p = *Tablero;
    int (*q)[8]= Tablero;
    for (  ; q<=Tablero+8 ; q++){

        for ( ;p < *q ;p++){
            cout << *p << "\t";
        }

        cout << endl;

    }

}




int main() {

    int a[8][8] = {
            {0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0},
            {0,0,0,1,2,0,0,0},
            {0,0,0,2,1,0,0,0},
            {0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,1},
                   };

    imprimir_tablero(a);

    return 0;
}
