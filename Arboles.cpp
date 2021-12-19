/*
  Autor: Bryan Vizcarra Aguilar
  Fecha de creacion: 9 de noviembre de 2021
  Fecha de ult mod: 10 de noviembre de 2021
  Arbol Binario
*/


#include <iostream>
#include <cstdlib>
#include <string.h>
#include <cctype>
#include <cstring>
using std::string;

int validarNumero(char [], int *);

struct Object{
    int id;
    string nombre;
    string direccion;
    string email;
    Object *left, *right;
};typedef struct Object *Node;


Node CreateNode(int id, string nombre, string direccion, string email){
  Node newNode = new( Object);
  newNode->id = id;
  newNode->nombre = nombre;
  newNode->direccion = direccion;
  newNode->email = email;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

void add(Node &ptr, int id, string nombre, string direccion, string email){
  if(ptr==NULL) {
    ptr = CreateNode(id,nombre,direccion,email);
  }else if(id < ptr->id){
    add(ptr->left, id, nombre, direccion, email);
  }else if(id > ptr->id){
    add(ptr->right, id, nombre, direccion, email);
  }
}


void preOrden(Node ptr) {
  if(ptr!=NULL) {
    std::cout << ptr->id <<" ";
    preOrden(ptr->left);
    preOrden(ptr->right);
  }
}


void enOrden(Node ptr) {
  if(ptr!=NULL) {
    enOrden(ptr->left);
    std::cout << ptr->id << " ";
    enOrden(ptr->right);
  }
}


void postOrden(Node ptr) {
  if(ptr!=NULL) {
    postOrden(ptr->left);
    postOrden(ptr->right);
    std::cout << ptr->id << " ";
  }
}

int search(Node ptr, int idBuscar){
  if(ptr!=NULL){
    if(ptr->id == idBuscar){ //evalua el id a buscar por el usuario con el del nodo
  		  std::cout << "SE ENCONTRO EL ID" << '\n'<< '\n';
        //Muetra los datos del contacto encontrado
        std::cout << "ID: "<< ptr->id << '\n';
        std::cout << "NOMBRE: "<< ptr->nombre << '\n';
        std::cout << "DIRECCION: "<< ptr->direccion << '\n';
        std::cout << "CORREO: "<< ptr->email << '\n'<< '\n'<< '\n';
        system("pause");
        return 0;
  		system("pause");
    }else if(idBuscar < ptr->id){ 	//
  		return search(ptr->left,idBuscar);
  	}else{
      return search(ptr->right,idBuscar);
    }
  }else{
    std::cout <<'\n'<< "NO SE ENCONTRO EL ID REGISTRADO" << '\n'<< '\n'<< '\n';
    system("pause");
    return 0;
  }
}


int edit(Node ptr,int idBuscar){
  int *ptrvalidar, band2=0;
  char nombre_[50], direccion_[50], email_[50];
  string nombre, direccion, email;


  if(ptr!=NULL){
    if(ptr->id == idBuscar){ //evalua el id a buscar por el usuario con el del nodo
        system("cls");


        std::cout << "INGRESE EL NUEVO NOMBRE DEL CONTACTO" << '\n';
        fflush(stdin);
        gets(nombre_);
        for(int i=0; nombre_[i] != '\0';i++){ //nombre a mayusculas
          nombre_[i] = toupper(nombre_[i]);
        }
        nombre = nombre_;


        std::cout << "INGRESE LA NUEVA DIRECCION DEL CONTACTO" << '\n';
        fflush(stdin);
        gets(direccion_);
        for(int i=0; direccion_[i] != '\0';i++){ //direccion a mayusculas
          direccion_[i] = toupper(direccion_[i]);
        }
        direccion = direccion_;


        std::cout << "INGRESE EL NUEVO EMAIL DEL CONTACTO" << '\n';
        fflush(stdin);
        gets(email_);
        for(int i=0; email_[i] != '\0';i++){ //email a mayusculas
          email_[i] = toupper(email_[i]);
        }
        email = email_;

        //asignacion de los nuevos datos al contacto
        ptr->nombre =  nombre;
        ptr->direccion = direccion;
        ptr->email = email;

  		system("pause");
    }else if(idBuscar < ptr->id){ 	//
  		return edit(ptr->left,idBuscar);
  	}else{
      return edit(ptr->right,idBuscar);
    }
  }else{
    std::cout <<'\n'<< "NO SE ENCONTRO EL ID REGISTRADO" << '\n'<< '\n'<< '\n';
    system("pause");
    return 0;
  }
}


void show(Node ptr,int cont){
	if(ptr==NULL){
		return;
	}else{
		show(ptr->right,cont+1);
		for(int i=0;i<cont;i++){
			std::cout<<"   ";
  	}
  	std::cout<<ptr->id<<'\n';
  	show(ptr->left,cont+1);
  }
}

Node buscarPadre(Node ptr, int idBuscar){
  Node temp = NULL;

   if(ptr==NULL){
     return NULL;
   }

   //VERIFICAR SI ES EL padre
   if(ptr->left!= NULL){
     if(ptr->left->id == idBuscar){
       return ptr;
     }
   }

   if(ptr->right != NULL){
     if(ptr->right->id == idBuscar){
       return ptr;
     }
   }

   if(ptr->left !=NULL && idBuscar < ptr->id){
     temp = buscarPadre(ptr->left, idBuscar);
   }

   if (ptr->right != NULL && idBuscar > ptr->id) {
     temp = buscarPadre(ptr->right, idBuscar);
   }

   return temp;

}

Node encontrarMinimo(Node ptr){
  if(ptr == NULL){
		return NULL;
	}
	if(ptr->left){//si tiene hijo izquierdo
		return encontrarMinimo(ptr->left);//buscamos en la part izq mas posible
	}
	else{//si no tiene hijo izq
		return ptr; //retornamos el mismo nodo
  }
}




int deleteContact(Node ptr, Node ptr2, int idBuscar){

  if(ptr!=NULL){
    if(ptr->id == idBuscar){ //evalua el id a buscar por el usuario con el del nodo

      if(ptr->left && ptr->right){//Si el nodo tiene hijo izq y derech
         Node menor = encontrarMinimo(ptr->right);
         Node padre = buscarPadre(ptr2,menor->id);
         ptr->id = menor->id;
         ptr->nombre = menor->nombre;
         ptr->direccion = menor->direccion;
         ptr->email = menor->direccion;
         padre->left = NULL;
         padre->right = NULL;
         delete (menor);
         return 0;
      }
      else if(ptr->left){//si tiene hijo izq
        Node padre = buscarPadre(ptr2,idBuscar);
        padre->left = ptr->left;
        ptr->left = NULL;
        ptr->right = NULL;
        delete (ptr);
        return 0;
      }
      else if(ptr->right){//si tiene hijo der
        Node padre = buscarPadre(ptr2,idBuscar);
        padre->right = ptr->right;
        ptr->left = NULL;
        ptr->right = NULL;
        delete (ptr);
        return 0;
      }
      else{//No tiene hijos
        Node padre = buscarPadre(ptr2,idBuscar);
        padre->left = NULL;
        padre->right = NULL;
        delete (ptr);
        return 0;
      }
        return 0;
  		system("pause");
    }else if(idBuscar < ptr->id){ 	//
  		return deleteContact(ptr->left, ptr2 ,idBuscar);
  	}else{
      return deleteContact(ptr->right, ptr2 ,idBuscar);
    }
  }else{
    std::cout <<'\n'<< "NO SE ENCONTRO EL ID REGISTRADO" << '\n'<< '\n'<< '\n';
    system("pause");
    return 0;
  }
}//FIN BORRAR CONTACTO




int main(int argc, char** argv) {
  Node ptr = NULL;
  int op,band=0, band2=0, *ptrvalidar,id,idBuscar;
  char validar[256], id_[10], nombre_[50], direccion_[50], email_[50],idBuscar_[10];
  string nombre, direccion, email;


  do{
    system("cls");
    std::cout << "-------ARBOL------"<< std::endl;
    std::cout << "1. CREAR NUEVOS NODOS" << '\n';
    std::cout << "2. ORDENAR PRE ORDEN" << '\n';
    std::cout << "3. ORDENAR IN ORDER" << '\n';
    std::cout << "4. ORDENAR POST ORDER" << '\n';
    std::cout << "5. BUSCAR NODO POR ID" << '\n';
    std::cout << "6. MODIFICAR DATOS DE UN NODO" << '\n';
    std::cout << "7. ELIMINAR UN NODO" << '\n';
    std::cout << "8. MOSTRAR EL ARBOL" << '\n';
    std::cout << "9. SALIR" << '\n'<< '\n'<< '\n';
    std::cout << "TU OPCION ES: ";
    fflush(stdin);
    gets(validar);
    op = atoi(validar);

    switch (op) {
      case 1:
        do{
          system("cls");
          std::cout << "-------CREAR NUEVO NODO------" << '\n';
          std::cout << "INGRESE EL ID DEL CONTACTO" << '\n';
          fflush(stdin);
          gets(id_);
          ptrvalidar = &band2;
          validarNumero(id_,ptrvalidar);
        }while(band2==0);
        id = atoi(id_);

        std::cout << "INGRESE EL NOMBRE DEL CONTACTO" << '\n';
        fflush(stdin);
        gets(nombre_);
        for(int i=0; nombre_[i] != '\0';i++){ //nombre a mayusculas
          nombre_[i] = toupper(nombre_[i]);
        }
        nombre = nombre_;


        std::cout << "INGRESE LA DIRECCION DEL CONTACTO" << '\n';
        fflush(stdin);
        gets(direccion_);
        for(int i=0; direccion_[i] != '\0';i++){ //direccion a mayusculas
          direccion_[i] = toupper(direccion_[i]);
        }
        direccion = direccion_;


        std::cout << "INGRESE EL EMAIL DEL CONTACTO" << '\n';
        fflush(stdin);
        gets(email_);
        for(int i=0; email_[i] != '\0';i++){ //email a mayusculas
          email_[i] = toupper(email_[i]);
        }
        email = email_;

        add(ptr, id,nombre, direccion, email);
      break;

      case 2:
        if(ptr==NULL){
          system("cls");
          std::cout << "NO HAY CONTACTOS AGREGADOS" << '\n'<< '\n';
          system("pause");
        }else{
          preOrden(ptr);
          std::cout << '\n' << '\n';
          system("pause");
        }
      break;

      case 3:
        if(ptr==NULL){
          system("cls");
          std::cout << "NO HAY CONTACTOS AGREGADOS" << '\n'<< '\n';
          system("pause");
        }else{
          enOrden(ptr);
          std::cout << '\n' << '\n';
          system("pause");
        }

      break;

      case 4:
        if(ptr==NULL){
          system("cls");
          std::cout << "NO HAY CONTACTOS AGREGADOS" << '\n'<< '\n';
          system("pause");
        }else{
          postOrden(ptr);
          std::cout << '\n' << '\n';
          system("pause");
        }
      break;

      case 5:
        band2=0;
        system("cls");
        if(ptr==NULL){
          std::cout << "NO HAY CONTACTOS AGREGADOS" << '\n'<< '\n';
          system("pause");
        }else{
          do{
            std::cout << "-------BUSCAR CONTACTO POR ID------" << '\n';
            std::cout << "INGRESE EL ID QUE DESEA BUSCAR" << '\n';
            gets(idBuscar_);
            ptrvalidar = &band2;
            validarNumero(idBuscar_, ptrvalidar);
          }while(band2==0);
          idBuscar = atoi(idBuscar_);
          search(ptr,idBuscar);
        }
      break;

      case 6: //EDITAR

          if(ptr==NULL){
            system("cls");
            std::cout << "NO HAY CONTACTOS AGREGADOS" << '\n'<< '\n';
            system("pause");
          }else{
            do{
              system("cls");
              std::cout << "-------MODIFICAR CONTACTO------"<< '\n';
              std::cout << "INGRESE EL ID QUE DESEA EDITAR" << '\n';
              gets(idBuscar_);
              ptrvalidar = &band2;
              validarNumero(idBuscar_, ptrvalidar);
            }while(band2==0);
            idBuscar = atoi(idBuscar_);
            edit(ptr, idBuscar);
          }
      break;

      case 7:
        if(ptr==NULL){
          system("cls");
          std::cout << "NO HAY CONTACTOS AGREGADOS" << '\n'<< '\n';
          system("pause");
        }else{
          do{
            system("cls");
            std::cout << "-------ELIMINAR CONTACTO POR ID------" << '\n';
            std::cout << "INGRESE EL ID DEL CONTACTO QUE DESEA ELIMINAR" << '\n';
            gets(idBuscar_);
            ptrvalidar = &band2;
            validarNumero(idBuscar_, ptrvalidar);
          }while(band2==0);
          idBuscar = atoi(idBuscar_);
          deleteContact(ptr,ptr,idBuscar);
        }
      break;

      case 8:
        if(ptr==NULL){
          system("cls");
          std::cout << "NO HAY CONTACTOS AGREGADOS" << '\n'<< '\n';
          system("pause");
        }else{
          show(ptr, 0);
          system("pause");
        }
      break;

      case 9:
        band=1;
      break;

      default:
        system("cls");
        std::cout << "LO INGRESADO NO ES VALIDO" << '\n';
        system("pause");
      break;
    }
  }while(band==0);
}//Fin main



int validarNumero(char numero[], int *band2){
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
