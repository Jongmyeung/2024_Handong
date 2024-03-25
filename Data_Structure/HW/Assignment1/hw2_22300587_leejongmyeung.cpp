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
        return true; // operand라는 말!
}

int get_precedence(char op) // $는 EOS를 의미함.
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
    // input += EOS; // 끝에 EOS 추가

    // algorithm converting infix to postfix
    stack1.push(EOS);

    for(int i = 0; i < input.size(); i++){

        if(is_operand(input[i])){ // operand인지 check하기
            output += input[i];
        }

        if(input[i] == '('){
            stack1.push(input[i]);
        }
        if(input[i] == ')'){
            while(1){
                if(stack1.top_element() == '('){
                    bin += stack1.pop(); // 버리기
                    break;
                } else {
                    output += stack1.pop(); // '('이 나올 때까지 pop하여 출력한다.
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
    cout << output << endl;

    while(1){
        if(stack1.empty()){
            break;
        }

        if(stack1.top_element() == '$'){ // 스택에 남아있는 $는 출력하지 않기 위한 코드
            bin = stack1.pop();
            break;
        }
        
        output += stack1.pop();
    }
    cout << output;
    
    return EXIT_SUCCESS;
}