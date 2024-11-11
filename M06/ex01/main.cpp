#include "Serializer.hpp"
#include <iomanip>

int main (void)
{
	Data data = { 42, "Hello, World!" };
	uintptr_t raw;
	Data* dataPtr;

	std::cout << "\n\n___***___ DESERIALIZER ___***___\n\n" << std::endl;
	std::cout << "Original data:\t\t\t\t" << data << std::endl;
	raw = Serializer::serialize(&data);
	std::cout << "Raw pointer from data:\t\t\t" << std::hex << std::showbase << raw << std::endl;
	dataPtr = Serializer::deserialize(raw);
	std::cout << std::dec << "Data pointed to by deserialized ptr:\t" << *dataPtr << std::endl;
	std::cout << "Original data is untouched:\t\t" << data << std::endl;

	return 0;
	
}