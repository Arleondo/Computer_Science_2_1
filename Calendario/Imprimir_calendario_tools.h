#ifndef CALENDARIO_IMPRIMIR_CALENDARIO_TOOLS_H
#define CALENDARIO_IMPRIMIR_CALENDARIO_TOOLS_H
#include <iostream>
using namespace std;
//para hacer tabs en el swicth del dia
void loop_cout_tabs(int veces){
    int y=0;
    while (y<veces){
        cout<<"\t";
        y++;
    }
}

//Saber si es bisiesto
bool Bisiesto (int year){
    if (year%4==0){
        return true;
    }
    else{
        return false;
    }
}


//Para imprimir segun los dias del mes
void Imprimir_mes(int Dias,int& contador){
    int x=1;
    while (true) {
        if (x <= Dias) {
            for (; contador < 7; contador++) {
                if (x <= Dias) {
                    cout << x << '\t';
                    x++;
                } else {
                    break;
                }
            }
            cout << endl;
            contador = 0;
        } else {
                break;
        }
    }
}

//Para recorrer los dias necesarios
int calendario_runner (int dia,int mes,int year){
    int contador_dias=0,anios=year-1900,meses=1;
    for (;anios<year;anios++){
        if (Bisiesto(anios)){
            contador_dias=contador_dias+366;
        } else {
            contador_dias=contador_dias+365;
        }
    }
    for (;meses<mes;meses++){
        if (meses%2==1||meses==8){
            contador_dias=+31;
        }else if (meses%2==0&&meses!=2){
            contador_dias=+30;
        } else if (meses==2&&!Bisiesto(anios)){
            contador_dias=+28;
        }else {
            contador_dias=+29;
        }
    }
    for (int dias=1;dias<dia;dias++){
        contador_dias++;
    }
    return contador_dias;
}
void CALENDARIO_Finder (){
    //hay que saber que El 1/1/1900 es Lunes

}

//Convertidor de escrito a numero del 0-6
int convertor_Dia_inicio(string& Dia){
    string Dias[7]={"Lunes","Martes","Miercoles","Jueves","Viernes","Sabado","Domingo"};
    int x=0;
    while (true){
        if (Dias[x]==Dia){
            return x;
        }
        else {
            cout<<"Error en escritura usar el siguiente formato:\n"<<"Mayuscula primera letra y palabra en ES";
            return -1;
        }
    }
}

//Referencias a dias para un mejor calculo
string Dia_1900 (){
    return "Lunes";
}

string Dia_2000(){
    return "Sabado";
}

#endif //CALENDARIO_IMPRIMIR_CALENDARIO_TOOLS_H