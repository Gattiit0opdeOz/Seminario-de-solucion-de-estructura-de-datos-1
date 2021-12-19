/*
  Autor: Bryan Vizcarra Aguilar
  Fecha de creacion: 26 de octubre de 2021
  Fecha de ult mod: 29 de octubre de 2021
  lista circular
*/

int validarNumero(char [], int *);

#include <iostream>
#include <cstdlib>
#include <cctype>

class CircularList{
private:
  class Node {
  public:
    int number;
    Node *next;
    Node *back;
  };
  Node *ptrHead;

  public:
    CircularList();
    ~CircularList();
    void insert_First(int);
    void insert_Last(int);
    bool empty();
    void print();
    int travel();
    void edit(int);
    void search(int);
    void remove(int);
};

CircularList::CircularList(){
  ptrHead = NULL;
}


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


void CircularList::insert_First(int number) {
  Node *new_node = new Node();
  new_node->number = number;
  if (ptrHead == NULL){
    new_node->next = new_node;
    new_node->back = new_node;
    ptrHead = new_node;
  }else{
    Node *last_node = ptrHead->back;
    new_node->next = ptrHead;
    new_node->back = last_node;
    ptrHead->back = new_node;
    last_node->next = new_node;
    ptrHead = new_node;
  }
}


void CircularList::insert_Last(int number) {
  Node *new_node = new Node();
  new_node->number = number;
  if (ptrHead == NULL){
    new_node->next = new_node;
    new_node->back = new_node;
    ptrHead = new_node;
  }else{
    Node *last_node = ptrHead->back;
    new_node->next = ptrHead;
    new_node->back = last_node;
    ptrHead->back = new_node;
    last_node->next = new_node;
  }
}


bool CircularList::empty() {
  if (ptrHead == NULL){
    return true;
  }else{
    return false;
  }
}


void CircularList::print() {
  if (!empty()) {
    Node *temp = ptrHead;
    do {
      std::cout<<temp->number <<"-";
      temp = temp->next;
    } while (temp != ptrHead);
  std::cout << "\n";
  }
}


int CircularList::travel() {
  int count = 0;
  if (!empty()){
    Node *temp = ptrHead;
    do {
      count++;
      temp = temp->next;
    } while (temp != ptrHead);
  }
  return count;
}


void CircularList::remove(int position) {
  if (position <= travel()){
    if (position == 1){
      if (travel() == 1){
        delete ptrHead;
        ptrHead = NULL;
      }else{
        Node *temp_ptrHead = ptrHead;
        Node *last_node = ptrHead->back;
        ptrHead = ptrHead->next;
        last_node->next = ptrHead;
        ptrHead->back = last_node;
        delete temp_ptrHead;
      }
    }else {
      Node *temp = ptrHead;
      for (int f = 1; f <= position-1; f++){
        temp = temp->next;
      }
      Node *temp_ptrHead = temp;
      Node *back = temp->back;
      temp = temp->next;
      back->next = temp;
      temp->back = back;
      delete temp_ptrHead;
    }
  }
}

void CircularList::search(int position){
  Node *temp = ptrHead;
  for (int i = 1; i <= position-1; i++){
    temp = temp->next;
  }
  std::cout << '\n';
  std::cout << "LA POSICION "<< position<< " CONTIENE EL NUMERO: " << temp->number << '\n'<< '\n';
  system("pause");
}

void CircularList::edit(int position){
  char numero[10];
  int band2=0, *ptr, valor;
  Node *temp = ptrHead;

  for (int i = 1; i <= position-1; i++){
    temp = temp->next;
  }

  do{
    system("cls");
    std::cout << "----MODIFICAR ELEMENTO POR POSICION----" << '\n'<< '\n';
    std::cout << "INGRESE EL NUEVO VALOR PARA LA POSICION "<< position << '\n'<< '\n';
    std::cout << "TU VALOR ES: ";
    gets(numero);
    ptr = &band2;
    validarNumero(numero,ptr);
  }while(band2==0);
  valor = atoi(numero);
  temp->number = valor;
}


