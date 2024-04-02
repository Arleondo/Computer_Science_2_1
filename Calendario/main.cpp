//Crear calendario que imprima la forma del calendario de windows
#include "Calendar.h"

int main (){

    int dia,mes,year;
    cout<<"Ingresar Fecha"<<endl;
    cout<<"Dia :";
    cin>>dia;
    cout<<"Mes :";
    cin>>mes;
    cout<<"Año :";
    cin>>year;
    Calendar fecha(dia,mes,year);
    fecha.Calendar_runner();
    fecha.Calendar_printer();

    return 0;
}