/*
Autor: Bryan Vizcarra Aguilar
Fecha de creacion: 4 de septiembre de 2021
Fecha de ult mod: 4 de septiembre de 2021
Conversion de decimal a binario
*/

#include <iostream>
#include <cstdlib>

int conversionBinario(int*);

int main(int argc, char const *argv[]) {
  int num, band=1;
  int *ptr = NULL;

  do{
    system("cls");
    std::cout << "Ingresa un numero" << '\n';
    std::cin >> num;
    ptr = &num;

    std::cout << '\n' << num << " a binario es igual a: ";
    conversionBinario(ptr);

    std::cout << "Continuar? 1.Si  0.No" << '\n';
    std::cin >> band;
  }while(band==1);
  return 0;
}

int conversionBinario(int *ptr){
  int cociente=0, residuo=0, i=0, j=0, numero;
  int binario[50];

  numero = *ptr;

  while (numero/2 > 0) {
    cociente = numero/2;
    residuo = numero%2;
    numero = cociente;
    binario[i] = residuo;
    i++;
  }
  binario[i] = cociente;


if(*ptr%2 == 0){
  for(i; i>=0; i--){
    std::cout << binario[i];
  }
}else{
   for(j = 0; j<=i; j++){
    std::cout << binario[j];
   }
}
  std::cout << '\n' << '\n';
}
