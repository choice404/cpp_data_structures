#include <cstddef>

#ifndef CPP_VECTORS_LIBRARY_H
#define CPP_VECTORS_LIBRARY_H

namespace Choi
{
    template<typename T>
    class Vector
    {
    public:
        Vector();
        ~Vector();
        void printFullVec();
        T* getAddr();
        size_t size();
        size_t capacity();
        void push_back(T);
        T pop_back();
        void insert(size_t, T);
        void clear();
        void extend(size_t, T);
        void print();
        bool empty();

        T& operator[](size_t);
    private:
        T* m_Vector;
        size_t m_Size;
        size_t m_Capacity;

    private:
        void vecAlloc(size_t);
    };
}

#endif //CPP_VECTORS_LIBRARY_H
