#include <iostream>
#include <string>

//  An ordered list using linked list
//  Practice in class

using namespace std;

class node {
public:
        string   name;
        double      score;
        node *link;
        void   set_data(string   s, double n);
};

void   node::set_data(string s, double n) {
           name = s;
           score = n;
}

class my_list {
        node   *head;
public:
        my_list() {
                head = NULL;
        }
        void insert_node(node   t);
        void show_all_data();
};

void my_list::insert_node(node t) {

    node *p, *k;
    p = new node;
    (*p) = t;
    if(head == NULL){
        p->link = head;
        head = p;
        return;
    } else {
        if(head->score > p->score){
            p->link = head;
            head = p;
            return;
        } else { // head->score 보다 p->score가 큰 경우
            k = head;
            while(k != NULL){
                if(k->link != NULL && k->link->score < p->score)
                    k = k->link;
                else if(k->score < p->score && k->link != NULL && k->link->score > p->score)
                    p->link = k->link->link;
                    k->link = p;
                    return;
            }
        }
    }
}

void my_list::show_all_data()
{
        node *p;

        for ( p = head; p != NULL; p = p->link)
                cout << p->name << " : " << p->score << endl;

}


int main()
{
my_list    thelist;
node   tmp;
        tmp.set_data("Kim", 73.5);
        thelist.insert_node(tmp);
        tmp.set_data("Lee", 82.2);
        thelist.insert_node(tmp);
        tmp.set_data("Park", 51.3);
        thelist.insert_node(tmp);
        tmp.set_data("Choi", 95.1);
        thelist.insert_node(tmp);
        tmp.set_data("Ryu", 71.3);
        thelist.insert_node(tmp);
        tmp.set_data("Yang", 58.2);
        thelist.insert_node(tmp);
        tmp.set_data("Hong", 83.5);
        thelist.insert_node(tmp);

        cout << "-- The list after insertions \n";
        thelist.show_all_data();

        return 0;
}

