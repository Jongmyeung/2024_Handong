#include<iostream>
#include<string>
#define SIZE 100
using namespace std;

class op_stack{
    char s[SIZE];
    int top;
public:
    op_stack(){top=0;}
    void push(char x){s[top++] = x;}
    char pop() {return s[--top];}
    bool empty() {return top == 0;}
    char top_element() {return top > 0 ? s[top-1] : '\0';}
};

bool is_operand(char ch){
    return ch >= 'a' && ch <= 'z';
}

int get_precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/' || op == '%') return 2;
    return 0;
}

bool check_parentheses(string input, string &error){
    op_stack stack;
    char expected;

    for (char& ch : input){
        if (ch == '(' || ch == '['){
            stack.push(ch);
        }else if (ch == ')' || ch == ']'){
            if (stack.empty()){
                error = "Error: An extra parenthesis ')' is found";
                return false;
            }
            expected=stack.pop();
            if ((ch == ')'&&expected !='(')||(ch == ']' && expected != '[')){
                error = "Error: mis-matched parenthesis, '";
                if (expected == '(') {
                    error += ")' is expected.";
                } else if (expected == '[') {
                    error += "]' is expected.";
                } else if (expected == '{') {
                    error += "}' is expected.";
                } else {
                    error += "unknown closing parenthesis is expected.";
                }
                return false;
            }
        }
    }

    if (!stack.empty()) {
    // 스택이 비어있지 않은 경우 실행
    error = "Error: mis-matched parenthesis, '";
    expected = stack.pop(); // 스택의 가장 위의 요소를 제거하고 반환
    if (expected == '(') {
        error += ")' is expected.";
    } else if (expected == '[') {
        error += "]' is expected.";
    } else if (expected == '{') {
        error += "}' is expected.";
    } else {
        error += "unknown closing parenthesis is expected.";
    }
    return false; // 함수를 빠져나가며 false를 반환
}

    return true;
}

string infix_to_postfix(string input){
    op_stack stack;
    string output;

    for (char& ch : input){
        if (is_operand(ch)){
            output += ch;
        } else if (ch == '(' || ch == '['){
            stack.push(ch);
        } else if (ch ==')'||ch==']'){
            while (!stack.empty() && stack.top_element() != '(' && stack.top_element() != '[') {
                output += stack.pop();
            }
            stack.pop();
        } else {
            while(!stack.empty()&&get_precedence(stack.top_element())>=get_precedence(ch)){
                output+=stack.pop();
            }
            stack.push(ch);
        }
    }

    while(!stack.empty()){
        output+=stack.pop();
    }

    return output;
}

int main() {
    string input,error;
    cout << "Input an infix expression to convert: ";
    cin >> input;

    if (check_parentheses(input,error)) {
        cout << "It's a normal expression" << endl;
        string postfix = infix_to_postfix(input);
        cout << "Postfix expression: " << postfix << endl;
    } else {
        cout << error << endl;
    }
    return 0;
}
