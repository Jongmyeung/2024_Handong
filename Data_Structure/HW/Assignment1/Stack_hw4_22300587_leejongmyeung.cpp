#include<iostream>
#include<string>
using namespace std;

#define SIZE 100
#define YES 1
#define NO 0

class palin_stack{
    char s[SIZE];
    int top;
    public:
        palin_stack();
        void push(char x);
        char pop();
};

palin_stack::palin_stack()
{
    top = 0;
}

void palin_stack::push(char x)
{
    s[top] = x;
    top++;
}

char palin_stack::pop()
{
    top--;
    return(s[top]);
}

int is_palin(char x1, char x2)
{
    if(x1 == x2)
        return 1; // 같으면
    else 
        return 2; // 다르면
}

int main() {

    string input, output;
    palin_stack stack1;
    cout << "Input string : ";
    cin >> input;

    // input.size()의 값의 상관없이 2로 나누면 된다. 왜냐하면 2로 나누면 몫만 남기 때문에 홀수여도 가운데 문자를 무시할 수 있다.
    // 이거는 입력 때만 같다.
    int check = 0;
    int ha_len = (input.size() / 2);
    for(int i = 0; i < ha_len; i++){
        stack1.push(input[i]);
    }
    if(input.size() % 2 == 0){ // 짝수일 때 좀 다름...
        for(int i = ha_len; i < input.size(); i++){
            check = is_palin(stack1.pop(), input[i]);
            if(check == 2)
                break;
        }
    } else {
        for(int i = ha_len + 1; i < input.size(); i++){
            check = is_palin(stack1.pop(), input[i]);
            if(check == 2)
                break;
        }
    }
    if(check == 2)
        output += "No, It’s not a palindrome.\n";
    if(check == 1)
        output += "Yes, it’s a palindrome.\n";

    cout << output;
}