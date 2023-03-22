// g++.exe -fdiagnostics-color=always -g ./main.cpp -o ./main.exe && ./main.exe
// gcc main.cpp -o main.exe -lstdc++

#include <iostream>

#include "function.h"

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