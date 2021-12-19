/*
  Autor: Bryan Vizcarra Aguilar
  Fecha de Creacion: 9 de septiembre de 2021
  Fecha de ult mod: 9 de septiembre de 2021
  Calculador de Area de figuras geometricas
*/

#include <iostream>
#include <cstdlib>
#include <ctype.h>


void menu(int, int*);


class triangulo{
private:
  double base;
  double altura;
  double area;

public:
  void setBase(double);
  int getBase();
  void setaAltura(double);
  int getAltura();
  void calcularArea();
  int getArea();
};

void triangulo::setBase(double base){
  this->base=base;
}

int triangulo::getBase(){
  return this->base;
}

void triangulo::setaAltura(double altura){
  this->altura=altura;
}

int triangulo::getAltura(){
  return this->altura;
}

void triangulo::calcularArea(){
  this->area=((this->base * this->altura)/2);
}

int triangulo::getArea(){
  return this->area;
}

class cuadrado{
private:
  double lado;
  double area;

public:
  void setLado(double);
  int getLado();
  void calcularArea();
  int getArea();
};

void cuadrado::setLado(double lado){
  this->lado=lado;
}

int cuadrado::getLado(){
  return this->lado;
}

void cuadrado::calcularArea(){
  this->area=(this->lado * this->lado);
}

int cuadrado::getArea(){
  return this->area;
}


class rectangulo{
private:
  double base;
  double altura;
  double area;

public:
  void setBase(double);
  int getBase();
  void setAltura(double);
  int getAltura();
  void calcularArea();
  int getArea();
};

void rectangulo::setBase(double base){
  this->base = base;
}

int rectangulo::getBase(){
  return this->base;
}

void rectangulo::setAltura(double altura){
  this->altura = altura;
}

int rectangulo::getAltura(){
  return this->altura;
}

void rectangulo::calcularArea(){
  this->area = (this->base * this->altura);
}

int rectangulo::getArea(){
  return this->area;
}


int main(int argc, char const *argv[]) {
  int band=0, op=0, *ptr;
  do {
    system("cls");
      std::cout << "SELECCIONE LA OPCION DESEADA" << '\n'<< '\n';
      std::cout << "1. CALCULAR AREA DE UN TRIANGULO" << '\n';
      std::cout << "2. CALCULAR AREA DE UN CUADRADO" << '\n';
      std::cout << "3. CALCULAR AREA DE UN RECTANGULO" << '\n';
      std::cout << "0. SALIR" << '\n'<< '\n' << '\n';
      std::cout << "TU OPCION ES: ";
      std::cin >> op;
      ptr=&band;
      menu(op, ptr);

  } while(band==0);
  return 0;
}

void menu(int op ,int *band){
  double baseTriangulo=0, alturaTriangulo=0, areaTiangulo;
  double ladoCuadrado=0, areaCuadrado=0;
  double baseRectangulo=0, areaRectangulo=0, alturaRectangulo=0;
  system("cls");
    switch (op) {
      case 0:
        *band=1;
      break;

      case 1:
        triangulo objTiangulo;
        std::cout << "----AREA DE UN TRIANGULO----" << '\n' << '\n' << '\n';
        std::cout << "INGRESE LA BASE DEL TRIANGULO" << '\n';
        std::cin >> baseTriangulo;
        std::cout << "INGRESE LA ALTURA DEL TRIANGULO" << '\n';
        std::cin >> alturaTriangulo;
        objTiangulo.setBase(baseTriangulo);
        objTiangulo.setaAltura(alturaTriangulo);
        objTiangulo.calcularArea();
        std::cout << '\n'<< '\n' << "EL AREA DEL TRIANGULO ES: " << objTiangulo.getArea() << '\n'<< '\n' << '\n'<< '\n'<< '\n' ;
        system("pause");
      break;

      case 2:
       cuadrado objCuadrado;
       std::cout << "----AREA DE UN CUADRADO----" << '\n' << '\n' << '\n';
       std::cout << "INGRESE EL LADO DEL CUADRADO" << '\n';
       std::cin >> ladoCuadrado;
       objCuadrado.setLado(ladoCuadrado);
       objCuadrado.calcularArea();
       std::cout << '\n' << '\n' << "EL AREA DEL CUADRADO ES: "<< objCuadrado.getArea() << '\n'<< '\n' << '\n'<< '\n'<< '\n';
       system("pause");
      break;

      case 3:
        rectangulo objRectangulo;
        std::cout << "----AREA DE UN RECTANGULO----" << '\n' << '\n' << '\n';
        std::cout << "INGRESE LA BASE DEL RECTANGULO" << '\n';
        std::cin >> baseRectangulo;
        std::cout << "INGRESE LA ALTURA DEL RECTANGULO" << '\n';
        std::cin >> alturaRectangulo;
        objRectangulo.setBase(baseRectangulo);
        objRectangulo.setAltura(alturaRectangulo);
        objRectangulo.calcularArea();
        std::cout << '\n'<< '\n' << "EL AREA DEL RECTANGULO ES: " << objRectangulo.getArea() << '\n'<< '\n' << '\n'<< '\n'<< '\n' ;
        system("pause");
      break;

      default:
        std::cout << "LA OPCION NO ES VALIDA" << '\n';
        system("pause");
      break;
    }

}
