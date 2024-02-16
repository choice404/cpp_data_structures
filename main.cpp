/*
 * Copyright (C) 2024 Austin Choi
 * See end of file for extended copyright information
 */

// Include header files
#include <iostream>
#include "./binaryTree/binaryTree.cpp"

// Preprocessor macro
#define Log(x) (std::cout << x << std::endl)

int main(int argc, char* argv[])
{
    // Create a binary tree
    BinaryTree tree;
    tree.insert(5, tree.root);
    tree.insert(7, tree.root);
    tree.insert(2, tree.root);
    tree.insert(3, tree.root);
    tree.insert(4, tree.root);
    tree.insert(6, tree.root);
    tree.insert(8, tree.root);

    tree.preorder(tree.getRoot(), [](Node* node) { std::cout << node->data << " "; });
    Log("");
    /* tree.postorder(tree.getRoot(), [](Node* node) { std::cout << node->data; }); */
    /* Log(""); */
    /* tree.inorder(tree.getRoot(), [](Node* node) { std::cout << node->data; }); */
    /* Log(""); */

    tree.preorder(tree.getRoot(), [](Node* node) { node->data *= 2; });

    tree.preorder(tree.getRoot(), [](Node* node) { std::cout << node->data << " "; });

    Log("");

    /* Log(tree.search(tree.getRoot(), [](Node* node) { return node->data == 2; })->data); */


    // End program
    return 0;
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
