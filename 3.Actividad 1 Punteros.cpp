/*
Autor: Bryan Vizcarra Aguilar
Fecha de creación 28 de agosto de 2021
Fecha de ult Mod: 28 de agosto de 2021
Calculadora haciendo uso de punteros
*/

#include <iostream>
#include <cstdlib>

int suma(int*, int*);
int resta(int*, int*);
int multiplicacion(int*, int*);
int division(int*, int*);

int main(int argc, char const *argv[]) {
  int *ptr1=NULL, *ptr2=NULL, numero1=0, numero2=0, band=1, opc=0;

  do{
    system("cls");
    std::cout << "Ingresa el primer numero" << '\n';
    std::cin >> numero1;
    std::cout << "Ingresa el segundo numero" << '\n';
    std::cin >> numero2;

    ptr1 = &numero1;
    ptr2 = &numero2;

    std::cout << '\n' << "Selecciona la opcion deseada" << '\n';
    std::cout << "1) Suma" << '\n';
    std::cout << "2) Resta" << '\n';
    std::cout << "3) Multiplicacion" << '\n';
    std::cout << "4) Division" << '\n';
    std::cin >> opc;

    switch (opc) {
      case 1:
        std::cout << '\n'<< "El resaultado de la Suma es: "<< suma(ptr1,ptr2)<< '\n';
      break;

      case 2:
        std::cout << '\n' << "El resultado de la Resta es: "<< resta(ptr1,ptr2) << '\n';
      break;

      case 3:
        std::cout << '\n' << "El resultado de la multiplicacion es: "<< multiplicacion(ptr1,ptr2) << '\n';
      break;

      case 4:
      std::cout << '\n' << "El resultado de la division es: "<< division(ptr1,ptr2) << '\n';
      break;
    }
     std::cout << '\n' << "Continuar? 1)Si 0)No" << '\n';
     std::cin >> band;
   }while(band==1);
}

int suma(int *ptr1, int *ptr2){
  int *ptr=(int*)malloc(sizeof(int));
  *ptr=(*ptr1 + *ptr2);
  return *ptr;
}

int resta(int *ptr1, int *ptr2){
  int *ptr=(int*)malloc(sizeof(int));
  *ptr=(*ptr1 - *ptr2);
  return *ptr;
}

int multiplicacion(int *ptr1, int*ptr2){
  int *ptr=(int*)malloc(sizeof(int));
  *ptr=(*ptr1 * *ptr2);
  return *ptr;
}
 int division(int *ptr1, int *ptr2){
   int *ptr=(int*)malloc(sizeof(int));
   *ptr=(*ptr1 / *ptr2);
   return *ptr;
 }
