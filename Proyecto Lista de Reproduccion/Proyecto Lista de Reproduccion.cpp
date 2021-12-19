/*
  ===================================================
  Autor: Bryan Vizcarra Aguilar
  Fecha de creacion: 19 de noviembre de 2021
  Fecha de ult mod: 22 de noviembre de 2021
  Programa: Lista de reproduccion de música
  Version: 6.0
  ===================================================
*/

int validarNumero(char [], int *);
void CrearMarco();
void opciones();
void datosCancion();
void lista();

#include <iostream>
#include <cstdlib>
#include <cctype>
#include <windows.h>
#include <string.h>

using std::string;

class CircularList{
private:
  class Node {
  public:
    int id;
    string nombre;
    string album;
    string artista;
    string genero;
    Node *next;
    Node *back;
  };
  Node *ptrHead, *last_node;

  public:
    CircularList();
    ~CircularList();
    void addSong(int, string, string, string, string);
    bool empty();
    void print(int);
    void currentSong(int);
    int deleteSong(int);
    void editSong(int);
};

//GOTOXY
void gotoxy(int x,int y){
  HANDLE hcon;
  hcon = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD dwPos;
  dwPos.X = x;
  dwPos.Y= y;
  SetConsoleCursorPosition(hcon,dwPos);
}


//constuctor
CircularList::CircularList(){
  ptrHead = NULL;
}

 //Desctructor
CircularList::~CircularList() {
  if (ptrHead != NULL) {
    Node *temp = ptrHead->next;
    Node *temp_ptrHead;
    while (temp != ptrHead){
      temp_ptrHead = temp;
      temp = temp->next;
      delete temp_ptrHead;
    }
    delete ptrHead;
  }
}


void CircularList::addSong(int id, string nombre, string album, string artista, string genero) {
  Node *new_node = new Node();
    new_node->id = id;
    new_node->nombre = nombre;
    new_node->album = album;
    new_node->artista = artista;
    new_node->genero = genero;

  if (ptrHead == NULL){
    ptrHead = new_node;
    last_node = new_node;
    ptrHead->next = ptrHead;
    ptrHead->back = last_node;
  }else{
    last_node->next = new_node;
    new_node->back = last_node;
    new_node->next = ptrHead;
    last_node = new_node;
    ptrHead->back = last_node;
  }
}


//Funcion para validar si la lista está vacia
bool CircularList::empty() {
  if (ptrHead == NULL){
    return true;
  }else{
    return false;
  }
}

