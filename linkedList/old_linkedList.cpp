/*
 * Copyright (C) 2024 Austin Choi
 * See end of file for extended copyright information
 */

#include "linkedList.h"

namespace Choi
{
    #define NodeT(x) template<typename T> x Node<T>
    #define LinkedListT(x) template<typename T> x LinkedList<T>

    // Default Node constructor
    // Set all members to null
    NodeT()::Node() : data(NULL), next(nullptr) {}

    // Overloaded Node constructor
    // Set data to the parameter and next to nullptr
    NodeT()::Node(T data) : data(data), next(nullptr) {}

    // Method to print out the current node
    // Input: N/A
    // Output: The value stored in data
    NodeT(void)::print()
    {
        std::cout << data;
        if(next != nullptr)
        {
            next->print();
        }
    }

    // Default constructor
    // Set all members as nullptr
    LinkedListT()::LinkedList() : head(nullptr), tail(nullptr), current(nullptr), m_Size(0) {}

    // Overloaded specialized constructor for strings
    // Reads in a file to populate the linked List
    template<> LinkedList<std::string>::LinkedList(std::string filename)
    {
        std::ifstream iFile(filename);
        while(!iFile.eof())
        {
            std::string data;
            iFile >> data;
            if(data[data.length() - 1] == ',')
            {
                data = data.substr(0, data.length() - 1);
            }

            push(data);
        }
    }

    // Overloaded specialized constructor for int
    // Reads in a file to populate the linked List
    template<> LinkedList<int>::LinkedList(std::string filename)
    {
        std::ifstream iFile(filename);
        while(!iFile.eof())
        {
            std::string data;
            iFile >> data;
            if(data[data.length() - 1] == ',')
            {
                data = data.substr(0, data.length() - 1);
            }
            int intData = std::stoi(data);

            push(intData);
        }
    }

    // Overloaded specialized constructor for float
    // Reads in a file to populate the linked List
    template<> LinkedList<double>::LinkedList(std::string filename)
    {
        std::ifstream iFile(filename);
        while(!iFile.eof())
        {
            std::string data;
            iFile >> data;
            if(data[data.length() - 1] == ',')
            {
                data = data.substr(0, data.length() - 1);
            }
            double intData = std::stod(data);

            push(intData);
        }
    }

    // Empty method to check if linked list is empty or not
    // Input: N/A
    // Output: Bool if head is pointing to anything or not
    LinkedListT(bool)::empty() { return head; }

    // Method to push a new node to the end of the linked list
    // Input: The new value of the data type of the linked list
    // Output: N/A
    LinkedListT(void)::push(T newValue)
    {
        // Check if linked list is empty then make the head the new Node
        if(this->empty()) { head = new Node<T>(newValue); }

        // If linked list is not empty
        else
        {
            // Set the tail->next to the address of the new Node
            tail->next = new Node<T>(newValue);
            // Make the new Node the tail
            tail = tail->next;
        }
        // Increment size
        m_Size++;
    }

    // Method to remove a Node at an index
    // Input: The index of the node to delete
    // Output: N/A
    LinkedListT(void)::remove(int index)
    {
        // Set current node to head to traverse the linked list
        current = head;

        // Check if the index is 0 to delete the head
        if(!index)
        {
            // Set head to the next node
            traverse(head, 1);
            // Set the current Node (old head) to nullptr
            current->next = nullptr;
            // Delete the current Node
            delete current;
            // Set current to nullptr
            current = nullptr;
            // Decrement size
            m_Size--;
            // return void
            return;
        }

        // Traverse current to the Node before the index
        traverse(current, index - 1);
        
        // Set a temp node to the node at the index
        Node<T> tempNode = current->next;
        // Set the current Node next to the address of the node after the Node to delete
        current->next = tempNode->next;
        // Set tempNode to nullptr
        tempNode->next = nullptr;
        // Delete tempNode
        delete tempNode;
        // Set current to nullptr
        current = nullptr;
    }

    // Private Method to return address of a Node at an index
    // Input: An int as an index of the linked list
    // Output: The address of a Node at the given index
    LinkedListT(Node<T>*)::getAddressOf(int index)
    {
        current = head;
        traverse(current, index);
        return &current;
    }

    // Method to sort the linked list
    LinkedListT(void)::sort()
    {
        int size = m_Size;
        bool sorted = false;
        for(int i = 0; i < size - 1; i++)
        {
            current = head;
            sorted = false;
            for(int j = 0; j < size - i - 1; j++)
            {
                if(current->value < current->next->value)
                {
                    swap(j, j + 1);
                }
                traverse(current, 1);
            }
        }
    }

    LinkedListT(void)::print() { head->print(); }

    // Private method to traverse a a Node pointer across the linked list
    // Input: The Node* we want to traverse, the number nodes to traverse
    // Output: N/A
    LinkedListT(void)::traverse(Node<T>* traverseNode, int amount)
    {
        for(int i = 0; i < amount; i++)
            traverseNode = traverseNode->next;
    }

    // Private method to swap the next value of 2 Nodes
    // Input: The addresses of the 2 nodes to swap the next
    // Output: N/A
    LinkedListT(void)::swapNext(Node<T>* A, Node<T>* B)
    {
        // Create a tempNode pointing to A
        Node<T>* tempNode = A->next;

        // Set A->next to B->next
        A->next = B->next;

        // Set B->next to tempNode
        B->next = tempNode;
    }

    // Private method to swap 2 nodes
    // Input: The indexes of the 2 nodes to swap
    // Output: N/A
    LinkedListT(void)::swap(int firstIndex, int secondIndex)
    {
        Node<T>* firstNode = head, secondNode = head;
        traverse(firstNode, firstIndex - 1);
        traverse(secondNode, secondIndex - 1);
        T tempValue = firstNode->value;
        firstNode->value = secondNode->value;
        secondNode->value = tempValue;
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
