#include <iostream>
#include <string>

using namespace std;

class  node {
public :
     string  name;
     double  score;
     node  *left, *right;
     void set_data(string s, double n);
};

void node::set_data(string s, double n)
{
        name = s;
        score = n;
}

class my_queue {
public:
        node *q[100];
        int front;
        int rear;
        my_queue();
        bool queue_empty();
        void add(node *p);
        node* del();
};

my_queue::my_queue()
{
        front = rear = 0;
}

bool my_queue::queue_empty() {
        return (front == rear);
}

void my_queue::add(node *p)
{
        q[rear] = p;
        rear = (rear+1) % 100;
}


node* my_queue::del()
{
        node *tmp;
        tmp = q[front];
        front = (front+1) % 100;
        return tmp;
}

class s_record{
public:
        string name;
        double score;
};
class my_tree {
public :
        int   node_count;  // 현재 node 수
        node   *root;   // root를 가리키는 pointer
        my_tree();   // 초기화

        my_tree(s_record a[], int n); // array a의 n개 원소를 level order 순서로 초기화

        int insert_root(node t); // root로 node내용 t추가
        int insert_left(string tname, node t); // tname의 node 왼쪽에 t 추가
        int insert_right(string tname, node t); // tname의 node 왼쪽에 t 추가

        void  print_data_inorder();  // inorder 순서로 모든 node의 값 출력

        void insert_node_levelorder(node t);  // level order의 첫번째 빈자리에t를 추가
                                              //
};

my_tree::my_tree()
{
        node_count = 0;
        root = NULL;
}

void my_tree::insert_node_levelorder(node t) // 현재 tree에서 levelorder 순서로 첫번째로 빈 곳에 주어진 t를 추가하는 함수
{
    my_queue q;
    node *t;

    while(1){
        if(q.queue_empty())
            return;
    }
}

my_tree::my_tree(s_record  a[], int n)
{
    my_queue q;
    node *t;

    for(int i = 0; i < 5; i++){
        t = new node;
        t->name = a[i].name;
        t->score = a[i].score;
    }
}

int  my_tree::insert_root(node t)
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
        if (p == NULL) return 0;
        if (p->name == tname) {
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
        else {
                result = node_insert_left(p->left, tname, tnode);
                if (result != 0)
                        return result;
                return node_insert_left(p->right, tname, tnode);
        }

}
int node_insert_right(node *p, string tname, node tnode)
{
        int result;
        if (p == NULL) return 0;
        if (p->name == tname) {
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
        else {
                result = node_insert_right(p->left, tname, tnode);
                if (result != 0)
                        return result;
                return node_insert_right(p->right, tname, tnode);
        }

}

int  my_tree::insert_left(string tname, node tnode)
{
        int result;

        result = node_insert_left(root, tname, tnode);
        if (result == 1)
                node_count++;
        return result;

}

int  my_tree::insert_right(string tname, node tnode)
{
        int result;

        result = node_insert_right(root, tname, tnode);
        if (result == 1)
                node_count++;
        return result;
}

void inorder_print(node *p)
{
    if (p == NULL) return;

    inorder_print(p->left);
    cout << p->name << " : " << p->score << "\n";
    inorder_print(p->right);
}

void my_tree::print_data_inorder()
{
        inorder_print(root);
}

int main()
{
        my_tree  thetree;
        node  tmp;
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

        // insert nodes  in level order
        tmp.set_data("Son", 95.3);
        thetree.insert_node_levelorder(tmp);

        tmp.set_data("Joo", 58.2);
        thetree.insert_node_levelorder(tmp);

        cout << "-- Inorder sequence after the insertion of two nodes \n";
        thetree.print_data_inorder();

        cout << "\n\nThe number of nodes = " << thetree.node_count << endl;
        s_record   list[5] = { {"Kim", 55.5}, {"Lee", 66.6}, {"Park",77.7}, {"Choi", 88.8}, {"Ryu", 99.9} };

        my_tree  tree2(list, 5);

        cout << "\n\n-- Inorder sequence of the second tree\n";
        tree2.print_data_inorder();

        cout << "\n\nThe number of nodes in second tree = " << tree2.node_count << endl;
        return 0;

}





