/*
  Autor: Bryan Vizcarra Aguilar
  Fecha de Creacion: 11 de octubre de 2021
  fecha de ult mod: 16 de octubre de 2021
  Proyecto Colas y Pilas dinámicas

*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <conio.h>
using std::string;


//PROTOTIPO DE FUNCION
void ImprimirLogo();
void CrearMarco();
void loading();
void taquilla();
void maletas();
void zonaAbordaje();
void avion();
void vuelo();
void camionIda();
void camionVuelta();
void taxiIda();
void taxiVuelta();

//CLASE NODO
class Nodo{
private:
  int passengers;
  string nombre;
  int numSuitcase;
  Nodo *sig;
public:
  Nodo();
  void enqueue(Nodo*&,Nodo*&,string);
  bool isEmpty(Nodo *);
   int randomsuitcase();
  void addPassenger(int);
  void ticketsQueue(Nodo *&,Nodo *&);
  void ticketsDequeue(Nodo *&, Nodo *&);
  void baggageQueue(Nodo *&, Nodo *&);
  void baggageDequeue(Nodo *&, Nodo *&);
  void push(Nodo *&);
  void pop(Nodo *&);
  void taxiQueue(Nodo *&, Nodo *&);
  VOID camionDequeue(Nodo *&, Nodo *&);
};


//CONSTRUCTOR
Nodo::Nodo(){
  passengers=0;
}


//GOTOXY
void gotoxy(int x,int y){
  HANDLE hcon;
  hcon = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD dwPos;
  dwPos.X = x;
  dwPos.Y= y;
  SetConsoleCursorPosition(hcon,dwPos);
}


//ASIGNACIÓN ALEATORIA DE MALETAS AL PASAJERO
int Nodo::randomsuitcase(){
  srand((unsigned)time(0));
  return (rand()%4+1);
}


//COLA PARA COMPRAR BOLETOS
void Nodo::ticketsQueue(Nodo *&primero, Nodo *&ultimo) {
  int i=22,j=1, rango=85,personas=passengers, ban=0;
  Nodo *temp = primero;
  Nodo *temp2 = ultimo;

  system("cls");
  ImprimirLogo();
  CrearMarco();
  taquilla();


  for(j=1;j<=passengers;j++){
      for(i=22;i<rango;i++){
          gotoxy(i,18);std::cout<<"  "<<j;
          gotoxy(i,19);std::cout<<"  o";
          gotoxy(i,20);std::cout<< " /|\\";
          if(ban==0){
              gotoxy(i,21);std::cout<< " / ";
              ban=1;
          }else{
              gotoxy(i,21);std::cout<< "   \\";
              ban=0;
          }
          gotoxy(i,23);std::cout << " "<< temp->nombre << '\n';

          Sleep(50);
      }
      gotoxy(i,18);std::cout<<"  "<<j;
      gotoxy(i,19);std::cout<<"  o";
      gotoxy(i,20);std::cout<< " /|\\";
      gotoxy(i-1,21);std::cout<< "  / \\";
      gotoxy(i,23);std::cout << temp->nombre << '\n';

      rango=rango-10;
      temp=temp->sig;
  }
  temp=primero;
  ticketsDequeue(temp,temp2);
}


//FUNCION QUE DESENCOLA DE COMPRAR BOLETOS
void Nodo::ticketsDequeue(Nodo *&temp, Nodo *&temp2){
  int i=22,j=1, rango=85,personas=passengers, ban=0;
  Nodo *aux = temp;
  Nodo *aux3 = temp;
  Nodo *aux2 = temp2;
  int count=1;

  while(aux!=NULL){
    int count2=count;
    aux3=aux;
    rango=85;

    for(j=1;j<=personas;j++){
      gotoxy(rango-10,18);std::cout<<"     ";
      gotoxy(rango-10,19);std::cout<<"     ";
      gotoxy(rango-10,20);std::cout<< "      ";
      gotoxy(rango-11,21);std::cout<< "     ";
      gotoxy(rango-10,23);std::cout << "     " << '\n';

      gotoxy(rango,18);std::cout<<"  "<<count2;
      gotoxy(rango,19);std::cout<<"  o";
      gotoxy(rango,20);std::cout<< " /|\\";
      gotoxy(rango-1,21);std::cout<< "  / \\";
      gotoxy(rango,23);std::cout << aux3->nombre <<"   "<< '\n';
      rango=rango-10;
      aux3=aux3->sig;
      count2++;
    }
    Sleep(1000);
    count++;
    personas--;

      if(aux==aux2){
        aux=NULL;
        aux2=NULL;
      }else{
        aux = aux->sig;
      }
  }
  system("cls");
  ImprimirLogo();
  CrearMarco();
  taquilla();

  gotoxy(40,17);std::cout << "T O D O S   L O S   P A S A J E R O S" << '\n';
  gotoxy(39,20);std::cout << "H A N   C O M P R A D O   B O L E T O S" << '\n';
  gotoxy(40,25);
  Sleep(3000);
}




//FUNCION DONDE SE REVISAN LOS BOLETOS Y MALETAS QUE LLEVAN LOS PASAJEROS
void Nodo::baggageQueue(Nodo *&primero ,Nodo *&ultimo){
  int i=22,j=1, rango=85,personas=passengers, ban=0;
  Nodo *temp = primero;
  Nodo *temp2 = ultimo;

  system("cls");
  ImprimirLogo();
  CrearMarco();
  maletas();
  gotoxy(41,8);printf("%c", 203);
  gotoxy(41,9);printf("%c", 186);
  gotoxy(41,10);printf("%c", 200);
  gotoxy(81,8);printf("%c", 203);
  gotoxy(81,9);printf("%c", 186);
  gotoxy(81,10);printf("%c", 188);
  for(int i=42;i<81;i++){
    gotoxy(i,10);printf("%c", 205);
  }
  gotoxy(43,9);std::cout << "R E V I S I O N  D E  E Q U I P A J E " << '\n';

  for(j=1;j<=passengers;j++){
      for(i=22;i<rango;i++){
          gotoxy(i,14);std::cout<<"  "<<j;
          gotoxy(i,15);std::cout<<"  o";
          gotoxy(i,16);std::cout<< " /|\\";
          if(ban==0){
              gotoxy(i,17);std::cout<< " / ";
              ban=1;
          }else{
              gotoxy(i,17);std::cout<< "   \\";
              ban=0;
          }
          gotoxy(i,19);std::cout << " "<< temp->nombre << '\n';

          Sleep(50);
      }
      gotoxy(i,14);std::cout<<"  "<<j;
      gotoxy(i,15);std::cout<<"  o";
      gotoxy(i,16);std::cout<< " /|\\";
      gotoxy(i-1,17);std::cout<< "  / \\";
      gotoxy(i,19);std::cout << temp->nombre << '\n';

      gotoxy(i,24);std::cout << temp->nombre << '\n';
      gotoxy(i,26);std::cout << "  "<< temp->numSuitcase<< '\n';
      gotoxy(i-1,28);std::cout << "MALETAS" << '\n';

      rango=rango-10;
      temp=temp->sig;
  }
  temp=primero;
  baggageDequeue(temp,temp2);
}


//FUNCION QUE DESENCOLA DE REVISION DE EQUIPAJE
void Nodo::baggageDequeue(Nodo *&temp, Nodo *&temp2){
  int i=22,j=1, rango=85,personas=passengers, ban=0;
  Nodo *aux = temp;
  Nodo *aux3 = temp;
  Nodo *aux2 = temp2;
  int count=1;

  while(aux!=NULL){
    int count2=count;
    aux3=aux;
    rango=85;

    for(j=1;j<=personas;j++){
      gotoxy(rango-10,14);std::cout<<"     ";
      gotoxy(rango-10,15);std::cout<<"     ";
      gotoxy(rango-10,16);std::cout<< "      ";
      gotoxy(rango-11,17);std::cout<< "     ";
      gotoxy(rango-10,19);std::cout << "      " << '\n';

      gotoxy(rango,14);std::cout<<"  "<<count2;
      gotoxy(rango,15);std::cout<<"  o";
      gotoxy(rango,16);std::cout<< " /|\\";
      gotoxy(rango-1,17);std::cout<< "  / \\";
      gotoxy(rango,19);std::cout << aux3->nombre <<"  "<< '\n';

      gotoxy(rango-10,24);std::cout << "      " << '\n';
      gotoxy(rango-10,26);std::cout << "    "<< '\n';
      gotoxy(rango-11,28);std::cout << "       " << '\n';

      gotoxy(rango,24);std::cout << aux3->nombre <<"  "<< '\n';
      gotoxy(rango,26);std::cout << "  "<< aux3->numSuitcase<< '\n';
      gotoxy(rango-1,28);std::cout << "MALETAS" << '\n';
      rango=rango-10;
      aux3=aux3->sig;
      count2++;
    }
    Sleep(1000);
    count++;
    personas--;

    if(aux==aux2){
      aux=NULL;
      aux2=NULL;
    }else{
      aux = aux->sig;
    }
  }
  system("cls");
  ImprimirLogo();
  CrearMarco();
  maletas();

  gotoxy(30,13);std::cout << "S E  H A N  R E V I S A D O  L O S  E Q U I P A J E S" << '\n';
  gotoxy(23,16);std::cout << "D E  T O D O S  L O S  P A S A J E R O S  C O R R E C T A M E N T E" << '\n';
  gotoxy(30,26);
  Sleep(3000);
  std::cout << "P R E S I O N E  U N A  T E C L A  P A R A  C O N T I N U A R" << '\n';
  getch();
}


//FUNCION DE APILAR PARA ABORDAR EL AVION
void Nodo::push(Nodo *&primero){
  int i=22,j=1, rango=85,personas=passengers, ban=0;
  Nodo *temp = primero;

  system("cls");
  ImprimirLogo();
  CrearMarco();

  gotoxy(43,8);printf("%c", 203);
  gotoxy(43,9);printf("%c", 186);
  gotoxy(43,10);printf("%c", 200);
  gotoxy(75,8);printf("%c", 203);
  gotoxy(75,9);printf("%c", 186);
  gotoxy(75,10);printf("%c", 188);
  for(int i=44;i<75;i++){
    gotoxy(i,10);printf("%c", 205);
  }
  gotoxy(45,9);std::cout << "Z O N A  D E  A B O R D A J E" << '\n';
  zonaAbordaje();
  for(j=1;j<=passengers;j++){
      for(i=22;i<rango;i++){
          gotoxy(i,18);std::cout<<"  "<<j;
          gotoxy(i,19);std::cout<<"  o";
          gotoxy(i,20);std::cout<< " /|\\";
          if(ban==0){
              gotoxy(i,21);std::cout<< " / ";
              ban=1;
          }else{
              gotoxy(i,21);std::cout<< "   \\";
              ban=0;
          }

          Sleep(50);
      }
      gotoxy(i,18);std::cout<<"  "<<j;
      gotoxy(i,19);std::cout<<"  o";
      gotoxy(i,20);std::cout<< " /|\\";
      gotoxy(i-1,21);std::cout<< "  / \\";
      rango=rango-10;
      temp=temp->sig;
  }

  gotoxy(39,13);std::cout << "T O D O S  L O S  P A S A J E R O S " << '\n';
  gotoxy(39,15);std::cout << "L I S T O S  P A R A  A B O R D A R" << '\n';
  Sleep(2000);


}


//FUNCION DE DESAPILAR PARA BAJAR DEL AVION
void Nodo::pop(Nodo *& primero){
  int i=22,j=1, rango=22,personas=passengers, ban=0;
  Nodo *temp = primero;
  system("cls");
  ImprimirLogo();
  CrearMarco();
  gotoxy(43,8);printf("%c", 203);
  gotoxy(43,9);printf("%c", 186);
  gotoxy(43,10);printf("%c", 200);
  gotoxy(75,8);printf("%c", 203);
  gotoxy(75,9);printf("%c", 186);
  gotoxy(75,10);printf("%c", 188);
  for(int i=44;i<75;i++){
    gotoxy(i,10);printf("%c", 205);
  }
  gotoxy(45,9);std::cout << "Z O N A  D E  D E S C E N S O" << '\n';
  zonaAbordaje();


  for(j=passengers;j>0;j--){
      for(i=84;i>rango;i--){
          gotoxy(i,18);std::cout<<"  "<<j<<" ";
          gotoxy(i,19);std::cout<<"  o ";
          gotoxy(i,20);std::cout<< " /|\\ ";
          if(ban==0){
              gotoxy(i,21);std::cout<< " /   ";
              ban=1;
          }else{
              gotoxy(i,21);std::cout<< "   \\  ";
              ban=0;
          }

          Sleep(50);
      }
      gotoxy(i,18);std::cout<<"  "<<j<<" ";
      gotoxy(i,19);std::cout<<"  o ";
      gotoxy(i,20);std::cout<< " /|\\ ";
      gotoxy(i-1,21);std::cout<< "  / \\ ";
      rango=rango+10;
      temp=temp->sig;
  }

  gotoxy(39,13);std::cout << "T O D O S  L O S  P A S A J E R O S " << '\n';
  gotoxy(38,15);std::cout << " H A N  B A J A D O  D E L  A V I O N" << '\n';
  Sleep(2000);
}

//COLA PARA ESPERAR EL TAXI
void Nodo::taxiQueue(Nodo *&primero, Nodo *&ultimo){
  int i=22,j=1, rango=85,personas=passengers, ban=0;
  Nodo *temp = primero;
  Nodo *temp2 = ultimo;

  system("cls");
  ImprimirLogo();
  CrearMarco();

  for(j=1;j<=passengers;j++){
      for(i=22;i<rango;i++){
          gotoxy(i,14-3);std::cout<<"  "<<j;
          gotoxy(i,15-3);std::cout<<"  o";
          gotoxy(i,16-3);std::cout<< " /|\\";
          if(ban==0){
              gotoxy(i,17-3);std::cout<< " / ";
              ban=1;
          }else{
              gotoxy(i,17-3);std::cout<< "   \\";
              ban=0;
          }
          gotoxy(i,19-3);std::cout << " "<< temp->nombre << '\n';

          Sleep(50);
      }
      gotoxy(i,14-3);std::cout<<"  "<<j;
      gotoxy(i,15-3);std::cout<<"  o";
      gotoxy(i,16-3);std::cout<< " /|\\";
      gotoxy(i-1,17-3);std::cout<< "  / \\";
      gotoxy(i,19-3);std::cout << temp->nombre << '\n';

      rango=rango-10;
      temp=temp->sig;
  }

  temp=primero;
  camionDequeue(primero, ultimo);
}

//DESENCOLAMIENTO POR RECOGIDA DEL TAXI
void Nodo::camionDequeue(Nodo *& primero, Nodo *&ultimo){
  int i=22,j=1, rango=85,personas=passengers, ban=0;
  Nodo *aux = primero;
  Nodo *aux3 = primero;
  Nodo *aux2 = ultimo;
  int count=1;
  camionIda();
  while(aux!=NULL){

    int count2=count;
    aux3=aux;
    rango=85;

    for(j=1;j<=personas;j++){

      gotoxy(rango-10,11);std::cout<<"     ";
      gotoxy(rango-10,12);std::cout<<"     ";
      gotoxy(rango-10,13);std::cout<< "      ";
      gotoxy(rango-11,14);std::cout<< "     ";
      gotoxy(rango-10,16);std::cout << "     " << '\n';

      gotoxy(rango,11);std::cout<<"  "<<count2;
      gotoxy(rango,12);std::cout<<"  o";
      gotoxy(rango,13);std::cout<< " /|\\";
      gotoxy(rango-1,14);std::cout<< "  / \\";
      gotoxy(rango,16);std::cout << aux3->nombre <<"   "<< '\n';

      rango=rango-10;
      aux3=aux3->sig;
      count2++;

    }

    Sleep(1000);
    count++;
    personas--;

      if(aux==aux2){
        aux=NULL;
        aux2=NULL;
      }else{
        aux = aux->sig;
      }
  }
  camionVuelta();
  taxiIda();
  system("cls");
  ImprimirLogo();
  CrearMarco();
  taxiVuelta();
}





//VERIFICACION SI LA COLA ESTÁ VACIA
bool Nodo::isEmpty(Nodo *primero){
  return(primero==NULL)? true:false;
}


//FUNCION AGREGAR ELEMENTO A LA COLA
void Nodo::enqueue(Nodo *&primero, Nodo *&ultimo, string nombre){
    Nodo *nuevoNodo = new Nodo();
    nuevoNodo->passengers = passengers++;
    nuevoNodo->nombre = nombre;
    nuevoNodo->numSuitcase = randomsuitcase();
    nuevoNodo->sig = NULL;

    if(isEmpty(primero)){
      primero = nuevoNodo;
    }else{
      ultimo->sig = nuevoNodo;
    }
    ultimo = nuevoNodo;
}


//FUNCION PRINCIPAL
int main(int argc, char const *argv[]) {
  Nodo obj;
  Nodo *primero=NULL;
  Nodo *ultimo=NULL;
  int countPassengers=1, band=0, band2=0,op;
  char nombre[30], validar[2];
  string nombre_;
  ImprimirLogo();
  CrearMarco();
  loading();

  do {
    band2=0;
    system("cls");
    ImprimirLogo();
    CrearMarco();
    gotoxy(43,10);
    printf("BIENVENIDO AL SISTEMA DE PASAJEROS"); gotoxy(22,15);
    std::cout << "INGRESE EL NOMBRE DEL PASAJERO "<< countPassengers << '\n'; gotoxy(22,20);
    std::cout << "EL NOMBRE DEL PASAJERO "<<countPassengers<<" ES: ";
    fflush(stdin);
    gets(nombre);
    for(int i=0; nombre[i] != '\0';i++){ //nombre a mayusculas
      nombre[i] = toupper(nombre[i]);
    }
    nombre_ = nombre;
    obj.enqueue(primero, ultimo, nombre_);

    do{
      system("cls");
      ImprimirLogo();
      CrearMarco();
      gotoxy(45,10);
      printf("%c",168);std::cout << "DESEA INGRESAR OTRO PASAJERO?" << '\n'; gotoxy(22,15);
      std::cout << "1. SI, DESEO AGREGAR OTRO PASAJERO" << '\n';gotoxy(22,17);
      std::cout << "2. NO, YA NO DESEO AGREGAR MAS PASAJEROS" << '\n';gotoxy(22,21);
      std::cout <<"TU OPCION INGRESADA ES: ";
      fflush(stdin);
      gets(validar);
      op = atoi(validar);

      switch (op) {
        case 1:
          countPassengers++;
          band2=1;
        break;

        case 2:
          band=1;
          band2=1;
        break;

        default:
        system("cls");
        ImprimirLogo();
        CrearMarco(); gotoxy(43,15);
        printf("LO QUE HAS INGRESADO NO ES VALIDO"); gotoxy(50,17);
        printf("VUELVE A INTENTARLO"); gotoxy(32,21);
        printf("PRESIONA UNA TECLA PARA REGRESAR AL MENU DE SELECCION");
        getch();
        system("CLS");
        break;
      }
    }while(band2==0);
  } while(band==0);

  obj.ticketsQueue(primero,ultimo);
  obj.baggageQueue(primero,ultimo);
  obj.push(primero);
  avion();
  vuelo();
  obj.pop(primero);
  obj.taxiQueue(primero,ultimo);
  getch();
  gotoxy(40,25);
  return 0;
}


//IMPRIME EL LOGO DEL AEROPUERTO DESDE UN ARCHIVO TXT
void ImprimirLogo(){
  int c;
  FILE* archivo;
    archivo = fopen("Logo.txt", "r");
     while ((c = fgetc (archivo)) != EOF)
         putchar(c);
}


//CREAR UN MARCO EN LA PANTALLA CON LINEAS
void CrearMarco(){
  int   i,fila,col,k;
  int   ladohor[2],ladover[2];

  ladohor[1]=8;
  ladohor[2]=0;
  ladover[1]=20;
  ladover[2]=100;

  for (i=1;i<=2;i++){
    gotoxy(20,ladohor[i]);
    for (col=20;col<=99;col++){
      printf ("%c",205);
      for(k=20;k<=29;k++);
    }
    for (fila=8;fila<=30;fila++){
      gotoxy(ladover[i],fila);
      printf("%c",186);
    }
  }
    gotoxy(20,8);       printf("%c",201);
    gotoxy(100,8);      printf("%c",187);
    gotoxy(20,30);      printf("%c",200);
    gotoxy(100,30);     printf("%c",188);
    gotoxy(2,2);
}


//PANTALLA FALSA DE CARGANDO
void loading() {
  gotoxy(53,14);
  printf("C A R G A N D O"); gotoxy(44,18);
  printf("P O R   F A V O R   E S P E R E"); gotoxy(40,21);
  for(int i=0;i<40;i++)
  {
    Sleep(50);//60
    printf(".");
  }
  system("cls");
}


//DIBUJA UNA TAQUILLA DE COMPRA DE BOLETOS
void taquilla() {
  gotoxy(90,14);printf("%c%c%c%c%c%c%c%c%c",201,205,205,205,205,205,205,205,187);
  gotoxy(90,15);printf("%cBOLETOS%c",186,186);
  gotoxy(90,16);printf("%c%c%c%c%c%c%c%c%c",204,205,205,205,205,205,205,205,185);
  gotoxy(90,17);printf("%c       %c",186,186);
  gotoxy(90,18);printf("%c       %c",186,186);
  gotoxy(90,19);printf("%c   o   %c",186,186);
  gotoxy(90,20);printf("%c  /|\\  %c",186,186);
  gotoxy(90,21);printf("%c%c%c%c%c%c%c%c%c",204,205,205,205,205,205,205,205,185);
  gotoxy(90,22);printf("%c%c%c%c%c%c%c%c%c",178,178,178,178,178,178,178,178,178);
}


//DIBUJA UNA TAQUILLA DE REVISION DE EQUIPAJE
void maletas(){
  int i=21;
  gotoxy(90,10);printf("%c%c%c%c%c%c%c%c%c%c",201,205,205,205,205,205,205,205,205,187);
  gotoxy(90,11);printf("%cEQUIPAJE%c",186,186);
  gotoxy(90,12);printf("%c%c%c%c%c%c%c%c%c%c",204,205,205,205,205,205,205,205,205,185);
  gotoxy(90,13);printf("%c        %c",186,186);
  gotoxy(90,14);printf("%c        %c",186,186);
  gotoxy(90,15);printf("%c    o   %c",186,186);
  gotoxy(90,16);printf("%c   /|\\  %c",186,186);
  gotoxy(90,17);printf("%c%c%c%c%c%c%c%c%c%c",204,205,205,205,205,205,205,205,205,185);
  gotoxy(90,18);printf("%c%c%c%c%c%c%c%c%c%c",178,178,178,178,178,178,178,178,178,178);
  gotoxy(20,22);printf("%c", 204);
  for(i;i<100;i++){
    gotoxy(i,22);printf("%c",205);
  }
  gotoxy(100,22);printf("%c",185 );
}


//DIBUJA LA ENTRADA AL AVION
void zonaAbordaje(){
  gotoxy(90,9);printf("%c%c%c%c%c%c%c%c%c%c",177,178,178,178,178,178,178,178,178,178);
  gotoxy(90,10);printf("%c%c%c%c%c%c%c%c%c%c",177,178,178,178,178,178,178,178,178,178);
  gotoxy(90,11);printf("%c%c%c%c%c%c%c%c%c%c",177,178,178,178,178,178,178,178,178,178);
  gotoxy(90,12);printf("%c%c%c%c%c%c%c%c%c%c",177,178,178,178,178,178,178,178,178,178);
  gotoxy(90,13);printf("%c%c%c%c%c%c%c%c%c%c",177,178,178,178,178,178,178,178,178,178);
  gotoxy(90,14);printf("%c%c%c%c%c%c%c%c%c%c",177,177,177,177,177,177,177,177,177,178);
  gotoxy(90,15);printf("%c%c%c%c%c%c%c%c%c%c",177,176,176,176,176,176,205,205,177,178);
  gotoxy(90,16);printf("%c%c%c%c%c%c%c%c%c%c",177,176,176,176,176,205,205,205,177,178);
  gotoxy(90,17);printf("%c%c%c%c%c%c%c%c%c%c",177,176,176,176,205,205,205,205,177,178);
  gotoxy(90,18);printf("%c%c%c%c%c%c%c%c%c%c",177,176,176,205,205,205,205,205,177,178);
  gotoxy(90,19);printf("%c%c%c%c%c%c%c%c%c%c",177,176,205,205,205,205,205,205,177,178);
  gotoxy(90,20);printf("%c%c%c%c%c%c%c%c%c%c",177,205,205,205,205,205,205,205,177,178);
  gotoxy(90,21);printf("%c%c%c%c%c%c%c%c%c%c",177,205,205,205,205,205,205,205,177,178);
  gotoxy(21,22);
  for(int i=22;i<30;i++){
    for(int j=21;j<100;j++){
      printf("%c",177);
      gotoxy(j,i);
    }
  }
  gotoxy(30,100);printf("%c", 177);
}


//FUNCION QUE IMPRIME EL AVION Y CUENTA REGRESIVA DE DESPEGUE
void avion(){
  system("cls");
  ImprimirLogo();
  int c;
  FILE* archivo;
    archivo = fopen("Avion.txt", "r");
     while ((c = fgetc (archivo)) != EOF){
         putchar(c);
     }
    CrearMarco();

    // ███████╗
    // ██╔════╝
    // ███████╗
    // ╚════██║
    // ███████║
    // ╚══════╝

    //IMPRIME EL 5 EN ASCII ART
    gotoxy(57,23);printf("%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,187);
    gotoxy(57,24);printf("%c%c%c%c%c%c%c%c",219,219,201,205,205,205,205,188);
    gotoxy(57,25);printf("%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,187);
    gotoxy(57,26);printf("%c%c%c%c%c%c%c%c",200,205,205,205,205,219,219,186);
    gotoxy(57,27);printf("%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,186);
    gotoxy(57,28);printf("%c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,188);
    Sleep(1000);

    // ██╗  ██╗
    // ██║  ██║
    // ███████║
    // ╚════██║
    //      ██║
    //      ╚═╝

    //IMPRIME EL 4 EN ASCII ART
    gotoxy(57,23);printf("%c%c%c%c%c%c%c%c",219,219,187,32,32,219,219,187);
    gotoxy(57,24);printf("%c%c%c%c%c%c%c%c",219,219,186,32,32,219,219,186);
    gotoxy(57,25);printf("%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,186);
    gotoxy(57,26);printf("%c%c%c%c%c%c%c%c",200,205,205,205,205,219,219,186);
    gotoxy(57,27);printf("%c%c%c%c%c%c%c%c",32,32,32,32,32,219,219,186);
    gotoxy(57,28);printf("%c%c%c%c%c%c%c%c",32,32,32,32,32,200,205,188);
    Sleep(1000);

    // ██████╗
    // ╚════██╗
    //  █████╔╝
    //  ╚═══██╗
    // ██████╔╝
    // ╚═════╝

    //IMPRIME EL 3 EN ASCII ART
    gotoxy(57,23);printf("%c%c%c%c%c%c%c%c",219,219,219,219,219,219,187,32);
    gotoxy(57,24);printf("%c%c%c%c%c%c%c%c",200,205,205,205,205,219,219,187);
    gotoxy(57,25);printf("%c%c%c%c%c%c%c%c",32,219,219,219,219,219,201,188);
    gotoxy(57,26);printf("%c%c%c%c%c%c%c%c",32,200,205,205,205,219,219,187);
    gotoxy(57,27);printf("%c%c%c%c%c%c%c%c",219,219,219,219,219,219,201,188);
    gotoxy(57,28);printf("%c%c%c%c%c%c%c%c",200,205,205,205,205,205,188,32);
    Sleep(1000);

    // ██████╗
    // ╚════██╗
    //  █████╔╝
    // ██╔═══╝
    // ███████╗
    // ╚══════╝

    //IMPRIME EL 2 EN ASCII ART
    gotoxy(57,23);printf("%c%c%c%c%c%c%c%c",219,219,219,219,219,219,187,32);
    gotoxy(57,24);printf("%c%c%c%c%c%c%c%c",200,205,205,205,205,219,219,187);
    gotoxy(57,25);printf("%c%c%c%c%c%c%c%c",32,219,219,219,219,219,201,188);
    gotoxy(57,26);printf("%c%c%c%c%c%c%c%c",219,219,201,205,205,205,188,32);
    gotoxy(57,27);printf("%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,187);
    gotoxy(57,28);printf("%c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,188);
    Sleep(1000);

     //  ██╗
     // ███║
     // ╚██║
     //  ██║
     //  ██║
     //  ╚═╝

     //IMPRIME EL 1 EN ASCII ART
     gotoxy(57,23);printf("%c%c%c%c%c%c%c%c",32,32,32,219,219,187,32,32);
     gotoxy(57,24);printf("%c%c%c%c%c%c%c%c",32,32,219,219,219,186,32,32);
     gotoxy(57,25);printf("%c%c%c%c%c%c%c%c",32,32,200,219,219,186,32,32);
     gotoxy(57,26);printf("%c%c%c%c%c%c%c%c",32,32,32,219,219,186,32,32);
     gotoxy(57,27);printf("%c%c%c%c%c%c%c%c",32,32,32,219,219,186,32,32);
     gotoxy(57,28);printf("%c%c%c%c%c%c%c%c",32,32,32,200,205,188,32,32);
     Sleep(1000);
}

//ANIMACION DE VUELO DEL AVION
void vuelo(){
  int i,j=87, k=87, l=87, count=0;
  system("cls");
  ImprimirLogo();
  CrearMarco();

  for(i=22;i<69;i++){

      gotoxy(j,10-1);std::cout << "   _.._  " << '\n';
      gotoxy(j,11-1);std::cout << "  .' .-'`  " << '\n';
      gotoxy(j,12-1);std::cout << " /  /  " << '\n';
      gotoxy(j,13-1);std::cout << " |  |  " << '\n';
      gotoxy(j,14-1);std::cout << " \\  '.___.;  " << '\n';
      gotoxy(j,15-1);std::cout << "  '._  _.'  " << '\n';
      gotoxy(j,16-1);std::cout << "     ``  " << '\n';


      gotoxy(i,13+1);std::cout << " __  _" << '\n';
      gotoxy(i,14+1);std::cout << " \\ `/ |" << '\n';
      gotoxy(i,15+1);std::cout << "  \\__`!" << '\n';
      gotoxy(i,16+1);std::cout << "  / ,' `-.__________________" << '\n';
      gotoxy(i,17+1);std::cout << " '-'\\_____                LI`-." << '\n';
      gotoxy(i,18+1);std::cout << "    <____()-=O=O=O=O=O=[]====--)" << '\n';
      gotoxy(i,19+1);std::cout << "      `.___ ,-----,_______...-'" << '\n';
      gotoxy(i,20+1);std::cout << "           /    .'" << '\n';
      gotoxy(i,21+1);std::cout << "          /   .'" << '\n';
      gotoxy(i,22+1);std::cout << "         /  .'" << '\n';
      gotoxy(i,23+1);std::cout << "         `-'" << '\n';
      Sleep(150);


      gotoxy(j-6,27-1);std::cout << " _.._             " << '\n';
      gotoxy(j-6,28-1);std::cout << " |  |             " << '\n';
      gotoxy(j-6,29-1);std::cout << " |  |  __   _:_._ " << '\n';
      gotoxy(j-6,30-1);std::cout << " |  | |  | |     | " << '\n';
      j--;

      count++;

      if (count>18) {
        gotoxy(k-6,27-1);std::cout << "     _.._        " << '\n';
        gotoxy(k-6,28-1);std::cout << "     |  |        " << '\n';
        gotoxy(k-6,29-1);std::cout << "  __ |  | _:_._ " << '\n';
        gotoxy(k-6,30-1);std::cout << " |  ||  ||     | " << '\n';
        k--;
      }

      if (count>35) {
        gotoxy(l-6,27-1);std::cout << " _..__.._        " << '\n';
        gotoxy(l-6,28-1);std::cout << " |  ||  |        " << '\n';
        gotoxy(l-6,29-1);std::cout << " |  ||  | _:_._ " << '\n';
        gotoxy(l-6,30-1);std::cout << " |  ||  ||     | " << '\n';
        l--;
      }
  }
}

void camionIda(){
  for(int i=22;i<68;i++){
    gotoxy(i,19);std::cout << "                           ___ " << '\n';
    gotoxy(i,20);std::cout << "   .-----------------------'  | " << '\n';
    gotoxy(i,21);std::cout << "  /| _ .---. .---. .---. .---.| " << '\n';
    gotoxy(i,22);std::cout << " /|j| ||___| |___| |___| |___|| " << '\n';
    gotoxy(i,23);std::cout << " \\ || |=======================| " << '\n';
    gotoxy(i,24);std::cout << "  [_| |/___\\__HOTEL___/___\\___] " << '\n';
    gotoxy(i,25);std::cout << "  [_|_||(O)\\_________|(O)\\____] " << '\n';
    Sleep(100);
  }
}


void camionVuelta(){
  for(int i=68;i>21;i--){
    gotoxy(i,19);std::cout << "                           ___ " << '\n';
    gotoxy(i,20);std::cout << "   .-----------------------'  | " << '\n';
    gotoxy(i,21);std::cout << "  /| _ .---. .---. .---. .---.| " << '\n';
    gotoxy(i,22);std::cout << " /|j| ||___| |___| |___| |___|| " << '\n';
    gotoxy(i,23);std::cout << " \\ || |=======================| " << '\n';
    gotoxy(i,24);std::cout << "  [_| |/___\\__HOTEL___/___\\___] " << '\n';
    gotoxy(i,25);std::cout << "  [_|_||(O)\\_________|(O)\\____] " << '\n';
    Sleep(100);
  }
  for(int i=68;i>21;i--){
    gotoxy(i,19);std::cout << "   " << '\n';
    gotoxy(i,20);std::cout << "   " << '\n';
    gotoxy(i,21);std::cout << "   " << '\n';
    gotoxy(i,22);std::cout << "   " << '\n';
    gotoxy(i,23);std::cout << "   " << '\n';
    gotoxy(i,24);std::cout << "   " << '\n';
    gotoxy(i,25);std::cout << "   " << '\n';
    gotoxy(i,26);std::cout << "   " << '\n';
    gotoxy(i,27);std::cout << "   " << '\n';
  }
}


void taxiIda(){
  for(int i=22;i<68;i++){
    gotoxy(i,19);std::cout << "        _______" << '\n';
    gotoxy(i,20);std::cout << "       //  ||\\ \\" << '\n';
    gotoxy(i,21);std::cout << " _____//___||_\\ \\___" << '\n';
    gotoxy(i,22);std::cout << " )  _    TAXI  _    \\" << '\n';
    gotoxy(i,23);std::cout << " |_/ \\________/ \\___|" << '\n';
    gotoxy(i,24);std::cout << "   \\_/        \\_/" << '\n';
    Sleep(100);
  }
}

void taxiVuelta(){
  for(int i=68;i>21;i--){
    gotoxy(i,19);std::cout << "        _______ " << '\n';
    gotoxy(i,20);std::cout << "       //  ||\\ \\ " << '\n';
    gotoxy(i,21);std::cout << " _____//___||_\\ \\___ " << '\n';
    gotoxy(i,22);std::cout << " )  _    TAXI  _    \\ " << '\n';
    gotoxy(i,23);std::cout << " |_/ \\________/ \\___| " << '\n';
    gotoxy(i,24);std::cout << "   \\_/        \\_/ " << '\n';
    Sleep(100);
  }
  for(int i=68;i>21;i--){
    gotoxy(i,19);std::cout << "   " << '\n';
    gotoxy(i,20);std::cout << "   " << '\n';
    gotoxy(i,21);std::cout << "   " << '\n';
    gotoxy(i,22);std::cout << "   " << '\n';
    gotoxy(i,23);std::cout << "   " << '\n';
    gotoxy(i,24);std::cout << "   " << '\n';
    gotoxy(i,25);std::cout << "   " << '\n';
    gotoxy(i,26);std::cout << "   " << '\n';
    gotoxy(i,27);std::cout << "   " << '\n';
  }
}
