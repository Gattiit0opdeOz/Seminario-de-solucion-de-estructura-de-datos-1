/*
  Autor: Bryan Vizcarra Aguilar
  Fecha de Creacion: 9 de septiembre de 2021
  Fecha de ult mod: 9 de septiembre de 2021
  Conversor de temperatura
*/

#include <iostream>
#include <cstdlib>
#include <ctype.h>


void menu(int, int*);

class celsiusAKelvin{
private:
  double celsius;
  double conversion;

public:
  void setCelsius(double);
  int getCelsius();
  void calcularConversion();
  int getConversion();
};

void celsiusAKelvin::setCelsius(double celsius){
  this->celsius = celsius;
}

int celsiusAKelvin::getCelsius(){
  return this->celsius;
}

void celsiusAKelvin::calcularConversion(){
  this->conversion = (this->celsius + 273);
}

int celsiusAKelvin::getConversion(){
  return this->conversion;
}


class kelvinACelsius{
private:
  double kelvin;
  double conversion;

public:
  void setKelvin(double);
  int getKelvin();
  void calcularConversion();
  int getConversion();
};

void kelvinACelsius::setKelvin(double kelvin){
  this->kelvin = kelvin;
}

int kelvinACelsius::getKelvin(){
  return this->kelvin;
}

void kelvinACelsius::calcularConversion(){
  this->conversion = (this->kelvin - 273);
}

int kelvinACelsius::getConversion(){
  return this->conversion;
}


class celsiusAFahrenheit{
private:
  double celsius;
  double conversion;

public:
  void setCelsius(double);
  int getCelsius();
  void calcularConversion();
  int getConversion();
};

void celsiusAFahrenheit::setCelsius(double celsius){
  this->celsius = celsius;
}

int celsiusAFahrenheit::getCelsius(){
  return this->celsius;
}

void celsiusAFahrenheit::calcularConversion(){
  this->conversion = (1.8 * this->celsius) + 32;
}

int celsiusAFahrenheit::getConversion(){
  return this->conversion;
}


class fahrenheitACelsius{
private:
  double fahrenheit;
  double conversion;

public:
  void setFahrenheit(double);
  int getFahrenheit();
  void calcularConversion();
  int getConversion();
};

void fahrenheitACelsius::setFahrenheit(double fahrenheit){
  this->fahrenheit = fahrenheit;
}

int fahrenheitACelsius::getFahrenheit(){
  return this->fahrenheit;
}

void fahrenheitACelsius::calcularConversion(){
  this->conversion = (this->fahrenheit - 32) / 1.8;
}

int fahrenheitACelsius::getConversion(){
  return this->conversion;
}



int main(int argc, char const *argv[]) {
  int band=0, op=0, *ptr;
  do {
    system("cls");
      std::cout << "SELECCIONE LA OPCION DESEADA" << '\n'<< '\n';
      std::cout << "1. CELSIUS A KELVIN" << '\n';
      std::cout << "2. KELVIN A CELSIUS" << '\n';
      std::cout << "3. CELSIUS A FAHRENHEIT" << '\n';
      std::cout << "4. FAHRENHEIT A CELSIUS"  << '\n';
      std::cout << "0. SALIR" << '\n'<< '\n' << '\n';
      std::cout << "TU OPCION ES: ";
      std::cin >> op;
      ptr=&band;
      menu(op, ptr);

  } while(band==0);
  return 0;
}

void menu(int op ,int *band){
  int celsius=0, kelvin=0, fahrenheit=0;

  system("cls");
    switch (op) {
      case 0:
        *band=1;
      break;

      case 1:
        celsiusAKelvin objCaK;
        std::cout << "-----CELSIUS A KELVIN-----" << '\n' << '\n';
        std::cout << "INGRESE LOS CELSIUS" << '\n';
        std::cin >> celsius;
        objCaK.setCelsius(celsius);
        objCaK.calcularConversion();
        std::cout << '\n'<< objCaK.getCelsius() <<" Celsius es igual a: "<< objCaK.getConversion() <<" Kelvin"<< '\n';
        std::cout << '\n'<< '\n'<< '\n';
        system("pause");
      break;

      case 2:
        kelvinACelsius objKaC;
        std::cout << "-----KELVIN A CELSIUS-----" << '\n' << '\n';
        std::cout << "INGRESE LOS KELVIN" << '\n';
        std::cin >> kelvin;
        objKaC.setKelvin(kelvin);
        objKaC.calcularConversion();
        std::cout << '\n'<< objKaC.getKelvin() <<" Kelvin es igual a: "<< objKaC.getConversion() <<" Celsius"<< '\n';
        std::cout << '\n'<< '\n'<< '\n';
        system("pause");
      break;

      case 3:
        celsiusAFahrenheit objCaF;
        std::cout << "-----CELSIUS A FAHRENHEIT-----" << '\n' << '\n';
        std::cout << "INGRESE LOS CELSIUS" << '\n';
        std::cin >> celsius;
        objCaF.setCelsius(celsius);
        objCaF.calcularConversion();
        std::cout << '\n'<< objCaF.getCelsius() <<" Celsius es igual a: "<< objCaF.getConversion() <<" Fahrenheit"<< '\n';
        std::cout << '\n'<< '\n'<< '\n';
        system("pause");
      break;

      case 4:
        fahrenheitACelsius objFaC;
        std::cout << "-----FAHRENHEIT A CELSIUS-----" << '\n' << '\n';
        std::cout << "INGRESE LOS FAHRENHEIT" << '\n';
        std::cin >> fahrenheit;
        objFaC.setFahrenheit(fahrenheit);
        objFaC.calcularConversion();
        std::cout << '\n'<< objFaC.getFahrenheit() <<" Fahrenheit es igual a: "<< objFaC.getConversion() <<" Celsius"<< '\n';
        std::cout << '\n'<< '\n'<< '\n';
        system("pause");
      break;

      default:
        std::cout << "LA OPCION NO ES VALIDA" << '\n';
        system("pause");
      break;
    }
}
