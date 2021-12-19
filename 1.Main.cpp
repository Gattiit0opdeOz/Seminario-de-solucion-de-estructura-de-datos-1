//Bryan Cristian Alberto Vizcarra Aguilar
//INTRODUCCION A PROGRAMACION

#include <iostream>
#include <cstdlib>
#include <math.h>
using namespace std;

int suma();
int resta();
double multiplicacion();
double division();
void factorial();
double raiz();
void menu();
void pedirNumeros();

double numero1=0, numero2=0;

int main(int argc, char const *argv[]) {
  int opc=0;
  do{
    system("cls");
    system("clear");
    menu();

    cout << "Continuar 1[si] 0[no]" <<endl;
    cin >> opc;
  }while(opc!=0);
  return 0;
}

void menu(){
    int opcion=0;
    cout << "-----MENU-----" <<endl;
    cout << "1) SUMA" <<endl;
    cout << "2) RESTA" <<endl;
    cout << "3) MULTIPLICACION" <<endl;
    cout << "4) DIVISION" <<endl;
    cout << "5) FACTORIAL" <<endl;
    cout << "6) RAIZ CUADRADA" <<endl;
    cout << "0) SALIR "<<endl;
    cin >> opcion;

    switch(opcion){
      case 0:
        exit(EXIT_SUCCESS);
      break;

      case 1:
        pedirNumeros();
        cout << "El resltado de la Suma es: "<< suma() <<endl <<endl;
      break;

      case 2:
        pedirNumeros();
        cout << "El resltado de la Resta es: "<< resta() <<endl <<endl;
      break;

      case 3:
        pedirNumeros();
        cout << "El resltado de la Multiplicacion es: "<< multiplicacion() <<endl <<endl;
      break;

      case 4:
        pedirNumeros();
        cout << "El resltado de la Division es: "<< division() <<endl <<endl;
      break;

      case 5:
        factorial();
      break;

      case 6:
        cout << "La raiz cuadrada es: "<< raiz() <<endl <<endl;
      break;

      default:
        system("cls");
        cout << "LA OPCION INGRESADA NO ES VALIDA" <<endl <<endl;
      break;
    }
}

void pedirNumeros(){
  cout << endl;
  cout << "Ingrese el valor del numero 1" <<endl;
  cin >> numero1;
  cout << "Ingrese el valor del numero 2" <<endl;
  cin >> numero2;
}

int suma(){
  return(numero1+numero2);
}

int resta (){
  return(numero1-numero2);
}

double multiplicacion(){
  return (numero1*numero2);
}

double division(){
  return (numero1/numero2);
}

double raiz(){
  cout << "Ingrese un numero" <<endl;
  cin>>numero1;
  return sqrt(numero1);
}

void factorial(){
  cout << "Ingrese un numero" <<endl;
  cin>>numero1;
  for(int i=numero1;i>2;i--){
    numero1*=(i-1);
  }
  cout<<"El factorial es: "<<numero1 <<endl <<endl;
}
