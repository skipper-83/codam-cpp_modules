#include "ScalarConverter.hpp"
#include <iostream>
#include <cmath>
#include <iomanip>

void ScalarConverter::convert(std::string const &input)
{
	try
	{
		Scalar scalar = determineType(input);
		_convertFunctions[scalar.type](input, scalar);
	}
	catch (InvalidInputException &e)
	{
		std::cout << e.what() << "\n\n";
		return;
	}
}

Scalar ScalarConverter::determineType(std::string const &input)
{
	size_t pos;
	Scalar scalar;
	scalar.precision = 0;
	scalar.charMessage = "";
	scalar.intMessage = "";
	scalar.floatMessage = "";

	if (input.length() == 3 && input[0] == '\'' && input[2] == '\'') // if the string is 3 characters long and the first and last characters are single quotes, it's a char
		return (scalar.type = CHAR, scalar);
	try
	{
		return infNanCheck(input, scalar);
	}
	catch (InvalidInputException &e)
	{
		if (input[0] == '-' || input[0] == '+' || isdigit(input[0]) || input[0] == '.') // if the first character is a digit, a minus sign or a dot, it's a number
		{

			if ((input[0] == '-' || input[0] == '+') && (input.length() <= 1 || !isdigit(input[1]))) // if the first character is a minus sign and the second character is not a digit, it's invalid
				throw InvalidInputException("siginfier without a digit following it");
			if ((pos = input.find('.')) != std::string::npos) // if there is a dot in the string, it's a float or a double
			{
				if (!isdigit(input[0]))
					scalar.precision--;
				for (size_t i = 1; i < pos; i++) // check if the characters before the dot are digits
				{
					if (!isdigit(input[i]))
						throw InvalidInputException("invalid character before dot");
				}
				for (size_t i = pos + 1; i < input.length(); i++) // check if the characters after the dot are digits
				{
					if (!isdigit(input[i]))
					{
						if (i == input.length() - 1 && (input[i] == 'f' || input[i] == 'F')) // if there is an f/F at the end of the string, it's a float
							return (scalar.type = FLOAT, scalar.precision += i - 1, scalar);
						throw InvalidInputException("invalid character after dot");
					}
				}
				return (scalar.type = DOUBLE, scalar.precision += input.length() - 1, scalar);
			}
			for (size_t i = 1; i < input.length(); i++) // if there is no dot in the string, it's an int
			{
				if (!isdigit(input[i])) // check if all the characters are digits
					throw InvalidInputException();
			}
			return (scalar.type = INT, scalar);
		}
	}
	throw InvalidInputException();
}

void ScalarConverter::convertChar(std::string const &input, Scalar &scalar)
{
	scalar.c = input[1];
	scalar.i = static_cast<int>(scalar.c);
	scalar.f = static_cast<float>(scalar.c);
	scalar.d = static_cast<double>(scalar.c);
	display(scalar);
}

void ScalarConverter::convertInt(std::string const &input, Scalar &scalar)
{
	try
	{
		scalar.i = std::stoi(input);
		rangeCheck(scalar.i, scalar.c, scalar.charMessage);
		scalar.f = static_cast<float>(scalar.i);
		scalar.d = static_cast<double>(scalar.i);
		display(scalar);
	}
	catch (const std::exception &e)
	{
		throw InvalidInputException(e.what());
	}
}

void ScalarConverter::convertFloat(std::string const &input, Scalar &scalar)
{
	scalar.f = std::stof(input);
	if (scalar.precision > std::numeric_limits<float>::digits10)
		throw InvalidInputException("too much siginificant digits for float, try double");
	scalar.d = static_cast<double>(scalar.f);
	if (scalar.charMessage.empty())
	{
		rangeCheck(scalar.f, scalar.c, scalar.charMessage);
		rangeCheck(scalar.f, scalar.i, scalar.intMessage);
	}
	display(scalar);
}

void ScalarConverter::convertDouble(std::string const &input, Scalar &scalar)
{
	if (scalar.precision > std::numeric_limits<double>::digits10)
		throw InvalidInputException("too much siginificant digits for double, I simply can't do it");
	scalar.d = std::stod(input);
	if (scalar.charMessage.empty())
	{
		rangeCheck(scalar.d, scalar.c, scalar.charMessage);
		rangeCheck(scalar.d, scalar.i, scalar.intMessage);
		scalar.f = static_cast<float>(scalar.d);
	}
	else
		rangeCheck(scalar.d, scalar.f, scalar.floatMessage);
	display(scalar);
}

void ScalarConverter::display(Scalar const &scalar)
{
	std::cout << "char: ";
	if (!scalar.charMessage.empty())
		std::cout << scalar.charMessage << "\n";
	else if (scalar.c < 32 || scalar.c > 126)
		std::cout << "non displayable\n";
	else
		std::cout << scalar.c << "\n";
	std::cout << "int: ";
	if (!scalar.intMessage.empty())
		std::cout << scalar.intMessage << "\n";
	else
		std::cout << scalar.i << "\n";
	std::cout << "float: ";
	if (!scalar.floatMessage.empty())
		std::cout << scalar.floatMessage << "\n";
	else if (scalar.precision == 0)
		std::cout << std::fixed << std::setprecision(1) << scalar.f << "f\n"
				  << std::setprecision(6) << std::defaultfloat;
	else
		std::cout << std::setprecision(scalar.precision > std::numeric_limits<float>::digits10 ? std::numeric_limits<float>::digits10 : scalar.precision) << scalar.f << "f\n"
				  << std::setprecision(6) << std::defaultfloat;
	std::cout << "double: ";
	if (scalar.precision == 0)
		std::cout << std::fixed << std::setprecision(1) << scalar.d << "\n"
				  << std::setprecision(6) << std::defaultfloat;
	else
		std::cout << std::setprecision(scalar.precision) << scalar.d << "\n"
				  << std::setprecision(6);
	std::cout << std::endl;
}

Scalar ScalarConverter::infNanCheck(std::string const &input, Scalar &scalar)
{
	std::string impossibleMessage;
	if (input == "-inff" || input == "+inff" || input == "inff" || input == "inf" || input == "-inf" || input == "+inf")
		impossibleMessage = "impossible: infinify";
	else if (input == "nan" || input == "nanf")
		impossibleMessage = "impossible: nan";
	else
		throw InvalidInputException();
	if ((impossibleMessage == "impossible: infinify" && input[input.length() - 1] == 'f') || (impossibleMessage == "impossible: nan" && input.back() == 'f'))
		scalar.type = FLOAT;
	else
		scalar.type = DOUBLE;
	return (scalar.charMessage = impossibleMessage, scalar.intMessage = impossibleMessage, scalar);
}

template <typename T, typename U>
void ScalarConverter::rangeCheck(U value, T &result, std::string &message)
{
	if (value > std::numeric_limits<T>::max() || value < std::numeric_limits<T>::min())
		message = "impossible -- out of range";
	else
		result = static_cast<T>(value);
}

ConvertFunctionPtr ScalarConverter::_convertFunctions[4] = {
	&ScalarConverter::convertChar,
	&ScalarConverter::convertInt,
	&ScalarConverter::convertFloat,
	&ScalarConverter::convertDouble};
