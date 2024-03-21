#pragma once
#include "iostream"

class Calendario

{
private:
  std::string Dias[7] = {"L", "M", "X", "J", "V", "S", "D"};
  int Dias_De_Meses[12] = {31,29,31,30,31,30,31,31,30,31,30,31 };
  int day_ingresado;
  int month_ingresado;
  int year_ingresado;
  int reference_year = 1900;
  int comienzo_de_semana;

public:
  Calendario(int dia, int mes, int year_1) {

    if (dia <= 0 || dia > 31) {
      throw std::invalid_argument("Dia no valido");
    }
    else {
      day_ingresado = dia;
    }

    if ((dia <= 0 || dia > 28) && mes == 2 && year_1 % 4 != 0) {
      throw std::invalid_argument("Dia no valido");
    }
    else if ((dia <= 0 || dia > 29) && mes == 2 && year_1 % 4 == 0) {
      throw std::invalid_argument("Dia no valido");
    }
    else {
      day_ingresado = dia;
    }

    if (mes <= 0 || mes > 12) {
      throw std::invalid_argument("Mes no valido");
    }
    else { 
      month_ingresado = mes; 
    }
    if (year_1 < 1900) {
      throw std::invalid_argument("Año invalido");
    }
    else {
      year_ingresado = year_1;
    }
  }

  void Imprimir_Calendario() {

    int indicador_continuar = comienzo_de_semana;

    if (year_ingresado % 4 != 0) {
      Dias_De_Meses[1] = 28;
      if (month_ingresado >= 3) {
        indicador_continuar--;
      }
    }

    std::cout << "Month:" << month_ingresado << "\t\t\t\t\t" << "Year: " << year_ingresado << "\n\n";
    for (int i = 0; i < 7; i++) {
      std::cout << Dias[i] << "\t";
      if (i == 6) {
        std::cout << "\n";
      }
    }

    for (int u = 0; u < indicador_continuar; u++) {
      std::cout << "-" << "\t";
    }

    for (int j = 1; j <= Dias_De_Meses[month_ingresado-1]; j++) {

      std::cout << j << "\t";
      indicador_continuar++;

      if (indicador_continuar % 7 == 0) {
        std::cout << "\n";
        indicador_continuar = 0;
      }
    }
    std::cout << "\n";
  }

  void Calcular_Calendario() {

    int indicador_dia = 0;

    for (int cont_year = reference_year + 1; cont_year <= year_ingresado; cont_year++) {
      if (cont_year % 4 == 0) {
        indicador_dia += 2;
      }
      else {
        indicador_dia += 1;
      }
    }
    indicador_dia = indicador_dia % 7;


    for (int i = 0; i < month_ingresado - 1; i++) {
      indicador_dia += (Dias_De_Meses[i] % 7);
      indicador_dia = indicador_dia % 7;
    }

    if (year_ingresado % 4 == 0) {
      indicador_dia -= 1;
      if (indicador_dia == -1) {
        indicador_dia = 6;
      }
    }

    comienzo_de_semana = indicador_dia;

    Imprimir_Calendario();

  }

};