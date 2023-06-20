#include <iostream>
#include <cstddef>

#ifndef UNTITLED_LIBRARY_H
#define UNTITLED_LIBRARY_H

namespace Choi
{
    template<typename T>
    class linkedList;
    template<typename T>
    class DoublyLinkedList;
    template<typename T>
    class Node;

    template<typename T>
    class LinkedList
    {
    public:
        LinkedList();
        ~LinkedList();
        void next();
        void insert(size_t position, T);
    private:
        Node<T>* head;
        Node<T>* current;
    };

    template<typename T>
    class DoublyLinkedList
    {

    };

    template<typename T>
    class Node
    {
    public:
        T data;
        Node* next;
    };
}

#endif //UNTITLED_LIBRARY_H
