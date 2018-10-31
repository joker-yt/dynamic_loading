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

extern "C" ISortInterface *create_object() { return new CSortTest; }
extern "C" void destroy_object(ISortInterface *obj) { delete obj; }
