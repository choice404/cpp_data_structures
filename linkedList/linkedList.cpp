/*
 * Copyright (C) 2024 Austin Choi
 * See end of file for extended copyright information
 */

// Include header files
#include <iostream>
#include "linkedList.h"

// Preprocessor macro
#define Log(x) (std::cout << x << std::endl)

namespace choi
{
    // Macro so I don't need to repeat this part lol
    #define LLT(x) template<typename T> x LinkedList<T>

    // Constructors and destructor
    
    // Default constructor
    LLT()::LinkedList()
    {
        this->head = nullptr;
        this->tail = nullptr;
        this->length = 0;
    }

    // Copy constructor
    LLT()::LinkedList(const LinkedList& other)
    {
        this->head = nullptr;
        this->tail = nullptr;
        this->length = 0;

        Node* current = other->head;
        while (current != nullptr)
        {
            this->push_back(current->data);
            current = current->next;
        }
    }

    // Destructor
    LLT()::~LinkedList()
    {
        Node* current = head, *next = nullptr;
        while (current != nullptr)
        {
            next = current->next;
            delete current;
            current = next;
        }
    }

    // Accessors

    // Returns the first element in the list
    // param: none
    // return: (T&) the first element in the list
    LLT(T&)::front() { return this->head->data; }

    // Returns the last element in the list
    // param: none
    // return: (T&) the last element in the list
    LLT(T&)::back() { return this->tail->data; }

    // Returns the element at the specified index
    // param: (size_t) the index of the element to return
    // return: (T&) the element at the specified index
    // throws: std::out_of_range if the index is out of range
    LLT(T&)::at(size_t index)
    {
        if (index < 0 || index >= this->length)
            throw std::out_of_range("Index out of range");

        Node* current = this->head;
        this->traverse(index, current);

        return current->data;
    }

    // Returns the element at the specified index
    // param: (size_t) the index of the element to return
    // return: (T&) the element at the specified index
    // throws: std::out_of_range if the index is out of range
    LLT(T&)::operator[](size_t index)
    {
        if (index < 0 || index >= this->length)
            throw std::out_of_range("Index out of range");

        Node* current = this->head;
        this->traverse(index, current);

        return current->data;
    }

    // Returns whether the list is empty
    // param: none
    // return: (bool) whether the list is empty
    LLT(bool)::empty() { return !this->length; }

    // Modifiers

    // Adds an element to the front of the list
    // param: (const T&) the element to add
    // return: none
    LLT(void)::push_front(const T& value)
    {
        Node* node = new Node;
        node->data = value;
        node->next = this->head;
        node->prev = nullptr;

        if (this->head != nullptr)
            this->head->prev = node;
        else
            this->tail = node;

        this->head = node;
        ++this->length;
    }

    // Adds an element to the back of the list
    // param: (const T&) the element to add
    // return: none
    LLT(void)::push_back(const T& value)
    {
        Node* node = new Node;
        node->data = value;
        node->next = nullptr;
        node->prev = this->tail;

        if (this->tail != nullptr)
            this->tail->next = node;
        else
            this->head = node;

        this->tail = node;
        ++this->length;
    }

    // Removes the first element in the list
    // param: none
    // return: none
    LLT(void)::pop_front()
    {
        if (!this->length)
            return;

        Node* node = this->head;
        this->head = this->head->next;
        delete node;

        if (this->head != nullptr)
            this->head->prev = nullptr;
        else
            this->tail = nullptr;

        --this->length;
    }

    // Removes the last element in the list
    // param: none
    // return: none
    LLT(void)::pop_back()
    {
        if (!this->length)
            return;

        Node* node = this->tail;
        this->tail = this->tail->prev;
        delete node;

        if (this->tail != nullptr)
            this->tail->next = nullptr;
        else
            this->head = nullptr;

        --this->length;
    }

    // Inserts an element at the specified index
    // param: (const T&) the element to insert
    // param: (size_t) the index to insert the element at
    // return: none
    LLT(void)::insert(const T& value, size_t index)
    {
        if (index < 0 || index > this->length)
            throw std::out_of_range("Index out of range");

        if (index == 0)
            this->push_front(value);
        else if (index == this->length)
            this->push_back(value);
        else
        {
            Node* current = this->head;
            this->traverse(index - 1, current);

            Node* node = new Node;
            node->data = value;
            node->next = current->next;
            node->prev = current;

            current->next->prev = node;
            current->next = node;

            ++this->length;
        }
    }

    // Removes the element at the specified index
    // param: (size_t) the index of the element to remove
    // return: none
    LLT(void)::remove(size_t index)
    {
        if (index < 0 || index >= this->length)
            throw std::out_of_range("Index out of range");

        if (index == 0)
            this->pop_front();
        else if (index == this->length - 1)
            this->pop_back();
        else
        {
            Node* current = this->head;
            this->traverse(index, current);

            current->prev->next = current->next;
            current->next->prev = current->prev;

            delete current;
            --this->length;
        }
    }

    // Removes all elements from the list
    // param: none
    // return: none
    LLT(void)::clear()
    {
        Node* current = this->head, *next = nullptr;
        while (current != nullptr)
        {
            next = current->next;
            delete current;
            current = next;
        }

        this->head = nullptr;
        this->tail = nullptr;
        this->length = 0;
    }

    // Reverses the list
    // param: none
    // return: none
    LLT(void)::reverse()
    {
        Node* current = this->head, *next = nullptr;
        while (current != nullptr)
        {
            next = current->next;
            current->next = current->prev;
            current->prev = next;
            current = next;
        }

        current = this->head;
        this->head = this->tail;
        this->tail = current;
    }

    // Capacity

    // Returns the number of elements in the list
    // param: none
    // return: (size_t) the number of elements in the list
    LLT(size_t)::size() { return this->length; }

    // Traversal and display

    // Prints the entire list
    // param: none
    // return: none
    LLT(void)::print(char delim)
    {
        Node* current = this->head;
        while (current != nullptr)
        {
            std::cout << current->data << delim;
            current = current->next;
        }
        std::cout << std::endl;
    }

    // Prints the element at the specified index
    // param: (size_t) the index of the element to print
    // return: none
    LLT(void)::print_at(size_t index)
    {
        if (index < 0 || index >= this->length)
            throw std::out_of_range("Index out of range");

        Node* current = this->head;
        this->traverse(index, current);

        std::cout << current->data << std::endl;
    }

    // Prints the list in reverse
    // param: none
    // return: none
    LLT(void)::print_reverse(char delim)
    {
        Node* current = this->tail;
        while (current != nullptr)
        {
            std::cout << current->data << ' ';
            current = current->prev;
        }
        std::cout << std::endl;
    }

    // Copy and assignment

    // Copy assignment operator
    // param: (const LinkedList&) the list to copy
    // return: (LinkedList&) the copied list
    LLT(LinkedList<T>&)::operator=(const LinkedList& other)
    {
        this->clear();

        Node* current = other->head;
        while (current != nullptr)
        {
            this->push_back(current->data);
            current = current->next;
        }

        return *this;
    }
    
    // Private member methods

    // Traverses the list to the specified index
    // param: (size_t) the number of nodes to traverse
    // param: (Node*&) the node that traverses the list
    LLT(void)::traverse(size_t amount, Node*& current)
    {
        for (size_t i = 0; i < amount; ++i)
            current = current->next;
    }

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
