// gcc -c function.cpp
// ar -r lib_function.lib function.o 生成静态链接库
// gcc -o main.exe main.cpp lib_function.lib -lstdc++ 或者
// 使用-L选项指定静态库的路径，使用-l选项指定静态库的名称（不包括lib和.a），例如：gcc -o test.out test.c -L. -ltestlib：
// gcc -o main.exe main.cpp -L. -llib_function -lstdc++

#include <iostream>

// #include "function.h"

extern int func();

class Animal {
  public:
    void say();
};

void Animal::say() {
  std::cout << "Animal say Hello World! \n";
};

class Dog: public Animal {
  public:
    void say() {
      std::cout << "Dog say Hello World! \n";
    }
};

int main() {
  Animal myAnimal;
  myAnimal.say();

  Dog myDog;
  myDog.say();

  func();
};