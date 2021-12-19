/*
  Autor: Bryan Vizcarra Aguilar
  Fecha de Creacion: 02 de octubre de 2021
  fecha de ult mod: 02 de octubre de 2021
  Implementacion de una cola estática utilizando gotoxy
*/

#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <strings.h>
#include <cctype>

int validarNumero(char [], int *);

class cola{
private:
  int inicio, fin;
  int dato[10];
public:
  cola();
  bool isFull();
  bool isEmpty();
  void enqueue(int);
  void dequeue();
  void printLast();
  void printFirst();
  void printQueue();
};

cola::cola(){
  inicio=0;
  fin=-1;
}

void gotoxy(int x,int y){
  HANDLE hcon;
  hcon = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD dwPos;
  dwPos.X = x;
  dwPos.Y= y;
  SetConsoleCursorPosition(hcon,dwPos);
}

bool cola::isFull(){
  return(fin==9)? true : false;
}

bool cola::isEmpty(){
  return(fin==-1)? true : false;
}

void cola::enqueue(int valor){
  system("cls");
  if (isFull()) {
    std::cout << "LA COLA ESTA LLENA Y NO ES POSIBLE INGRESAR MAS ELEMENTOS" << '\n';
    system("pause");
  }else{
    fin++;
    dato[fin] = valor;
  }
}

void cola::dequeue() {
  system("cls");
  if(isEmpty()){
    std::cout << "LA COLA ESTA VACIA. NO CONTIENE NINGUN ELEMENTO" << '\n';
    system("pause");
  }else{
    for(int i=0; i<=fin;i++){
      dato[i] = dato[i+1];
    }
    fin--;
  }
}

void cola::printFirst(){
  system("cls");
  if(isEmpty()){
    std::cout << "LA COLA ESTA VACIA. NO CONTIENE NINGUN ELEMENTO" << '\n';
  }else{
    std::cout << "EL PRIMER ELEMENTO ES: " << dato[inicio] << '\n';
  }
}

void cola::printLast() {
  system("cls");
  if(isEmpty()){
    std::cout << "LA COLA ESTA VACIA. NO CONTIENE NINGUN ELEMENTO" << '\n';
  }else{
    std::cout << "EL ULTIMO ELEMENTO ES: " << dato[fin] << '\n';
  }
}

void cola::printQueue(){
  if(isEmpty()){
    std::cout << "LA COLA ESTA VACIA" << '\n';
  }else{
    for(int i=fin;i>=0;i--){
      printf("%c%c%c%c%c",201,205,205,205,187);
    }
    std::cout << '\n';
    for(int i=fin;i>=0;i--){
        printf("%c ",186);
        std::cout << dato[i];
        printf(" %c",186);
    }
    std::cout << '\n';
    for(int i=fin;i>=0;i--){
      printf("%c%c%c%c%c", 200,205,205,205,188);
    }
  }
}


int main(int argc, char const *argv[]) {
  int op, band=0, band2=0, *ptr=NULL, valor;
  char validar[2], numero[10];
  cola objQueue;

  do {
    system("cls");
    objQueue.printQueue(); gotoxy(0,5);
    std::cout << "SELECCIONA LA OPCION DESEADA" << '\n';
    std::cout << "1. AGREGAR ELEMENTO" << '\n';
    std::cout << "2. ELIMINAR ELEMENTO" << '\n';
    std::cout << "3. MOSTRAR INICIO" << '\n';
    std::cout << "4. MOSTRAR FINAL" << '\n';
    std::cout << "5. SALIR" << '\n'<< '\n'<< '\n';
    std::cout << "TU OPCION ES: ";
    fflush(stdin);
    gets(validar);

    switch (op=atoi(validar)) {

      case 1:
        do {
          system("cls");
          std::cout << "----------AGREGAR ELEMENTO----------" << '\n'<< '\n';
          std::cout << "INGRESA EL NUMERO QUE DESEAS AGREGAR" << '\n';   gotoxy(0,5);
          std::cout << "TU NUMERO ES: " << '\n';
          fflush(stdin);
          gets(numero);
          ptr = &band2;
          validarNumero(numero,ptr);
        }while(band2==0);
        valor = atoi(numero);
        objQueue.enqueue(valor);

      break;

      case 2:
        objQueue.dequeue();
      break;

      case 3:
        objQueue.printFirst();
        system("pause");
      break;

      case 4:
        objQueue.printLast();
        system("pause");
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

  } while(band==0);
  return 0;
}

int validarNumero(char numero[], int *band){
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
