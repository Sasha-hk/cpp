#include "stack.h"

template <class Type>
Stack<Type>::Stack() {
  this->capacity = 0;
  this->top = 0;
}

template <class Type>
Stack<Type>::Stack(int capacity) {
  this->top = 0;
  this->capacity = capacity;
  this->stack = new Type[this->capacity];
}

template <class Type>
void Stack<Type>::push(Type data) {
  // Check if stack size enough
  if (this->capacity != this->top) {
    this->stack[this->top] = data;
    this->top++;
  }
  else {
    // Create new pointer to save old stack
    Type* temp = this->stack;
    this->capacity *= 2;

    // Create new stack twice large
    this->stack = new Type[this->capacity];

    // Copy old stack to new
    for (int i = 0; i < top; i++) {
      this->stack[i] = temp[i];
    }

    // Delete old stack
    delete[] temp;

    // Push data
    this->stack[this->top] = data;
    top++;
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
int Stack<Type>::size() {
  return this->capacity;
}

template <class Type>
bool Stack<Type>::isFull() {
  return this->capacity == this->top;
}

template <class Type>
bool Stack<Type>::isEmpty() {
  return 0 == this->top;
}

template <class Type>
Stack<Type>::~Stack() {
  delete[] stack;
}
