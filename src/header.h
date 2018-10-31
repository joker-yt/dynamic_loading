#ifndef __HEADER_H__
#define __HEADER_H__

#include <string>
using namespace std;

class ISortInterface {
private:
  /* data */

public:
  ISortInterface(){};
  virtual ~ISortInterface(){};
  virtual int function() { return 0; };
};

#endif /* end of include guard: __HEADER_H__ */
