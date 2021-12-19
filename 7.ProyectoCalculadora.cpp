/*
  Autor: Bryan Vizcarra Aguilar
  Fecha de creacion: 11 de septiembre de 2021
  Fecha de ult mod:
  Calculadora con funciones extras
*/
#include <iostream>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <strings.h>



//Prototipo de Funciones
void menu();
int validarNumero(char [], int *);
void pedirNumeros(double *, double *);
void pedirUnNumero(double *);
double suma(double, double);
double resta(double, double);
double multiplicacion(double, double);
double division(double, double);
double potencia(double, double);
double factorial(double *);
double decimalBinario(double *);
double binarioDecimal(double *);
double decimalOctal(double *);
double octalDecimal(double *);
double decimalHexadecimal(double *);
int hexadecimalDecimal(char[]);


//Función main();
int main(int argc, char const *argv[]) {
 bool band=true, band2=true;
 int salir;
 char validar[2];

  do{
    menu();
    system("cls");

    do{
      std::cout << "SEGURO QUE DESEA SALIR?" << '\n';
      std::cout << "1. Si" << '\n';
      std::cout << "2. No" << '\n';
      gets(validar);

      salir = atoi(validar);

      if(salir==1){
        band2=false;
        band=false;
      } else if(salir==2){
        band2=false;
      } else{
        system("cls");
        std::cout << "LO INGRESADO NO ES VALIDO, INTENTE DE NUEVO" << '\n';
        band2=true;
        system("pause");
        system("cls");
      }
    }while(band2==true);
  }while(band==true);

  return 0;
}//Fin main();

