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
    postorder(getRoot(), [](Node* node) { delete node; return; });
}

void BinaryTree::deleteTree(Node* leaf)
{
    if(leaf == nullptr)
        return;
    deleteTree(leaf->right);
    deleteTree(leaf->left);
    delete leaf;
}

bool BinaryTree::isEmpty()
{
    return root == nullptr;
}

void BinaryTree::insert(int data, Node* leaf)
{
    if(isEmpty())
    {
        root = new Node;
        root->data = data;
        root->left = nullptr;
        root->right = nullptr;
        return;
    }
    if(data < leaf->data)
    {
        if(leaf->left != nullptr)
          insert(data, leaf->left);
        else
        {
            leaf->left = new Node;
            leaf->left->data = data;
            leaf->left->left = nullptr;
            leaf->left->right = nullptr;
        }
    }
    else if(data >= leaf->data)
    {
        if(leaf->right != nullptr)
          insert(data, leaf->right);
        else
        {
            leaf->right = new Node;
            leaf->right->data = data;
            leaf->right->left = nullptr;
            leaf->right->right = nullptr;
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
    preorder(node->left, f);
    preorder(node->right, f);
}

template <typename Function>
void BinaryTree::inorder(Node* node, Function f)
{
    if(node == nullptr)
      return;
    inorder(node->left, f);
    f(node);
    inorder(node->right, f);
}

template <typename Function>
void BinaryTree::postorder(Node* node, Function f)
{
    if(node == nullptr)
      return;
    postorder(node->left, f);
    postorder(node->right, f);
    f(node);
}

template <typename Function>
Node* BinaryTree::search(Node* node, Function f)
{
    Node* result = nullptr;
    if(f(node))
        return node;
    if(node == nullptr)
        return nullptr;
    if(node->left != nullptr)
    {
        result = search(node->left, f);
        if(result != nullptr)
            return result;
    }
    if(node->right != nullptr)
    {
        result = search(node->right, f);
        if(result != nullptr)
            return result;
    }
    return nullptr;
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
