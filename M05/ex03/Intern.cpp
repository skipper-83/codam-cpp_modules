#include "Intern.hpp"

Intern::Intern()
{
        std::cout << GRAY << "Intern standard constructor\n" << NO_COLOR;
}

Intern::Intern(Intern const &src)
{
          std::cout << GRAY << "Intern copy constructor\n" << NO_COLOR;
}

Intern::~Intern()
{
      std::cout << GRAY << "Intern destructor\n" << NO_COLOR;
}

Intern &Intern::operator=(Intern const &rhs)
{
    std::cout << GRAY << "Intern copy assignment operator\n" << NO_COLOR;
    if (this == &rhs)
        return (*this);
    
}