//Función menu();
void menu() {
  double num1, num2;
  int opc;
  double *ptr1=NULL, *ptr2=NULL;
  char validar[2], numero[10];
  bool band = true;

  do{
    system("cls");
    std::cout << "--------CALCULADORA--------" << '\n';
    std::cout << "SELECCIONA LA OPCION DESEADA" << '\n'<< '\n';
    std::cout << "1. SUMA" << '\n';
    std::cout << "2. RESTA" << '\n';
    std::cout << "3. MULTIPLICACION" << '\n';
    std::cout << "4. DIVISION" << '\n';
    std::cout << "5. POTENCIA" << '\n';
    std::cout << "6. FACTORIAL" << '\n';
    std::cout << "7. DECIMAL - BINARIO" << '\n';
    std::cout << "8. BINARIO - DECIMAL" << '\n';
    std::cout << "9. DECIMAL - OCTAL" << '\n';
    std::cout << "10. OCTAL - DECIMAL" << '\n';
    std::cout << "11. DECIMAL - HEXADECIMAL" << '\n';
    std::cout << "12. HEXADECIMAL - DECIMAL" << '\n';
    std::cout << "13. SALIR" << '\n';
    fflush(stdin);
    gets(validar);


    opc = atoi(validar);

    switch (opc) {
      case 1:
        system("cls");
        std::cout << "-------SUMA-------" << '\n' << '\n';
        ptr1 = &num1;
        ptr2 = &num2;
        pedirNumeros(ptr1, ptr2);
        std::cout << '\n';
        std::cout << "LA SUMA DE " << num1 <<" + " << num2 << " ES IGUAL A: " << suma(num1,num2) << '\n'<< '\n'<< '\n';
        system("pause");
        band=true;
      break;

      case 2:
        /*Por alguna estraña razon quitar esta linea de codigo altera el espacio tiempo del
        programa en la validacion del case 6 ***NO BORRAR**
        Esta linea de aqui>*/std::cout << "-------FACTORIAL-------" << '\n' << '\n';
        system("cls");

        std::cout << "-------RESTA-------" << '\n' << '\n';
        ptr1 = &num1;
        ptr2 = &num2;
        pedirNumeros(ptr1, ptr2);
        std::cout << '\n';
        std::cout << "LA RESTA DE " << num1 <<" - " << num2 << " ES IGUAL A: " << resta(num1,num2) << '\n'<< '\n'<< '\n';
        system("pause");
        band=true;
      break;

      case 3:
        system("cls");
        std::cout << "-------MULTIPLICACION-------" << '\n'<< '\n';
        ptr1 = &num1;
        ptr2 = &num2;
        pedirNumeros(ptr1, ptr2);
        std::cout << '\n';
        std::cout << "LA MULTIPLICACION DE " << num1 <<" x " << num2 << " ES IGUAL A: " << multiplicacion(num1,num2) << '\n'<< '\n'<< '\n';
        system("pause");
        band=true;
      break;

      case 4:
        system("cls");
        std::cout << "-------DIVISION-------" << '\n'<< '\n';
        ptr1 = &num1;
        ptr2 = &num2;
        pedirNumeros(ptr1, ptr2);
        std::cout << '\n';
        std::cout << "LA DIVISION DE " << num1 <<" / " << num2 << " ES IGUAL A: " << division(num1,num2) << '\n'<< '\n'<< '\n';
        system("pause");
        band=true;
      break;

      case 5:
        system("cls");
        std::cout << "-------POTENCIA-------" << '\n'<< '\n';
        std::cout << "ESCRIBA EL NUMERO QUE DESEA ELEVAR" << '\n';
        std::cout << "DESPUES ESCRIBA LA POTENCIA A LA QUE DESEA QUE SEA ELEVADO" << '\n'<< '\n';
        ptr1 = &num1;
        ptr2 = &num2;
        pedirNumeros(ptr1, ptr2);
        std::cout << '\n';
        std::cout << "EL NUMERO " << num1 <<" ELEVADO A LA " << num2 << " POTENCIA ES IGUAL A: " << potencia(num1,num2) << '\n'<< '\n'<< '\n';
        system("pause");
        band=true;
      break;

      case 6:
      system("cls");
      std::cout << "-------FACTORIAL-------" << '\n' << '\n';
      ptr1 = &num1;
      pedirUnNumero(ptr1);
      num2 = num1;
      ptr2 = &num2;
      std::cout << '\n';
      std::cout  << num1 <<" FACTORIAL ES IGUAL A " << factorial(ptr2) << '\n'<< '\n'<< '\n';
      system("pause");
      band=true;
      break;

      case 7:
        system("cls");
        std::cout << "-------DECIMAL A BINARIO-------" << '\n'<< '\n';
        ptr1 = &num1;
        pedirUnNumero(ptr1);
        num2 = num1;
        ptr2 = &num2;
        std::cout << '\n';
        std::cout << num1 << " ES IGUAL A ";
        decimalBinario(ptr2) ;
        std::cout << " EN BINARIO" << '\n'<< '\n'<< '\n';
        system("pause");
      break;

      case 8:
        system("cls");
        std::cout << "------- BINARIO A DECIMAL-------" << '\n'<< '\n';
        ptr1 = &num1;
        pedirUnNumero(ptr1);
        std::cout << '\n';
        std::cout << num1 << " ES IGUAL A ";
        binarioDecimal(ptr1);
        std::cout << " DECIMAL" << '\n'<< '\n'<< '\n';
        system("pause");
      break;

      case 9:
        system("cls");
        std::cout << "-------DECIMAL A OCTAL-------" << '\n'<< '\n';
        ptr1 = &num1;
        pedirUnNumero(ptr1);
        std::cout << '\n';
        std::cout << num1 << " ES IGUAL A ";
        std::cout << decimalOctal(ptr1)<< " OCTAL" << '\n'<< '\n'<< '\n';
        system("pause");
      break;

      case 10:
        system("cls");
        std::cout << "-------OCTAL A DECIMAL-------" << '\n'<< '\n';
        ptr1 = &num1;
        pedirUnNumero(ptr1);
        std::cout << '\n';
        std::cout << num1 << " ES IGUAL A ";
        std::cout << octalDecimal(ptr1)<< " DECIMAL" << '\n'<< '\n'<< '\n';
        system("pause");
      break;

      case 11:
        system("cls");
        std::cout << "--------DECIMAL A HEXADECIMAL-------" << '\n'<< '\n';
        ptr1 = &num1;
        pedirUnNumero(ptr1);
        std::cout << '\n';
        std::cout << num1;
        decimalHexadecimal(ptr1);
        std::cout << " EN HEXADECIMAL"<< '\n'<< '\n'<< '\n';
        system("pause");
      break;

      case 12:
        system("cls");
        std::cout << "-------HEXADECIMAL A DECIMAL-------" << '\n'<< '\n';
        std::cout << "INGRESE EL NUMERO HEXADECIMAL" << '\n';
        fflush(stdin);
        gets(numero);

        for(int i=0; numero[i] != '\0';i++){ //Conversion a Mayusculas
          numero[i] = toupper(numero[i]);
        }
        std::cout << '\n';
        std::cout << numero << " ES IGUAL A " << hexadecimalDecimal(numero) <<" EN DECIMAL" << '\n'<< '\n'<< '\n';
        system("pause");
      break;

      case 13:
        band=false;
      break;

      default:
        band=true;
        system("cls");
        std::cout << "LO INGRESADO NO ES VALIDO" << '\n';
        system("pause");
      break;
    }
  }while(band==true);
}//Fin menu()


//Solicita 2 numero
void pedirNumeros(double *num1, double *num2){
  char numero[10];
  int band=0, *ptr=NULL;

  do{
    std::cout << "INGRESE EL NUMERO 1" << '\n';
    fflush(stdin);
    gets(numero);
    ptr = &band;
    validarNumero(numero, ptr);
    *num1 = atoi(numero);
  }while(band==0);

  band=0;

  do{
    std::cout << '\n' << "INGRESE EL NUMERO 2" << '\n';
    fflush(stdin);
    gets(numero);
    ptr = &band;
    validarNumero(numero, ptr);
    *num2 = atoi(numero);
  }while(band==0);
}//Fin pedirNumeros();

