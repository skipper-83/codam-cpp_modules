#include "Span.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <chrono>

#define VECTOR_LENGHT 10
#define SPAN_SIZE 10

std::vector<int> createRandomVector(unsigned int size)
{
  std::srand(static_cast<unsigned int>((std::chrono::steady_clock::now().time_since_epoch().count())));
  std::vector<int> randomVector;
  for (unsigned int i = 0; i < size; i++)
  {
    randomVector.push_back(rand() % 2000000);
  }
  return randomVector;
}

void printVector(std::vector<int> intVector)
{
  std::cout << "[";
  for (std::vector<int>::iterator it = intVector.begin(); it != intVector.end(); it++)
  {
    std::cout << *it;
    if (it != intVector.end() - 1)
    {
      std::cout << ", ";
    }
  }
  std::cout << "]" << std::endl;
}

int main()
{
  std::cout << "Creating vector with random ints, size: " << VECTOR_LENGHT << std::endl;
  std::vector<int> intVector = createRandomVector(VECTOR_LENGHT);
  printVector(intVector);

  std::cout << "\nCreating Span with size: " << SPAN_SIZE << std::endl;
  Span span(SPAN_SIZE);
  std::cout << span << std::endl;

  std::cout << "\nAdding numbers to Span" << std::endl;
  span.addNumber(10);
  span.addNumber(20);
  std::cout << span << std::endl;

  // Adding too many numbers
  try
  {
    std::cout << "current size: " << span.size() << std::endl;
    std::cout << "Range length: " << std::distance(intVector.begin(), intVector.end()) << std::endl;
    std::cout << "Adding range to Span" << std::endl;
    span.addRange(intVector.begin(), intVector.end());
  }
  catch (std::exception &e)
  {
    std::cerr << e.what() << std::endl;
  }

  // Adding correct amount of numbers
  try
  {
    std::cout << "current size: " << span.size() << std::endl;
    std::cout << "Range length: " << std::distance(intVector.begin(), intVector.end() - 2) << std::endl;
    std::cout << "Adding range to Span" << std::endl;
    span.addRange(intVector.begin(), intVector.end() - 2);
    std::cout << span << std::endl;
  }
  catch (std::exception &e)
  {
    std::cerr << e.what() << std::endl;
  }
  std::cout << "Current size: " << span.size() << std::endl;
  std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
  std::cout << "Longest span: " << span.longestSpan() << std::endl;
  std::cout << std::endl;

  return 0;
}

// int main()
// {
// Span sp = Span(5);
// sp.addNumber(6);
// sp.addNumber(3);
// sp.addNumber(17);
// sp.addNumber(9);
// sp.addNumber(11);
// std::cout << sp.shortestSpan() << std::endl;
// std::cout << sp.longestSpan() << std::endl;
// return 0;
// }