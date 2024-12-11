#include <iostream>
#include "Array.hpp"
#include <string>
#include <chrono>

#define ENTRIES 5
int main(void)
{
	std::string numbers[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

	Array<float> floatArr(ENTRIES);
	Array<int> intArr(ENTRIES);
	Array<std::string> stringArr(ENTRIES);

	std::cout << "INITILAIZED ARRAYS" << std::endl;
	std::cout << "Float array: " << floatArr.printElements() << std::endl;
	std::cout << "Int array: " << intArr.printElements() << std::endl;
	std::cout << "String array: " << stringArr.printElements() << std::endl;
	std::cout << std::endl << std::endl;

	for (int i = 0; i < ENTRIES; i++)
	{
		int randInt = std::rand() % 100;
		floatArr[i] = randInt / 10.0;
		intArr[i] = randInt;
		stringArr[i] = numbers[(randInt / 10) % 10] + "." + numbers[randInt % 10];
	}

	std::cout << "AFTER ASSIGNING VALUES" << std::endl;
	std::cout << "Float array: " << floatArr.printElements() << std::endl;
	std::cout << "Int array: " << intArr.printElements() << std::endl;
	std::cout << "String array: " << stringArr.printElements() << std::endl;
	std::cout << std::endl << std::endl;

	Array<float> floatArrCopy(floatArr);
	Array<int> intArrCopy(intArr);
	Array<std::string> stringArrCopy(stringArr);

	std::cout << "AFTER COPYING" << std::endl;
	std::cout << "Float array:\t\t" << floatArr.printElements() << std::endl;
	std::cout << "Float array copy:\t" << floatArrCopy.printElements() << std::endl;
	std::cout << "Int array:\t\t" << intArr.printElements() << std::endl;
	std::cout << "Int array copy:\t\t" << intArrCopy.printElements() << std::endl;
	std::cout << "String array:\t\t" << stringArr.printElements() << std::endl;
	std::cout << "String array copy:\t" << stringArrCopy.printElements() << std::endl;
	std::cout << std::endl << std::endl;

	Array<float> floatArrAssign = floatArr;
	Array<int> intArrAssign = intArr;
	Array<std::string> stringArrAssign = stringArr;

	std::cout << "AFTER ASSIGNING" << std::endl;
	std::cout << "Float array:\t\t" << floatArr.printElements() << std::endl;
	std::cout << "Float array copy:\t" << floatArrCopy.printElements() << std::endl;
	std::cout << "Float array assign:\t" << floatArrAssign.printElements() << std::endl;
	std::cout << "Int array:\t\t" << intArr.printElements() << std::endl;
	std::cout << "Int array copy:\t\t" << intArrCopy.printElements() << std::endl;
	std::cout << "Int array assign:\t" << intArrAssign.printElements() << std::endl;
	std::cout << "String array:\t\t" << stringArr.printElements() << std::endl;
	std::cout << "String array copy:\t" << stringArrCopy.printElements() << std::endl;
	std::cout << "String array assign:\t" << stringArrAssign.printElements() << std::endl;
	std::cout << std::endl << std::endl;

	for (int i = 0; i < ENTRIES; i++)
	{
		int randomInt = std::rand() % 100;
		floatArrCopy[i] = randomInt / 10.0;
		intArrCopy[i] = randomInt;
		stringArrCopy[i] = numbers[(randomInt / 10) % 10] + "." + numbers[randomInt % 10];
	}

	std::cout << "AFTER CHANGING COPIES" << std::endl;
	std::cout << "Float array:\t\t" << floatArr.printElements() << std::endl;
	std::cout << "Float array copy:\t" << floatArrCopy.printElements() << std::endl;
	std::cout << "Float array assign:\t" << floatArrAssign.printElements() << std::endl;
	std::cout << "Int array:\t\t" << intArr.printElements() << std::endl;
	std::cout << "Int array copy:\t\t" << intArrCopy.printElements() << std::endl;
	std::cout << "Int array assign:\t" << intArrAssign.printElements() << std::endl;
	std::cout << "String array:\t\t" << stringArr.printElements() << std::endl;
	std::cout << "String array copy:\t" << stringArrCopy.printElements() << std::endl;
	std::cout << "String array assign:\t" << stringArrAssign.printElements() << std::endl;
	std::cout << std::endl << std::endl;

	for (int i = 0; i < ENTRIES; i++)
	{
		int randomInt = std::rand() % 100;
		floatArrAssign[i] = randomInt / 10.0;
		intArrAssign[i] = randomInt;
		stringArrAssign[i] = numbers[(randomInt / 10) % 10] + "." + numbers[randomInt % 10];
	}

	std::cout << "AFTER CHANGING ASSIGNMENTS" << std::endl;
	std::cout << "Float array:\t\t" << floatArr.printElements() << std::endl;
	std::cout << "Float array copy:\t" << floatArrCopy.printElements() << std::endl;
	std::cout << "Float array assign:\t" << floatArrAssign.printElements() << std::endl;
	std::cout << "Int array:\t\t" << intArr.printElements() << std::endl;
	std::cout << "Int array copy:\t\t" << intArrCopy.printElements() << std::endl;
	std::cout << "Int array assign:\t" << intArrAssign.printElements() << std::endl;
	std::cout << "String array:\t\t" << stringArr.printElements() << std::endl;
	std::cout << "String array copy:\t" << stringArrCopy.printElements() << std::endl;
	std::cout << "String array assign:\t" << stringArrAssign.printElements() << std::endl;
	std::cout << std::endl << std::endl;

	Array<int> intArrEmpty;
	Array<int> intArraySizeOne(1);
	std::cout << "Empty int array: " << intArrEmpty.printElements() << std::endl;
	try{
		std::cout << "Trying to access element at index 0: " << intArrEmpty[0] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "Int array with size 1: " << intArraySizeOne.printElements() << std::endl;
	try{
		std::cout << "Trying to access element at index 0: " << intArraySizeOne[0] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try{
		std::cout << "Trying to access element at index 1: " << intArraySizeOne[1] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
