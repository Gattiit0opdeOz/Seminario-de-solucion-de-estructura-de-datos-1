/*
  Autor: Bryan Vizcarra Aguilar
  Fecha de Creacion: 02 de octubre de 2021
  fecha de ult mod: 02 de octubre de 2021
  Implementacion de una cola dinámica utilizando gotoxy
*/

#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <strings.h>
#include <cctype>

int validarNumero(char [], int *);

class Nodo{
public:
  int inicio;
  int valor;
  Nodo  *sig;
};

bool isEmpty(Nodo *primero){
  return(primero==NULL)? true : false;
}

void push(Nodo *&primero, Nodo *&ultimo, int valor){
  Nodo *nuevoNodo = new Nodo();
  nuevoNodo->valor = valor;
  nuevoNodo->sig = NULL;

  if(isEmpty(primero)){
    primero = nuevoNodo;
  }else{
    ultimo->sig = nuevoNodo;
  }
  ultimo = nuevoNodo;
}

void pop(Nodo *&primero, Nodo *&ultimo){
  Nodo *aux = primero;
  if(isEmpty(primero)){
    system("cls");
    std::cout << "LA COLA ESTA VACIA. NO CONTIENE NINGUN ELEMENTO" << '\n';
    system("pause");
  }else if(primero==ultimo){
    primero=NULL;
    ultimo=NULL;
  }else{
    primero = primero->sig;
  }
  delete aux;
}

void gotoxy(int x,int y){
  HANDLE hcon;
  hcon = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD dwPos;
  dwPos.X = x;
  dwPos.Y= y;
  SetConsoleCursorPosition(hcon,dwPos);
}

void printQueue(Nodo *&primero, int cont){
  Nodo *temp = primero;
  if (isEmpty(primero)) {
      std::cout << "LA COLA ESTA VACIA" << '\n';
  }else{
    for(int i=cont;i>0;i--){
      printf("%c%c%c%c%c",201,205,205,205,187);
    }
    std::cout << '\n';
    while(temp!=NULL){
      printf("%c ",186);
      std::cout << temp->valor;
      printf(" %c",186);
      temp = temp->sig;
    }
    std::cout << '\n';
    for(int i=cont;i>0;i--){
      printf("%c%c%c%c%c", 200,205,205,205,188);
    }
  }
}


int main(int argc, char const *argv[]) {
  int op, band=0, band2=0, *ptr=NULL, valor, cont=0;
  char validar[2], numero[10];
  Nodo *primero = NULL;
  Nodo *ultimo = NULL;

  do {
    system("cls");
    printQueue(primero, cont); gotoxy(0,5);
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
        push(primero, ultimo, valor);
        cont++;
      break;

      case 2:
        pop(primero, ultimo);
        cont--;
      break;

      case 3:
        system("cls");
        if(isEmpty(primero)){
          std::cout << "LA COLA ESTA VACIA. NO CONTIENE NINGUN ELEMENTO" << '\n';
          system("pause");
        }else{
          std::cout << "EL INICIO DE LA COLA ES: " <<primero->valor << '\n';
          system("pause");
        }
      break;

      case 4:
        system("cls");
        if(isEmpty(primero)){
          std::cout << "LA COLA ESTA VACIA. NO CONTIENE NINGUN ELEMENTO" << '\n';
          system("pause");
        }else{
          std::cout << "EL FINAL DE LA COLA ES: " <<ultimo->valor << '\n';
          system("pause");
        }
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
