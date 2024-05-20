//Trasmutar la Matriz de 3x5 a 5x3 y viceversa
//Multiplicar matrices No cuadradas tipo: MxI IxN = MxN
#include <iostream>
using namespace std;

void Imprimir_Matriz (int Filas ,int Columnas ,int ** Matriz){
    for (int i=0, x=0; i<Filas ;i++ , x++){
        cout <<"{";
        for (int j=0 ; j < Columnas ; j++, x++){
            cout <<"\t"<< Matriz[i][j];
        }
        cout <<"\t}"<< endl;
    }
}


int ** Crear_Matriz (int Filas ,int Columnas,int ** Matriz ){
    Matriz = new int *[Filas];
    for (int **i=Matriz; i<Matriz+Filas ; i++){
        *i = new int [Columnas];
    }
    return Matriz;
}

void Borrar_Matriz (int Filas, int ** Matriz) {
    for (int ** i = Matriz; i < Matriz + Filas; i++) {
        delete[] * i;
    }
    delete[] Matriz;
}

int ** Transpuesta_Matriz (int Filas, int Columnas, int **Matriz){
    int ** Matriz_Return=Crear_Matriz(Columnas, Filas, Matriz);
    //No se puede implementar con punteros debido a que en dinamica se asignan en posiciones totalmente diferentes A[0]=100, A[1]=200 , A[0][0]=100 pero A solo llegua hasta A[0][3]=116
    for (int i=0 ; i<Columnas ; i++){
        for (int j=0; j<Filas ; j++){
            Matriz_Return[i][j]=Matriz[j][i];
        }
    }



    return Matriz_Return;
}

int main() {
    int **A ;
    A = Crear_Matriz(3,4,A);

    //Asignador de valores para rotarlos;
    for (int i=0, x=0; i<3 ;i++ , x++){
        for (int j=0 ; j < 4 ; j++, x++){
            A[i][j]=x;
        }
    }

    int **Trans_A = Transpuesta_Matriz(3,4,A);
    cout << "Matriz A :" << endl;
    Imprimir_Matriz(3,4,A);
    cout << "Matriz A_Transpuesta: "<<endl;
    Imprimir_Matriz(4,3,Trans_A);

    Borrar_Matriz(4,Trans_A);
    Borrar_Matriz(3,A);
    return 0;
}




/* Codigo no usado (pero bien implementado), error de asignacion de memoria (La lista de *Matriz_r esta en 100 pero la de **Matriz_r esta en 300).
 * int ** Matriz_Return=Crear_Matriz(Columnas, Filas, Matriz);
    int ** Fil_r = Matriz_Return , * Col_r = *Fil_r;
    int ** Fil=Matriz;
    int * Col = * Fil;
    int * re_Fil = *(Fil_r +1);
    for (; Fil_r < Matriz_Return+Columnas ; Fil_r++ ){
        for (; Col_r<*(Fil_r+1) ; Col++, Col_r++){
            if ( Col>= *(Fil+1) ){ break;}
            *Col_r = *Col;
        }
        Col++;
        if ( Col >= *(Fil + 1) ){
            Fil++;
            Col = * Fil;
        }
    }
*/