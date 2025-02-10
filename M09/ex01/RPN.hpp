#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <stack>
#include <vector>

class RPN {
    public:
        RPN(std::string expression);
        RPN(const RPN &original);
        ~RPN();

        RPN &operator=(const RPN &original);

        int calculate();
    
    typedef struct RPNElem {
        int value;
        int (*operation)(int,int);
    } RPNElem;

    private:
        RPN();
        int _mult(int a, int b);
        int _div(int a, int b);
        int _add(int a, int b);
        int _sub(int a, int b);
        std::stack<RPNElem> _stack;
        int (*f)(int, int);
        int _getOperation(std::string op);
};

#endif