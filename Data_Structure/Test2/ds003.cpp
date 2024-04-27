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

        int    count_high_score(int t);
        double d_min_max();  // 최대 점수와 최소 점수의 차이 값

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


int n_high_score(node *p, double t)
{
      int count = 0;

      if(p == NULL){
        return 0;
      }

      if(p->score > t){
        count++;
      }

      return n_high_score(p->left, t) + n_high_score(p->right, t) + count;
}


int    my_tree::count_high_score(int t)
{

        return  n_high_score(root, t);

}

double get_maxscore(node *p)
{
    double max = 0;

    if(p == NULL)
        return max;

    if(p->score > max){
        max = p->score;
    }

    double result1 = get_maxscore(p->left);

    if(max < result1){
        max = result1;
    }

    double result2 = get_maxscore(p->right);
    
    if(max < result2){
        max = result2;
    }

    return max;
}

double get_minscore(node *p)
{
    double min = 100;

    if(p == NULL)
        return min;

    if(p->score < min){
        min = p->score;
    }

    double result1 = get_minscore(p->left);

    if(min > result1){
        min = result1;
    }

    double result2 = get_minscore(p->right);
    
    if(min > result2){
        min = result2;
    }

    return min;
}

double my_tree::d_min_max()
{
    return (get_maxscore(root) - get_minscore(root));
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

        int n, t;
        double d;

        t = 80.0;   // the test data

        n = thetree.count_high_score(t);

        cout << "The number of students scoring over " << t <<  " points : " << n << endl;

        d = thetree.d_min_max();

        cout << "The difference between the highest and lowest : " << d << endl;

        return 0;

}








