//
// Created by austi on 6/17/2023.
//

#include "202a4.cpp"
#include <iostream>

int main() {
    std::cout << "Reading integers:" << std::endl;
    LinkedList<int> li("integers.txt");
    li.print();
    std::cout << "Sorted integers:" << std::endl;
    li.sort();
    li.print();
    std::cout << std::endl;
    std::cout << "Reading floats:" << std::endl;
    LinkedList<float> lf("floats.txt");
    lf.print();
    std::cout << "Sorted floats:" << std::endl;
    lf.sort();
    lf.print();
    std::cout << std::endl;
    std::cout << "Reading strings:" << std::endl;
    LinkedList<std::string> ls("strings.txt");
    ls.print();
    std::cout << "Sorted strings:" << std::endl;
    ls.sort();
    ls.print();

    std::cout << "Reading empty:" << std::endl;
    LinkedList<std::string> le;
    le.print();
    std::cout << "Sorted strings:" << std::endl;
    le.sort();
    le.print();
}
