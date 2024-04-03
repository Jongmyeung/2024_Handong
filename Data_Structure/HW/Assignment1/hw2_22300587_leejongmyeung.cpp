#include<iostream>
#include<string>
using namespace std;

#define SIZE 100
#define EOS '$'

class oper_stack {
    private :
        char s[SIZE];
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
    return (s[top - 1]);
}

bool is_operand(char ch)
{
    if((ch == ')') || (ch == '(') ||
        (ch == '+') || (ch == '-') ||
        (ch == '*') || (ch == '/') ||
        (ch == '%') || (ch == '$'))
        return false;
    else 
        return true; // operand??? ??!
}

int get_precedence(char op) // $?? EOS?? ?????.
{
    if((op == '$') || (op == '('))
        return (0);
    if((op == '+') || (op == '-'))
        return (1);
    if((op == '*') || (op == '/') || (op == '%'))
        return (2);
    return (-1);
}

int main()
{
    string input, output, bin;
    oper_stack stack1;
    cout << "Input an infix expression to convert : ";
    cin >> input;
    // input += EOS; // ???? EOS ???

    // algorithm converting infix to postfix
    stack1.push(EOS);

    for(int i = 0; i < input.size(); i++){

        if(is_operand(input[i])){ // operand???? check???
            output += input[i];
            continue;
        }

        if(input[i] == '('){
            stack1.push(input[i]);
            continue;
        }
        if(input[i] == ')'){
            while(1){
                if(stack1.top_element() == '('){
                    bin += stack1.pop(); // ??????
                    break;
                } else {
                    output += stack1.pop(); // '('?? ???? ?????? pop??? ??????.
                }
            }
        } else {
            while(1){
                if(get_precedence(input[i]) > get_precedence(stack1.top_element()))
                    break;
                output += stack1.pop();
            }
            stack1.push(input[i]);
        }
    }

    while(1){
        if(stack1.empty()){
            break;
        }

        if(stack1.top_element() == '$'){ // ????? ??????? $?? ??????? ??? ???? ???
            bin = stack1.pop();
            break;
        }
        
        output += stack1.pop();
    }
    cout << output;
    
    return EXIT_SUCCESS;
}