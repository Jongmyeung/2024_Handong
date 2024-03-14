#include<iostream>
#include<string>
using namespace std;

class oper_stack {
    private :
        char s[20];
        int top;
    public  :
        oper_stack();
        void push(char x);
        char pop();
        bool empty();
        char top_element();
};

oper_stack::oper_stack()
{
    top = 0;
}

void oper_stack::push(char x)
{
    s[top] = x;
    top++;
}

char oper_stack::pop()
{
    top--;
    return(s[top]);
}

bool oper_stack::empty()
{
    return (top == 0);
}

char oper_stack::top_element()
{
    return (s[top -1 ]);
}

bool is_operand(char ch)
{
    if((ch == ')') || (ch == '(') ||
        (ch == '+') || (ch == '-') ||
        (ch == '*') || (ch == '/') ||
        (ch == '%') || (ch == '$'))
        return false;
    else 
        return true;
}

int main()
{
    return EXIT_SUCCESS;
}