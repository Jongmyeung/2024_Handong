// Infix expression을 Postfix expression으로 변환하는 프로그램을 작성하시오.
#include <iostream>
#include <string>
#define SIZE 100
#define EOS '$'
using namespace std;
       
 //문자 원소(operator)를 저장할 수 있는 stack class
 class op_stack{
        char s[SIZE];
        int top;
        public:
        op_stack();
        void push(char x);
        char pop();
        bool empty();
    
        char top_element();
        };
        op_stack::op_stack(){
            top =0;
        }
        void op_stack::push(char x){
            s[top]=x;
            top++;
        }
        char op_stack::pop(){
            top--;
            return(s[top]);
        }
        bool op_stack::empty(){
            return(top==0);
        }
        char op_stack::top_element(){
            return(s[top-1]);
        }

        //주어진 문자가 operand 인가 여부를 판단하는 함수
        bool is_operand(char ch)
        {
            if((ch=='(') || (ch==')')||
            (ch=='+')||(ch=='-')||
             (ch=='*')||(ch=='/')||
              (ch=='%')||(ch=='$'))
              return false;
              else
              return true;

        }

        //주어진 문자(operator)의 우선순위(precedence)를 알아내는 함수
        int get_precedence(char op)
        {
            if((op=='$')||(op=='('))
            return(0);
        if((op=='+')||(op=='-'))
            return(1);
        if((op=='*')||(op=='/')||(op=='%'))
            return(2);
        return(-1);
        }
//여기서부터 작성
  string infix_to_postfix(string input){
    op_stack stack1;
    string output;


    for(int i=0;i<input.size();i++){
        if(is_operand(input[i])){
            output+=input[i];
        }else{
            if(input[i] == '('){
                stack1.push(input[i]);
            }else if(input[i] == ')'){
                while(stack1.top_element() != '('){
                    output += stack1.pop();
                }
                stack1.pop();//'('제거
            }else{
                while(get_precedence(stack1.top_element())>=get_precedence(input[i])){
                    output+=stack1.pop();
                }
                stack1.push(input[i]);
            }
        }
    }
    while(!stack1.empty()&&stack1.top_element()!= EOS){
        output+=stack1.pop();
    }

    return output;
}

int main(){
    string input;
    cout <<"Input an infix expression to convert: ";
    cin >> input;

    string postfix=infix_to_postfix(input);
    cout <<"Postfix expression: "<< postfix <<endl;

    return 0;
}