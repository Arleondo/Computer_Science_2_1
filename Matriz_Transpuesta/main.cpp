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
    int * arr [Columnas];
    for (int **memory_dir=Matriz,**p = arr;memory_dir< Matriz+Filas; memory_dir++,p++){
        *p=*memory_dir;
    }
    for (int **Filas_R = Matriz_Return, **Filas_M = Matriz; Filas_R < Matriz_Return + Columnas ; Filas_R++){
        *Filas_R = new int [Filas];
        for (int *Colum_R=*Filas_R ; Filas_M<Matriz + Filas ; Filas_M++, Colum_R++){
            *Colum_R = **Filas_M;
            (*Filas_M)++;
        }
        Filas_M=Matriz;
    }
    for (int **p=arr, **arreglo=Matriz; p<arr+Filas;p++, arreglo++ ){
        *arreglo=*p;
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