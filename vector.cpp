#include "library.h"

#include <iostream>

#define Log(x) (std::cout << x << std::endl)

namespace Choi
{
    #define VectorT(x) template<typename T> x Vector<T>

    VectorT()::Vector() { vecAlloc(2); };

    VectorT()::~Vector()
    {
        if(m_Vector != nullptr)
        {
            delete m_Vector;
            m_Vector = nullptr;
        }
    };

    VectorT(void)::printFullVec()
    {
        for(int i = 0; i < m_Capacity; i++)
        {
            std::cout << m_Vector[i] << " ";
        }
        std::cout << std::endl;
    }

    VectorT(T*)::getAddr()
    {
        return &m_Vector;
    }

    VectorT(size_t)::size() { return m_Size; }
    VectorT(size_t)::capacity() { return m_Capacity; }

    VectorT(void)::push_back(T value)
    {
        if(m_Size >= m_Capacity)
        {
            vecAlloc(m_Capacity + m_Capacity / 2);
        }

        m_Vector[m_Size] = value;
        m_Size++;
    }

    VectorT(T)::pop_back()
    {
        T returnValue = m_Vector[m_Size - 1];
        m_Size--;
        return returnValue;
    }

    VectorT(void)::print()
    {
        for(int i = 0; i < m_Size; i++)
            std::cout << m_Vector[i] << " ";
        std::cout << std::endl;
    }

    VectorT(bool)::empty() { return !m_Size; }

    VectorT(void)::insert(size_t position, T value)
    {
        if(m_Size == m_Capacity)
        {
            vecAlloc(m_Capacity + m_Capacity / 2);
        }
        for(size_t i = m_Size; i > position; i--)
        {
            m_Vector[i] = m_Vector[i-1];
        }
        m_Vector[position] = value;
        m_Size++;
    }

    VectorT(void)::clear()
    {
        delete[] m_Vector;
        m_Vector = nullptr;
        m_Size = 0;
        m_Capacity = 0;
    }

    VectorT(void)::extend(size_t amount, T newValue)
    {
        while(m_Size + amount >= m_Capacity)
            vecAlloc(m_Capacity + m_Capacity / 2);
        for(int i = 0; i < amount; i++)
            m_Vector[m_Size + i] = newValue;
        m_Size += amount;
    }

    VectorT(T&)::operator[](size_t index) { return m_Vector[index]; }

    VectorT(void)::vecAlloc(size_t newCapacity)
    {
        T* tempVector = new T[newCapacity];
        size_t size = m_Size;

        if(newCapacity < size)
        {
            size = newCapacity;
        }

        for(size_t i = 0; i < m_Size; i++)
        {
            tempVector[i] = m_Vector[i];
        }
        delete[] m_Vector;
        m_Vector = tempVector;
        tempVector = nullptr;
        m_Capacity = newCapacity;
    }
}