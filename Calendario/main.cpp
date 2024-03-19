//Crear calendario que imprima la forma del calendario de windows
#include "Imprimir_calendario.h"

int main (){
    int day,month,year;

    cout<<"Ingresar Fecha\n"<<"Dia:";
    cin>>day;
    cout<<"Mes:";
    cin>>month;
    cout<<"Year:";
    cin>>year;
    cout<<endl;

    long int Dias = calendario_runner(day,month,year);
    string Dia_c = CALENDARIO_Finder(Dias);
    int Dia_0 = convertor_Dia_inicio(Dia_c);

    

    imprimir_calendario(month,year,Dia_0);

    return 0;
}