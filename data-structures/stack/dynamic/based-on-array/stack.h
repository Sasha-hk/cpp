#pragma stack
#ifndef STACK_H
#define STACK_H

/**
 * Stack data structure
 */
template <class Type> class Stack {
  private:
    Type* stack;
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
     * Stack constructor
     * @param capacity Max count of items before expanding the stack
     */
    Stack(int capacity) {
      this->top = 0;
      this->capacity = capacity;
      this->stack = new Type[this->capacity];
    }

    /**
     * Push data to stack
     * @param data Data
     */
    void push(Type data) {
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
      return this->stack[this->top];
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

    /**
     * Stack destructor
     */
    ~Stack() {
      delete[] stack;
    }
};

#endif