//Solicita 1 numero
void pedirUnNumero(double *num1){
  char numero2[10];
  int band=0, *ptr=NULL;

  do{
    std::cout << "INGRESE EL NUMERO 1" << '\n';
    fflush(stdin);
    gets(numero2);
    ptr = &band;
    validarNumero(numero2, ptr);
      fflush(stdin);
    *num1 = atoi(numero2);
  }while(band==0);
}//Fin pedirNumeros();


//Validación de digitos
int validarNumero(char numero[], int *band){
  int contador=0;
    fflush(stdin);
  for(int i=0; i<=10;i++){
    if(isdigit(numero[i])){
      contador++;
    }
  }
  if(contador>0){
    *band=1;
  }else{
      fflush(stdin);
    std::cout << '\n' << "LO INGRESADO NO ES UN VALOR VALIDO, INTENTE DE NUEVO" << '\n';
    system("pause");
    system("cls");
  }
}


//Funcion de Suma
double suma(double num1, double num2){
  return (num1+num2);
}

//Funcion de Resta
double resta(double num1, double num2){
  return (num1-num2);
}

//Funcion de Multiplicacion
double multiplicacion(double num1, double num2){
  return (num1*num2);
}

//Funcion de Division
double division(double num1, double num2){
  return (num1/num2);
}

//Funcion de Potencia
double potencia(double num1, double num2){
  return pow(num1,num2);
}

//Funcion de Factorial
double factorial(double *ptr){
  for(int i=*ptr; i>2;i--){
    *ptr *= (i-1);
  }
  return *ptr;
}

//Funcion Decimal a Binario
double decimalBinario(double *ptr){
  int cociente=0, residuo=0, i=0, j=0, numero, numero2;
  int binario[50];

  numero = *ptr;
  numero2 = numero;

  while (numero/2 > 0) {
    cociente = numero/2;
    residuo = numero%2;
    numero = cociente;
    binario[i] = residuo;
    i++;
  }
  binario[i] = cociente;


  if(numero2%2 == 0){
    for(i; i>=0; i--){
      std::cout << binario[i];
    }
  }else{
     for(j = 0; j<=i; j++){
      std::cout << binario[j];
     }
  }
}

//Funcion Binario a Decimal
double binarioDecimal(double *ptr){
  int exp,digito;
    double binario, decimal;
   binario = *ptr;
   exp=0;
   decimal=0;
   while(((int)(binario/10))!=0)
   {
           digito = (int)binario % 10;
           decimal = decimal + digito * pow(2.0,exp);
           exp++;
           binario=(int)(binario/10);
   }
   decimal=decimal + binario * pow(2.0,exp);
   std::cout << decimal;
}

//Funcion Decimal a Octal
double decimalOctal(double *ptr){
  int rem, i = 1;
  double numeroOctal = 0, numeroDecimal = *ptr;

    while( numeroDecimal != 0 ) {
        rem = (int)numeroDecimal % 8;
        numeroDecimal /= 8;
        numeroOctal += rem * i;
        i *= 10;
    }
    return numeroOctal;
}

//Funcion Octal a Decimal
double octalDecimal(double *ptr){
  int i=0, rem;
  double decimalNum=0 , octalNum = *ptr;

    while(octalNum!=0)
    {
        rem = (int)octalNum%10;
        decimalNum = decimalNum + (rem*pow(8,i));
        i++;
        octalNum = octalNum/10;
    }
    return decimalNum;
}

//Funcion Decimal a Hexadecimal
double decimalHexadecimal(double *ptr){
  int residuo,  cociente, i=0, j;
  int letrahexadecimal[20];
  double numeroDecimal = *ptr;

  do{
    residuo = (int)numeroDecimal%16;
    cociente = numeroDecimal/16;
    letrahexadecimal[i] = residuo;
    numeroDecimal = cociente;
    i++;
  }while(cociente > 15);

  letrahexadecimal[i] = cociente;

  std::cout  << " ES IGUAL A ";

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
}

//Funcion Hexadecimal a Decimal
int hexadecimalDecimal(char num[]){
  int len = atoi(num);
   int base = 1;
   int temporal = 0;
   for (int i=len-1; i>=0; i--) {
      if (num[i]>='0' && num[i]<='9') {
         temporal += (num[i] - 48)*base;
         base = base * 16;
      }
      else if (num[i]>='A' && num[i]<='F') {
         temporal += (num[i] - 55)*base;
         base = base*16;
      }
   }
   return temporal;
}
























//
