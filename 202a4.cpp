// Include header files
#include <iostream>
#include <fstream>

// Preprocessor macros cause I'm lazy to type things out
// Macro for Node template
#define NodeT(x) template<typename T> x Node<T>
// Macro for LinkedList template
#define LinkedListT(x) template<typename T> x LinkedList<T>
// Macro for specialized LinkedList template
#define LinkedListSpecializedT(x, y) template<> x LinkedList<y>
// Macro to output things for debugging
#define Log(x) (std::cout << x << std::endl)

// Class prototypes
template<typename T>
class linkedList;
template<typename T>
class Node;

// Class of Node
template<typename T>
class Node
{
public:
    T data;
    Node* next;

public:
    Node();
    Node(T);
    ~Node();
    void print();
};

// Class of LinkedList
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
    void swap(int, int);
    void traverse(Node<T>*&, int);
    Node<T>* getAddressOf(int);

private:
    Node<T>* head;
    Node<T>* tail;
    Node<T>* current;
    int size;
};

// Default Node constructor
// Set all members to null
NodeT()::Node() : data(NULL), next(nullptr) {}

// Overloaded Node constructor
// Set data to the parameter and next to nullptr
NodeT()::Node(T data) : data(data), next(nullptr) {}

// Node deconstructor
NodeT()::~Node() { if(next != nullptr) delete next; }

// Method to print out the current node
// Input: N/A
// Output: The value stored in data
NodeT(void)::print()
{
    // Output the data
    std::cout << data << ' ';

    // Propogate the print using the next address
    if(next != nullptr) next->print();
}

// Default constructor
// Set all members as nullptr
LinkedListT()::LinkedList() : head(nullptr), tail(nullptr), current(nullptr), size(0) {}

// Overloaded specialized constructor for strings
// Reads in a file to populate the linked List
LinkedListT()::LinkedList(std::string filename) : head(nullptr), tail(nullptr), current(nullptr), size(0)
{
    // Create ifstream object
    std::ifstream iFile(filename);

    // Declare a temporary variable to hold the data
    std::string data = "";

    // While loop to populate the linked list with values from the file
    while(!iFile.eof())
    {
        // Read from the ifstream object to data
        iFile >> data;

        // Remove comma if any
        if(data[data.length() - 1] == ',')
            data = data.substr(0, data.length() - 1);

        // Push the data to the linked list
        push(data);
    }
}

// Overloaded specialized constructor for int
// Reads in a file to populate the linked List
LinkedListSpecializedT(,int)::LinkedList(std::string filename) : head(nullptr), tail(nullptr), current(nullptr), size(0)
{
    // Create ifstream object
    std::ifstream iFile(filename);

    // Declare a temporary variable to hold the data
    std::string data = "";
    
    // While loop to populate the linked list with values from the file
    while(!iFile.eof())
    {
        // Read from the ifstream object to data
        iFile >> data;
        
        // Remove comma if any
        if(data[data.length() - 1] == ',')
            data = data.substr(0, data.length() - 1);

        // Cast the data to integer
        int intData = std::stoi(data);

        // Push the data to the linked list
        push(intData);
    }
}

// Overloaded specialized constructor for float
// Reads in a file to populate the linked List
LinkedListSpecializedT(,float)::LinkedList(std::string filename) : head(nullptr), tail(nullptr), current(nullptr), size(0)
{
    // Create ifstream object
    std::ifstream iFile(filename);

    // Declare a temporary variable to hold the data
    std::string data = "";
    
    // While loop to populate the linked list with values from the file
    while(!iFile.eof())
    {
        // Read from the ifstream object to data
        iFile >> data;
        
        // Remove comma if any
        if(data[data.length() - 1] == ',')
            data = data.substr(0, data.length() - 1);

        // Cast the data to float
        float floatData = std::stof(data);

        // Push the data to the linked list
        push(floatData);
    }
}

// LinkedList deconstructor
LinkedListT()::~LinkedList()
{
    tail = nullptr;
    current = nullptr;
    delete head;
    head = nullptr;
}

// Empty method to check if linked list is empty or not
// Input: N/A
// Output: Bool if head is pointing to anything or not
LinkedListT(bool)::empty() { return head == nullptr ? true : false; }

