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
        char top_element(); // 괄호 확인을 위해서
};

path_stack::path_stack() // init
{
    int top = 0; // 넣어야 할 위치
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

char path_stack::top_element()
{
    return (s[top--]);
}

bool is_parentheses(char x) // 괄호인지 찾는 함수
{
    if((x == '(') || (x == ')') ||
        (x == '{') || (x == '}') ||
        (x == '[') || (x == ']'))
        return true;
    else
        return false; // 괄호가 아닌 것
}

int get_pair(char pa1, char pa2){
    
}

int main() {

    // string 선언
    // stack 선언
    // 문구 출력
    // cin으로 입력 받기

    // 여는 괄호라면 스택에 넣기
    // 닫는 괄호라면 스택에서 빼고 비교
}