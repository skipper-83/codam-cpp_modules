#include <iostream>
int main(void)
{
	int *a = new int[0];
	std::cout << "a: " << a << "a size: " << sizeof(a) << std::endl;

}