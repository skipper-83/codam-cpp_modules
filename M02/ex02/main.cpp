#include "Fixed.hpp"

int	main(void)
{
	float const	first = 3.12;
	float const	second = 4.23;
	
	Fixed inc;
	Fixed subj_mult = ( Fixed( 5.0508f ) * Fixed( 2 ) );
	Fixed const a(Fixed (first) + Fixed (second));
	Fixed const b(Fixed (first) - Fixed (second));
	Fixed const c(Fixed (first) * Fixed (second));
	Fixed const d(Fixed (first) / Fixed (second));


	std::cout << "class output " << a << " :: cpp output " << first + second << std::endl;
	std::cout << "class output " << b << " :: cpp output " << first - second << std::endl;
	std::cout << "class output " << c << " :: cpp output " << first * second << std::endl;
	std::cout << "class output " << d << " :: cpp output " << first / second << std::endl;

	std::cout << std::boolalpha << a << " == " << a << ": " << (a == a) << std::endl;
	std::cout << std::boolalpha << a << " == " << b << ": " << (a == b) << std::endl;
	std::cout << std::boolalpha << a << " != " << a << ": " << (a != a) << std::endl;
	std::cout << std::boolalpha << a << " != " << b << ": " << (a != b) << std::endl;
	std::cout << std::boolalpha << a << " >= " << a << ": " << (a >= a) << std::endl;
	std::cout << std::boolalpha << a << " >= " << b << ": " << (a >= b) << std::endl;
	std::cout << std::boolalpha << b << " >= " << a << ": " << (b >= a) << std::endl;
	std::cout << std::boolalpha << a << " <= " << a << ": " << (a <= a) << std::endl;
	std::cout << std::boolalpha << a << " <= " << b << ": " << (a <= b) << std::endl;
	std::cout << std::boolalpha << b << " <= " << a << ": " << (b <= a) << std::endl;
	std::cout << std::boolalpha << a << " < " << b << ": " << (a < b) << std::endl;
	std::cout << std::boolalpha << b << " < " << a << ": " << (b < a) << std::endl;
	std::cout << std::boolalpha << a << " > " << b << ": " << (a > b) << std::endl;
	std::cout << std::boolalpha << b << " > " << a << ": " << (b > a) << std::endl;

	std::cout << inc << std::endl;
	std::cout << ++inc << std::endl;
	std::cout << inc << std::endl;
	std::cout << inc++ << std::endl;
	std::cout << inc << std::endl;
	std::cout << --inc << std::endl;
	std::cout << inc << std::endl;
	std::cout << inc-- << std::endl;
	std::cout << inc << std::endl;

	std::cout << "Max " << a << " | " << b << ": " << Fixed::max(a, b) << std::endl;
	std::cout << "Min " << a << " | " << b << ": " << Fixed::min(a, b) << std::endl;
	std::cout << "Max " << inc << " | " << subj_mult << ": " << Fixed::max(inc, subj_mult) << std::endl;
	std::cout << "Min " << inc << " | " << subj_mult << ": " << Fixed::min(inc, subj_mult) << std::endl;

	std::cout << subj_mult << std::endl;

	return 0;
}