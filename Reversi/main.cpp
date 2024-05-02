#include <iostream>
using namespace std;
//Hacer el reversi con una matriz de 8x8
//Solo verificar arriba,abajo,izq,der; (Diagonales para los cracks)
//De preferencia hacer que solo se pueda jugar en coordenadas adyacentes

void imprimir_tablero(int (*Tablero)[8]){

    char coords [8]= {'A','B','C','D','E','F','G','H'};
    cout << "  | ";
    for (char coord : coords){cout << coord << " | ";}
    cout << endl ;
    for (int i=0;i<8;i++){
        cout << i+1 << " | ";
        for (int j=0;j<8;j++){
            if ( Tablero[i][j] == 0){
                cout << " " << " | ";
            }
            else if ( Tablero[i][j] == 1){
                cout << "X" << " | ";
            }
            else {
                cout << "O" << " | ";
            }
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
            {0,0,0,0,0,0,0,0},
                   };

    imprimir_tablero(a);

    return 0;
}