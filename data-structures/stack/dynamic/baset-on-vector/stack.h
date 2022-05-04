#pragma stack
#ifndef STACK_H
#define STACK_H

#include <vector>

using std::vector;

/**
 * Stack data structure
 */
template <class Type> class Stack {
  private:
    vector<Type> stack;

  protected:
    int capacity;
    int top;

  public:
    /**
     * Defalt constructor
     */
    Stack() {
      this->capacity = 0;
      this->top = 0;
    }

    /**
     * Push data to stack
     * @param data Data
     */
    void push(Type data) {
      if (top == capacity) {
        this->stack.push_back(data);
        this->top++;
      }
      else {
        this->stack[this->top] = data;
        this->top++;
      }
    }

    /**
     * Pop item
     */
    Type pop() {
      this->top--;
      return this->stack[this->top];
    }

    /**
     * Peek item
     */
    Type peek() {
      return this->stack[this->top - 1];
    }

    /**
     * Get current max
     */
    bool isFull() {
      return this->capacity == this->top;
    }

    /**
     * Check if stack if full
     */
    bool isEmpty() {
      return 0 == this->top;
    }

    /**
     * Check if stack is empty
     */
    int size() {
      return this->capacity;
    }
};

#endif
