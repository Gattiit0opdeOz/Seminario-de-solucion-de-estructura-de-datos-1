/*
  Autor: Bryan Vizcarra Aguilar
  Fecha de creacion: 7 de octubre de 2020
  Fecha de ult mod: 9 de octubre de 2020
  Lista Enlazada Simple
*/

#include <iostream>
#include <cstdlib>
#include <string.h>
#include <cctype>
#include <cstring>
using std::string;

int validarNumero(char [], int *);


template<typename T>
class Nodo{
public:
  Nodo();
  Nodo(T,T,T,T);
  ~Nodo();
  Nodo *next;
  T id;
  T nombre;
  T telefono;
  T correo;
  void print();
  void delete_all();
};

// Eliminar todos los Nodos
template<typename T>
void Nodo<T>::delete_all()
{
    if (next)
    next->delete_all();
    delete this;
}

template <typename T>
Nodo<T>::Nodo(){
  id=NULL;
  nombre=NULL;
  telefono=NULL;
  correo=NULL;
  next=NULL;
}



template<typename T>
Nodo<T>::Nodo(T id, T nombre, T telefono, T correo){
  this->id = id;
  this->nombre = nombre;
  this->telefono = telefono;
  this->correo = correo;
  next = NULL;
}

template<typename T>
void Nodo<T>::print(){
  std::cout << "ID: "<< id << '\n';
  std::cout << "NOMBRE: " << nombre<< '\n';
  std::cout << "TELEFONO: "<< telefono << '\n';
  std::cout << "CORREO: "<< correo << '\n'<< '\n'<< '\n';
}

template<typename T>
Nodo<T>::~Nodo(){}

template <class T>
class List{
private:
  Nodo<T> *primero;
  Nodo<T> *ultimo;
  int total_nodes;
public:
  List();
  ~List();
  void addElement(T,T,T,T);
  void print();
  void searchByPos(int);
  void searchByName(T);
  void searchById(T);
  void invert();
  void deleteById(T);
  void del_all();
  void editContact(int);
};

template<typename T>
List<T>::List(){
  total_nodes = 0;
  primero = NULL;
}

template <typename T>
List<T>::~List(){}


template <typename T>
void List<T>::addElement(T id, T nombre, T telefono, T correo){
  Nodo<T> *nuevo_nodo = new Nodo<T> (id, nombre, telefono, correo);
  Nodo<T> *temp = primero;
  if(primero==NULL){
    primero = nuevo_nodo;
    primero->next = NULL;
    ultimo = nuevo_nodo;
  }else{
    ultimo->next = nuevo_nodo;
    nuevo_nodo->next = NULL;
    ultimo = nuevo_nodo;
  }
  total_nodes++;
}

