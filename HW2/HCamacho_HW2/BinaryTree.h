#pragma once
#include "Node.h"
#include "DoublyLinkedList.h"
#include "CircularLinkedList.h"
#include <iostream>

using namespace std;

class BinaryTree
{
    public:
        BinaryTree();
        ~BinaryTree();

        void insert(int value);
        // Inserts new node in the binary search tree

        bool contains(int value);
        // Returns true if value is found in the tree

        bool contains(int value, Node<int>*& iter);
        // Overloaded contains function that returns a reference
        // pointing to the nodes location

        int getMin();
        // Returns the minimum value stored in the tree

        int getMax();
        // Returns the maximum value stored in the tree

        void removeNode(int value);
        // Remove the node with the given value

        bool isBalanced();
        // Returns true if both sides of the tree are of similar depth

        int getHeight();
        // Returns the depth of the tree

        DoublyLinkedList<int>* splitLeft();
        // Cuts the left half off of a binary tree. leaving only the right
        // Half intact.

        Node<int>* splitRight();
        // Cuts the right half off of a binary tree. leaving only the left
        // half intact.

        Node<int>* popRoot();
        // Pops the root off of a binary tree. Only works for trees of size 1

        void printInorder();

        void unrollTree();

        void createCircular(CircularLinkedList<int>& newList);
    private:
        Node<int>* root;
    protected:
        Node<int>* inOrderPrint(Node<int>* node);
        void unrollRight(Node<int>* root);
        void unrollLeft(Node<int>* root);
};

