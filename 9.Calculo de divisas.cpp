/*
  Autor: Bryan Vizcarra Aguilar
  Fecha de Creacion: 17 de septiembre de 2021
  fecha de ult mod: 17 de septiembre de 2021
  Calculo de divisas utilizando Herencia
*/

void pedirMoneda(double *);
int validarValor(char [], int *);

#include <iostream>
#include <cstdlib>
#include <math.h>

class monedas{
private:
  double peso;
  double pesoEuro;
  double pesoYen;
  double pesoYuan;
  double dolar;
  double euro;
  double yen;
  double yuan;
public:
  void setPeso(double);
  double getPeso();

  void setpesoEuro(double);
  double getpesoEuro();

  void setpesoYen(double);
  double getpesoYen();

  void setpesoYuan(double);
  double getpesoYuan();

  void setDolar(double);
  double getDolar();

  void setEuro(double);
  double getEuro();

  void setYen(double);
  double getYen();

  void setBase(double);
  double getBase();

  void setYuan(double);
  double getYuan();
};
void monedas:: setPeso(double peso){
  this->peso=peso;
}
double monedas:: getPeso(){
  return this->peso;
}
void monedas:: setpesoEuro(double pesoEuro){
  this->pesoEuro=pesoEuro;
}
double monedas:: getpesoEuro(){
  return this->pesoEuro;
}
void monedas:: setpesoYen(double pesoYen){
  this->pesoYen=pesoYen;
}
double monedas:: getpesoYen(){
  return this->pesoYen;
}
void monedas:: setpesoYuan(double pesoYuan){
  this->pesoYuan=pesoYuan;
}
double monedas:: getpesoYuan(){
  return this->pesoYuan;
}
void monedas:: setDolar(double dolar){
  this->dolar=dolar;
}
double monedas:: getDolar(){
  return this->dolar;
}
void monedas:: setEuro(double euro){
  this->euro=euro;
}
double monedas:: getEuro(){
  return this->euro;
}
void monedas:: setYen(double yen){
  this->yen=yen;
}
double monedas:: getYen(){
  return this->yen;
}
void monedas:: setYuan(double yuan){
  this->yuan=yuan;
}
double monedas:: getYuan(){
  return this->yuan;
}


class pesoDolar:public monedas{

private:
  double cambio;
public:
  void Calcularpesod();
  double getCambio();
};

void pesoDolar:: Calcularpesod(){
  this->cambio=(this->getPeso()/20);
}
double pesoDolar::getCambio(){
  return this->cambio;
}


class dolarPeso:public monedas{

private:
  double cambio;
public:
  void Calculardolarp();
  double getCambio();
};

void dolarPeso:: Calculardolarp(){
  this->cambio=(this->getDolar()*20);
}
double dolarPeso::getCambio(){
  return this->cambio;
}

class PesoE:public monedas{

private:
  double cambio;
public:
  void CalcularpesoEuro();
  double getCambio();
};

void PesoE:: CalcularpesoEuro(){
  this->cambio=(this->getpesoEuro()/24);
}
double PesoE::getCambio(){
  return this->cambio;
}

class EuroP:public monedas{

private:
  double cambio;
public:
  void CalcularEurop();
  double getCambio();
};

void EuroP:: CalcularEurop(){
  this->cambio=(this->getEuro()*24);
}
  double EuroP::getCambio(){
  return this->cambio;
}


class PesoY:public monedas{

private:
  double cambio;
public:
  void Calcularpesosyen();
  double getCambio();
};

void PesoY:: Calcularpesosyen(){
  this->cambio=(this->getpesoYen()*5.50);
}
double PesoY::getCambio(){
  return this->cambio;
}

class Yenp:public monedas{

private:
  double cambio;
public:
  void CalcularYenp();
  double getCambio();
};

void Yenp:: CalcularYenp(){
this->cambio=(this->getYen()/5.50);
}
double Yenp::getCambio(){
  return this->cambio;
}

class PesoYun:public monedas{

private:
  double cambio;
public:
  void Calcularpesosyuan();
  double getCambio();
};

void PesoYun:: Calcularpesosyuan(){
  this->cambio=(this->getpesoYuan()*3.10);
}
double PesoYun::getCambio(){
  return this->cambio;
}

class Yuanp:public monedas{

private:
  double cambio;
public:
  void CalcularYuan();
  double getCambio();
};

void Yuanp:: CalcularYuan(){
  this->cambio=(this->getYuan()/3.10);
}
double Yuanp::getCambio(){
  return this->cambio;
}


