#ifndef CALENDARIO_CALENDAR_H
#define CALENDARIO_CALENDAR_H
#include "iostream"
using namespace std;

class Calendar {
private:

    string Dias[7]={"D","L","M","M","J","V","S"};
    string Meses[12]={"Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Setiembre", "Octubre", "Noviembre", "Deciembre"};
    int Dias_Meses_N[12]={31,28,31,30,31,30,31,31,30,31,30,31},
        Dias_Meses_B[12]={31,29,31,30,31,30,31,31,30,31,30,31};
    [[maybe_unused]] int Dias_c;
    int Meses_c,Anios_c;
    int Year_Inicial=1900;
    int Dia_inicio{};

    static bool bisiesto_check (int check){
        if (check % 400 == 0){
            return true;
        }
        else if (check % 100 == 0){
            return false;
        }
        else if (check % 4 == 0){
            return true;
        }
        else{
            return false;
        }
    };
    static int tabs(int dia_inicial){
        int i=0;
        for (;i<dia_inicial;i++){
            cout<<"\t";
        }
        return i;
    }

public:
    //Constructor
    Calendar(int dia, int mes, int anio) {
        //Check del día puesto es correcto
        if ((0 < dia && dia < 32) && mes != 2 ) {
            Dias_c = dia;
        }
        else if ( dia < 29  && !bisiesto_check(anio) ) {
            Dias_c = dia;
        } else if ( dia < 30 && bisiesto_check(anio) ) {
            Dias_c = dia;
        } else {
            throw out_of_range("Dia fuera de calendario");
        }
        //Check del mes
        if ( 0<mes && mes<13 ){
            Meses_c=mes;
        }
        else {
            throw out_of_range ("Mes inexistente");
        }
        //Check del año
        if ( 1900<anio ){
            Anios_c=anio;
        }
        else {
            throw out_of_range("Año menor que 1900");
        }
    };

    //function para saber que día inicia el mes
    void Calendar_runner (){

        int dia_inicio_temp = 0 , contador_anio = Year_Inicial , contador_mes = 0;

        for (;contador_anio<=Anios_c;contador_anio++){
            if (bisiesto_check(contador_anio)){
                dia_inicio_temp = dia_inicio_temp + 2;
            }
            else {
                dia_inicio_temp = dia_inicio_temp + 1;
            }
        }
        dia_inicio_temp = dia_inicio_temp % 7;

        for (; contador_mes < Meses_c-1 ; contador_mes++){
            if (bisiesto_check(Anios_c)){
                dia_inicio_temp = dia_inicio_temp + (Dias_Meses_B[contador_mes] % 7);
            }
            else {
                dia_inicio_temp = dia_inicio_temp+ (Dias_Meses_N[contador_mes] % 7);
            }
        }
        dia_inicio_temp = dia_inicio_temp % 7;

        if (bisiesto_check(Anios_c)){
            dia_inicio_temp -= 1;
        }
        if (dia_inicio_temp==-1){
            dia_inicio_temp=0;
        }
        Dia_inicio=dia_inicio_temp;

    }
    //Imprimir el calendario
    void Calendar_printer (){

        int Semanas=1, Days=1;

        cout<<"Año : "<< Anios_c << "\nMes : " << Meses[Meses_c-1]<<endl;

        for (const auto & Dia : Dias){
            cout<< Dia << "\t";
        }
        cout<<endl;

        int Dias_tabs=tabs (Dia_inicio), i=Dias_tabs+0;

        for (;Semanas<6;Semanas++) {

            for (;i<7;i++){
                cout<< Days <<"\t";
                Days = Days + 1;

                if (bisiesto_check(Anios_c)){
                    if ( Days-1==Dias_Meses_B[Meses_c-1]){
                        break;
                    }
                }
                else{
                    if ( Days-1==Dias_Meses_N[Meses_c-1]){
                        break;
                    }
                }

            }
            i=0;
            cout<<endl;

        }
    }
};

#endif //CALENDARIO_CALENDAR_H