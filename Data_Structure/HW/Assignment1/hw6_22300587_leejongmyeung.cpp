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
        node delete_from_head();
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
    p = new node; 
    (*p) = t;
    p->link = head; // head가 가리키는 곳을 copy
    head = p;
    if(tail == NULL) 
        tail = p;
}

void my_list::add_to_tail(node t)
{
    node *p;
    p = new node;
    (*p) = t;
    p->link = NULL;
    if(tail != NULL)
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
    for(t = head; t != NULL; t = t->link) 
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

double my_list::score_sum()
{
    node *t;
    double count = 0;
    for(t = head; t != NULL; t = t->link)
        count += t->score;
    return count;
}

double my_list::get_score(string t_name)
{
    node *t;
    double num = 0;
    for(t = head; t != NULL; t = t->link)
        if(t_name.compare(t->name) == 0) // compare() == 0 이면 같다는 것
            num = t->score;
    return num;
}

int my_list::remove_a_node(string t_name)
{

    node *t, *k;

    if(head == NULL){
        cout << "List is Empty ...\n";
        return 0;
    }
    
    if(head->name.compare(t_name) == 0) {
        node *deleteNode = head;
        head = head->link;
        delete deleteNode;
        return 1;
    }
    else {
        k = head;
        t = head->link;

        while(t != NULL){
            if(t->name.compare(t_name) == 0){
                node *deleteNode = t;
                k->link = t->link;
                delete deleteNode;
                return 1;
            } else {
                k = t;
                t = t->link;
            }
        }
    }
}

int main()
{
my_list a;
node tmp;
    tmp.set_data("Kim", 83.5);
    a.add_to_head(tmp);
    // cout << a.num_nodes();
    
    tmp.set_data("Lee", 78.2);
    a.add_to_head(tmp);
    // cout << a.num_nodes();
    cout << a.num_nodes() << ":" << a.score_sum() << "\n"; // 1단계 점검

    tmp.set_data("Park", 91.3);
    a.add_to_tail(tmp);
    // cout << a.num_nodes() << "\n";

    cout << a.num_nodes() << ":" << a.score_sum() << "\n"; // 2단계 점검
    tmp = a.delete_from_head();
    cout << tmp.name << " is deleted.\n"; // 3단계 점검
    tmp.set_data("Choi", 85.1);
    a.add_to_tail(tmp);
    tmp.set_data("Ryu", 94.3);
    a.add_to_head(tmp); 
    cout << a.num_nodes()<< ":" << a.score_sum() << "\n"; 
    cout << "Park??s score : " << a.get_score("Park")<< "\n"; // 4단계 점검
    if(a.remove_a_node("Kim") == 1)
        cout << "Kim is deleted from the list.\n"; // 5단계 점검
    cout << a.num_nodes() << ":" << a.score_sum() << "\n"; // 최종 점검
    return 0;
}