template<typename T>
void List<T>::editContact(int pos){
  if(primero == NULL){
    std::cout << "LA AGENDA NO TIENE CONTACTOS REGISTRADOS" << '\n';
  }else{
    if(pos>total_nodes){
      std::cout << "LA POSICION ES INVALIDA" << '\n';
    }else if(pos<0){
      std::cout << "LA POSICION ES INVALIDA" << '\n';
    }else{
      char validar[2], id_[5] , telefono_[11];
      int op, band=0, band2=0, *ptr;
      string cad;
      Nodo<T> *aux=primero;

      for(int i=1;i<pos;i++){
        aux = aux->next;
      }

      do{
        system("cls");
        std::cout << "SELECCIONE LA OPCION DESEADA" << '\n';
        std::cout << "1. EDITAR ID" << '\n';
        std::cout << "2. EDITAR NOMBRE" << '\n';
        std::cout << "3. EDITAR TELEFONO" << '\n';
        std::cout << "4. EDITAR CORREO" << '\n';
        std::cout << "5. REGRESAR AL MENU ANTERIOR" << '\n';
        fflush(stdin);
        gets(validar);
        op = atoi(validar);

        switch (op) {
          case 1:
            do {
              std::cout << "INGRESA EL NUEVO ID DEL CONTACTO" << '\n';
              fflush(stdin);
              gets(id_);
              ptr = &band2;
              validarNumero(id_, ptr);
            } while(band2==0);
            band2=0;
            cad=id_;
            aux->id=cad;
            std::cout << '\n' << "EDITADO CORRECTAMENTE" << '\n'<< '\n'<< '\n';
            system("pause");
          break;

          case 2:
            std::cout << "INGRESA EL NUEVO NOMBRE" << '\n';
            getline(std::cin,cad);
            aux->nombre=cad;
            std::cout << '\n' << "EDITADO CORRECTAMENTE" << '\n'<< '\n'<< '\n';
            system("pause");
          break;

          case 3:
            do {
              std::cout << "INGRESA EL TELEFONO DEL CONTACTO" << '\n';
              fflush(stdin);
              gets(telefono_);
              ptr = &band2;
              validarNumero(telefono_, ptr);
            } while(band2==0);
            band2=0;
            cad=telefono_;
            aux->telefono=cad;
            std::cout << '\n' << "EDITADO CORRECTAMENTE" << '\n'<< '\n'<< '\n';
            system("pause");
          break;

          case 4:
            std::cout << "INGRESA EL NUEVO CORREO" << '\n';
            getline(std::cin,cad);
            aux->correo=cad;
            std::cout << '\n' << "EDITADO CORRECTAMENTE" << '\n'<< '\n'<< '\n';
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
      }while(band==0);

    }
  }
}

template<typename T>
void List<T>::deleteById(T id){
  int count =0;

  if(primero==NULL){
    std::cout << "NO EXISTEN CONTACTOS EN LA AGENDA" << '\n';
  }else{
    Nodo<T> *temp = primero;
    Nodo<T> *temp2 = primero->next;
    if(primero->id == id){
      primero = temp->next;
    }else{
      while(temp2){
        if(temp2->id == id){
          Nodo<T> *aux = temp2;
          temp->next = temp2->next;
          delete aux;
          count=1;
          total_nodes--;
          std::cout << "CONTACTO ELIMINADO CORRECTAMENTE" << '\n';
        }
        temp = temp->next;
        temp2 = temp2->next;
      }
    }
  }
  if(count == 0){
    std::cout << "NO SE ENCONTRO EL ID EN LA AGENDA" << '\n';
  }
}

template<typename T>
void List<T>::print(){
  Nodo<T> *temp = primero;
  if(primero==NULL){
    system("cls");
    std::cout << "LA AGENTA NO TIENE NINGUN CONTACTO" << '\n';
  }else{
    system("cls");
    std::cout << "-------TODOS LOS CONTACTOS-------" << '\n'<< '\n';
    while (temp!=NULL){
      temp->print();
      temp = temp->next;
    }
  }
  std::cout  << '\n'<< '\n';
  system("pause");
}

template<typename T>
void List<T>::searchById(T id){
  Nodo<T> *temp=primero;
  int count=0;

  while (temp!=NULL) {
    if(temp->id==id){
      system("cls");
      std::cout << "------BUSCAR CONTACTO POR ID------" << '\n'<< '\n';
      std::cout << "SE HA ENTRADO EL ID EN LA POSICION "<< count+1 << '\n'<< '\n';
      print();
      count++;
    }
    temp = temp->next;
  }
  if (count==0){
    system("cls");
    std::cout << "------BUSCAR CONTACTO POR ID------" << '\n'<< '\n';
    std::cout << "NO SE HA ENCONTRADO EN LA AGENDA" << '\n'<< '\n';
  }
}

//ELIMINAR TODO
template<typename T>
void List<T>::del_all(){
  if(primero==NULL){
    std::cout<<"";
  }else{
    primero->delete_all();
    primero = 0;
  }
}

template<typename T>
void List<T>::searchByName(T nombre){
  Nodo<T> *temp=primero;
  int count=0;

  while (temp!=NULL) {
    if(temp->nombre==nombre){
      system("cls");
      std::cout << "------BUSCAR CONTACTO POR NOMBRE------" << '\n'<< '\n';
      std::cout << "SE HA ENTRADO EL NOMBRE EN LA POSICION "<< count+1 << '\n'<< '\n';
      print();
      count++;
    }
    temp = temp->next;
  }
  if (count==0){
    system("cls");
    std::cout << "------BUSCAR CONTACTO POR NOMBRE------" << '\n'<< '\n';
    std::cout << "NO SE HA ENCONTRADO EN LA AGENDA" << '\n'<< '\n';
  }
}




template<typename T>
void List<T>::searchByPos(int pos){
  Nodo<T> *temp = primero;

  if(total_nodes == 0){
    std::cout << "LA AGENDA NO CONTIENE NINGUN CONTACTO" << '\n';
  }else{
    if(pos<total_nodes+1 && pos>0){
      for(int i=1;i<pos;i++){
        temp=temp->next;
      }
      std::cout << "ID: "<< temp->id<< '\n';
      std::cout << "NOMBRE: "<< temp->nombre << '\n';
      std::cout << "TELEFONO: "<< temp->telefono << '\n';
      std::cout << "CORREO: "<< temp->correo << '\n';
    }else{
      std::cout << "LA POSICION NO ES VALIDA" << '\n';
    }
  }
}


template<typename T>
void List<T>::invert(){
  Nodo<T> *anterior = NULL;
    Nodo<T> *next = NULL;
    Nodo<T> *temp = primero;

    while (temp) {
        next = temp->next;
        temp->next = anterior;
        anterior = temp;
        temp = next;
    }
    primero = anterior;
}



int main(int argc, char const *argv[]) {
  List<string> list;
  int band=0,band2=0, band3=0,*ptr=NULL,op, op2, position;
  char validar[2];
  char id_[5] , telefono_[11], pos_[4];
  string nombre, correo, id, telefono;

  do{
    band3=0; //case 9
    system("cls");
    std::cout << "-------SELECCIONA LA OPCION DESEADA-------" << '\n'<< '\n';
    std::cout << "1.  AGREGAR UN NUEVO CONTACTO" << '\n';
    std::cout << "2.  BUSCAR CONTACTO POR ID" << '\n';
    std::cout << "3.  ELIMINAR UN CONTACTO" << '\n';
    std::cout << "4.  BUSCAR UN CONTACTO POR POSICION" << '\n';
    std::cout << "5.  INVERTIR LA LISTA DE CONTACTOS" << '\n';
    std::cout << "6.  BUSCAR CONTACTO POR NOMBRE" << '\n';
    std::cout << "7.  MOSTRAR TODO LOS CONTACTOS" << '\n';
    std::cout << "8.  EDITAR UN CONTACTO" << '\n';
    std::cout << "9.  ELIMINAR TODOS LOS CONTACTOS" << '\n';
    std::cout << "10. SALIR" << '\n'<< '\n'<< '\n';
    std::cout << "TU OPCION ES: ";
    fflush(stdin);
    gets(validar);
    op = atoi(validar);

    switch (op) {
      case 1:
        system("cls");
        do {
          std::cout << "------AGREGAR UN CONTACTO NUEVO------" << '\n'<< '\n';
          std::cout << "INGRESA EL ID DEL CONTACTO" << '\n';
          fflush(stdin);
          gets(id_);
          ptr = &band2;
          validarNumero(id_, ptr);
        } while(band2==0);
        band2=0;
        std::cout << "INGRESE EL NOMBRE DEL CONTACTO" << '\n';
        getline(std::cin,nombre);
        for (int i = 0; i < nombre.length(); i++) {
          nombre[i] = toupper(nombre[i]);
        }
        do{
          std::cout << "INGRESE EL NUMERO DEL CONTACTO" << '\n';
          fflush(stdin);
          gets(telefono_);
          validarNumero(telefono_, ptr);
        }while(band2==0);
        std::cout << "INGRESE EL CORREO DEL CONTACTO" << '\n';
        getline(std::cin,correo);
        telefono = telefono_;
        id = id_;
        list.addElement(id, nombre, telefono, correo);
        system("cls");
        std::cout << "-----CONTACTO AGREGADO CORRECTAMENTE-----" << '\n'<< '\n';
        std::cout  << '\n';
        system("pause");
        band2=0;
      break;

      case 2:
        do{
          system("cls");
          std::cout << "------BUSCAR CONTACTO POR ID------" << '\n'<< '\n';
          std::cout << "INGRESA EL ID DEL CONTACTO" << '\n';
          fflush(stdin);
          gets(id_);
          ptr = &band2;
          validarNumero(id_, ptr);
        }while(band2==0);
        id = id_;
        list.searchById(id);

        band2=0;
      break;

      case 3:
        do{
          system("cls");
          std::cout << "------ELIMINAR CONTACTO POR ID------" << '\n'<< '\n';
          std::cout << "INGRESA EL ID DEL CONTACTO A ELIMINAR" << '\n';
          fflush(stdin);
          gets(id_);
          ptr = &band2;
          validarNumero(id_, ptr);
        }while(band2==0);
        id = id_;
        list.deleteById(id);
        system("pause");
        band2=0;
      break;

      case 4:
        do{
          system("cls");
          std::cout << "------ELIMINAR CONTACTO POR POSICION------" << '\n'<< '\n';
          std::cout << "INGRESA LA POSICION DEL CONTACTO A ELIMINAR" << '\n';
          fflush(stdin);
          gets(pos_);
          ptr = &band2;
          validarNumero(pos_, ptr);
        }while(band2==0);
        position = atoi(pos_);
        list.searchByPos(position);
        system("pause");
        band2=0;
      break;

      case 5:
        system("cls");
        std::cout << "------INVERTIR LA AGENDA------" << '\n'<< '\n';
        list.invert();
        std::cout << "LA AGENDA SE HA INVERTIDO SATISFACTORIAMENTE" << '\n'<< '\n';
        system("pause");
      break;

      case 6:
        system("cls");
        std::cout << "------BUSCAR CONTACTO POR NOMBRE------" << '\n'<< '\n';
        std::cout << "INGRESA EL NOMBRE DEL CONTACTO A BUSCAR" << '\n';
        getline(std::cin,nombre);
        for (int i = 0; i < nombre.length(); i++) {
          nombre[i] = toupper(nombre[i]);
        }
        list.searchByName(nombre);
        system("pause");


      break;


      case 7:
        list.print();
        system("cls");
      break;

      case 8:
        band2=0;
        do{
          system("cls");
          std::cout << "------EDITAR CONTACTO------" << '\n'<< '\n';
          std::cout << "INGRESA LA POSICION DEL CONTACTO A EDITAR" << '\n';
          fflush(stdin);
          gets(pos_);
          ptr = &band2;
          validarNumero(pos_, ptr);
        }while(band2==0);
        position = atoi(pos_);
        list.editContact(position);
        system("pause");
        band2=0;

      break;

      case 9:
      do{
          system("cls");
          std::cout << "----------ELIMINAR TODOS LOS CONTACTOS----------" << '\n'<< '\n';
          std::cout << "ESTA SEGURO QUE DESAS ELIMINAR TODOS LOS CONTACOS?" << '\n';
          std::cout << "ESTA OPERACION NO SE PUEDE DESHACER" << '\n'<< '\n' << '\n';
          std::cout << "1. SI, ELIMINAR TODOS LOS CONTACTOS" << '\n'<< '\n';
          std::cout << "2. NO, CONSERVAR MIS CONTACTOS" << '\n'<< '\n'<< '\n'<< '\n';
          std::cout << "TU OPCION ES: " ;
          fflush(stdin);
          gets(validar);

          op2 = atoi(validar);

          switch (op2) {
            case 1:
              list.del_all();
              std::cout << '\n'<< '\n';
              std::cout << "TODOS LOS CONTACTOS ELIMINADOS CORRECTAMENTE" << '\n'<< '\n'<< '\n';
              system("pause");
              band3=1;
            break;

            case 2:
              std::cout << '\n'<< '\n';
              std::cout << "NO SE HAN ELIMIDADO LOS CONTACTOS" << '\n'<< '\n'<< '\n';
              system("pause");
              band3=1;

            break;

            default:
              system("cls");
              std::cout << "LO INGRESADO NO ES VALIDO" << '\n';
              system("pause");
            break;
          }
        }while(band3==0);
      break;

      case 10:
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
} //END MAIN


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