//funcion para imprimir los datos de cada cancion
void CircularList::print(int invert) {
  // NO INVERTIDO---------------------------------------------------------------
  if(invert == 0){
    int i=9;
    int trespuntos=0;
    if (!empty()) {
      Node *temp = ptrHead;
      do {
        gotoxy(4,i);
        std::cout<<temp->id;

        //nombre en la lista
        gotoxy(13,i);
        trespuntos = temp->nombre.length();

        if (trespuntos<10) {
          std::cout<<temp->nombre<<"          ";
        }else{
          std::cout<<temp->nombre;
        }
        if (trespuntos>20) {
          gotoxy(31,i); printf("...%c",186);
        }

        //album en la lista
        trespuntos=0;
        gotoxy(35,i);
        trespuntos = temp->album.length();
        if (trespuntos<10) {
          std::cout<<temp->album<<"          ";
        }else{
          std::cout<<temp->album;
        }
        if (trespuntos>20) {
          gotoxy(53,i); printf("...%c",186);
        }

          //artista en la lista
        trespuntos=0;
        gotoxy(57,i);
        trespuntos = temp->artista.length();
        if (trespuntos<10) {
          std::cout<<temp->artista<<"          ";
        }else{
          std::cout<<temp->artista;
        }
        if (trespuntos>20) {
          gotoxy(75,i); printf("...%c",186);
        }

        //genero en la lista
        gotoxy(79,i);
        trespuntos=0;
        trespuntos = temp->genero.length();
        if (trespuntos<10) {
          std::cout<<temp->genero<<"          ";
        }else{
          std::cout<<temp->genero;
        }
        if (trespuntos>20) {
          gotoxy(97,i); printf("...%c",186);
        }


        temp = temp->next;
        i=i+2;
      } while (temp != ptrHead);
    }
  }
    //INVERTIDO-----------------------------------------------------------------
  if(invert==1){
    int i=9;
    int trespuntos=0;
    Node* temp = new Node();
	  temp = last_node;

		do{
      gotoxy(4,i);
      std::cout<<temp->id;

      //nombre en la lista
      gotoxy(13,i);
      trespuntos = temp->nombre.length();

      if (trespuntos<10) {
        std::cout<<temp->nombre<<"          ";
      }else{
        std::cout<<temp->nombre;
      }
      if (trespuntos>20) {
        gotoxy(31,i); printf("...%c",186);
      }

      //album en la lista
      trespuntos=0;
      gotoxy(35,i);
      trespuntos = temp->album.length();
      if (trespuntos<10) {
        std::cout<<temp->album<<"          ";
      }else{
        std::cout<<temp->album;
      }
      if (trespuntos>20) {
        gotoxy(53,i); printf("...%c",186);
      }

        //artista en la lista
      trespuntos=0;
      gotoxy(57,i);
      trespuntos = temp->artista.length();
      if (trespuntos<10) {
        std::cout<<temp->artista<<"          ";
      }else{
        std::cout<<temp->artista;
      }
      if (trespuntos>20) {
        gotoxy(75,i); printf("...%c",186);
      }

      //genero en la lista
      gotoxy(79,i);
      trespuntos=0;
      trespuntos = temp->genero.length();
      if (trespuntos<10) {
        std::cout<<temp->genero<<"          ";
      }else{
        std::cout<<temp->genero;
      }
      if (trespuntos>20) {
        gotoxy(97,i); printf("...%c",186);
      }

      i=i+2;
      temp = temp->back;
		}while(temp!=last_node);
  }
}


  void CircularList::currentSong(int idBuscar){
    Node *temp = ptrHead;

    while (idBuscar!=temp->id) {
      temp=temp->next;
    }

    gotoxy(14,2);
    std::cout << temp->nombre;
    gotoxy(12,5);
    std::cout << temp->album;
    gotoxy(64,2);
    std::cout << temp->artista;
    gotoxy(63,5);
    std::cout << temp->genero;
}

int CircularList::deleteSong(int idBuscar){
  Node* actual = new Node();
	actual = ptrHead;
	Node* anterior = new Node();
  int i=1;

  if(ptrHead->next == ptrHead){
    ptrHead=NULL;
    delete ptrHead;
    return 0;
  }else{
    do {
      if (actual->id==idBuscar) {
        if (actual==ptrHead) {
          ptrHead = ptrHead->next;
  				ptrHead->back = last_node;
  				last_node->next = ptrHead;
          delete actual;
        }else if (actual==last_node) {
          last_node = anterior;
  				last_node->next = ptrHead;
  				ptrHead->back = last_node;
          delete actual;
        }else{
          anterior->next = actual->next;
  				actual->next->back = anterior;
        }
      }
      anterior = actual;
  		actual = actual->next;
    } while(actual!=ptrHead);

  actual = ptrHead;
  do{
      actual->id = i;
      i++;
			actual = actual->next;
		}while(actual!=ptrHead);
  return i-1;
  }
}

void CircularList::editSong(int idBuscar){
  char  nombre_[50], album_[50], artista_[50], genero_[50];
  string nombre, album, artista, genero;
  Node *temp = ptrHead;

  system("cls");
  CrearMarco();
  while (idBuscar!=temp->id) {
    temp=temp->next;
  }

  gotoxy(41,3);
  std::cout << "EDITAR UNA CANCION";

  gotoxy(7,12);
  std::cout << "INGRESE EL NOMBRE DE LA CANCION: ";
  fflush(stdin);
  gets(nombre_);
  for(int i=0; nombre_[i] != '\0';i++){ //email a mayusculas
    nombre_[i] = toupper(nombre_[i]);
  }
  nombre = nombre_;

  gotoxy(7,15);
  std::cout << "INGRESE EL ALBUM DE LA CANCION: ";
  fflush(stdin);
  gets(album_);
  for(int i=0; album_[i] != '\0';i++){ //email a mayusculas
    album_[i] = toupper(album_[i]);
  }
  album = album_;

  gotoxy(7,18);
  std::cout << "INGRESE EL ARTISTA DE LA CANCION: ";
  fflush(stdin);
  gets(artista_);
  for(int i=0; artista_[i] != '\0';i++){ //email a mayusculas
    artista_[i] = toupper(artista_[i]);
  }
  artista = artista_;

  gotoxy(7,21);
  std::cout << "INGRESE EL GENERO DE LA CANCION: ";
  fflush(stdin);
  gets(genero_);
  for(int i=0; genero_[i] != '\0';i++){ //email a mayusculas
    genero_[i] = toupper(genero_[i]);
  }
  genero = genero_;

  gotoxy(30,26);
  std::cout << "EDITANDO CANCION EN LA LISTA DE REPRODUCCION"; gotoxy(7,29);
  for(int i=0; i<85;i++){
    std::cout << ".";
    Sleep(10);
  }

  temp->nombre = nombre;
  temp->album = album;
  temp->artista = artista;
  temp->genero = genero;

}


