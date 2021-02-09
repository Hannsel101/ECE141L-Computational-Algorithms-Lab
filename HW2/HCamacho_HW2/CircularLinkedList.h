#pragma once
#include "DoublyLinkedList.h"


template<class type>
class CircularLinkedList :
    public DoublyLinkedList<type>
{
public:
    CircularLinkedList();
    ~CircularLinkedList();
    void setHead(Node<type>* root);
    void print();
private:
    Node<int>* head;
    Node<int>* tail;
    int size;
protected:
};

template<class type>
CircularLinkedList<type>::CircularLinkedList()
    :DoublyLinkedList<type>()
{
    head = nullptr;
    tail = nullptr;
    size = 0;
}


template<class type>
CircularLinkedList<type>::~CircularLinkedList()
{

}

template<class type>
void CircularLinkedList<type>::setHead(Node<type>* root)
{
    
    if (size == 0)
    {
        head = root;
        tail = root;
        Node<type>* iter = head;
        size++;
        while (iter->next != nullptr)
        {
            size++;
            iter = iter->next;
        }
        // Point the end of the list to the front and vice versa
        // set tail right before head
        iter->next = head;
        head->prev = iter;
        tail = iter;
    }
}

template<class type>
void CircularLinkedList<type>::print()
{
    Node<int>* iter = head;

    cout << "CircularList: ";
    do {
        cout << iter->data << "  ";
        iter = iter->next;
    } while (iter != head);
}

