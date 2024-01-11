/*
 * Copyright (C) 2024 Austin Choi
 * See end of file for extended copyright information
 */

// Include header files
#include "vector.h"

// Preprocessor macro
#define Log(x) (std::cout << x << std::endl)

namespace Choi
{
    // Macro so I don't need to repeat this part lol
    #define VectorT(x) template<typename T> x Vector<T>

    // Constructor and destructor
    // Default constructor for Vector. Will allocate an array of size 2
    VectorT()::Vector() { vecAlloc(2); };

    // Constructor for Vector. Will allocate an array of size passed
    // Input: size (size_t) - The size of the array to allocate
    VectorT()::Vector(size_t size) { vecAlloc(size); };

    // Copy constructor for Vector. Will copy the Vector passed
    // Input: vector (Vector&) - The Vector to copy
    VectorT()::Vector(const Vector& vector)
    {
        vecAlloc(vector->m_Capacity);
        for(size_t i = 0; i < vector.m_Size; i++)
            m_Vector[i] = vector->m_Vector[i];
        m_Size = vector->m_Size;
    };

    // Vector deconstructor. Deletes the vector and sets it to nullptr
    VectorT()::~Vector()
    {
        if(m_Vector != nullptr)
        {
            delete m_Vector;
            m_Vector = nullptr;
        }
    };
    
    // Element access

    // Method to get the value at the index passed
    // Input: index (size_t) - The index to get the value from
    // Output: (T&) The value at the index passed
    VectorT(T&)::at(size_t index) const { return m_Vector[index]; }

    // Overloaded operator to get the value at the index
    VectorT(T&)::operator[](size_t index) { return m_Vector[index]; }

    // Method to get the first value in the Vector
    // Input: N/A
    // Output: (T&) The first value in the Vector
    VectorT(T&)::front() { return m_Vector[0]; }

    // Method to get the last value in the Vector
    // Input: N/A
    // Output: (T&) The last value in the Vector
    VectorT(T&)::back() { return m_Vector[m_Size - 1]; }

    // Capacity

    // Method to get the size of the Vector
    // Input: N/A
    // Output: (size_t) The size of the Vector that is being used
    VectorT(size_t)::size() const { return m_Size; }

    // Method to get the capacity of the Vector
    // Input N/A
    // Output: (size_t) The total capacity of theVector that was allocated
    VectorT(size_t)::capacity() { return m_Capacity; }

    // Method to check if the Vector is empty
    // Input: N/A
    // Output: (bool) Returns if the Vector has size or not
    VectorT(bool)::empty() { return !m_Size; }

    // Method to reserve a certain amount of memory for the Vector
    // Input: (size_t) The amount of memory to reserve
    // Output: N/A
    VectorT(void)::reserve(size_t amount)
    {
        if(amount > m_Capacity)
            vecAlloc(amount);
    }

    // Method to shrink the Vector to the size of the Vector
    // Input: N/A
    // Output: N/A  
    VectorT(void)::shrink_to_fit()
    {
        if(m_Size < m_Capacity)
            vecAlloc(m_Size);
    }

    // Method to extend Vector with a new value by a certain amount
    // Input: (size_t) The amount to extend by
    // Input: (T) The new value to extend with
    // Output: N/A
    VectorT(void)::extend(size_t amount, T newValue)
    {
        while(m_Size + amount >= m_Capacity)
            vecAlloc(m_Capacity + m_Capacity / 2);
        for(size_t i = 0; i < amount; i++)
            m_Vector[m_Size++] = newValue;
    }

    // Modifiers
    
    // Method to push a new value to the end of the Vector like a stack
    // Input: (T) A value of the data type of the Vector
    // Output: N/A
    VectorT(void)::push_back(T value)
    {
        if(m_Size >= m_Capacity)
        {
            vecAlloc(m_Capacity + m_Capacity / 2);
        }

        m_Vector[m_Size] = value;
        m_Size++;
    }

    // Method to pop the value at the end of the Vector like a stack and return it
    // Input: N/A
    // Output: (T&) The last value in the array, the array no longer has that value
    VectorT(T&)::pop_back()
    {
        T returnValue = m_Vector[m_Size - 1];
        m_Size--;
        return returnValue;
    }

    // Method to insert a new value at the the index passed
    // Input: (size_t) int of type size_t as the index, the value to insert
    // Output: N/A
    VectorT(void)::insert(size_t position, T value)
    {
        if(m_Size == m_Capacity) vecAlloc(m_Capacity + m_Capacity / 2);
        for(size_t i = m_Size; i > position; i--)
            m_Vector[i] = m_Vector[i-1];
        m_Vector[position] = value;
        m_Size++;
    }

    // Method to effectively clear the Vector by setting size to 0
    // Input: N/A
    // Output: N/A
    VectorT(void)::clear() { m_Size = 0; }

    // Print

    // Method to print the entire array in the Vector, not just the data stores
    // Input: N/A
    // Output N/A
    VectorT(void)::print_full_vector()
    {
        for(size_t i = 0; i < m_Capacity; i++)
        {
            std::cout << m_Vector[i] << " ";
        }
        std::cout << std::endl;
    }

    // Method to print the entire Vector delimited by spaces
    // Input: N/A
    // Output: N/A
    VectorT(void)::print()
    {
        for(size_t i = 0; i < m_Size; i++)
            std::cout << m_Vector[i] << " ";
        std::cout << std::endl;
    }

    // Getters
    
    // Method to get the base address of the Vector
    // Input: N/A
    // Output: (T*) The address pointing to the vector
    VectorT(T*)::get_address() const { return this; }


    // Private methods

    // Private method to allocate new memory to the array
    // Input: (size_t) The new capacity of allocated memory
    // Output: N/A
    VectorT(void)::vecAlloc(size_t newCapacity)
    {
        T* tempVector = new T[newCapacity];
        size_t size = m_Size;

        if(newCapacity < size)
        {
            size = newCapacity;
        }

        for(size_t i = 0; i < m_Size; i++)
            tempVector[i] = m_Vector[i];
        delete[] m_Vector;
        m_Vector = tempVector;
        tempVector = nullptr;
        m_Capacity = newCapacity;
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
