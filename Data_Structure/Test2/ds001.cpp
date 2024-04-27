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

class my_tree {
public :
        int   node_count;  // 현재 node 수
        node   *root;   // root를 가리키는 pointer
        my_tree();   // 초기화
        int insert_root(node t); // root로 node내용 t추가
        int insert_left(string tname, node t); // tname의 node 왼쪽에 t 추가
        int insert_right(string tname, node t); // tname의 node 왼쪽에 t 추가

        double max_score();
        double get_score_byname(string tname);
        int    n_d1_nodes();
        int    n_d2_nodes();
        int    n_leaf_nodes();

};

my_tree::my_tree()
{
        node_count = 0;
        root = NULL;
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


int count_leaf_nodes(node *p)
{
    int count = 0;
    if(p == NULL)
        return 0;
    if((p->left == NULL) && (p->right == NULL)){
        count++;
    }
    return count_leaf_nodes(p->left) + count_leaf_nodes(p->right) + count;  
}   


int  my_tree::n_leaf_nodes()
{
        return count_leaf_nodes(root);
}



int count_d1_nodes(node *p)
{
    int count = 0;
    if(p == NULL)
        return 0;
    if((p->left == NULL && p->right != NULL) || (p->left != NULL && p->right == NULL)){
        count++;
    }
    return count_d1_nodes(p->left) + count_d1_nodes(p->right) + count;
}


int  my_tree::n_d1_nodes()
{
        return count_d1_nodes(root);
}

int count_d2_nodes(node *p)
{
    int count = 0;
    if(p == NULL)
        return 0;
    if((p->left != NULL) && (p->right != NULL)){
        count++;
    } 
    return count_d2_nodes(p->left) + count_d2_nodes(p->right) + count;
}


int  my_tree::n_d2_nodes()
{
        return count_d2_nodes(root);
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

        cout << "The number of degree-2 nodes : " << thetree.n_d2_nodes() << endl;
        cout << "The number of degree-1 nodes : " << thetree.n_d1_nodes() << endl;
        cout << "The number of leaf nodes : " << thetree.n_leaf_nodes() << endl;

        return 0;

}

