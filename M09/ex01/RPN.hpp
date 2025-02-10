#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <stack>
#include <vector>

class RPN;

using operatorFunction = int (RPN::*)(int, int);

class RPN {
    public:
        RPN(std::string expression);
        RPN(const RPN &original);
        ~RPN();

        RPN &operator=(const RPN &original);

        int calculate();
    
    typedef struct RPNElem {
        int value;
        operatorFunction operation;
    } RPNElem;

    private:
        RPN();
        int _mult(int a, int b);
        int _div(int a, int b);
        int _add(int a, int b);
        int _sub(int a, int b);
        std::vector<RPNElem> _expression;
		std::stack<int> _stack;
        operatorFunction _getOperation(std::string operation);
		void _parseExpression(std::string expression);
		bool _parseNumber(std::string &word, int &value);
};

#endif