#include "iter.hpp"
#include <iostream>

void print_char(char &c)
{
    std::cout << c;
}

void to_upper(char &c)
{
    if (c >= 'a' && c <= 'z')
        c -= 32;
}

void print_int(int &i)
{
    std::cout << i << " ";
}

void square(int &i)
{
    i *= i;
}

void print_float(float &f)
{
    std::cout << f << " ";
}

void half(float &f)
{
    f /= 2;
}

int main (void)
{
    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "Testing with chars:" << std::endl;
    char array[] = "Hello, World!";
    iter(array, 13, print_char);
    std::cout << std::endl;
    iter(array, 13, to_upper);
    iter(array, 13, print_char);
    std::cout << std::endl;
    std::cout << "---------------------------------------------" << std::endl << std::endl;

    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "Testing with ints:" << std::endl;
    int int_array[] = {1, 2, 3, 4, 5};
    iter(int_array, 5, print_int);
    std::cout << std::endl;
    iter(int_array, 5, square);
    iter(int_array, 5, print_int);
    std::cout << std::endl;
    std::cout << "---------------------------------------------" << std::endl << std::endl;

    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "Testing with floats:" << std::endl;
    float float_array[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    iter(float_array, 5, print_float);
    std::cout << std::endl;
    iter(float_array, 5, half);
    iter(float_array, 5, print_float);
    std::cout << std::endl;
    std::cout << "---------------------------------------------" << std::endl << std::endl;

}