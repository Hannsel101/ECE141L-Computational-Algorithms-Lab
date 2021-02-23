#pragma once
#include <iostream>
#include <cassert>
#include "unorderedLinkedList.h"

using namespace std;

template <class Type>
class linkedQueueType : public unorderedLinkedList<Type> {
public:
    const linkedQueueType<Type>& operator=(const linkedQueueType<Type>&);
    //Overload the assignment operator.
    bool isEmptyQueue() const;
    //Function to determine whether the queue is empty.
    //Postcondition: Returns true if the queue is empty, otherwise returns false.
    bool isFullQueue() const;
    //Function to determine whether the queue is full.
    //Postcondition: Returns true if the queue is full, otherwise returns false.
    void initializeQueue();
    //Function to initialize the queue to an empty state.
    //Postcondition: queueFront = nullptr; queueRear = nullptr
    Type front() const;
    //Function to return the first element of the queue.
    //Precondition: The queue exists and is not empty.
    //Postcondition: If the queue is empty, the program terminates; otherwise, the first
    // element of the queue is returned.
    Type back() const;
    //Function to return the last element of the queue.
    //Precondition: The queue exists and is not empty.
    //Postcondition: If the queue is empty, the program terminates; otherwise, the last
    // element of the queue is returned.
    void addQueue(const Type& queueElement);
    //Function to add queueElement to the queue.
    //Precondition: The queue exists and is not full.
    //Postcondition: The queue is changed and queueElement is added to the queue.
    void deleteQueue();
    //Function to remove the first element of the queue.
    //Precondition: The queue exists and is not empty.
    //Postcondition: The queue is changed and the first element is removed from the queue.
    linkedQueueType();
    //Default constructor
    linkedQueueType(const linkedQueueType<Type>& otherQueue);
    //Copy constructor
    ~linkedQueueType();
    //Destructor
   /* private:
    nodeType<Type> *queueFront; //pointer to the front of the queue
    nodeType<Type> *queueRear; //pointer to the rear of the queue*/
};
//------------------------------------------------------------------------------
//FUNCTION DEFINITIONS START HERE///////////////////////////////////////////////
//------------------------------------------------------------------------------
template<class Type>
const linkedQueueType<Type>& linkedQueueType<Type>::operator=
(const linkedQueueType<Type>& otherQueue)
{
    unorderedLinkedList<Type>::operator =(otherQueue);
}
//------------------------------------------------------------------------------
template<class Type>
bool linkedQueueType<Type>::isEmptyQueue() const
{
    return (unorderedLinkedList<Type>::isEmptyList());
}
//------------------------------------------------------------------------------
template<class Type>
bool linkedQueueType<Type>::isFullQueue() const
{
    return false;
}
//------------------------------------------------------------------------------
template<class Type>
void linkedQueueType<Type>::initializeQueue()
{
    unorderedLinkedList<Type>::initializeList();
}
//------------------------------------------------------------------------------
template<class Type>
void linkedQueueType<Type>::addQueue(const Type& queueElement)
{
    unorderedLinkedList<Type>::insertLast(queueElement);
}
//------------------------------------------------------------------------------
template<class Type>
void linkedQueueType<Type>::deleteQueue()
{
    nodeType<Type>* temp;//temporary node to hold and delete first element

    if (!isEmptyQueue())
    {
        temp = this->first;//store first into temp
        this->first = this->first->link;//move first over one place
        delete temp;//remove item from queue

        if (this->first == nullptr)//check for empty list
            this->last = nullptr;
    }
    else
        cout << "Cannot remove from an empty queue" << endl;//error message
}
//------------------------------------------------------------------------------
template<class Type>
linkedQueueType<Type>::linkedQueueType()
{
    this->first = nullptr;
    this->last = nullptr;
}
//------------------------------------------------------------------------------
template<class Type>
linkedQueueType<Type>::linkedQueueType(const linkedQueueType<Type>& otherQueue)
{
    unorderedLinkedList<Type>::operator =(otherQueue);
}
//------------------------------------------------------------------------------
template<class Type>
linkedQueueType<Type>::~linkedQueueType()
{
    unorderedLinkedList<Type>::destroyList();
}
//------------------------------------------------------------------------------
template<class Type>
Type linkedQueueType<Type>::front() const
{
    assert(this->first != nullptr);
    return this->first->info;
}
//------------------------------------------------------------------------------
template<class Type>
Type linkedQueueType<Type>::back() const
{
    assert(this->last != nullptr);
    return this->last->info;
}
