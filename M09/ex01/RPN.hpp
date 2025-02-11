#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <stack>

class RPN;


class RPN {
    public:
        RPN(std::string expression);
        RPN(const RPN &original);
        ~RPN();

        RPN &operator=(const RPN &original);

        int calculate();

    private:
        RPN();
		
		std::string _expression;
		std::stack<int> _stack;

		void _parseExpression(std::string expression);
		bool _parseNumber(std::string &word, int &value);
		bool _isOperator(std::string &word);
		int _applyOperator(int a, int b, char op);
};

#endif