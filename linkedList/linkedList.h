/*
 * Copyright (C) 2024 Austin Choi
 * See end of file for extended copyright information
 */

#pragma once

#include <iostream>

namespace choi
{
    template<typename T>
    class LinkedList
    {
    public:
        // Constructors and destructor
        LinkedList();
        LinkedList(const LinkedList&);
        ~LinkedList();

        // Accessors
        T& front();
        T& back();
        T& at(size_t);
        T& operator[](size_t);
        bool empty();

        // Modifiers
        void push_front(const T&);
        void push_back(const T&);
        void pop_front();
        void pop_back();
        void insert(const T& value, size_t);
        void remove(size_t);
        void clear();
        void reverse();

        // Capacity
        size_t size();
        
        // Traversal and display
        void print(char = ' ');
        void print_at(size_t);
        void print_reverse(char = ' ');

        // Copy and assignment
        LinkedList& operator=(const LinkedList&);

    private:
        // Node structure
        struct Node
        {
            T data;
            Node* next;
            Node* prev;
        };

        // Private member variables
        Node* head;
        Node* tail;
        size_t length;

    private:
        // Private member methods
        void traverse(size_t, Node*&);
    };
}

/*
 * Copyright (C) 2024 Austin Choi
 * 
 * Data Structures
 * A collection of my implementations of various data structures in C++
 *
 * This code is licensed under the GNU General Public License 3.0.
 * Please see the LICENSE file in the root directory of this project for the full license details.
 */
