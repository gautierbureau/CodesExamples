#include <stdlib.h>
#include <stdio.h>
#include <dlfcn.h>
#include <iostream>

typedef int num_t1();
typedef int num_t2();

int main() {

  void* handle1;
  void* handle2;
  char* error;

  handle1 = dlopen ("./foo1.so", RTLD_NOW);
  if (!handle1) {
    fputs (dlerror(), stderr);
    exit(1);
  }

  num_t1* num_func1 = reinterpret_cast<num_t1*>(dlsym(handle1, "num"));
  if ((error = dlerror()) != NULL)  {
    fputs(error, stderr);
    exit(1);
  }

  handle2 = dlopen ("./foo2.so", RTLD_NOW);
  if (!handle2) {
    fputs (dlerror(), stderr);
    exit(1);
  }

  num_t2* num_func2 = reinterpret_cast<num_t2*>(dlsym(handle2, "num"));
  if ((error = dlerror()) != NULL)  {
    fputs(error, stderr);
    exit(1);
  }

  std::cout << num_func1() << std::endl;
  std::cout << num_func2() << std::endl;

  return 0;
}
