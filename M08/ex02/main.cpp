#include <iostream>
#include "MutantStack.hpp"

int main() {
    std::cout << "Testing MutantStack..." << std::endl;

    // Create an instance of MutantStack
    MutantStack<int> mstack;

    // Test push and top
    mstack.push(5);
    mstack.push(10);
    std::cout << "Top of stack: " << mstack.top() << std::endl; // Should print 10

    // Test pop
    mstack.pop();
    std::cout << "Top after pop: " << mstack.top() << std::endl; // Should print 5

    // Test size
    std::cout << "Size of stack: " << mstack.size() << std::endl; // Should print 1

    // Test iterator functionality
    mstack.push(15);
    mstack.push(20);
    std::cout << "Elements in stack: ";
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Test const iterator
    std::cout << "Elements using const iterator: ";
    for (MutantStack<int>::const_iterator it = mstack.cbegin(); it != mstack.cend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Test reverse iterator
    std::cout << "Elements in reverse: ";
    for (MutantStack<int>::reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); ++rit) {
        std::cout << *rit << " ";
    }
    std::cout << std::endl;

    // Test const reverse iterator
    std::cout << "Elements in reverse using const reverse iterator: ";
    for (MutantStack<int>::const_reverse_iterator rit = mstack.crbegin(); rit != mstack.crend(); ++rit) {
        std::cout << *rit << " ";
    }
    std::cout << std::endl;

    // Test copy constructor
    MutantStack<int> mstack_copy(mstack);
    std::cout << "Elements in copied stack: ";
    for (MutantStack<int>::iterator it = mstack_copy.begin(); it != mstack_copy.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Test assignment operator
    MutantStack<int> mstack_assigned;
    mstack_assigned = mstack;
    std::cout << "Elements in assigned stack: ";
    for (MutantStack<int>::iterator it = mstack_assigned.begin(); it != mstack_assigned.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}


// int main()
// {
//     MutantStack<int> mstack;
//     mstack.push(5);
//     mstack.push(17);
//     std::cout << mstack.top() << std::endl;
//     mstack.pop();
//     std::cout << mstack.size() << std::endl;
//     mstack.push(3);
//     mstack.push(5);
//     mstack.push(737);
//     //[...]
//     mstack.push(0);
//     std::cout << "\nIterating..." << std::endl;
//     MutantStack<int>::iterator it = mstack.begin();
//     MutantStack<int>::iterator ite = mstack.end();
//     ++it;
//     --it;
//     while (it != ite)
//     {
//         std::cout << *it << std::endl;
//         ++it;
//     }
//     std::stack<int> s(mstack);
//     return 0;
// }