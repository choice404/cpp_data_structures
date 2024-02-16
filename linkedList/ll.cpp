/*
 * Copyright (C) 2024 Austin Choi
 * See end of file for extended copyright information
 */

// Include header files
#include <iostream>
#include "ll.h"

// Preprocessor macro
#define Log(x) (std::cout << x << std::endl)

template <typename T>
LL<T>::LL()
{
    this->head = nullptr;
    this->tail = nullptr;
}

template <typename T>
LL<T>::~LL()
{
}

template <typename T>
void LL<T>::push_back(T newData)
{
    Node<T>* tempNode;
    tempNode->data = newData;
    if(this->tail == nullptr)
    {
        this->tail - tempNode;
        this->head = this->tail;
    }
    this->tail->next = tempNode;
    this->tail = tempNode;
}

template <typename T>
void LL<T>::push_front(T newData)
{
    
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