int main(int argc, char** argv) {
  CircularList *obj = new CircularList();
  int band=0, band2=0, op, *ptr, valor, position;
  char validar[2], numero[10];

  do {
    system("cls");
    std::cout << "LA LISTA ES:" << '\n'<<'\n';
    if(obj->empty()==true){
      std::cout << "LA LISTA ESTA VACIA." << '\n';
    }else{
      obj->print();
    }
    std::cout << '\n';
    std::cout << "SELECCIONE LA OPCION DESEADA" << '\n'<< '\n';
    std::cout << "1. INSERTAR AL PRINCIPIO" << '\n';
    std::cout << "2. INSERTAR AL FINAL" << '\n';
    std::cout << "3. BUSCAR POR POSICION" << '\n';
    std::cout << "4. MODIFICAR" << '\n';
    std::cout << "5. IMPRIMIR LISTA" << '\n';
    std::cout << "6. ELIMINAR UN ELEMENTO" << '\n';
    std::cout << "7. SALIR" << '\n'<< '\n';
    std::cout << "TU OPCION ES: ";
    fflush(stdin);
    gets(validar);
    op = atoi(validar);

    switch (op) {
      case 1: //AGREGAR ELEMENTO AL PRINCIPIO
        band2=0;
        do{
          system("cls");
          std::cout << "----AGREGAR ELEMENTO AL PRINCIPIO----" << '\n'<< '\n';
          std::cout << "INGRESE EL ELEMENTO QUE DESEA AGREGAR" << '\n'<< '\n';
          std::cout << "TU VALOR ES: ";
          gets(numero);
          ptr = &band2;
          validarNumero(numero,ptr);
        }while(band2==0);
        valor = atoi(numero);
        obj->insert_First(valor);
      break;

      case 2: //AGREGAR ELEMENTO AL FINAL
        band2=0;
        do{
          system("cls");
          std::cout << "----AGREGAR ELEMENTO AL FINAL----" << '\n'<< '\n';
          std::cout << "INGRESE EL ELEMENTO QUE DESEA AGREGAR" << '\n'<< '\n';
          std::cout << "TU VALOR ES: ";
          gets(numero);
          ptr = &band2;
          validarNumero(numero,ptr);
        }while(band2==0);
        valor = atoi(numero);
        obj->insert_Last(valor);
      break;

      case 3: //BUSCAR POR POSICIÓN
        band2=0;
        if(obj->empty()==true){
          system("cls");
          std::cout << '\n' << '\n' << "LA LISTA ESTA VACIA." << '\n' << '\n' << '\n';
          system("pause");
        }else{
          do{
            system("cls");
            std::cout << "----BUSCAR ELEMENTO POR POSICION----" << '\n'<< '\n';
            std::cout << "INGRESE LA POSICION QUE DESEA BUSCAR" << '\n'<< '\n';
            std::cout << "TU POSICION ES: ";
            gets(numero);
            ptr = &band2;
            validarNumero(numero,ptr);
          }while(band2==0);
          position = atoi(numero);
          if(position>obj->travel() || position<=0){
            system("cls");
            std::cout << '\n' << '\n' << "LA POSICION INGRESADA ES INVALIDA" << '\n' << '\n' << '\n';
            system("pause");
          }else{
            obj->search(position);
          }
        }
      break;

      case 4: //MODIFICAR
        band2=0;
        if(obj->empty()==true){
          system("cls");
          std::cout << '\n' << '\n' << "LA LISTA ESTA VACIA." << '\n' << '\n' << '\n';
          system("pause");
        }else{
          do{
            system("cls");
            std::cout << "----MODIFICAR ELEMENTO POR POSICION----" << '\n'<< '\n';
            std::cout << "INGRESE LA POSICION QUE DESEA MODIFICAR" << '\n'<< '\n';
            std::cout << "TU POSICION ES: ";
            gets(numero);
            ptr = &band2;
            validarNumero(numero,ptr);
          }while(band2==0);
          position = atoi(numero);
          if(position>obj->travel() || position<=0){
            system("cls");
            std::cout << '\n' << '\n' << "LA POSICION INGRESADA ES INVALIDA" << '\n' << '\n' << '\n';
            system("pause");
          }else{
            obj->edit(position);
          }
        }
      break;

      case 5: //IMPRIMIR LA LISTA
        system("cls");
        std::cout << "----IMPRIMIR LA LISTA----" << '\n'<< '\n';
        std::cout << "LA LISTA ES LA SIGUIENTE" << '\n'<< '\n';
        obj->print();
        std::cout << '\n'<< '\n';
        system("pause");
      break;

      case 6: //ELIMINAR
        band2=0;
        if(obj->empty()==true){
          system("cls");
          std::cout << "NO ES POSIBLE ELIMINAR ELEMENTOS";
          std::cout << '\n' << '\n' << "LA LISTA ESTA VACIA." << '\n' << '\n' << '\n';
          system("pause");
        }else{
          do{
            system("cls");
            std::cout << "----ELIMINAR ELEMENTO POR POSICION----" << '\n'<< '\n';
            std::cout << "INGRESE LA POSICION QUE DESEA ELIMINAR" << '\n'<< '\n';
            std::cout << "LA POSICION ES ES: ";
            gets(numero);
            ptr = &band2;
            validarNumero(numero,ptr);
          }while(band2==0);
          position = atoi(numero);
          if(position>obj->travel() || position<=0){
            system("cls");
            std::cout << '\n' << '\n' << "LA POSICION INGRESADA ES INVALIDA" << '\n' << '\n' << '\n';
            system("pause");
          }else{
            obj->remove(position);
          }
        }


      break;

      case 7: //SALIR
        band=1;
      break;

      default:
        system("cls");
        std::cout << '\n' << '\n' << "LO INGRESADO NO ES UN VALOR VALIDO, INTENTE DE NUEVO." << '\n' << '\n' << '\n';
        system("pause");
        system("cls");
      break;
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
