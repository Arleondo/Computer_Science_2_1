#ifndef CALENDARIO_IMPRIMIR_CALENDARIO_TOOLS_H
#define CALENDARIO_IMPRIMIR_CALENDARIO_TOOLS_H
#include <iostream>
using namespace std;

//Referencias a dias para un mejor calculo

string Dia_1900 (){
    return "Lunes";
}

/* No usado (referencia para optimizar el proceso)
string Dia_2000(){
    return "Sabado";
}
*/

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

    if (year%4 == 0 and year%100 != 0 or year%400 == 0){
        return true;
    } else{
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
                    return;
                }
            }
            cout << endl;
            contador = 0;
        } else {
                return;
        }
    }
}

//Convertidor de escrito a numero del 0-6
int convertor_Dia_inicio(const string& Dia){
    string Dias[7]={"Domingo","Lunes","Martes","Miercoles","Jueves","Viernes","Sabado"};
    int x=0;
    while (true){
        if (Dias[x]==Dia){
            return x;
        }
        else if(x>6) {
            cout<<"Error en escritura usar el siguiente formato:\n"<<"Mayuscula primera letra y palabra en ES"<<endl;
            return -1;
        }
        x++;
    }
}
string convertidor_Dia_int (const int& x){
    string Dias[7]={"Domingo","Lunes","Martes","Miercoles","Jueves","Viernes","Sabado"};
    return Dias[x];
}

//Para recorrer los dias necesarios
long int calendario_runner (int dia,int mes,int year){

    long int contador_dias=0,anios=year-1900,meses=1,x=0;

    for (;x<anios;x++){
        if (Bisiesto(x)){
            contador_dias=contador_dias+366;
        } else {
            contador_dias=contador_dias+365;
        }
    }

    for (;meses<mes;meses++){
        if (meses%2==1||meses==8){
            contador_dias=contador_dias+31;
        }else if (meses%2==0 && meses!=2){
            contador_dias=contador_dias+30;
        }else if (meses==2 && Bisiesto(x)){
            contador_dias=contador_dias+29;
        }else {
            contador_dias=contador_dias+28;
        }
    }

    for (int y=1;y<=dia;y++){
        contador_dias=contador_dias+1;
    }

    return contador_dias;
}

//Para saber primer dia del mes
string CALENDARIO_Finder (long int Contador_dias){
    //hay que saber que El 1/1/1900 es Lunes
    int Dia_inicio_mes=(Contador_dias%7)+ convertor_Dia_inicio(Dia_1900());
    string Dias[7]={"Domingo","Lunes","Martes","Miercoles","Jueves","Viernes","Sabado"};
    return Dias[Dia_inicio_mes];
}

#endif //CALENDARIO_IMPRIMIR_CALENDARIO_TOOLS_H