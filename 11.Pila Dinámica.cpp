/*
  Autor: Bryan Vizcarra Aguilar
  Fecha de Creacion: 26 de septiembre de 2021
  fecha de ult mod: 26 de septiembre de 2021
  Implementacion de una pila dinamica utilizando gotoxy
*/

#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <strings.h>
#include <cctype>

int validarNumero(char [], int *);
bool isEmpty();

class Nodo{
public:
  int value;
  Nodo* next;
  void gotoxy(int, int);
};

bool isEmpty(int cont){
  if(cont==0){
    return  true;
  }else{
    return false;
  }
}


void gotoxy(int x,int y){
  HANDLE hcon;
  hcon = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD dwPos;
  dwPos.X = x;
  dwPos.Y= y;
  SetConsoleCursorPosition(hcon,dwPos);
}

void push(Nodo *&pila, int n){
  Nodo *temp = new Nodo();
  temp->value = n;
  temp->next = pila;
  pila = temp;
};

void pop(Nodo *&pila){
  Nodo *temp = pila;
  pila = temp->next;
  delete(temp);
};

void display(Nodo *&pila, int cont){
  Nodo *temp =pila;
  printf("\t\t%c%c%c%c%c     \n",201,205,205,205,187 );
  while(temp!=NULL){
    printf("\t\t%c ", 186, 205 );
    std::cout << temp->value;
    printf(" %c\n", 186);
    printf("\t\t%c%c%c%c%c\n", 204,205,205,205,185);
    temp = temp->next;
  }
};


int main(){
  Nodo *pila = NULL;
  int value, opc, band=0, band2=0, *ptr=NULL, cont=0;
  char validar[2];
  char numero[5];

  do{
    system("cls");
    std::cout << "SELECCIONA LA OPCION DESEA" << '\n';
    std::cout << "1. APLILAR" << '\n';
    std::cout << "2. DESAPILAR" << '\n';
    std::cout << "3. MOSTRAR TOPE" << '\n';
    std::cout << "4. MOSTRAR PILA" << '\n';
    std::cout << "5. SALIR" << '\n';
    gotoxy(0,7); std::cout << "TU OPCIOEN ES: ";
    fflush(stdin);
    gets(validar);

    opc=atoi(validar);

    switch (opc) {
      case 1:
        do {
          gotoxy(0,10);
          std::cout << "INGRESE EL NUMERO A APLILAR" << '\n';
          fflush(stdin);
          gets(numero);
          ptr = &band2;
          validarNumero(numero, ptr);
        }while(band2==0);
        cont++;
        value = atoi(numero);
        push(pila, value);
      break;

      case 2:
        if (isEmpty(cont)) {
          system("cls");
          std::cout << "LA PILA ESTA VACIA" << '\n';
          system("pause");
        }else{
          cont--;
          pop(pila);
        }
      break;

      case 3:
        if (isEmpty(cont)) {
          system("cls");
          std::cout << "LA PILA ESTA VACIA" << '\n';
          system("pause");
        }else{
          system("cls");
          std::cout << "EL TOPE DE LA PILA ES: " << pila->value << '\n';
          system("pause");
          system("cls");
        }
      break;

      case 4:
        if (isEmpty(cont)) {
          system("cls");
          std::cout << "LA PILA ESTA VACIA" << '\n';
          system("pause");
        }else{
          system("cls");
          gotoxy(8,0);
          std::cout << "LA PILA ES LA SIGUIENTE" << '\n';
          display(pila, cont);
          std::cout  << '\n';
          std::cout  << '\n';
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
  }while(band==0);
}

validarNumero(char numero[], int *band2){
  int contador=0;

  for(int i=0; i<5;i++){
    if(isdigit(numero[i])){
      contador++;
    }
  }
  if(contador>0){
    *band2=1;
  }else{
    std::cout << '\n' << "LO INGRESADO NO ES UN VALOR VALIDO, INTENTE DE NUEVO" << '\n';
    system("pause");
    system("cls");
  }
}
