#include<iostream>
using namespace std;

class node {
    public:
        string name;
        double score;
        node *left, *right;
        void set_data(string s, double n);
};

class my_tree {
    public:
        int node_count;
        node *root;
        my_tree();
        int insert_root(node t);
        int insert_left(string name, node t);
        int insert_right(string name, node t);
        double score_sum();
        double score_average();
        void print_data_inorder();
        void print_data_preorder();
        void print_data_postorder();
};

void node::set_data(string s, double n)
{
    name = s;
    score = n;
}

my_tree::my_tree()
{
    node_count = 0;
    root = NULL;
}

int node_insert_left(node *p, string tname, node t)
{
    if(p == NULL)
        return 0;
    
    if(p->name == tname){
        if(p->left != NULL) // find correct name node but already there is data 
            return -1;

        node *k;
        k = new node;
        (*k) = t;
        k->left = NULL;
        k->right = NULL;
        p->left = k; // p가 넣으려고 하는 node 즉, k를 left가 가리키도록 한다

        return 1;

    } else {
        int result = node_insert_left(p->left, tname, t);

        if(result != 0)
            return result;

        return node_insert_left(p->right, tname, t);
    }
}

int node_insert_right(node *p, string tname, node t)
{
    if(p == NULL)
        return 0;
    
    if(p->name == tname){
        if(p->right != NULL)
            return -1;
        node *k;
        k = new node;
        (*k) = t;

        k->left = NULL;
        k->right = NULL;
        p->right = k;

        return 1;
    } else {
        int result = node_insert_right(p->left, tname, t);

        if(result != 0)
            return result;

        return node_insert_right(p->right, tname, t);
    }
}

double sum_allnodes(node *p)
{
    if(p == NULL)
        return 0;
    return sum_allnodes(p->left) + sum_allnodes(p->right) + p->score;
}

int my_tree::insert_root(node t)
{
    // if root is not NULL return 0
    if(root != NULL)
        return 0;
    // make new node memory and copy data
    node *p;
    p = new node;
    (*p) = t;
    // init its pointers
    p->left = NULL;
    p->right = NULL;
    // connect new node with root
    root = p;
    node_count++;
    return 1;
}

int my_tree::insert_left(string name, node t)
{
    int result;

    result = node_insert_left(root, name, t);
    // if result is 1 inserting is complete
    if(result == 1)
        node_count++;

    return result;
}

int my_tree::insert_right(string name, node t)
{
    int result;

    result = node_insert_right(root, name, t);
    // if result is 1 inserting is complete
    if(result == 1)
        node_count++;

    return result;
}

void inorder_print(node *p)
{
    if(p == NULL)
        return;
    inorder_print(p->left);
    cout << p->name << " : " << p->score << endl;
    inorder_print(p->right);
}

void preorder_print(node *p)
{
    if(p == NULL)
        return;
    cout << p->name << " : " << p->score << endl;
    preorder_print(p->left);
    preorder_print(p->right);
}

void postorder_print(node *p)
{
    if(p == NULL)
        return;
    postorder_print(p->left);
    postorder_print(p->right);
    cout << p->name << " : " << p->score << endl;
}

double my_tree::score_sum()
{
    return sum_allnodes(root);
}

double my_tree::score_average()
{
    return sum_allnodes(root) / node_count;
}

void my_tree::print_data_inorder()
{
    inorder_print(root);
}

void my_tree::print_data_preorder()
{
    preorder_print(root);
}
void my_tree::print_data_postorder()
{
    postorder_print(root);
}

int main(){

    my_tree tree;
    node tmp;

    tmp.set_data("Kim", 8.1);
    tree.insert_root(tmp);
    tmp.set_data("Lee", 6.5);
    tree.insert_left("Kim", tmp);
    tmp.set_data("Park", 8.3);
    tree.insert_right("Kim", tmp);

    tmp.set_data("Choi", 7.2);
    tree.insert_left("Lee", tmp);
    tmp.set_data("Ryu", 9.0);
    tree.insert_right("Lee", tmp);
    
    tmp.set_data("Cho", 7.7);
    tree.insert_right("Park", tmp);

    cout << "Score Sum : " << tree.score_sum() << "\n";
    cout << "Score Average : " << tree.score_average() << "\n";
    cout << "\nInorder Traversal Result \n";
    tree.print_data_inorder(); 
    cout << "\nPreorder Traversal Result \n";
    tree.print_data_preorder(); 
    cout << "\nPostorder Traversal Result \n";
    tree.print_data_postorder(); 

    return 0;
}