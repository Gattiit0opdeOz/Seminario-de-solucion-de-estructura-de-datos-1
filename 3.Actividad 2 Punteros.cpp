/*
Autor: Bryan Vizcarra Aguilar
Fecha de creación 28 de agosto de 2021
Fecha de ult Mod: 28 de agosto de 2021
Calculadora de factorial haciendo uso de punteros
*/

#include <iostream>
#include <cstdlib>

int factorial(int*);

int main(int argc, char const *argv[]) {
    int *ptr= NULL, numero=0;

    std::cout << "Ingrese el numero a sacar factorial" << '\n';
    std::cin >> numero;
    ptr= &numero;
    std::cout << '\n' << numero ;
    std::cout << " factorial es igual a "<<factorial(ptr) << '\n' << '\n';
  return 0;
}

int factorial(int *ptr){
  for(int i=*ptr; i>2;i--){
    *ptr *= (i-1);
  }
  return *ptr;
}
