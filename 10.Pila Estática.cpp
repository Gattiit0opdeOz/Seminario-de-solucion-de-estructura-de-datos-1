/*
  Autor: Bryan Vizcarra Aguilar
  Fecha de Creacion: 25 de septiembre de 2021
  fecha de ult mod: 25 de septiembre de 2021
  Implementacion de una pila estatica utilizando gotoxy
*/

#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <strings.h>
#include <cctype>

int validarNumero(char [], int *);

class pila{
private:
  int datos[10];
  int tope;
public:
  pila(); //contrusctor
  void push();
  void pop();
  int empty();
  int full();
  void mostrarTope();
  void mostrarPila();
  void gotoxy(int, int);
};

pila::pila(){
  tope=-1;
}

void pila:: gotoxy(int x,int y){
  HANDLE hcon;
  hcon = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD dwPos;
  dwPos.X = x;
  dwPos.Y= y;
  SetConsoleCursorPosition(hcon,dwPos);
}

void pila::push(){
  char numero[5];
  int x, band=0, *ptr=NULL;

  if(full()==0){
    do{
      gotoxy(10,20);
      std::cout << "INGRESA UN NUMERO" << '\n';
      fflush(stdin);
      gets(numero);
      ptr = &band;
      validarNumero(numero, ptr);
      x = atoi(numero);
    }while(band==0);

    tope++;
    datos[tope]=x;
  }
}

void pila::pop(){
  if(empty()==0){
    datos[tope]=0;
    tope--;
  }
}

void pila::mostrarTope(){
  if(empty()==0){
    system("cls");
    std::cout << "EL TOPE ES: " <<datos[tope] << '\n';
    system("pause");
  }
}

void pila::mostrarPila(){
  int i;
  if(empty()==0){
    system("cls");
    gotoxy(8,0); std::cout << "LA PILA ES LA SIGUIENTE" << '\n';
    printf("\n\n\t\t%c%c%c%c%c     \n",201,205,205,205,187 );
    for(i=tope;i>=0;i--){
      printf("\t\t%c ", 186, 205 );
      std::cout << datos[i]; printf(" %c\n", 186);
      printf("\t\t%c%c%c%c%c\n", 204,205,205,205,185);
    }
  }
  std::cout << "\n\n\n";
  system("pause");
}

int pila::empty(){
  if(tope==-1){
    system("cls");
    std::cout << "LA PILA ESTA VACIA" << '\n';
    system("pause");
    system("cls");
    return 1;
  }else{
    return 0;
  }
}

int pila::full(){
  if(tope==9){
    system("cls");
    std::cout << "LA PILA ESTA LLENA" << '\n';
    system("pause");
    return 1;
  }else{
    return 0;
  }
}

int main(int argc, char const *argv[]) {
  pila p;
  int op, num, band=0;
  char validar [2];

    do{
      system("cls");
      std::cout << "SELECCIONE LA OPCION DESEADA" << '\n';
      std::cout << "1. APILAR" << '\n';
      std::cout << "2. DESAPILAR" << '\n';
      std::cout << "3. MOSTRAR TOPE" << '\n';
      std::cout << "4. MOSTRAR PILA" << '\n';
      std::cout << "5. SALIR" << '\n';
      fflush(stdin);
      gets(validar);

      op = atoi(validar);

      switch (op) {
        case 1:
          p.push();
        break;

        case 2:
          p.pop();
        break;

        case 3:
          p.mostrarTope();
        break;

        case 4:
          p.mostrarPila();
        break;

        case 5:
          band=1;
        break;

        default:
          system("cls");
          std::cout << "LO INGRESADO NO ES VALIDO" << '\n';
          system("pause");
        break;
      }

    }while(band==0);

  return 0;
}


validarNumero(char numero[], int *band){
  int contador=0;

  for(int i=0; i<5;i++){
    if(isdigit(numero[i])){
      contador++;
    }
  }
  if(contador>0){
    *band=1;
  }else{
    std::cout << '\n' << "LO INGRESADO NO ES UN VALOR VALIDO, INTENTE DE NUEVO" << '\n';
    system("pause");
    system("cls");
  }
}
