#include <iostream>
using namespace std;
#define Q_SIZE 100

// node
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

// stack
class mystack

{
private:
    int top;
    int SIZE;
    node *s[100]; // main으로부터 넘어오는 배열

public:
    mystack();
    void push(node *x); // 원소를 넣는 함수
    node *pop();        // 원소를 빼고 제거하는 함수
    bool stack_full();  // 원소가 다 찼는지 확인하는 함수
    bool stack_empty(); // 원수가 다 비워졌는지 확인하는 함수
    int topNum();
};

mystack::mystack()
{
    top = 0; // top의 초기값은 index가 0이어야 함
    SIZE = 100;
}

void mystack ::push(node *x)
{
    s[top] = x; // top이 0으로 선언되었으니 일단 파라미터로 받은 값을 저장한다.
    top++;      // 이후에 top을 하나 증가시켜서 index의 증감을 해준다.
};

node *mystack ::pop()
{
    top--;         // 마지막으로 저장된 원소의 값에서 하나가 증가된 상황이니 1을 빼주어야 한다.
    return s[top]; // 1을 빼준 top의 값은 마지막으로 저장된 원소의 위치를 가리키니 그 값을 return 하면 된다.
};

bool mystack ::stack_full()
{
    if (top >= SIZE) // 만약 마지막 원소를 넣을 위치가 s
        return true;
    else
        return false;
}

bool mystack ::stack_empty()
{
    if (top == 0)
        return true;
    else
        return false;
}

// queue
class my_queue
{
    node *q[Q_SIZE];
    int front, rear;

public:
    my_queue();
    void insert_q(node *x);
    node *delete_q(); // delete 사용은 유의 bool queue_full();
    bool queue_empty();
    bool queue_full();
};

my_queue::my_queue()
{
    front = 0;
    rear = 0;
}

void my_queue::insert_q(node *x)
{
    if (!queue_full())
    {
        q[rear] = x;
        rear = (rear + 1) % Q_SIZE;
    }
    // else part 구현 가능
}

node *my_queue::delete_q()
{
    node *tmp;
    if (!queue_empty())
    {
        tmp = q[front];
        front = (front + 1) % Q_SIZE;
        return (tmp);
    }
    else
        return NULL;
    // else part 구현 가능
}

bool my_queue::queue_full()
{
    if ((rear + 1) % Q_SIZE == front)
        return true;
    else
        return false;
}

bool my_queue::queue_empty()
{
    if (rear == front)
        return true;
    else
        return false;
}

// tree
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
    bool equal_test(my_tree t1, my_tree t2);
    bool equal_test(node *p1, node *p2);
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

        if (result == 0)
            return node_insert_left(p->right, tname, tnode);
        else
            return result;
    }
}

int my_tree::insert_left(string tname, node tnode)

{
    int result;
    result = node_insert_left(root, tname, tnode); // member 함수가 아님 if (result == 1)
    node_count++;
    return result;
}

void my_tree::nonrecursive_inorder()
{
    mystack s1;
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
}

void my_tree::print_data_levelorder()
{
    my_queue a1;
    node *t;

    if (root == NULL)
        return;
    a1.insert_q(root);
    while (1)
    {
        if (a1.queue_empty())
            return;
        t = a1.delete_q();
        cout << t->name << " : " << t->score << endl;
        if (t->left != NULL)
            a1.insert_q(t->left);
        if (t->right != NULL)
            a1.insert_q(t->right);
    }
}

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

node *make_copy(node *p)
{
    node *t;

    if (p == NULL)
        return 0;

    t = new node;

    *t = *p; // data copy
    t->left = make_copy(p->left);
    t->right = make_copy(p->right);
    return t;
}
void copy_tree(my_tree &t1, my_tree t2)
{
    t1.node_count = t2.node_count;
    t1.root = make_copy(t2.root);
}

bool equal_test(node *p1, node *p2)
{
    if ((p1 == NULL) && (p2 == NULL))
        return true;
    if (p1 == NULL)
        return false;
    if (p2 == NULL)
        return false;
    if (p1->name != p2->name)
        return false;
    if (p1->score != p2->score)
        return false;
    if (equal_test(p1->left, p2->left) && equal_test(p1->right, p2->right))
        return true;
    else
        return false;
}
// bool equal_test(node *p1, node *p2)
// {
//     return ((p1 == NULL) && (p2 == NULL) || (p1 != NULL) && (p2 != NULL) && (p1->name == p2->name) && (p1->score == p2->score) && equal_test(p1->left, p2->left) && equal_test(p1->right, p2->right));
// }
bool equal_tree(my_tree t1, my_tree t2)
{
    if (t1.node_count != t2.node_count)
        return false;
    return equal_test(t1.root, t2.root);
}

// 메인 함수
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

    cout << "\nNon-recursive Inorder Result \n";
    thetree.nonrecursive_inorder();
    cout << "\nLevel-Order traversal Result \n";
    thetree.print_data_levelorder();
    my_tree tree2;
    copy_tree(tree2, thetree);
    cout << "\nThe inorder traversal Result of the new tree \n";
    tree2.print_data_inorder();
    if (equal_tree(tree2, thetree))
        cout << "Yes\n";
    else
        cout << "No\n";
    tmp.set_data("Youn", 7.7);
    thetree.insert_right("Cho", tmp);
    if (equal_tree(tree2, thetree))
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}