#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery Creation Form rev2023c12.1", 145, 137), _target(target)
{
	std::cout << GRAY << "Shrubbery string constructor" << NO_COLOR << "\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : AForm(src), _target(src._target)
{
	std::cout << GRAY << "Shrubbery copy constructor" << NO_COLOR << "\n";
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << GRAY << "Shrubbery destructor" << NO_COLOR << "\n";
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(ShrubberyCreationForm const&  rhs)
{
	// Since almost all members are constant, this is a bit superfluous.
	if(this == &rhs)
		return *this;
	this->_target = rhs._target;
	return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	executeCheck(executor.getGrade(), *this);
	std::ofstream new_file(_target + "_shrubbery");
	new_file 
		<< "                           ⣦⣼⠻⠿⣦⣄ ⢀⣼⢦⡀                           \n"
		<< "                         ⢀⣴⡾⠃   ⠉⠙⠚⠙⢿⣿⣄                          \n"
		<< "                ⢀⣴⡾⣦⢾⣦⣤  ⢀⢙⡿⠃        ⠉⣿⡀⢀⣼⠿⣷⣼⣦⣀                  \n"
		<< "              ⣠⡴⠾⠋   ⠉⣻⡿⠞⠛⢻⣅⣀⡀        ⠙⡿⠛⠁ ⠉⠁⠛⣿⣾⡆                \n"
		<< "             ⠐⢿⡄      ⠈⠁    ⠉⠁                ⢀⣼⡁                \n"
		<< "              ⣾⡇                              ⢈⣹⡏                \n"
		<< "              ⠘⣿⣦⡀                         ⣀⣀⡶⣿⡉                 \n"
		<< "      ⢰⣦⣶⣶⣤⣀    ⢹⣷⣶⣦⣤⡶                    ⠈⢻⣦ ⢹⣧⣦⣴⠆⢠⣦⣦⡆          \n"
		<< "   ⢀⣠⣶⡾⠃  ⠉⠟⠷⢶⣶⣶⡀ ⣀⣤⣸⠇            ⢀⣤⣀⣤⣠⣤⡶⣿⣳⠟⠁⣤⣾  ⠘⠷⠋ ⣸⣇⡀         \n"
		<< " ⢰⣿⠟⠈⠁        ⠈⠛⠷⡼⠏ ⠁           ⢀⣾⠛ ⠈⠘⠃⠉  ⠈⠛⠒⠋       ⠈⠉⣿         \n"
		<< "⣰⣿⡿                     ⣴⡄⢀⣴⡇ ⢀⣠⣾⠉                    ⢾⡇⢀⣀⡀      \n"
		<< "⠋⣿⣶⡄              ⣀⣠⣤   ⢿⡽⣿⠿⣧⠷⣼⣧⠉⠁                    ⠈⠛⠋⢯⡆      \n"
		<< " ⣾⡿              ⠈⠋⠱⣿⣿⢶  ⢣⣿⡆⠈⡷⢷⡜⣷⣤                       ⣠⠇      \n"
		<< "⢸⣿⡇                   ⠙⣿⣓⣾⠽⣇ ⢁⡞⠑⠛⢻⡾⣷⣀⡄⣀⣤⣠⠄ ⣠⣤      ⣀⡀⣤⣠⣤⡼⣉⣤⣦⡀⢀   \n"
		<< "⠈⠙⣿⣄ ⣠⣦⡄  ⢰⣶⣆  ⡀    ⢠⣀⣴⠋⠉⠹⣆⢹⣄⠸ ⢠⠟⢸⠃⠈⠉⢻⡏⢻⠁ ⢠⣟⣞⣀  ⢀  ⠿⢽⣧⣹⣠⣿⠏⠉⠙⠛⢻⣖⠴⣦\n"
		<< "  ⠛⠿⠺⠻⠻⣧⣶⣴⣾⡿⣿⣴⠟⢛⡷⠂  ⡀ ⠁   ⠈⠛⣛⠓⣆⣞ ⡏   ⣸⠃⡏⢀⡠⠼⡟⢫⣧⡖⠊⠉     ⠉⠙⠁       ⣿\n"
		<< "       ⠈⠛⢻⣿⣤⣀ ⢠⡾⠁  ⠳⣽⠂⢀ ⣀⡴⣶⣶⠉⢷⠈⠙ ⣇  ⣰⢃⡼⠛⠉⣠⡤⠿⠻⣆⠙⢦                ⢿\n"
		<< "       ⢀⣀⣠⡏⠉⠻⡷⡞   ⣠⠞⣠⠴⠞⠋⠁ ⠈⢿⣇⡤⡶⠛⣷⣭    ⠁⣻⣋⣀⣀⣀⢀⣈⠳⠸⠷⠤⠆             ⣸\n"
		<< "    ⢠⣾⣟⠟⠛⠋       ⠠⢃⣰⠃      ⠈⠟   ⢱⢿⡀⠠⡤⢤⣼⠟⠋⠛⠉⠋⠁⠉⠁                ⣸⠻\n"
		<< "    ⠈⣿⠉           ⠉⠁             ⣼⠇⣼⠁⡟⠁                 ⣀⣀⣀⣄⣰⡞⠻⠃ \n"
		<< "     ⢻⣧⣤⣀⣄                   ⣀⣀⣴⠾⠋ ⠃⠠⡇  ⣀⡀⣀            ⣿⣿⣛⣋⡁⠉    \n"
		<< "      ⠉⠙⠉⣿⢂⣄     ⣿⢀⡀     ⢴⣤⠶⠷⠛⠉⢳    ⣰⠿⣤⢦⠟⢻⢻⡟           ⠈⠉⠻⣻⠟     \n"
		<< "         ⠉⢻⣿⣦⣴⣤⡿⢿⣋⣿⠇     ⠈⠙⠲⡄  ⢸   ⣰⠃ ⠉⠉ ⣾⡛⠁        ⣰⢦⣦⣤⣤⣴⡏      \n"
		<< "          ⠈ ⠉ ⠁ ⠈⣯⡀⡀⡀⢀ ⣠⡄⣼⠶⠾⠃  ⡞   ⢹     ⠈⢷⢦⣤⣄   ⢠⣤⣴⠟  ⠉ ⠈       \n"
		<< "                 ⠈⠛⠓⠛⠛⠛⠋⠛⠋     ⡇   ⢸⡇      ⠈ ⠹⠷⣾⡍⠛⠁              \n"
		<< "                               ⣷   ⢸           ⠈⠁                \n"
		<< "                               ⢸⡀  ⢸                             \n"
		<< "                               ⠈⡇  ⠸⡆                            \n"
		<< "                               ⢠⡇   ⢧⡀                           \n"
		<< "                              ⣰⠏    ⢈⡻⠆                          \n"
		<< "														kisses, " << executor.getName() << "\n";
}
std::string ShrubberyCreationForm::getTarget(void) const
{
	return _target;
}

std::ostream &operator<<(std::ostream &os, const ShrubberyCreationForm &t)
{
	os << "Form name:\t" << t.getName()
	<< "\nTarget:\t\t" << t.getTarget()
	<< "\nSign grade:\t" << t.getSignGrade()
	<< "\nExecute grade:\t" << t.getExecuteGrade()
	<< "\nSigned\t\t" << (t.isSigned() ? "yes" : "no");
	return (os);
}
