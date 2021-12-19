/*
  Autor: Bryan Vizcarra Aguilar
  Fecha de Creacion: 17 de septiembre de 2021
  fecha de ult mod: 17 de septiembre de 2021
  Calculo de area de Figuras usando Herencia
*/

#include <iostream>
#include <cstdlib>
#include <strings.h>
#include <cctype>

void pedirBase(double *);
void pedirAltura(double *);
void pedirPerimetro(double *);
void pedirApotema(double *);
int validarValor(char [], int *);

class figuras{
private:
  double base;
  double altura;
public:
  void setBase(double);
  double getBase();
  void setAltura(double);
  double getAltura();
};
void figuras::setBase(double base){
  this->base = base;
}
double figuras::getBase(){
  return this->base;
}
void figuras::setAltura(double altura){
  this->altura = altura;
}
double figuras::getAltura(){
  return this->altura;
}


class triangulo:public figuras{
private:
  double area;
public:
  void calcularArea();
  double getArea();
};
void triangulo::calcularArea(){
  this->area = (this->getBase() * this->getAltura()) / 2;
}
double triangulo::getArea(){
  return this->area;
}


class cuadrado:public figuras{
private:
  double area;
public:
  void calcularArea();
  double getArea();
};
void cuadrado::calcularArea(){
  this->area = this->getBase() * this->getBase();
}
double cuadrado::getArea(){
  return this->area;
}


class rectangulo:public figuras{
private:
  double area;
public:
  void calcularArea();
  double getArea();
};
void rectangulo::calcularArea(){
  this->area = this->getBase() * this->getAltura();
}
double rectangulo::getArea(){
  return this->area;
}

class poligono:public figuras{
private:
  double area;
  double perimetro;
  double apotema;
public:
  void setPerimetro(double);
  double getPerimetro();
  void setApotema(double);
  double getApotema();
  void calcularArea();
  double getArea();
};
void poligono::setPerimetro(double lados){
  this->perimetro = lados;
}
double poligono::getPerimetro(){
  return this->perimetro;
}
void poligono::setApotema(double apotema){
  this->apotema = apotema;
}
double poligono::getApotema(){
  return this->apotema;
}
void poligono::calcularArea(){
  this->area = (this->perimetro * this->apotema) /2;
}
double poligono::getArea(){
  return this->area;
}





int main(int argc, char const *argv[]) {
  int band = 0, band2=0;
  int opc=0;
  char validar[1];
  double baseTriangulo=0, alturaTriangulo=0,*ptr1=NULL;
  double baseCuadrado=0, alturaCuadrado=0;
  double baseRectangulo=0, alturaRectangulo=0;
  double perimetroPoligono=0, apotemaPoligono=0;

  do {
    system("cls");
      std::cout << "SELECCIONE LA OPCION DESEADA" << '\n'<< '\n';
      std::cout << "1. CALCULAR AREA DE UN TRIANGULO" << '\n';
      std::cout << "2. CALCULAR AREA DE UN CUADRADO" << '\n';
      std::cout << "3. CALCULAR AREA DE UN RECTANGULO" << '\n';
      std::cout << "4. CALCULAR AREA DE UN POLIGONO REGULAR" << '\n';
      std::cout << "5. SALIR" << '\n'<< '\n' << '\n';
      std::cout << "TU OPCION ES: ";
      fflush(stdin);
      gets(validar);
      system("cls");
      opc = atoi(validar);

      switch (opc) {
        case 1:
          triangulo objTiangulo;
          std::cout << "----AREA DE UN TRIANGULO----" << '\n' << '\n' << '\n';
          ptr1 = &baseTriangulo;
          pedirBase(ptr1);
          ptr1 = &alturaTriangulo;
          pedirAltura(ptr1);

          objTiangulo.setBase(baseTriangulo);
          objTiangulo.setAltura(alturaTriangulo);
          objTiangulo.calcularArea();

          std::cout << '\n'<< '\n' << "EL AREA DEL TRIANGULO ES: " << objTiangulo.getArea() << '\n'<< '\n' << '\n'<< '\n'<< '\n' ;
          system("pause");
        break;

        case 2:
          cuadrado objCuadrado;
          std::cout << "----AREA DE UN CUADRADO----" << '\n' << '\n' << '\n';
          ptr1 = &baseCuadrado;
          pedirBase(ptr1);

          objCuadrado.setBase(baseCuadrado);
          objCuadrado.calcularArea();

          std::cout << '\n'<< '\n' << "EL AREA DEL CUADRADO ES: " << objCuadrado.getArea() << '\n'<< '\n' << '\n'<< '\n'<< '\n' ;
          system("pause");
        break;

        case 3:
          rectangulo objRectangulo;
          std::cout << "----AREA DE UN RECTANGULO----" << '\n' << '\n' << '\n';
          ptr1 = &baseRectangulo;
          pedirBase(ptr1);
          ptr1 = &alturaRectangulo;
          pedirAltura(ptr1);

          objRectangulo.setBase(baseRectangulo);
          objRectangulo.setAltura(alturaRectangulo);
          objRectangulo.calcularArea();

          std::cout << '\n'<< '\n' << "EL AREA DEL RECTANGULO ES: " << objRectangulo.getArea() << '\n'<< '\n' << '\n'<< '\n'<< '\n' ;
          system("pause");
        break;

        case 4:
          poligono objPoligono;
          std::cout << "----AREA DE UN POLIGONO REGULAR----" << '\n' << '\n' << '\n';
          ptr1 = &perimetroPoligono;
          pedirPerimetro(ptr1);
          ptr1 = &apotemaPoligono;
          pedirApotema(ptr1);

          objPoligono.setPerimetro(perimetroPoligono);
          objPoligono.setApotema(apotemaPoligono);
          objPoligono.calcularArea();

          std::cout << '\n'<< '\n' << "EL AREA DEL POLIGONO ES: " << objPoligono.getArea() << '\n'<< '\n' << '\n'<< '\n'<< '\n' ;
          system("pause");
        break;

        case 5:
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




void pedirBase(double *num1){
  char numero2[10];
  int band=0, *ptr=NULL;

  do{
    std::cout << "INGRESE LA BASE" << '\n';
    fflush(stdin);
    gets(numero2);
    ptr = &band;
    validarValor(numero2, ptr);
      fflush(stdin);
    *num1 = atoi(numero2);
  }while(band==0);
}

void pedirAltura(double *num1){
  char numero2[10];
  int band=0, *ptr=NULL;

  do{
    std::cout << "INGRESE LA ALTURA" << '\n';
    fflush(stdin);
    gets(numero2);
    ptr = &band;
    validarValor(numero2, ptr);
      fflush(stdin);
    *num1 = atoi(numero2);
  }while(band==0);
}


void pedirApotema(double *num1){
  char numero2[10];
  int band=0, *ptr=NULL;

  do{
    std::cout << "INGRESE LA APOTEMA DEL POLIGONO" << '\n';
    fflush(stdin);
    gets(numero2);
    ptr = &band;
    validarValor(numero2, ptr);
      fflush(stdin);
    *num1 = atoi(numero2);
  }while(band==0);
}

void pedirPerimetro(double *num1){
  char numero2[10];
  int band=0, *ptr=NULL;

  do{
    std::cout << "INGRESE EL PERIMETRO DEL POLIGONO" << '\n';
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