// Method to push a new node to the end of the linked list
// Input: The new value of the data type of the linked list
// Output: N/A
LinkedListT(void)::push(T newValue)
{
    // Create a new Node
    Node<T>* newNode = new Node<T>(newValue);

    // Check if linked list is empty then make the head the new Node
    if(empty()) {
        // Set head to new node
        head = newNode;

        // Set tail to head
        tail = head;

        // Increase size of linked list
        size++;

        // set the temporary node to nullptr
        newNode = nullptr;

        // Return
        return;
    }


    // If linked list is not empty
    // Set the tail->next to the address of the new Node
    tail->next = newNode;

    // Make the new Node the tail
    traverse(tail, 1);

    // Increment size
    size++;

    // Set temp newNode to nullptr
    newNode = nullptr;
}

// Method to remove a Node at an index
// Input: The index of the node to delete
// Output: N/A
LinkedListT(void)::remove(int index)
{
    // End function if linked list is empty
    if(empty()) return;

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
        size--;

        // return
        return;
    }

    // Check if the index is the tail then delete and set new tail
    if(index == size - 1)
    {
        // Delete the tail
        delete tail;

        // Set tail to head
        tail = head;

        // Traverse to the new tail
        traverse(tail, index -1);

        // Decrement size
        size--;

        // return
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
    // Set current to head
    current = head;

    // Traverse current to the index
    traverse(current, index);

    // Return the address of the index
    return &current;
}

// Method to sort the linked list
// Input: N/A
// Output: N/A
LinkedListT(void)::sort()
{
    // End function if linked list is empty
    if(empty()) return;

    // Set a variable to false, this will check if a loop of the sorting does nothing
    bool sorted = false;
    
    // Loop to sort
    for(int i = 0; i < size - 1; i++)
    {
        // Set current to head
        current = head;

        // Set sorted to false
        sorted = false;

        // Inner loop to sort
        for(int j = 0; j < size - i - 1; j++)
        {
            // If current node data is less than next node data
            if(current->data < current->next->data)
            {
                // Swap the data
                swap(j, j + 1);
                
                // Set sorted to true
                sorted = true;
            }

            // Go to the next node
            traverse(current, 1);
        }

        // If nothing was sorted in the last iteration, then end sorting
        if(!sorted)
            break;
    }
}

// Specialized method to sort a linked list of strings
// Input: N/A
// Output: N/A
LinkedListSpecializedT(void, std::string)::sort()
{
    // End function if linked list is empty
    if(empty()) return;

    // Set a variable to false, this will check if a loop of the sorting does nothing
    bool sorted = false;
    
    // Loop to sort
    for(int i = 0; i < size - 1; i++)
    {
        // Set current to head
        current = head;

        // Set sorted to false
        sorted = false;

        // Inner loop to sort
        for(int j = 0; j < size - i - 1; j++)
        {
            // Set variable to the length of whichever Node (this or the next one) is shorter
            int min = (current->data.length() < current->next->data.length()) ? current->data.length() : current->next->data.length();

            // Loop to compare each letter in the strings
            for(int n = 0; n < min; n++)
            {
                // If the letters of the current are the same then continue to the next iteration
                if(current->data[n] == current->next->data[n])
                    continue;

                // If the curent data is greater than the next then swap
                if(current->data[n] > current->next->data[n])
                {
                    // Swap this and the next Node's data
                    swap(j, j + 1);
                    
                    // Set sorted to true
                    sorted = true;

                    // Break from the loop
                    break;
                }

                // If current data is less than the next then break from the loop
                break;
            }

            // Go to the next node
            traverse(current, 1);
        }

        // If nothing was sorted in the last iteration, then end sorting
        if(!sorted)
            break;
    }
}

// Method to print out the linked list
// Input: N/A
// Output: All the data in the linked list
LinkedListT(void)::print()
{
    // End function if linked list is empty
    if(empty()) return;

    // Print the linked list starting from print
    head->print();

    // Output newline
    std::cout << std::endl;
}

// Private method to traverse a a Node pointer across the linked list
// Input: The Node* we want to traverse by reference, the number nodes to traverse
// Output: N/A
LinkedListT(void)::traverse(Node<T>*& traverseNode, int amount)
{
    // Traverse the linked list the number of times as the amount
    for(int i = 0; i < amount; i++)
        traverseNode = traverseNode->next;
}

// Private method to swap 2 nodes
// Input: The indexes of the 2 nodes to swap
// Output: N/A
LinkedListT(void)::swap(int firstIndex, int secondIndex)
{
    // Create 2 temporary Node* that are intialized to head
    Node<T>* firstNode = head;
    Node<T>* secondNode = head;

    // Traver the first temp node by the first index
    traverse(firstNode, firstIndex);

    // Traver the second temp node by the second index
    traverse(secondNode, secondIndex);

    // Swap the values of the 2 nodes
    T tempValue = firstNode->data;
    firstNode->data = secondNode->data;
    secondNode->data= tempValue;
}
