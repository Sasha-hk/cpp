#include "stack.h"
#include <iostream>

using namespace std;

Stack::Stack() {}

Stack::Stack(int maxSize) {
  this->maxSize = maxSize;
  this->stack = new int[this->maxSize];
}

void Stack::push(int data) {
  if (size != maxSize) {
    this->stack[size] = data;
    this->size++;
  }
  else {
    int* temp = new int[this->maxSize];
    temp = this->stack;
    delete[] this->stack;
    this->stack = new int[maxSize*2];

    for (int i = 0; i < size; i++) {
      this->stack[i] = temp[i];
    }

    this->maxSize *= 2;
    this->stack[this->size] = data;
    this->size++;
  }
}

int Stack::pop() {
  this->size--;
  return this->stack[this->size];
}

int Stack::getSize() {
  return this->size;
}

int Stack::getMaxSize() {
  return this->maxSize;
}
