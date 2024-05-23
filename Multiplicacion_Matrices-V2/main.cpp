#include <iostream>
using namespace std;
//Multiplication de matrices no cuadradas, primero tenemos A(3x4),
//y su A_transpuesta(4x3), lo cual deberia dar la identidad.
//Primero tenemos las funciones de Transpuesta_Matriz:
//Inprimir_Matriz, Crear_Matriz, Borrar_Matriz;

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

int ** Multiplicacion_Matrices(int **Matriz_1, int **Matriz_2, int Filas_M1, int Columnas_M2, int Factor_C){
    int ** Matriz_Resultado = nullptr;
    Matriz_Resultado = Crear_Matriz(Filas_M1, Columnas_M2, Matriz_Resultado);

    for (int Fil_r=0; Fil_r < Filas_M1 ; Fil_r++){
        for (int Col_r=0; Col_r < Columnas_M2; Col_r++){
            int resultado_temp=0;
            for (int u=0; u<Factor_C; u++){
                resultado_temp = resultado_temp + ( Matriz_1[Fil_r][u] * Matriz_2[u][Col_r] );
            }
            Matriz_Resultado[Fil_r][Col_r]= resultado_temp;
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
