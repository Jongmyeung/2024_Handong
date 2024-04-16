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

    node *newNode, *k;
    newNode = new node;
    (*newNode) = t;

    // debugging

    // cout << newNode->name << " : " << newNode->score << "\n" << endl;
    
    // node *p; 
    // for(p = head; p != NULL; p = p->link){
    //     cout << p->name << " : " << p->score << endl;
    // }
    // cout << "\n";

    if(head == NULL){ // case1 - list is empty
        newNode->link = head;
        head = newNode;
        return;
    } else {
        if(head->score > newNode->score){ // case2 - list is not empty but score in newNode is smaller than head
            newNode->link = head;
            head = newNode;
            return;
        } else {
            for(k = head; k != NULL; k = k->link){
                if(k->link == NULL){ // case3 - score in newNode is largest score in list
                    newNode->link = NULL;
                    k->link = newNode;
                    return;
                } else {
                    if(k->link->score > newNode->score) { // else
                        newNode->link = k->link;
                        k->link = newNode;
                        return;
                    }
                }
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

