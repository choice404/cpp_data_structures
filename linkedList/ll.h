/*
 * Copyright (C) 2024 Austin Choi
 * See end of file for extended copyright information
 */

#pragma once

#include <iostream>

template <typename T>
struct Node
{
    Node* next;
    Node* prev;
    T data;
};

template <typename T>
class LL
{
public:
    LL();
    ~LL();

    void push_back(T);
    void push_front(T);

private:
    Node<T>* head;
    Node<T>* tail;
};

/*
 * Copyright (C) 2024 Austin Choi
 * 
 * Data Structures
 * A collection of my implementations of various data structures in C++
 *
 * This code is licensed under the GNU General Public License 3.0.
 * Please see the LICENSE file in the root directory of this project for the full license details.
 */
