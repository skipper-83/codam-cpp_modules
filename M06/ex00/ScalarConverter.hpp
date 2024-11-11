#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <string>

enum ScalarType
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE
};

struct Scalar
{
	ScalarType type;
	char c;
	int i;
	float f;
	double d;
	int precision;
	std::string charMessage;
	std::string intMessage;
	std::string floatMessage;
};

typedef void (*ConvertFunctionPtr)(std::string const &input, Scalar &scalar);


class ScalarConverter
{
	public:
		static void convert(std::string const &input);

	private:
		ScalarConverter();

		static Scalar determineType(std::string const &input);
		static ConvertFunctionPtr _convertFunctions[4];

		static void convertChar(std::string const &input, Scalar &scalar);
		static void convertInt(std::string const &input, Scalar &scalar);
		static void convertFloat(std::string const &input, Scalar &scalar);
		static void convertDouble(std::string const &input, Scalar &scalar);
		static void display(Scalar const &scalar);
		static Scalar infNanCheck(std::string const &input, Scalar &scalar);
	
	class InvalidInputException : public std::exception
	{
		private:
			std::string _message;

		public:
			InvalidInputException() : _message("Invalid input: generic input error") {}
			InvalidInputException(std::string const &message) : _message("Invalid input: " + message) {}
			~InvalidInputException() throw() {} // had to put this here to avoid compiler warning
			virtual const char *what() const throw() {
				return _message.c_str();
			};
	};
};

#endif

