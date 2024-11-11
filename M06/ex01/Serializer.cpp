#include "Serializer.hpp"

/**
 * @brief Return the raw address of the Data object
 * 
 * @param ptr pointer to the Data object
 * @return uintptr_t 
 */
uintptr_t Serializer::serialize(Data *ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

/**
 * @brief Return a pointer to the Data object from the raw address
 * 
 * @param raw raw address of the Data object
 * @return Data* 
 */
Data *Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}