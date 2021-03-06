#pragma once

#ifndef TREE
#define TREE

#include <cstddef>

/**
 * Node structure
 *
 * @param left node
 * @param data node data
 * @param right node
 */
template <class Type> struct Node {
  struct Node<Type>* left;
  Type data;
  struct Node<Type>* right;
};

/**
 * Binary tree data structure
 */
template <class Type> class Tree {
  private:
    /**
     * Root node
     */
    Node<Type>* root;

    /**
     * Destroy tree
     *
     * @param node node to delete
     */
    void destroyTree(Node<Type>* node) {
      if (node->left) {
        destroyTree(node->left);
      }

      if (node->right) {
        destroyTree(node->right);
      }

      delete node;
    }

  public:

    /**
     * Constructor
     *
     * @param data data for root node
     */
    Tree(Type data) {
      Node<Type>* node = new Node<Type>({
        NULL,
        data,
        NULL
      });

      root = node;
    }

    /**
     * Search in the tree
     *
     * @param data to find
     * @return it returns the value closest to the desired one
     */
    Node<Type>* search(Type data) {
      // Node to compare data
      Node<Type>* compare = root;

      // Find node to insert new
      while (true) {
        // Break if data is found
        if (compare->data == data) {
          break;
        }

        // Define the side to continue the search
        if (compare->data > data) {
          if (compare->left == NULL) {
            break;
          }
          else {
            compare = compare->left;
            continue;
          }
        }
        else if (compare->data < data) {
          if (compare->right == NULL) {
            break;
          }
          else {
            compare = compare->right;
            continue;
          }
        }

        break;
      }

      return compare;
    }

    /**
     * Get element
     *
     * @param data to find
     * @return If element exists return the element else return NULL
     */
    Node<Type>* get(Type data) {
      Node<Type>* foundNode = search(data);

      if (foundNode->data == data) {
        return foundNode;
      }

      return NULL;
    }

    /**
     * Insert element into the tree
     *
     * @param data data to insert
     */
    void insert(Type data) {
      // Find the node to insert
      Node<Type>* node = search(data);

      // Create new node
      Node<Type>* newNode = new Node<Type>({
        NULL,
        data,
        NULL
      });

      // Define the side to insert new node
      if (node->data > data) {
        node->left = newNode;
      }
      else if (node->data < data) {
        node->right = newNode;
      }
    }

    /**
     * Destructor
     */
    ~Tree() {
      destroyTree(root);
    }
};

#endif
