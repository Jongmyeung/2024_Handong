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
    int insert_right(string tname, node t); // tname의 node 오른쪽에 t 추가
    double score_sum();                     // 모든 node의 score 합
    double score_average();                 // 모든 node의 core 평균
    void print_data_inorder();              // inorder 순서로 모든 node의 값 출력
    void print_data_preorder();             // preorder 순서로 모든 node의 값 출력
    void print_data_postorder();            // postorder 순서로 모든 node의 값 출력

    void nonrecursive_inorder();  // non-recursive inorder traversal
    void print_data_levelorder(); // levelorder 순서로 모든 node의 값 출력
};
my_tree::my_tree() // constructor : 초기 empty 상태 설정
{
    node_count = 0;
    root = NULL;
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

int my_tree::insert_right(string tname, node tnode)
{
    int result;
    result = node_insert_right(root, tname, tnode); // member 함수가 아님 if (result == 1)
    if (result == 1)
        node_count++;
    return result;
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

int my_tree::insert_left(string tname, node tnode)
{
    int result;
    result = node_insert_left(root, tname, tnode); // member 함수가 아님 if (result == 1)
    if (result == 1)
        node_count++;
    return result;
}

double sum_allnodes(node *p)
{
    if (p == NULL)
        return 0;
    return sum_allnodes(p->left) + sum_allnodes(p->right) + p->score;
}

double my_tree::score_sum()
{
    return sum_allnodes(root);
}

double my_tree ::score_average()
{
    return score_sum() / node_count;
}

//=========
// 주어진 node를 root로 하는 tree에 적용한 recursive function
void inorder_print(node *p)
{
    if (p == NULL)
        return;
    inorder_print(p->left);
    cout << p->name << " : " << p->score << "\n";
    inorder_print(p->right);
}

// my_tree의 member function
void my_tree::print_data_inorder()
{
    inorder_print(root);
}

//=========
// 주어진 node를 root로 하는 tree에 적용한 recursive function
void preorder_print(node *p)
{
    if (p == NULL)
        return;
    cout << p->name << " : " << p->score << "\n";
    preorder_print(p->left);
    preorder_print(p->right);
}

// my_tree의 member function
void my_tree::print_data_preorder()
{
    preorder_print(root);
}

//========
// 주어진 node를 root로 하는 tree에 적용한 recursive function
void postorder_print(node *p)
{
    if (p == NULL)
        return;
    postorder_print(p->left);
    postorder_print(p->right);
    cout << p->name << " : " << p->score << "\n";
}
// my_tree의 member function
void my_tree::print_data_postorder()
{
    postorder_print(root);
}

class nstack
{
private:
    int top;
    int SIZE;
    node *s[100]; // main으로부터 넘어오는 배열

public:
    nstack();           // 기초 설정 값
    void push(node *x); // 원소를 넣는 함수
    node *pop();        // 원소를 빼고 제거하는 함수
    bool stack_full();  // 원소가 다 찼는지 확인하는 함수
    bool stack_empty(); // 원수가 다 비워졌는지 확인하는 함수
};

nstack::nstack()
{
    top = 0; // top의 초기값은 index가 0이어야 함
}

void nstack::push(node *x)
{
    s[top] = x; // top이 0으로 선언되었으니 일단 파라미터로 받은 값을 저장한다.

    top++; // 이후에 top을 하나 증가시켜서 index의 증감을 해준다.
};

node *nstack::pop()
{
    top--;         // 마지막으로 저장된 원소의 값에서 하나가 증가된 상황이니 1을 빼주어야 한다.
    return s[top]; // 1을 빼준 top의 값은 마지막으로 저장된 원소의 위치를 가리키니 그 값을 return 하면 된다.
};

bool nstack::stack_full()
{
    if (top >= SIZE) // 만약 마지막 원소를 넣을 위치가 s
        return true;
    else
        return false;
}

bool nstack::stack_empty()
{
    if (top == 0)
        return true;
    else
        return false;
}

void my_tree::nonrecursive_inorder()
{
    nstack s1;
    node *t;

    t = root;
    while (1)
    {
        while (t != NULL)
        {
            s1.push(t);
            t = t->left;
        }
        while (t == NULL)
        {
            if (s1.stack_empty())
                return;
            t = s1.pop();
        }
        cout << t->name << " : " << t->score << endl;
        t = t->right;
    }
};

void my_tree::print_data_levelorder(){};

int main(void)
{

    my_tree thetree;
    node tmp;
    tmp.set_data("Kim", 8.1);
    thetree.insert_root(tmp);
    tmp.set_data("Lee", 6.5);
    thetree.insert_left("Kim", tmp);
    tmp.set_data("Park", 8.3);
    thetree.insert_right("Kim", tmp);
    tmp.set_data("Choi", 7.2);
    thetree.insert_left("Lee", tmp);
    tmp.set_data("Ryu", 9.0);
    thetree.insert_right("Lee", tmp);
    tmp.set_data("Cho", 7.7);
    thetree.insert_right("Park", tmp);

    // cout << "Score Sum : " << thetree.score_sum() << "\n";
    // cout << "Score Average : " << thetree.score_average() << "\n";
    // cout << "\n Inorder Traversal Result \n";
    // thetree.print_data_inorder();
    // cout << "\n Preorder Traversal Result \n";
    // thetree.print_data_preorder();
    // cout << "\n Postorder Traversal Result \n";
    // thetree.print_data_postorder();
    thetree.nonrecursive_inorder();
    // cout << thetree.root->left->name << endl;
    return 0;
}