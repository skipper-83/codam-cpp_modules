#ifndef CANONICAL_H
#define CANONICAL_H
#include <iostream>

class Canon
{
	public:
		Canon();
		Canon(Canon const& src);
		~Canon();

		Canon&	operator=(Canon const& rhs);
		int		getFoo();
		void	setFoo(int);
	
	private:
		int	_foo;
};

#endif