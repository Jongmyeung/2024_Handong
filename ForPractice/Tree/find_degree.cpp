// 문제설명(PPT 파일참조) 에서 제시한 binary tree에 속한 원소들의  다음 내용이 수행되도록 프로그램을 완성하시오.

//        cout << "The number of degree-2 nodes : " << thetree.n_d2_nodes() << endl;

//      cout << "The number of degree-1 nodes : " << thetree.n_d1_nodes() << endl;

//      cout << "The number of leaf nodes : " << thetree.n_leaf_nodes() << endl;
#include <iostream>
#include <string>

using namespace std;

class node
{
public:
    string name;
    double score;
    node *left, *right;
    void set_data(string s, double n);
};

void node::set_data(string s, double n)
{
    name = s;
    score = n;
}

class my_tree
{
public:
    int node_count;                         // 현재 node 수
    node *root;                             // root를 가리키는 pointer
    my_tree();                              // 초기화
    int insert_root(node t);                // root로 node내용 t추가
    int insert_left(string tname, node t);  // tname의 node 왼쪽에 t 추가
    int insert_right(string tname, node t); // tname의 node 왼쪽에 t 추가

    void find_n_d1(node *p);
    void find_n_d2(node *p);
    void find_n_leaf(node *p);

    int n_d2_nodes();
    int n_d1_nodes();
    int n_leaf_nodes();
    int count;
};

my_tree::my_tree()
{
    node_count = 0;
    root = NULL;
    count = 0;
}

int my_tree::insert_root(node t)
{
    if (root != NULL)
        return 0;
    node *p;
    p = new node;
    (*p) = t;
    p->left = NULL;
    p->right = NULL;
    root = p;
    node_count++;
    return 1;
}

int node_insert_left(node *p, string tname, node tnode)
{
    int result;
    if (p == NULL)
        return 0;
    if (p->name == tname)
    {
        if (p->left != NULL)
            return -1;

        node *t;
        t = new node;
        (*t) = tnode;

        t->left = NULL;
        t->right = NULL;
        p->left = t;
        return 1;
    }
    else
    {
        result = node_insert_left(p->left, tname, tnode);
        if (result != 0)
            return result;
        return node_insert_left(p->right, tname, tnode);
    }
}

int node_insert_right(node *p, string tname, node tnode)
{
    int result;
    if (p == NULL)
        return 0;
    if (p->name == tname)
    {
        if (p->right != NULL)
            return -1;

        node *t;
        t = new node;
        (*t) = tnode;

        t->left = NULL;
        t->right = NULL;
        p->right = t;
        return 1;
    }
    else
    {
        result = node_insert_right(p->left, tname, tnode);
        if (result != 0)
            return result;
        return node_insert_right(p->right, tname, tnode);
    }
}

int my_tree::insert_left(string tname, node tnode)
{
    int result;

    result = node_insert_left(root, tname, tnode);
    if (result == 1)
        node_count++;
    return result;
}

int my_tree::insert_right(string tname, node tnode)
{
    int result;

    result = node_insert_right(root, tname, tnode);
    if (result == 1)
        node_count++;
    return result;
}

void my_tree::find_n_d2(node *p)
{
    if (p == NULL) // 만약에 p가 NULL이면 return
        return;
    else if (p->left != NULL && p->right != NULL)
    {
        count++;
    }
    find_n_d2(p->left);
    find_n_d2(p->right);
};
int my_tree::n_d2_nodes()
{
    count = 0;
    find_n_d2(root);
    return count;
};

void my_tree::find_n_d1(node *p)
{
    if (p == NULL)
        return;
    if ((p->left == NULL) && (p->right != NULL) || (p->left != NULL) && (p->right == NULL)) // one of two 둘 중 하나만 NULL
    {
        count++;
    }
    find_n_d1(p->left);
    find_n_d1(p->right);
};
int my_tree::n_d1_nodes()
{
    count = 0;
    find_n_d1(root);
    return count;
};

void my_tree::find_n_leaf(node *p)
{
    if (p == NULL)
        return;
    else if (p->left == NULL && p->right == NULL)
    {
        count++;
    }
    find_n_leaf(p->left);
    find_n_leaf(p->right);
};
int my_tree::n_leaf_nodes()
{
    count = 0;
    find_n_leaf(root);
    return count;
};

int main()
{
    my_tree thetree;
    node tmp;
    tmp.set_data("Kim", 81.1);
    thetree.insert_root(tmp);
    tmp.set_data("Lee", 86.2);
    thetree.insert_left("Kim", tmp);
    tmp.set_data("Park", 79.4);
    thetree.insert_right("Kim", tmp);
    tmp.set_data("Choi", 77.8);
    thetree.insert_left("Lee", tmp);
    tmp.set_data("Ryu", 92.2);
    thetree.insert_right("Lee", tmp);
    tmp.set_data("Cho", 68.6);
    thetree.insert_right("Park", tmp);
    tmp.set_data("Yang", 72.8);
    thetree.insert_left("Ryu", tmp);
    tmp.set_data("Jung", 62.3);
    thetree.insert_left("Cho", tmp);

    cout << "The number of degree-2 nodes : " << thetree.n_d2_nodes() << endl;
    cout << "The number of degree-1 nodes : " << thetree.n_d1_nodes() << endl;
    cout << "The number of leaf nodes : " << thetree.n_leaf_nodes() << endl;

    return 0;
}
