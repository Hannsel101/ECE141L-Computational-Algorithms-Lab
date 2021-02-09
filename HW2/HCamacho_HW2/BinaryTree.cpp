#include "BinaryTree.h"

//******************************************************************
//******************************************************************
BinaryTree::BinaryTree()
{
    root = nullptr;
}
//******************************************************************
BinaryTree::~BinaryTree()
{

}
//******************************************************************
void BinaryTree::insert(int value)
{
    Node<int>* newNode = new Node<int>;
    newNode->data = value;

    if (root == nullptr) // Empty list case
    {
        root = newNode;
    }
    else// All other cases
    {
        Node<int>* iter = root;

        while (iter != nullptr)
        {
            if (iter->data > value)// New node is less than current node
            {
                if (iter->prev == nullptr)// Insert if empty spot found
                {
                    iter->prev = newNode;
                    return;
                }
                iter = iter->prev;
            }
            else if (iter->data < value)// New node is greater than current
            {
                if (iter->next == nullptr)// Insert if empty spot found
                {
                    iter->next = newNode;
                    return;
                }
                iter = iter->next;
            }
            else// New node already exist in the tree
            {
                delete newNode;
                return;
            }
        }
    }
}
//******************************************************************
bool BinaryTree::contains(int value)
{
    if (root == nullptr)
    {
        return false;
    }

    Node<int>* iter = root;
    while (iter != nullptr)
    {
        if (iter->data == value)// Value found
        {
            return true;
        }
        else if (iter->data > value)// Search left
        {
            if (iter->prev == nullptr)
                return false;
            iter = iter->prev;
        }
        else if (iter->data < value)// Search right
        {
            if (iter->next == nullptr)
                return false;
            iter = iter->next;
        }
    }
}
//******************************************************************
bool BinaryTree::contains(int value, Node<int>*& iter)
{
    iter = root;
    if (root == nullptr)
    {
        return false;
    }

    while (iter != nullptr)
    {
        if (iter->data == value)// Value found
        {
            return true;
        }
        else if (iter->data > value)// Search left
        {
            if (iter->prev == nullptr)
                return false;
            iter = iter->prev;
        }
        else if (iter->data < value)// Search right
        {
            if (iter->next == nullptr)
                return false;
            iter = iter->next;
        }
    }
}
//******************************************************************
int BinaryTree::getMin()
{
    // No members exist
    if (root == nullptr)
        return -2000000;

    // Iterate to the left as far as possible to find min
    Node<int>* iter = root;
    while (iter->prev != nullptr)
        iter = iter->prev;
    return iter->data;
}
//******************************************************************
int BinaryTree::getMax()
{
    // No members exist
    if (root == nullptr)
        return -2000000;

    // Iterate to the right as far as possible to find max
    Node<int>* iter = root;
    while (iter->next != nullptr)
        iter = iter->next;
    return iter->data;
}
//******************************************************************
void BinaryTree::removeNode(int value)
{
    if (root == nullptr)
    {
        cout << "Cannot remove from empty list\n";
        return;
    }

    Node<int>* curr = root;
    Node<int>* prev = curr;
    if (root->data == value)// Root node is to be deleted
    {
        if (root->next == nullptr && root->prev == nullptr)
        {
            delete root;
            root = nullptr;
        }
        else if (root->next == nullptr)
        {
            root = root->prev;
            curr->prev = nullptr;
            delete curr;
        }
        else if (root->prev == nullptr)
        {
            root = root->next;
            curr->next = nullptr;
            delete curr;
        }
        else
        {

        }
    }
}
//******************************************************************
bool BinaryTree::isBalanced()
{
    return true;
}
//******************************************************************
int BinaryTree::getHeight()
{
    if (root == nullptr)
        return 0;
}
//******************************************************************
DoublyLinkedList<int>* BinaryTree::splitLeft()
{
    DoublyLinkedList<int>* newList = new DoublyLinkedList<int>();
    Node<int>* newRoot = root;

    if (newRoot->prev == nullptr)
        return nullptr;

    // Make first left node the new root of the new list and trim it off
    // from the original tree
    newRoot = newRoot->prev;
    root->prev = nullptr;

    // Create iterators
    Node<int>* curr = newRoot;
    Node<int>* prev = newRoot;
    
    //while ((newRoot->prev) || (newRoot->next))
    //{
        // Go to the farthest left node
        //while()
       
    //}
    return nullptr;
}
//******************************************************************
Node<int>* BinaryTree::splitRight()
{
    return nullptr;
}
//******************************************************************
Node<int>* BinaryTree::popRoot()
{
    return nullptr;
}
//******************************************************************
Node<int>* BinaryTree::inOrderPrint(Node<int>* node)
{
    if (node == nullptr)
        return nullptr;

    inOrderPrint(node->prev);

    cout << node->data << " ";

    inOrderPrint(node->next);

    return nullptr;
}

void BinaryTree::printInorder()
{
    inOrderPrint(root);
}
//******************************************************************
void BinaryTree::unrollRight(Node<int>* root)
{
    Node<int>* curr;
    Node<int>* prev;
    curr = root;
    prev = curr;

    if (curr->next == nullptr)
        return;

    curr = curr->next;

    while (curr->next != nullptr || curr->prev != nullptr)
    {
        while (curr->prev != nullptr)
        {
            Node<int>* temp = curr->prev;
            if (temp->next == nullptr)
            {        
                    temp->next = curr;
                    prev->next = temp;
                    curr->prev = nullptr;
                    curr = temp;    
            }
            else if (temp->next != nullptr)
            {
                Node<int>* iter = temp->next;
                while (iter->prev != nullptr)
                    iter = iter->prev;
                iter->prev = temp;
                curr->prev = temp->next;
                temp->next = nullptr;
            }
        }
        prev = curr;
        curr = curr->next;
    }
}

void BinaryTree::unrollLeft(Node<int>* root)
{
    Node<int>* curr;
    Node<int>* prev;
    curr = root;
    prev = curr;

    if (curr->prev == nullptr || curr == nullptr)
        return;

    curr = curr->prev;

    while (curr->next != nullptr || curr->prev != nullptr)
    {
        while(curr->next != nullptr)
        {
            Node<int>* temp = curr->next;
            if (temp->prev == nullptr)
            {
                temp->prev = curr;
                prev->prev = temp;
                curr->next = nullptr;
                curr = temp;
            }
            else if (temp->prev != nullptr)
            {
                Node<int>* iter = temp->prev;
                while (iter->next != nullptr)
                    iter = iter->next;
                iter->next = temp;
                curr->next = temp->prev;
                temp->prev = nullptr;
            }
        }
        prev = curr;
        curr = curr->prev;
    }
}
void BinaryTree::unrollTree()
{
    unrollRight(root);
    unrollLeft(root);
}

void BinaryTree::createCircular(CircularLinkedList<int>& newList)
{
    // flatten each side of the binary tree
    unrollTree();

    // Configure the pointer references from the left and right of the 
    // tree to form a doubly linked list
    Node<int>* iter = root;
    Node<int>* prevIter = iter;

    // Configure the left side
    while (iter->prev != nullptr)
    {
        iter = iter->prev;
        iter->next = prevIter;
        prevIter = iter;
    }

    iter = root;
    prevIter = iter;
    
    // Configure the right side
    while (iter->next != nullptr)
    {
        iter = iter->next;
        iter->prev = prevIter;
        prevIter = iter;
    }

    //configure the head and tail of the doubly linked list
    while (root->prev != nullptr)
        root = root->prev;

    
    newList.setHead(root);
    root = nullptr;
}