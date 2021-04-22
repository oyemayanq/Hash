#ifndef HASHITEM_H
#define HASHITEM_H

template <class a,class b>
class HashItem{
  private:
    a key;
    b value;
  public:
    HashItem();
    HashItem(a,b);

    void setKey(a);
    void setValue(b);
    void setItem(a,b);

    a getKey();
    b getValue();
};

template <class a,class b>
HashItem<a,b>::HashItem(){
  //Do Nothing
}

template <class a,class b>
HashItem<a,b>::HashItem(a key,b value){
  this->key = key;
  this->value = value;
}

template <class a,class b>
void HashItem<a,b>::setKey(a key){
  this->key = key;
}

template <class a,class b>
void HashItem<a,b>::setValue(b value){
  this->value = value;
}

template <class a,class b>
void HashItem<a,b>::setItem(a key,b value){
  setKey(key);
  setValue(value);
}

template <class a,class b>
a HashItem<a,b>::getKey(){
  return key;
}

template <class a,class b>
b HashItem<a,b>::getValue(){
  return value;
}

#endif
