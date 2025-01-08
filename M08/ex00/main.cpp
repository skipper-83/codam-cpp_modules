#include <iostream>
#include <vector>
#include <list>
#include <cassert>

#include "easyfind.hpp"

// Include your easyfind function definition here.

void test_easyfind_vector() {
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);

    // Test: Value is found
    std::vector<int>::iterator it = easyfind(vec, 3);
    assert(it != vec.end() && *it == 3);

    // Test: Value is not found
    it = easyfind(vec, 10);
    assert(it == vec.end());

    // Test: First element
    it = easyfind(vec, 1);
    assert(it != vec.end() && *it == 1);

    // Test: Last element
    it = easyfind(vec, 5);
    assert(it != vec.end() && *it == 5);
}

void test_easyfind_list() {
    std::list<int> lst;
    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);
    lst.push_back(40);
    lst.push_back(50);

    // Test: Value is found
    std::list<int>::iterator it = easyfind(lst, 30);
    assert(it != lst.end() && *it == 30);

    // Test: Value is not found
    it = easyfind(lst, 60);
    assert(it == lst.end());

    // Test: First element
    it = easyfind(lst, 10);
    assert(it != lst.end() && *it == 10);

    // Test: Last element
    it = easyfind(lst, 50);
    assert(it != lst.end() && *it == 50);
}

void test_easyfind_empty_container() {
    std::vector<int> emptyVec;
    std::list<int> emptyList;

    // Test: Empty vector
    std::vector<int>::iterator it = easyfind(emptyVec, 1);
    assert(it == emptyVec.end());

    // Test: Empty list
    std::list<int>::iterator itList = easyfind(emptyList, 1);
    assert(itList == emptyList.end());
}

void test_easyfind_with_duplicates() {
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(2);
    vec.push_back(5);

    // Test: Finds the first occurrence of the value
    std::vector<int>::iterator it = easyfind(vec, 2);
    assert(it != vec.end() && *it == 2);
    assert(it == vec.begin() + 1); // Ensure it's the first occurrence
}

int main() {
    test_easyfind_vector();
    test_easyfind_list();
    test_easyfind_empty_container();
    test_easyfind_with_duplicates();

    std::cout << "All tests passed!" << std::endl;
    return 0;
}
