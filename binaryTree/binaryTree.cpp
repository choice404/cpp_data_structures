/*
 * Copyright (C) 2024 Austin Choi
 * See end of file for extended copyright information
 */

// Include header files
#include <iostream>
#include "./binaryTree.h"

// Preprocessor macro
#define Log(x) (std::cout << x << std::endl)

BinaryTree::BinaryTree() : root(nullptr)
{}

BinaryTree::BinaryTree(int data) : root(nullptr)
{
    root = new Node;
    root->data = data;
    root->left = nullptr;
    root->right = nullptr;
}

BinaryTree::~BinaryTree()
{
    /* deleteTree(root); */

    postorder(root, [](Node* node) { delete node; });
}

void BinaryTree::deleteTree(Node* leaf)
{
    if(leaf != nullptr)
    {
        deleteTree(leaf->left);
        deleteTree(leaf->right);
        delete leaf;
    }
}

bool BinaryTree::isEmpty()
{
    return root == nullptr;
}

void BinaryTree::insert(int data, Node* leaf)
{
    Log("Inserting " << data);
    if(isEmpty()) [[unlikely]]
    {
        Log("Leaf is null");
        leaf = new Node;
        leaf->data = data;
        Log("Root: " << leaf->data);
        leaf->left = nullptr;
        Log("Root left null");
        leaf->right = nullptr;
        Log("Root right null");
        Log("Leaf: " << leaf->data);
        return;
    }
    if(leaf->left == nullptr && leaf->right == nullptr)
    {
        if(data < leaf->data)
        {
            leaf->left = new Node;
            leaf->left->data = data;
            leaf->left->left = nullptr;
            leaf->left->right = nullptr;
            return;
        }
        else if(data >= leaf->data)
        {
            leaf->right = new Node;
            leaf->right->data = data;
            leaf->right->left = nullptr;
            leaf->right->right = nullptr;
            return;
        }
    }
    else
    {
        if(data < leaf->data)
        {
            insert(data, leaf->left);
        }
        else if(data >= leaf->data)
        {
            insert(data, leaf->right);
        }
    }
}

Node* BinaryTree::getRoot() { return root; }

template <typename Function>
void BinaryTree::preorder(Node* node, Function f)
{
    if(node == nullptr)
      return;
    f(node);
    preorder(root->left, f);
    preorder(root->right, f);
    return;
}

template <typename Function>
void BinaryTree::inorder(Node* node, Function f)
{
    if(node == nullptr)
      return;
    inorder(root->left, f);
    f(node);
    inorder(root->right, f);
    return;
}

template <typename Function>
void BinaryTree::postorder(Node* node, Function f)
{
    if(node == nullptr)
      return;
    postorder(root->left, f);
    postorder(root->right, f);
    f(node);
    return;
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
