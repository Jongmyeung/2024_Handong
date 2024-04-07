#include<iostream>
#include<string>
using namespace std;

#define EOS '$'

class node{
    public :
        char data;
        node *link;
        void set_data(char a);
};

class my_list {
    node *top;
    public :
        my_list();
        void add_to_top(node t);
        char delete_from_top();
        bool is_empty();
        char top_element();
};

void node::set_data(char a)
{   
    data = a;
}

my_list::my_list()
{
    top = NULL;
}

bool my_list::is_empty()
{
    if(top == NULL)
        return true;
    else 
        return false;
}

void my_list::add_to_top(node t) // 처음 node가 NULL을 가리키도록 그래서 가리키는 방향이 반대가 되도록 하자.
{
    node *newNode;
    newNode = new node;
    (*newNode) = t;
    newNode->link = NULL;

    if(top == NULL)
        top = newNode;
    else {
        newNode->link = top;
        top = newNode;
    } 
}
char my_list::delete_from_top()
{
    char delData;
    node *deleteNode = top;

    if(!is_empty()){
        top = top->link;
        delData = deleteNode->data;
        delete deleteNode;
    } 
    return delData;
}

char my_list::top_element()
{
    return top->data;
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
    my_list list;
    node tmp;
    cout << "Input an infix expression to convert : ";
    cin >> input;

    tmp.set_data(EOS);
    list.add_to_top(tmp);

    cout << list.top_element() << "\n";

    for(int i = 0; i < input.size(); i++){

       
        cout << input[i] << "\n";
         cout << output << "\n";

        if(is_operand(input[i])){
            output += input[i];
            continue;
        }

        if(input[i] == '('){
            tmp.set_data(input[i]);
            list.add_to_top(tmp);
            continue;
        } 
        
        if(input[i] == ')'){
            while(1){
                if(list.top_element() == '('){
                    bin += list.delete_from_top();
                    break;
                } else 
                    output += list.delete_from_top();
            }
        } else {
            while(1){
                if(get_precedence(input[i]) > get_precedence(list.top_element()))
                    break;
                output += list.delete_from_top();
            }
            tmp.set_data(input[i]);
            list.add_to_top(tmp);
        }
    }

    while(1){
        if(list.is_empty())
            break;
        
        if(list.top_element() == '$'){
            bin += list.delete_from_top();
            break;
        }

        output += list.delete_from_top();
    }

    cout << "Postfix is : " << output << endl;

    return EXIT_SUCCESS;
    
}


