#include "canonical.hpp"

int	main()
{
	Canon	canon_standard;
	canon_standard.setFoo(42);
	Canon	canon_copy(canon_standard);
	std::cout << "Foo from std: " << canon_standard.getFoo() << std::endl;
	std::cout << "Foo from copy: " << canon_copy.getFoo() << std::endl;
	canon_copy.setFoo(12);
	Canon	canon_assigned;
	canon_assigned = canon_copy;
	std::cout << "Foo from copy: " << canon_copy.getFoo() << std::endl;
	std::cout << "Foo from assignment: " << canon_assigned.getFoo() << std::endl;
}