int main(int argc, char** argv) {
  CircularList *obj = new CircularList();
  int band=0, band2=0, op, *ptr, id=0;
  char validar[256], nombre_[50], album_[50], artista_[50], genero_[50];
  string nombre, album, artista, genero;
  int i=9, flecha=1, idBuscar=1;
  int invert=0 ,musica=0;

  do {

    //SI ESTÁ VACIA-------------------------------------------------------------------------------
    if(obj->empty()==true){
      CrearMarco();
      gotoxy(34,3);
      std::cout << "BIENVENIDO A TU LISTA DE REPRODUCCION";
      gotoxy(30,17);
      std::cout << "NO HAY CANCIONES EN LA LISTA DE REPRODUCCION";
      gotoxy(30,19);
      std::cout << "                                                " << '\n';
      opciones();
      fflush(stdin);
      gets(validar);
      gotoxy(116,31);
      std::cout << "   ";
      op = atoi(validar);

      switch (op) {
        case 1:
          system("cls");
          CrearMarco();
          opciones();
          gotoxy(41,3);
          std::cout << "AGREGAR NUEVA CANCION";

          gotoxy(7,12);
          std::cout << "INGRESE EL NOMBRE DE LA CANCION: ";
          fflush(stdin);
          gets(nombre_);
          for(int i=0; nombre_[i] != '\0';i++){ //email a mayusculas
            nombre_[i] = toupper(nombre_[i]);
          }
          nombre = nombre_;

          gotoxy(7,15);
          std::cout << "INGRESE EL ALBUM DE LA CANCION: ";
          fflush(stdin);
          gets(album_);
          for(int i=0; album_[i] != '\0';i++){ //email a mayusculas
            album_[i] = toupper(album_[i]);
          }
          album = album_;

          gotoxy(7,18);
          std::cout << "INGRESE EL ARTISTA DE LA CANCION: ";
          fflush(stdin);
          gets(artista_);
          for(int i=0; artista_[i] != '\0';i++){ //email a mayusculas
            artista_[i] = toupper(artista_[i]);
          }
          artista = artista_;

          gotoxy(7,21);
          std::cout << "INGRESE EL GENERO DE LA CANCION: ";
          fflush(stdin);
          gets(genero_);
          for(int i=0; genero_[i] != '\0';i++){ //email a mayusculas
            genero_[i] = toupper(genero_[i]);
          }
          genero = genero_;

          gotoxy(30,26);
          std::cout << "AGREGANDO CANCION A LA LISTA DE REPRODUCCION"; gotoxy(7,29);
          for(int i=0; i<85;i++){
            std::cout << ".";
            Sleep(10);
          }

          id++;
          obj->addSong(id,nombre,album,artista,genero);
        break;

        //NO HACER NADA EN ESTOS CASOS
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        break;

        case 9:
          gotoxy(35,19);
          band=1;
        break;

        default:
          system("cls");
          CrearMarco();
          opciones();
          gotoxy(40,17);
          std::cout << "LO INGRESADO NO ES VALIDO";gotoxy(35,19);
          system("pause");
        break;
      }

      //SI NO ESTÁ VACIA----------------------------------------------------------------------------------------
    }else{
      system("cls");
      gotoxy(2,i); printf("%c",254);
      CrearMarco();
      datosCancion();
      lista();
      obj->print(invert);
      obj->currentSong(idBuscar);



      opciones();
      fflush(stdin);
      gets(validar);
      op = atoi(validar);

      switch (op) {
        case 1: //Añadir nueva cancion
          system("cls");
          CrearMarco();
          opciones();
          gotoxy(41,3);
          std::cout << "AGREGAR NUEVA CANCION";

          gotoxy(7,12);
          std::cout << "INGRESE EL NOMBRE DE LA CANCION: ";
          fflush(stdin);
          gets(nombre_);
          for(int i=0; nombre_[i] != '\0';i++){ //email a mayusculas
            nombre_[i] = toupper(nombre_[i]);
          }
          nombre = nombre_;

          gotoxy(7,15);
          std::cout << "INGRESE EL ALBUM DE LA CANCION: ";
          fflush(stdin);
          gets(album_);
          for(int i=0; album_[i] != '\0';i++){ //email a mayusculas
            album_[i] = toupper(album_[i]);
          }
          album = album_;

          gotoxy(7,18);
          std::cout << "INGRESE EL ARTISTA DE LA CANCION: ";
          fflush(stdin);
          gets(artista_);
          for(int i=0; artista_[i] != '\0';i++){ //email a mayusculas
            artista_[i] = toupper(artista_[i]);
          }
          artista = artista_;

          gotoxy(7,21);
          std::cout << "INGRESE EL GENERO DE LA CANCION: ";
          fflush(stdin);
          gets(genero_);
          for(int i=0; genero_[i] != '\0';i++){ //email a mayusculas
            genero_[i] = toupper(genero_[i]);
          }
          genero = genero_;

          gotoxy(30,26);
          std::cout << "AGREGANDO CANCION A LA LISTA DE REPRODUCCION"; gotoxy(7,29);
          for(int i=0; i<85;i++){
            std::cout << ".";
            Sleep(10);
          }

          id++;
          obj->addSong(id,nombre,album,artista,genero);
          invert=0;
          i=9;
          flecha=1;
          idBuscar=1;
          musica=1;
        break;

        case 2://Siguiente
          //MOVER LA SELECCION
          if(invert==0){ //si no esta inviertido
            if (id>flecha) {
              i=i+2;
              flecha++;
              gotoxy(2,i); printf("%c",254);
              idBuscar++;
            }
          }else{ //si esta invertido
            if (idBuscar>1) {
              i=i+2;
              flecha++;
              gotoxy(2,i); printf("%c",254);
              idBuscar--;
            }
          }
        break;

        case 3://Anterior
        //MOVER LA SELECCION
          if(invert==0){ //si no está invertdo
            if (flecha>1) {
              i=i-2;
              flecha--;
              gotoxy(2,i); printf("%c",254);
              idBuscar--;
            }
          }else{ //si está invertido
            if(i!=9){
                i=i-2;
                flecha--;
                gotoxy(2,i); printf("%c",254);
                idBuscar++;
            }
          }
        break;

        case 4: //eliminar la cancion seleccionada
          id = obj->deleteSong(idBuscar);
          i=9;
          flecha=1;
          idBuscar=1;
          invert=0;
          system("cls");
        break;

        case 5: //Modificar la cancion seleccionada
          obj->editSong(idBuscar);
          invert=0;
          i=9;
          flecha=1;
          idBuscar=1;
          musica=1;
        break;

        case 6: //Invertir la lista de reproduccion
          if(invert==0){
            invert=1;
            flecha=id;
            idBuscar=id;
            i=9;
          }else{
            invert=0;
            i=9;
            flecha=1;
            idBuscar=1;
          }
        break;

        case 7: //Eliminar la primer cancion
          if(invert==0){
            id = obj->deleteSong(1);
            i=9;
            flecha=1;
            idBuscar=1;
            invert=0;
            system("cls");
          }else{
            id = obj->deleteSong(id);
            i=9;
            flecha=1;
            idBuscar=1;
            invert=0;
            system("cls");
          }
        break;

        case 8: //Eliminar la ultima cancion
          if(invert==0){
            id = obj->deleteSong(id);
            i=9;
            flecha=1;
            idBuscar=1;
            invert=0;
            system("cls");
          }else{
            id = obj->deleteSong(1);
            i=9;
            flecha=1;
            idBuscar=1;
            invert=0;
            system("cls");
          }
        break;

        case 9: //Salir
          system("cls");
          CrearMarco();
          gotoxy(35,19);
          band=1;
        break;

        default:
          system("cls");
          CrearMarco();
          opciones();
          gotoxy(40,17);
          std::cout << "LO INGRESADO NO ES VALIDO";gotoxy(35,19);
          system("pause");
        break;
      }
    }
  }while(band==0);
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
    system("cls");
    std::cout << '\n' << '\n' << "LO INGRESADO NO ES UN VALOR VALIDO, INTENTE DE NUEVO." << '\n' << '\n' << '\n';
    system("pause");
    system("cls");
  }
}


