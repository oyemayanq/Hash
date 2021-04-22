#ifndef HASH_H
#define HASH_H

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
#include "hashitem.h"


template <class a,class b>
class Hash{
  private:
    int size;
    int count;
    HashItem<a,b>** items;
  public:
    Hash();
    ~Hash();

    int hashFunction(a key);
    int getSize();
    void insert(a key,b value);
    b search(a key);
    void remove(a key);
};

template <class a,class b>
Hash<a,b>::Hash(){
  size = 100;
  count = 0;
  items = new HashItem<a,b>*[size];
  items[0] = NULL;
  for(int i=0;i<size;i++)
    items[i] = NULL;
}

template <class a,class b>
int Hash<a,b>::getSize(){
  return size;
}

template <class a,class b>
int Hash<a,b>::hashFunction(a key){
  int n = this->getSize();
  string res = "";
  if(*typeid(key).name() == 'i'){
    while(key != 0){
      int z = key%10;
      key = key/10;
      res = (char)(z + 48)  + res;
    }
  }
  int val = 0;
  for(int i=0;res[i] != '\0';i++)
    val = val + res[i]%48;
  return val % n;
}

template <class a,class b>
void Hash<a,b>::insert(a key,b value){
  int index = this->hashFunction(key);
  HashItem<a,b>* item = new HashItem<a,b>();
  if(items[index] == NULL){
    item->setItem(key,value);
    items[index] = item;
    return;
  }
  if(items[index]->getKey() == key){
    items[index]->setValue(value);
    return;
  }
  int i = 1;
  while(items[index] != NULL){
    index = (index + i*index)%size;
  }
  item->setItem(key,value);
  items[index] = item;
}

template <class a,class b>
b Hash<a,b>::search(a key){
  int index = this->hashFunction(key);
  if(items[index] != NULL){
    if(items[index]->getKey() == key)
      return items[index]->getValue();
    else{
      int i = 1;
      while(items[index] != NULL){
        index = (index + i*index)%size;
        if(items[index] == NULL)
          break;
        if(items[index]->getKey() == key)
          return items[index]->getValue();
      }
    }
  }
  std::cout<<"Key: \" "<<key<<" \" does not exist"<<endl;
  exit(1);
}

template <class a,class b>
void Hash<a,b>::remove(a key){
  int index = this->hashFunction(key);
  if(items[index] == NULL)
    return;
  if(items[index]->getKey() == key)
    items[index] = NULL;
  else{
    int i = 1;
    while(items[index] != NULL && items[index]->getKey() != key){
      index = (index + i*index)%size;
      i++;
    }
    items[index] = NULL;
  }
}

template <class a,class b>
Hash<a,b>::~Hash(){
  for(int i=0;i<this->getSize();i++)
    delete items[i];
  delete[] items;
}

#endif
