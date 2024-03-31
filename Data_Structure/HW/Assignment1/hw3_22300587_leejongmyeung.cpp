#include<iostream>
#include<string>
using namespace std;

#define SIZE 100 // define에서 ; 필요 없음

class path_stack { // (parentheses)
    char s[SIZE];
    int top;
    public:
        path_stack();
        void push(char x);
        char pop();
        bool is_empty();
};

path_stack::path_stack() // init
{
    top = 0; // 넣어야 할 위치
}

void path_stack::push(char x)
{
    s[top] = x;
    top++;
}

char path_stack::pop()
{
    top--;
    return(s[top]);
}

bool path_stack::is_empty()
{
    if(top == 0)
        return true;
    else 
        return false;
}

int is_parenthesis(char x) // 여는 괄호인지 찾는 함수
{
    if((x == '(') || (x == '{') || (x == '['))
        return 0;
    else if((x == ')') || (x == '}') || (x == ']'))
        return 1;
    else 
        return 2; 
}

int is_pair(char x1, char x2)
{
    if(x2 == ')')
        if(x1 == '(')
            return 1;
    if(x2 == '}')
        if(x1 == '{')
            return 1;
    if(x2 == ']')
        if(x1 == '[')
            return 1;
    return 0;
}

char get_pair(char x)
{
    if(x == '(')
        return ')';
    if(x == '{')
        return '}';
    if(x == '[')
        return ']';
}

int main() {

    string input, output, bin; // string 선언
    path_stack stack1; // stack 선언
    int check = 0;
    cout << "Input an expression : ";
    cin >> input; // cin으로 입력 받기
    
    for(int i = 0; i < input.size(); i++){
        
        if(is_parenthesis(input[i]) == 0) {
            // cout << input[i] << endl;
            stack1.push(input[i]);
        } else if (is_parenthesis(input[i]) == 1) { // 닫는 괄호인 경우
            // cout << input[i] << endl;
            if(stack1.is_empty()){
                check = 1;
                output += "Error: An extra parenthesis ‘" + std::string(1, input[i]) + "’ is found.\n"; // 여는 괄호 부족한 상황 (1)
                break;
            }
            char a = stack1.pop();
            if(is_pair(a, input[i]) != 1){ 
                check = 2;
                output += "Error: mis-matched parenthesis, ‘" + std::string(1, get_pair(a)) + "’ is expected."; // 괄호 타입이 맞지 않음.(2)
                break;
            }
        } else {
            // cout << input[i] << endl;
            bin += input[i];
        }
    }

    if(check != 1 && check != 2)
        if(stack1.is_empty() == 1)
            output += "It’s a normal expression\n"; // 괄호 타입 맞음
        else
            output += "Closing parenthesis lack.\n"; // 닫는 괄호 부족

    cout << output;

    return EXIT_SUCCESS;
}