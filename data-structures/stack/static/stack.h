#pragma stack
#ifndef STACK_H
#define STACK_H

class Stack {
  private:
  protected:
    int* stack;
    int maxSize = 10;
    int size = 0;

  public:
    Stack();
    Stack(int size);

    void push(int data);

    int pop();

    int getMaxSize();

    int getSize();

    ~Stack() {
      delete[] stack;
    }
};

#endif 