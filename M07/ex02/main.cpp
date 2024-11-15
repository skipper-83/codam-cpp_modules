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
}

// #include <iostream>
// #include "Array.hpp"

// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(nullptr));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;
// }