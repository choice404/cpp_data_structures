/*
 * Copyright (C) 2024 Austin Choi
 * See end of file for extended copyright information
 */

#include <iostream>

#pragma once

namespace Choi
{
    template<typename T>
    class Vector
    {
    public:
        // Constructors and deconstructor
        Vector();
        Vector(size_t);
        Vector(const Vector&);
        ~Vector();

        // Element access
        T& at(size_t) const;
        T& operator[](size_t);
        T& front();
        T& back();

        // Capacity
        size_t size() const;
        size_t capacity();
        bool empty();
        void reserve(size_t);
        void shrink_to_fit();

        // Modifiers
        void push_back(T);
        T& pop_back();
        void insert(size_t, T);
        void clear();
        void extend(size_t, T);

        // Print
        void print_full_vector();
        void print();

        // Getters
        T* get_address() const;

    private:
        T* m_Vector;
        size_t m_Size;
        size_t m_Capacity;

    private:
        void vecAlloc(size_t);
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
