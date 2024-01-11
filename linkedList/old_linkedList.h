/*
 * Copyright (C) 2024 Austin Choi
 * See end of file for extended copyright information
 */

#include <iostream>
#include <fstream>

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
    class Node
    {
    public:
        T data;
        Node* next;

    public:
        Node();
        Node(T);
        void print();
    };

    template<typename T>
    class LinkedList
    {
    public:
        LinkedList();
        LinkedList(std::string);
        ~LinkedList();
        bool empty();
        void push(T);
        void remove(int);
        void sort();
        void print();

    private:
        Node<T>* merge(Node<T>*, Node<T>*);
        void swapNext(Node<T>*, Node<T>*);
        void swap(int, int);
        void traverse(Node<T>*, int);
        Node<T>* getAddressOf(int);

    private:
        Node<T>* head;
        Node<T>* tail;
        Node<T>* current;
        int m_Size;
    };

    template<typename T>
    class DoublyLinkedList
    {

    };

}

#endif //UNTITLED_LIBRARY_H

/*
 * Copyright (C) 2024 Austin Choi
 * 
 * Data Structures
 * A collection of my implementations of various data structures in C++
 *
 * This code is licensed under the GNU General Public License 3.0.
 * Please see the LICENSE file in the root directory of this project for the full license details.
 */
