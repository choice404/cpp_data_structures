/*
 * Copyright (C) 2024 Austin Choi
 * See end of file for extended copyright information
 */

struct Node
{
    int data;
    Node* left;
    Node* right;
};

class BinaryTree
{
public:
    BinaryTree();
    BinaryTree(int);
    ~BinaryTree();

    void insert(int, Node*);
    Node* search(int, Node*);

    Node* getRoot();

    template <typename Function>
    void preorder(Node*, Function);

    template <typename Function>
    void inorder(Node*, Function);

    template <typename Function>
    void postorder(Node*, Function);

    void deleteTree(Node*);

    bool isEmpty();

public:
    Node* root;

private:

    void rotateLeft(Node* leaf);
    void rotateRight(Node* leaf);
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
