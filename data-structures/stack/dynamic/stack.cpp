#include "stack.h"
#include <iostream>

using namespace std;

template <class Type>
Stack<Type>::Stack() {}

template <class Type>
Stack<Type>::Stack(int capacity) {
  this->top = 0;
  this->capacity = capacity;
  this->stack = new Type[this->capacity];
}

template <class Type>
void Stack<Type>::push(Type data) {
  if (capacity != top) {
    this->stack[top] = data;
    this->top++;
  }
  else {
    int* temp = new int[this->top];
    temp = this->stack;
    delete[] this->stack;
    this->stack = new int[capacity * 2];

    for (int i = 0; i < top; i++) {
      this->stack[i] = temp[i];
    }

    delete[] temp;

    this->capacity *= 2;
    this->stack[this->top] = data;
    this->top++;
  }
}

template <class Type>
Type Stack<Type>::pop() {
  this->top--;
  return this->stack[this->top];
}

template <class Type>
Type Stack<Type>::peek() {
  return this->stack[this->top];
}

template <class Type>
bool Stack<Type>::isFull() {
  return capacity == top;
}

template <class Type>
bool Stack<Type>::isEmpty() {
  return 0 == top;
}

template <class Type>
int Stack<Type>::size() {
  return this->capacity;
}

template <class Type>
Stack<Type>::~Stack() {
  delete[] this->stack;
}