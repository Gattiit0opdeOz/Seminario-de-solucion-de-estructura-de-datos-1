/*
Autor:
Fecha de creacion: 19 de octubre de 2021
Fecha de ult mod: 19 de octubre de 2021
lista doblemente enlazada
*/

#include <iostream>
using namespace std;


template<class TIPO> class List;
template<class TIPO>
class Node {
public:
  Node(TIPO v, Node<TIPO> *pnext = NULL, Node<TIPO> *pprev = NULL) : value(v), ptrNext(pnext), ptrPrev(pprev) {}
private:
  TIPO value;
  Node<TIPO> *ptrNext;
  Node<TIPO> *ptrPrev;
  friend class List<TIPO>; // funcion amiga que permite sobrecargar la lista
};

template<class TIPO>
class List { // objeto lista
public:
  List() : ptrList(NULL) {}
  ~List();
  void Add(TIPO v);
  void remove(TIPO v);
  bool Empty() { return ptrList == NULL; }
  void print();
  void ptrNext();
  void ptrPrev();
  void First();
  void Last();
  bool Current() { return ptrList != NULL; }
  TIPO CurrentValue() { return ptrList->value; }
private:
  Node<TIPO> *ptrList; // puntero de la lista
};

template<class TIPO>
List<TIPO>::~List(){ // Destructor de lca clase

  Node<TIPO> *aux;
  First();
  while(ptrList) {
    aux = ptrList;
    ptrList = ptrList->ptrNext;
    delete aux;
  }
}

template<class TIPO>
void List<TIPO>::Add(TIPO v){ // Agregar al Nodo
  Node<TIPO> *ptrNew;
  First(); // Metodo que permite insertar al inicio de la lista
  if(Empty() || ptrList->value > v) {
    ptrNew = new Node<TIPO>(v, ptrList);
    if(!ptrList){
      ptrList = ptrNew;
    }else{
      ptrList->ptrPrev = ptrNew;
    }
  }else{
    // se mueve hasta el último nodo que tenva un valor mayor
    while(ptrList->ptrNext && ptrList->ptrNext->value <= v) {
      ptrNext();
    }
    ptrNew = new Node<TIPO>(v, ptrList->ptrNext, ptrList);
    ptrList->ptrNext = ptrNew;
    if(ptrNew->ptrNext){
      ptrNew->ptrPrev = ptrNew;
    }
  }
}


template<class TIPO>
void List<TIPO>::remove(TIPO v){
Node<TIPO> *ptrNode;
  First();
  ptrNode = ptrList;
  while(ptrNode && ptrNode->value < v) {
    ptrNode = ptrNode->ptrNext;
  }
  while(ptrNode && ptrNode->value > v) {
    ptrNode = ptrNode->ptrPrev;
  }
  if(ptrNode->value != v){
    return;
  }
  if(ptrNode->ptrPrev){ // no es el primer elemento
      ptrNode->ptrPrev->ptrNext = ptrNode->ptrNext;
    }
  if(ptrNode->ptrNext){ // no el último Node
    ptrNode->ptrPrev = ptrNode->ptrNext;
  }
}


template<class TIPO>
void List<TIPO>::print(){
Node<TIPO> *ptrNode;
  First();
  ptrNode = ptrList;
  while(ptrNode!=NULL) {
    cout << ptrNode->value << "-> ";
    ptrNode=ptrNode->ptrNext;
  }
  cout << endl;
}


template<class TIPO>
void List<TIPO>::ptrNext(){
  if(ptrList) {
    ptrList = ptrList->ptrNext;
  }
}


template<class TIPO>
void List<TIPO>::ptrPrev(){
  if(ptrList) {
    ptrList = ptrList->ptrPrev;
  }
}


template<class TIPO>
void List<TIPO>::First(){
  while(ptrList && ptrList->ptrPrev) {
    ptrList = ptrList->ptrPrev;
  }
}


template<class TIPO>
void List<TIPO>::Last(){
  while(ptrList && ptrList->ptrNext) {
    ptrList = ptrList->ptrNext;
  }
}


int main(int argc, char** argv) {
  List<int> list;
  list.Add(10);
  list.Add(20);
  list.Add(30);
  list.Add(40);
  list.print();
  list.First();
  cout << "First Node: " << list.CurrentValue() << endl;
  list.Last();
  cout << "Last Node: " << list.CurrentValue() << endl;
  cout << "Insert new nodes: 80,85"<<endl;
  list.Add(80);
  list.Add(85);
  list.print();
  list.First();
  cout << "First Node: " << list.CurrentValue() << endl;
  list.Last();
  cout << "Last Node: " << list.CurrentValue() << endl;
  cout << "remove Node: 40"<<endl;
  list.remove(40);
  list.print();
  return 0;
}
