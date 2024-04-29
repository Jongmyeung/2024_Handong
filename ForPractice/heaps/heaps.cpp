#include<iostream>
using namespace std;

#define HSIZE 100

class element {
    public:
        string name;
        double score;
        void set_data(string n, double s);
    
};

class my_heap {
    element h[HSIZE];
    int csize;
    public:
        my_heap();
        int h_size();
        void insert_heap(element t);
        element delete_heap();
        bool heap_full();
        bool heap_empty();
};

my_heap::my_heap(){
    csize = 0;
}

int my_heap::h_size(){
    return csize;
}

void my_heap::insert_heap(element t){
    /*
    size를 1 증가시킨다.
    끝 위치의 원소로부터 시작하여 다음 작업을 반복한다.
        parent의 key 값이 주어진 key 값보다 작으면,
            parent 원소 값을 현위치로 이동시키고
            parent로 위치를 옮긴다.
        parent 원소 값이 크거나 root에 도달하면 원소를 넣을 곳을 현위치로 확정한다.
    찾은 위치에 주어진 값을 넣는다.
    */

    csize++;
    int k = csize;
    while(k != 1 && t.score > h[k/2].score) // root가 array에서 1 위치이다.
    {
        h[k] = h[k/2];
        k = k/2;
    }
    h[k] = t;

}
element my_heap::delete_heap(){
    /*
    root의 원소를 저장 : return 준비
    끝 원소를 저장 : 위치를 조정할 원소
    size를 1 감소시킨다.
    root 위치의 원소로부터 시작하여 아래쪽으로 다음 작업을 반복하여 해당 원소(끝원소)를 넣을 위치를 찾는다.
        1) 더 이상 child가 없으면, parent의 위치로 결정
        2) left child와 right child(있으면)를 비교하여 key값의 큰 node를 선택하고,
        3) 해당 원소의 key값과 비교하여 child가 작으면 현 위치(parent 위치)로 결정
        4) child가 크면, 해당 child 원소 값을 parent로 이동시키고 위치를 child로 이동하여 1)부터 반복
    */

    element t; // t는 class!!
    element tmp;
    int parent, child;

    t = h[1];
    tmp = h[csize];
    csize--;
    parent = 1;
    child = 2;

    while(child <= csize){
        if((child < csize) && (h[child].score < h[child + 1].score)){
            child++;
        }
        if(tmp.score >= h[child].score){
            break;
        }
        h[parent] = h[child];
        parent = child;
        child *= 2;
    }
    h[parent] = tmp;
    return t;
}
bool my_heap::heap_full(){
    if(csize == HSIZE - 1)
        return true;
    else 
        return false;
}

bool my_heap::heap_empty(){
    if(csize == 0)
        return true;
    else 
        return false;
}

void element::set_data(string n, double s){
    name = n;
    score = s;
}

int main() {
    my_heap h1;

    element tmp;
    tmp.set_data("Kim", 88);
    h1.insert_heap(tmp);
    tmp.set_data("Lee", 77);
    h1.insert_heap(tmp);
    tmp.set_data("Park", 98);
    h1.insert_heap(tmp);
    tmp.set_data("Choi", 74);
    h1.insert_heap(tmp);
    tmp.set_data("Ryu", 94);
    h1.insert_heap(tmp);
    tmp.set_data("Cho", 85);
    h1.insert_heap(tmp);

    while(h1.h_size() > 0){
        tmp = h1.delete_heap();
        cout << tmp.name << " : " << tmp.score << endl;
    }

    return 0;
}