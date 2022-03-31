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
    Stack();

    /**
     * Stack constructor
     * @param capacity Max count of items before expanding the stack
     */
    Stack(int capacity);

    /**
     * Push data to stack
     * @param data Data
     */
    void push(Type data);

    /**
     * Pop item
     */
    Type pop();

    /**
     * Peek item
     */
    Type peek();

    /**
     * Get current max
     */
    bool isFull();

    /**
     * Check if stack if full
     */
    bool isEmpty();

    /**
     * Check if stack is empty
     */
    int size();

    /**
     * Stack destructor
     */
    ~Stack();
};

#endif