//CREAR UN MARCO EN LA PANTALLA CON LINEAS
void CrearMarco(){
  int   i,k,j;

  //Lineas Horizontales
  for(i=3;i<124;i++){
    gotoxy(i,1);
    printf("%c",205);
    gotoxy(i,34);
    printf("%c",205);
  }

  //Lineas Verticales
  for(j=1;j<35;j++){
    gotoxy(3,j);
    printf("%c",186);
    gotoxy(100,j);
    printf("%c",186);
    gotoxy(124,j);
    printf("%c",186);
  }

  //Linea divisora
  for(k=3;k<100;k++){
    gotoxy(k,6);
    printf("%c",205);
  }

  //Esquinas y bordes del marco
  gotoxy(3,1);       printf("%c",201);
  gotoxy(124,1);     printf("%c",187);
  gotoxy(3,34);      printf("%c",200);
  gotoxy(124,34);    printf("%c",188);
  gotoxy(100,1);     printf("%c",203);
  gotoxy(100,34);    printf("%c",202);
  gotoxy(3,6);       printf("%c",204);
  gotoxy(100,6);     printf("%c",185);
  gotoxy(4,2);
}

void lista() {
  int i;

  //Lineas Verticales
  for(i=7;i<34;i++){
    gotoxy(12,i);
    printf("%c",186);
    gotoxy(34,i);
    printf("%c",186);
    gotoxy(56,i);
    printf("%c",186);
    gotoxy(78,i);
    printf("%c",186);
  }

  gotoxy(6,7);
  std::cout << " ID";

  gotoxy(19,7);
  std::cout << " NOMBRE";

  gotoxy(42,7);
  std::cout << " ALBUM";

  gotoxy(63,7);
  std::cout << " ARTISTA";

  gotoxy(86,7);
  std::cout << " GENERO";

  gotoxy(12,6);  printf("%c",203);
  gotoxy(12,34);  printf("%c",202);

  gotoxy(34,6);  printf("%c",203);
  gotoxy(34,34);  printf("%c",202);

  gotoxy(56,6);  printf("%c",203);
  gotoxy(56,34);  printf("%c",202);

  gotoxy(78,6);  printf("%c",203);
  gotoxy(78,34);  printf("%c",202);

  for(int j=3;j<100;j++){
    gotoxy(j,8);
    printf("%c",205);
  }

  gotoxy(3,8);  printf("%c",204);
  gotoxy(12,8);  printf("%c",206);
  gotoxy(34,8);  printf("%c",206);
  gotoxy(56,8);  printf("%c",206);
  gotoxy(78,8);  printf("%c",206);
  gotoxy(100,8);  printf("%c",185);
}


