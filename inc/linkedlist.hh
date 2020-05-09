#ifndef LINKEDLIST_HH
#define LINKEDLIST_HH

#include <iostream>

template <typename T>
class LinkedList
{
    private:
        class Node
        {
            T data;
            Node* previous;
            Node* next;
            friend class Iterator;
            friend class LinkedList;
        };

    public:
        class Iterator
        {
            private:
                Node* currentNode;
                Iterator(Node* position);
            public:
                Iterator();
                T& getData();
                const bool operator ==(const Iterator& positionToCompare);
                const bool operator !=(const Iterator& positionToCompare);
                Iterator& operator ++();
                Iterator& operator --();
                friend class LinkedList;
        };

    private:
        int size;
        Node* head;
        Node* tail;

    public:
        LinkedList();
        const int getSize();
        const bool isEmpty();
        Iterator begin();
        Iterator end();
        Iterator insertFront(const T& newData);
        Iterator insertBack(const T& newData);
        void insertAtPosition(const Iterator& position, const T& newData);
        bool contains(const T& dataToCheck);
};

template <typename T>
LinkedList<T>::Iterator::Iterator(Node* position)
{
    currentNode = position;
}

template <typename T>
LinkedList<T>::Iterator::Iterator()
{
    currentNode = NULL;
}

template <typename T>
T& LinkedList<T>::Iterator::getData()
{
    return currentNode->data;
}

template <typename T>
const bool LinkedList<T>::Iterator::operator ==(const LinkedList<T>::Iterator& positionToCompare)
{
    return currentNode == positionToCompare.currentNode;
}

template <typename T>
const bool LinkedList<T>::Iterator::operator !=(const LinkedList<T>::Iterator& positionToCompare)
{
    return currentNode != positionToCompare.currentNode;
}

template <typename T>
typename LinkedList<T>::Iterator& LinkedList<T>::Iterator::operator ++()
{
    currentNode = currentNode->next;
    return *this;
}

template <typename T>
typename LinkedList<T>::Iterator& LinkedList<T>::Iterator::operator --()
{
    currentNode = currentNode->previous;
    return *this;
}

template <typename T>
LinkedList<T>::LinkedList()
{
    size = 0;
    head = new Node;
    tail = new Node;
    head->next = tail;
    tail->previous = head;
}

template <typename T>
const int LinkedList<T>::getSize()
{
    return size;
}

template <typename T>
const bool LinkedList<T>::isEmpty()
{
    if (size == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <typename T>
typename LinkedList<T>::Iterator LinkedList<T>::begin()
{
    return Iterator(head->next);
}

template <typename T>
typename LinkedList<T>::Iterator LinkedList<T>::end()
{
    return Iterator(tail);
}

template <typename T>
void LinkedList<T>::insertAtPosition(const LinkedList<T>::Iterator &position, const T& newData)
{
    Node* positionNode = position.currentNode;
    Node* positionNodePredecessor = positionNode->previous;
    Node* newNode = new Node;
    newNode->data = newData;
    newNode->next = positionNode;
    positionNode->previous = newNode;
    newNode->previous = positionNodePredecessor;
    positionNodePredecessor->next = newNode;
    size++;
}

template <typename T>
typename LinkedList<T>::Iterator LinkedList<T>::insertFront(const T& newData)
{
    insertAtPosition(begin(), newData);
    return begin();
}

template <typename T>
typename LinkedList<T>::Iterator LinkedList<T>::insertBack(const T& newData)
{
    insertAtPosition(end(), newData);
    return begin();
}

template <typename T>
bool LinkedList<T>::contains(const T& dataToCheck)
{
    for (Iterator iter(begin()); iter != end(); ++iter)
    {
        if (iter.getData() == dataToCheck)
        {
            return true;
        }
    }
    return false;
}

template <typename T>
std::ostream& operator << (std::ostream& out, LinkedList<T> linkedList)
{
    for (typename LinkedList<T>::Iterator iter = linkedList.begin(); iter != linkedList.end(); ++iter)
    {
        out << iter.getData() << "->";
    }
    out << "NULL";
    return out;
}


#endif