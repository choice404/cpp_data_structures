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
    // Write code here
    Log("Data Structures created");

    // Create a binary tree
    BinaryTree tree;
    tree.insert(5, tree.root);
    Log(tree.root->data);
    tree.insert(3, tree.root);
    tree.insert(7, tree.root);
    Log(tree.root->data);

    /* tree.preorder(tree.getRoot(), [](Node* node) { Log(node->data); }); */

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