void opciones(){
  gotoxy(102,2);
  std::cout << "       LISTA DE"; gotoxy(102,4);
  std::cout << "     REPRODUCCION" << '\n';
  gotoxy(102,9);
  std::cout << "1.NUEVA CANCION"; gotoxy(102,11);
  std::cout << "2.SIGUIENTE"; gotoxy(102,13);
  std::cout << "3.ANTERIOR"; gotoxy(102,15);
  std::cout << "4.ELIMINAR CANCION"; gotoxy(102,17);
  std::cout << "5.EDITAR CANCION"; gotoxy(102,19);
  std::cout << "6.INVERTIR LISTA"; gotoxy(102,21);
  std::cout << "7.ELIMINAR PRIMER"; gotoxy(102,22);
  std::cout << "  CANCION"; gotoxy(102,24);
  std::cout << "8.ELIMINAR ULTIMA"; gotoxy(102,25);
  std::cout << "  CANCION"; gotoxy(102,27);
  std::cout << "9.SALIR"; gotoxy(102,31);
  std::cout << "TU OPCION ES: ";
}

void datosCancion(){
  gotoxy(5,2);
  std::cout << "CANCION: ";

  gotoxy(5,5);
  std::cout << "ALBUM: ";

  gotoxy(55,2);
  std::cout << "ARTISTA: ";

  gotoxy(55,5);
  std::cout << "GENERO: ";
}



























//
