#include<iostream>
using namespace std;

class myStack {
    int s[100]; // SIZE is 100
    int top;
public:
    void init();
    void push(int x);
    int pop();
    bool stack_full();
    bool stack_empty();
};

void myStack::init() // initialize stack
{
    top = 0; // Top is zero
}

void myStack::push(int x) // add stack
{ 
    // if(!stack_full()){ // 이를 검사할 필요 없음. 왜냐하면 main코드에서 검사하고 이 함수를 실행하도록 하면 되기 때문! 분리시키는 작업이 필요함.
    //     s[top] = x;
    //     top++;
    // }
    s[top] = x;
    top++;
}

int myStack::pop()
{
    // if(!stack_empty()){ // 이를 검사할 필요 없음. 왜냐하면 main코드에서 검사하고 이 함수를 실행하도록 하면 되기 때문! 분리시키는 작업이 필요함.
    //     // top--;
    //     // return s[top];
    //     return s[--top];
    // }
    return s[--top];
}

bool myStack::stack_full()// check stack is full
{
    if(top >= 100)
        return true;
    else
        return false;
}

bool myStack::stack_empty()// check stack is empty
{
    if(top <= 0)
        return true;
    else 
        return false;
}

int main() 
{
myStack s1;
int list[5] = {32, 123, 27, 131, 242}, i, x;
    s1.init();
    for(i = 0; i < 5; i++) // oh... 
        if(list[i] > 100)
            s1.push(list[i]);
    while( !s1.stack_empty())
    {
        x = s1.pop();
        cout << x << endl; // endl is endline
    }
    return EXIT_SUCCESS;
}

