/*
Autor: Bryan Vizcarra Aguilar
Fecha de creacion: 4 de septiembre de 2021
Fecha de ult mod: 4 de septiembre de 2021
Conversion de decimal a hexadecimal
*/

#include <iostream>
#include <cstdlib>

int conversionHexadecimal(int*);

int main(int argc, char const *argv[]) {
  int num, *ptr=NULL;

  std::cout << "Ingresa un numero" << '\n';
  std::cin >> num;

  ptr = &num;

  conversionHexadecimal(ptr);

  return 0;
}

int conversionHexadecimal(int *ptr){
  int residuo,  cociente, i=0, j;
  int letrahexadecimal[20];

  do{
    residuo = *ptr%16;
    cociente = *ptr/16;
    letrahexadecimal[i] = residuo;
    *ptr = cociente;
    i++;
  }while(cociente > 15);

  letrahexadecimal[i] = cociente;

  std::cout << '\n' << "El numero hexadecimal es: ";

  for(j = i; j >= 0 ; j--){
    switch (letrahexadecimal[j]) {
      case 10:
        std::cout << "A";
      break;

      case 11:
        std::cout << "B";
      break;

      case 12:
        std::cout << "C";
      break;

      case 13:
        std::cout << "D";
      break;

      case 14:
         std::cout << "E";
      break;

      case 15:
        std::cout << "F";
      break;

      default:
        std::cout << letrahexadecimal[j] ;
      break;
    }
  }
  std::cout << '\n' << '\n';
}
