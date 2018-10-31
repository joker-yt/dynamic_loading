#include "header.h"

#include <iostream>

using namespace std;

class CSortTest : public ISortInterface {
private:
public:
  CSortTest(){};
  virtual ~CSortTest(){};
  int function() {
    cout << "this is liba sort function" << endl;
    return 0;
  }
};

extern "C" ISortInterface *create_object() {
  ISortInterface *p = new CSortTest;
  return p;
}
extern "C" void destroy_object(ISortInterface *obj) { delete obj; }
