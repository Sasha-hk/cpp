#pragma stack
#ifndef STACK_H
#define STACK_H

template <class Type> class Stack {
  private:
    Type* stack;
  protected:
    int capacity;
    int top;

  public:
    Stack();
    Stack(int capacity);

    void push(Type data);

    Type pop();

    Type peek();

    bool isFull();

    bool isEmpty();

    int size();

    ~Stack();
};

#endif 