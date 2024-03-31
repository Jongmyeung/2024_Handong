#include<iostream>
#include<string.h>
using namespace std;

class node {
    public :
        string name;
        double score;
        node *link;
        void set_data(string s, double n);
};

class my_list {
    node *head, *tail;
    public:
        my_list(); // constructor
        void add_to_head(node t);
        void add_to_tail(node t);
        void delete_from_head();
        int num_nodes();
        bool list_empty();
        double score_sum();
        double get_score(string t_name);
        int remove_a_node(string t_name);
};

void node::set_data(string s, double n)
{
    name = s;
    score = n;
}

my_list::my_list()
{
    head = NULL;
    tail = NULL;
}

void my_list::add_to_head(node t)
{
    node *p;
    p = new node; // c언어 메모리 할당
    (*p) = t;
    p->link = head; // head가 가리키고 있는 곳 copy
    if(tail = NULL) 
        tail = p;
}

void my_list::add_to_tail(node t)
{
    node *p;
    p = new node;
    (*p) = t;
    p->link = NULL;
    if(tail != NULL) // tail이 가리키고 있는 곳이 있는 경우
        tail->link = p;
     else    
        head = p;
    tail = p;
}

node my_list::delete_from_head()
{
    node temp;
    node *t;
    t = head;
    temp = *head;
    head = head->link;
    delete t;
    if(head == NULL)
        tail = NULL;
    return temp;
}

int my_list::num_nodes()
{
    node *t;
    int count = 0;
    for(t = head; t != NULL; t = t->link) // 순회하기
        count++;
    return count;
}

bool my_list::list_empty()
{
    if(head == NULL)
        return true;
    else  
        return false;
}