int main(int argc, char const *argv[]) {
  int band = 0, band2=0;
  char validar[1];
  int opc=0;
  double *ptr1=NULL;
  double peso,pesoEuro,pesoYen,pesoYuan,dolar, euros, yen, yuan;

  do {
    system("cls");
      std::cout << "SELECCIONE LA OPCION DESEADA" << '\n'<< '\n';
      std::cout << "1. PESO A DOLAR" << '\n';
      std::cout << "2. DOLAR A PESO" << '\n';
      std::cout << "3. PESO A EURO" << '\n';
      std::cout << "4. EURO A PESO" << '\n';
      std::cout << "5. PESO A YEN" << '\n';
      std::cout << "6. YEN A PESO" << '\n';
      std::cout << "7. PESO A YUAN" << '\n';
      std::cout << "8. YUAN A PESO" << '\n';
      std::cout << "9. SALIR" << '\n'<< '\n' << '\n';
      std::cout << "TU OPCION ES: ";
      fflush(stdin);
      gets(validar);
      system("cls");
      opc = atoi(validar);

      switch (opc) {
        case 1:
          pesoDolar pesoaDolar;
          std::cout << "----PESO A DOLAR----" << '\n' << '\n' << '\n';
          ptr1 = &peso;
          pedirMoneda(ptr1);
          pesoaDolar.setPeso(peso);
          pesoaDolar.Calcularpesod();
          std::cout << '\n';
          std::cout << "LA CANTIDAD INGRESADA DE PESOS EN DOLAR SON: " << pesoaDolar.getCambio() << '\n'<< '\n'<< '\n';
          system("pause");
        break;

        case 2:
          dolarPeso DolaraPeso;
          std::cout << "----DOLAR A PESO----" << '\n' << '\n' << '\n';
          ptr1 = &dolar;
          pedirMoneda(ptr1);
          DolaraPeso.setDolar(dolar);
          DolaraPeso.Calculardolarp();
          std::cout << '\n';
          std::cout << "LA CANTIDAD INGRESADA DE DOLARES EN PESOS SON: " << DolaraPeso.getCambio() << '\n'<< '\n'<< '\n';
          system("pause");
        break;

        case 3:
          PesoE pesoaEuro;
          std::cout << "----PESO A EURO----" << '\n' << '\n' << '\n';
          ptr1 = &pesoEuro;
          pedirMoneda(ptr1);
          pesoaEuro.setpesoEuro(pesoEuro);
          pesoaEuro.CalcularpesoEuro();
          std::cout << '\n';
          std::cout << "LA CANTIDAD INGRESADA DE DOLARES EN PESOS SON: " << pesoaEuro.getCambio() << '\n'<< '\n'<< '\n';
          system("pause");
        break;

        case 4:
          EuroP euroaPeso;
          std::cout << "----EURO A PESO----" << '\n' << '\n' << '\n';
          ptr1 = &euros;
          pedirMoneda(ptr1);
          euroaPeso.setEuro(euros);
          euroaPeso.CalcularEurop();
          std::cout << "LA CANTIDAD INGRESADA DE DOLARES EN PESOS SON: " << euroaPeso.getCambio() << '\n'<< '\n'<< '\n';
          system("pause");
        break;

        case 5:
          PesoY pesoaYen;
          std::cout << "----PESO A YEN----" << '\n' << '\n' << '\n';
          ptr1 = &pesoYen;
          pedirMoneda(ptr1);
          pesoaYen.setpesoYen(pesoYen);
          pesoaYen.Calcularpesosyen();
          std::cout << "LA CANTIDAD INGRESADA DE DOLARES EN PESOS SON: " << pesoaYen.getCambio() << '\n'<< '\n'<< '\n';
          system("pause");
        break;

        case 6:
        Yenp yenaPeso;
          std::cout << "----YEN A PESO----" << '\n' << '\n' << '\n';
          ptr1 = &yen;
          pedirMoneda(ptr1);
          yenaPeso.setYen(yen);
          yenaPeso.CalcularYenp();
          std::cout << "LA CANTIDAD INGRESADA DE DOLARES EN PESOS SON: " << yenaPeso.getCambio() << '\n'<< '\n'<< '\n';
          system("pause");
        break;

        case 7:
          PesoYun pesoaYuan;
          std::cout << "----PESO A YUAN----" << '\n' << '\n' << '\n';
          ptr1 = &pesoYuan;
          pedirMoneda(ptr1);
          pesoaYuan.setpesoYuan(pesoYuan);
          pesoaYuan.Calcularpesosyuan();
          std::cout << "LA CANTIDAD INGRESADA DE DOLARES EN PESOS SON: " << pesoaYuan.getCambio() << '\n'<< '\n'<< '\n';
          system("pause");
        break;

        case 8:
          Yuanp ob8;
          std::cout << "----PESO A YUAN----" << '\n' << '\n' << '\n';
          ptr1 = &yuan;
          pedirMoneda(ptr1);
          ob8.setYuan(yuan);
          ob8.CalcularYuan();
          std::cout << "LA CANTIDAD INGRESADA DE DOLARES EN PESOS SON: " << ob8.getCambio() << '\n'<< '\n'<< '\n';
          system("pause");
        break;

        case 9:
         band=1;
        break;

        default:
          system("cls");
          std::cout << "LO QUE HAS INGRSADO NO ES VALIDO" << '\n'<< '\n';
          system("pause");
        break;
      }

  }while(band==0);
}


void pedirMoneda(double *num1){
  char numero2[10];
  int band=0, *ptr=NULL;

  do{
    std::cout << "INGRESE CUANTAS MONESAS VA A CONVERTIR" << '\n';
    fflush(stdin);
    gets(numero2);
    ptr = &band;
    validarValor(numero2, ptr);
      fflush(stdin);
    *num1 = atoi(numero2);
  }while(band==0);
}

int validarValor(char numero[], int *band){
  int contador=0;
    fflush(stdin);
  for(int i=0; i<=10;i++){
    if(isdigit(numero[i])){
      contador++;
    }
  }
  if(contador>0){
    *band=1;
  }else{
      fflush(stdin);
    std::cout << '\n' << "LO INGRESADO NO ES UN VALOR VALIDO, INTENTE DE NUEVO" << '\n';
    system("pause");
    system("cls");
  }
}
