/*
Autor: Bryan Vizcarra Aguilar
Fecha de creación: 18 de Agosto de 2020
Fecha de ult Mod: 19 de Agisto de 2020
Agenda de Contactos
*/
#include <iostream>
#include <cstdlib>
#include <string.h>

struct contactos{
  int id;
  char nombre[30];
  char direccion[30];
  char email[50];
}contactos[5];

int pos=0;

void registroContacto(void);
int buscarPorId(int);
int buscarPorNombre(char*);
void mostrarContacto(int);
void editarContacto();
void eliminarContacto(int);
void menu();


int main(int argc, char const *argv[]) {
  int opcion=0;
  do{
    menu();
    std::cout << "Continuar 1[Si] 0[No]" << '\n';
    std::cin >> opcion;
  }while(opcion!=0);
  return 0;
}

void menu(){
  int opc=0,opc2=0,id=0;
  char nombre[30];
  system("cls");
  std::cout << "SELECCIONE LA OPCION DESEADA" << '\n' << '\n';
  std::cout << "1) Registrar Contacto" << '\n';
  std::cout << "2) Buscar Contacto" << '\n';
  std::cout << "3) Editar Contacto" << '\n';
  std::cout << "4) Eliminar Contacto" << '\n';
  std::cin >> opc;

  switch (opc) {
    case 1:
      registroContacto();
    break;

    case 2:
      system("cls");
      std::cout << "BUSQUEDA DE CONTACTO" << '\n' << '\n';
      std::cout << "1)Buscar contacto por ID" << '\n';
      std::cout << "2)Buscar Contacto por Nombre" << '\n';
      std::cin >> opc2;
      switch (opc2) {
        case 1:
          std::cout << "Ingrese el ID del contacto a buscar" << '\n';
          std::cin >> id;
          mostrarContacto(buscarPorId(id));
        break;

        case 2:
          std::cout << "Ingrese el Nombre del contacto a buscar" << '\n';
          std::cin >> nombre;
          mostrarContacto(buscarPorNombre(nombre));
        break;
      }
    break;

    case 3:
      editarContacto();
    break;

    case 4:
      std::cout << "Ingrese el Nombre del contacto a eliminar" << '\n';
      std::cin >> nombre;
      eliminarContacto(buscarPorNombre(nombre));
    break;

    default:
      std::cout << "La opcion ingresada no es valida, vuelva a intentarlo" << '\n';
    break;
  }
}

void registroContacto(){
  system("cls");
  std::cout << "REGISTRAR NUEVO CONTACTO" << '\n' << '\n';
  contactos[pos].id=pos+1;
  std::cout << "Ingrese Nombre del Contacto" << '\n';
  std::cin >> contactos[pos].nombre;
  std::cout << "Ingrese la Direccion del Contacto" << '\n';
  std::cin >> contactos[pos].direccion;
  std::cout << "Ingrese el Email del Contacto" << '\n';
  std::cin >> contactos[pos].email;
  pos++;
  system("cls");
}

int buscarPorId(int id){
  bool band=false;
  int i, posicion=0;

  while(band==false && i<pos){
    if(contactos[i].id==id){
      posicion=i;
      band=true;
    }
    i++;
  }
  return posicion;
}

int buscarPorNombre(char* nombre){
  bool band=false;
  int i=0, posicion=0;

  while(band==false && i<pos){
    if(strcmp(nombre,contactos[i].nombre)==0){
      posicion=i;
      band=true;
    }
    i++;
  }
  return posicion;
}

void mostrarContacto(int posicion){
  system("cls");
  std::cout << "CONTACTO" << '\n' << '\n' ;
  std::cout << "Nombre del Contacto: " << contactos[posicion].nombre << '\n';
  std::cout << "Direccion de Contacto: " << contactos[posicion].direccion << '\n';
  std::cout << "Email del Contacto: " << contactos[posicion].email << '\n';
}

void editarContacto(){
  system("cls");
  char nombre[30];
  int posicion=0, opcion=0;

  std::cout << "EDITAR CONTACTO" << '\n' << '\n';
  std::cout << "Escribe el nombre del contacto que deseas editar" << '\n';
  std::cin >> nombre;
  posicion = buscarPorNombre(nombre);
  system("cls");
  std::cout << "EDITAR CONTACTO" << '\n' << '\n';
  std::cout << "SELECCIONE LA OPCION DESEADA" << '\n';
  std::cout << "1) Editar Nombre" << '\n';
  std::cout << "2) Editar Direccion" << '\n';
  std::cout << "3) Editar Email" << '\n';
  std::cout << "4) Editar Todos" << '\n';
  std::cout << "5) Eliminar el Contacto" << '\n';
  std::cin >> opcion;

  switch (opcion) {
    case 1:
      std::cout << "Escriba el nuevo nombre del contacto" << '\n';
      std::cin >> contactos[posicion].nombre;
      system("cls");
    break;

    case 2:
      std::cout << "Escriba la nueva direccion del contacto" << '\n';
      std::cin >> contactos[posicion].direccion;
      system("cls");
    break;

    case 3:
      std::cout << "Escriba el nuevo Email del contacto" << '\n';
      std::cin >> contactos[posicion].email;
      system("cls");
    break;

    case 4:
      std::cout << "Escriba el nuevo nombre del contacto" << '\n';
      std::cin >> contactos[posicion].nombre;
      std::cout << "Escriba la nueva direccion del contacto" << '\n';
      std::cin >> contactos[posicion].direccion;
      std::cout << "Escriba el nuevo Email del contacto" << '\n';
      std::cin >> contactos[posicion].email;
      system("cls");
    break;

    case 5:
      eliminarContacto(posicion);
    break;
    default:
      std::cout << "La opcion ingresada no es valida, vuelva a intentarlo" << '\n';
    break;
  }
}

void eliminarContacto(int posicion){
  for(posicion;posicion<pos;posicion++){
    contactos[posicion].id = contactos[posicion+1].id;
    strcpy(contactos[posicion].nombre , contactos[posicion+1].nombre);
    strcpy(contactos[posicion].direccion , contactos[posicion+1].direccion);
    strcpy(contactos[posicion].email , contactos[posicion+1].email);
  }
  pos--;
}
