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

    Stack(int size) {
      this->maxSize = size;
      this->stack = new int[this->maxSize];
    }

    void push(int data) {
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

    int pop() {
      this->size--;
      return this->stack[this->size];
    }

    int peek() {
      return this->stack[this->size - 1];
    }

    int getMaxSize() {
      return this->maxSize;
    }

    int getSize() {
      return this->size;
    }

    ~Stack() {
      delete[] stack;
    }
};

#endif
