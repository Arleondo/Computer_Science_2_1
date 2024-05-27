//Trasmutar la Matriz de 3x5 a 5x3 y viceversa
//Multiplicar matrices No cuadradas tipo: MxI IxN = MxN
#include <iostream>
using namespace std;

void Imprimir_Matriz (int Filas ,int Columnas ,int ** Matriz){
    for (int **i=Matriz ; i<Matriz+Filas ; i++){
        cout <<"{";
        for (int *j=*i ; j < (*i)+Columnas ; j++ ){
            cout <<"\t"<< *j;
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

    int ** Matriz_Return = new int *[Columnas];
    for (int **Filas_R = Matriz_Return, Colum_M=0; Filas_R < Matriz_Return + Columnas ; Filas_R++, Colum_M++){
        *Filas_R = new int [Filas];
        for (int **Filas_M = Matriz, *Colum_R=*Filas_R  ; Filas_M<Matriz + Filas; Filas_M++, Colum_R++){
            *Colum_R = (*Filas_M)[Colum_M];
        }
    }
    return Matriz_Return;

}

int main() {
    int **A ;
    A = Crear_Matriz(3,4,A);

    //Asignador de valores para rotarlos;
    for (int **i=A, x=12; i < A+3 ; i++){
        for (int *j=*i ; j < (*i)+4 ; j++, x--){
            *j=x;
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




/* Codigo no usado (pero implementado, para "Funcionar"), error de asignacion de  memoria (La lista de *Matriz_r esta en 100 pero la de**Matriz_r esta en 300).
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

    *Primera forma de "Intento" de recorrido de punteros en el heap

    int ** Matriz_Return = new int *[Columnas];
    for (int **Filas_R = Matriz_Return, Colum_M=0; Filas_R < Matriz_Return + Columnas ; Filas_R++, Colum_M++){
        *Filas_R = new int [Filas];
        for (int **Filas_M = Matriz, Copiador_cont=0  ; Filas_M<Matriz + Filas; Filas_M++, Copiador_cont++){
            *((*Filas_R)+Copiador_cont) = *((*Filas_M)+Colum_M);
        }
    }
*/