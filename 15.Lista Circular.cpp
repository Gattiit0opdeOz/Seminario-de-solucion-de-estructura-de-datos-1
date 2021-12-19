/*
Autor:
Fecha de creacion: 26 de octubre de 2021
Fecha de ult mod: 26 de octubre de 2021
lista doblemente enlazada
*/


#include <iostream>
using namespace std;

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
    void remove(int );
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
      cout<<temp->number <<"-";
      temp = temp->next;
    } while (temp != ptrHead);
  cout << "\n";
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
      for (int f = 1; f <= position- 1; f++){
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


int main(int argc, char** argv) {
  CircularList *obj = new CircularList();
  obj->insert_First(1);
  obj->insert_First(2);
  obj->insert_First(3);
  cout <<"Nodos Insertados\n";
  obj->print();

  obj->insert_Last(4);
  obj->insert_Last(5);
  obj->insert_Last(6);
  cout<<"Nodos Insertados\n";

  obj->print();
  cout<<"Recorrido:" <<obj->travel() <<"\n";
  cout <<"Remover la primer position:\n";
  obj->remove(3);
  obj->print();

  delete obj;
  return 0;
}
