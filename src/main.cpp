#include <dlfcn.h>
#include <errno.h>
#include <iostream>
#include <string.h>
#include "header.h"

using namespace std;

void *handle;
ISortInterface *(*create)();
void (*destroy)(ISortInterface *);

void load_lib(const char *name) {
  handle = dlopen(name, RTLD_LAZY);

  if (!handle) {
    cout << dlerror() << endl;
  }

  create = (ISortInterface * (*)())dlsym(handle, "create_object");
  if (!create) {
    cout << dlerror() << endl;
  }

  destroy = (void (*)(ISortInterface *))dlsym(handle, "destroy_object");
  if (!destroy) {
    cout << dlerror() << endl;
  }
}

void dosomething() {
  ISortInterface *obj = create();
  obj->function();
  destroy(obj);
}

int main(int argc, char *argv[]) {
  load_lib("/home/tk/tmp/dynamic_loading/libs/liba.so");
  dosomething();

  load_lib("/home/tk/tmp/dynamic_loading/libs/libb.so");
  dosomething();
  return 0;
}
