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

int ** Multiplicacion_Matrices(int **Matriz_1, int **Matriz_2, int FilasM1, int ColumnasM2, int FactorC){

    int ** Matriz_Resultado = nullptr;
    Matriz_Resultado = Crear_Matriz(FilasM1,ColumnasM2,Matriz_Resultado);

    int *arr_M2[FactorC];
    //Guardado de direcciones de memoria
    for (int **memory_dir=Matriz_2,**p = arr_M2;memory_dir< Matriz_2+FactorC; memory_dir++,p++){
        *p=*memory_dir;
    }

    for (int **Filas_M1=Matriz_1, **Filas_MR = Matriz_Resultado; Filas_M1<Matriz_1+FilasM1; Filas_M1++, Filas_MR++){

        for(int *Columnas_MR=*Filas_MR ; Columnas_MR<(*Filas_MR)+ColumnasM2; Columnas_MR++) {
            int Temp_Resultado=0;

            for (int *Col_M1 = *Filas_M1, **Filas_M2=Matriz_2 ; Col_M1 < (*Filas_M1) + FactorC; Col_M1++, Filas_M2++) {
                Temp_Resultado = Temp_Resultado + (*Col_M1 * (**Filas_M2));
                (*Filas_M2)++;
            }
            *Columnas_MR = Temp_Resultado;
        }

        for (int **p=arr_M2, **arreglo=Matriz_2; p<arr_M2+FactorC;p++, arreglo++ ){
            *arreglo=*p;
        }
    }

    return Matriz_Resultado;
}

int main() {

    int Factor_C = 3;
    int **A = nullptr;
    int Filas_A = 4;
    int **B = nullptr;
    int Columnas_B= 2;
    A = Crear_Matriz(Filas_A,Factor_C,A);
    B = Crear_Matriz(Factor_C,Columnas_B,B);

    //Para llenar A
    for (int i=0, x; i < Filas_A ; i++){
        for (int j=0 ; j < Factor_C ; j++){
            cout <<"Ingresar A["<<i<<"]["<<j<<"] :";
            cin >>x;
            A[i][j]=x;
        }
    }
    //Para llenar B
    for (int i=0, x; i < Factor_C ; i++){
        for (int j=0 ; j < Columnas_B ; j++){
            cout <<"Ingresar B["<<i<<"]["<<j<<"] :";
            cin >>x;
            B[i][j]=x;
        }
    }

    cout << "Matriz A :"<<endl;
    Imprimir_Matriz(Filas_A,Factor_C,A);
    cout << "Matriz B :"<<endl;
    Imprimir_Matriz(Factor_C,Columnas_B,B);


    cout << "Resultado de la Multiplicacion :"<<endl ;
    int **Matriz_resultado = Multiplicacion_Matrices(A,B,Filas_A,Columnas_B,Factor_C);
    Imprimir_Matriz(Filas_A,Columnas_B,Matriz_resultado);


    Borrar_Matriz(Filas_A,A);
    Borrar_Matriz(Factor_C,B);
    Borrar_Matriz(Filas_A,Matriz_resultado);
}
