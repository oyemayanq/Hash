#include <iostream>
#include "../include/complex.h"
#include "../include/hash.h"

using namespace std;

int main(){
  Hash<int,int> h;
  h.insert(1,10);
  h.insert(10,1);
  h.remove(2);
  return 0;
}
