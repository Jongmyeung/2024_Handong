#include<iostream>
using namespace std;

class weight{
    int kg; // This is private so have to access through public member functions
    int gram;
    public:
        void set_weight(int n1, int n2);
        int get_weight();
};

void weight::set_weight(int n1, int n2) // use scope resolution operator
{
    kg = n1;
    gram = n2;
}

int weight::get_weight() // use scope resolution operator
{
    return kg * 1000 + gram;
}

weight add_weight(weight w1, weight w2){ 
    weight W;
    int totalWeight, kg, g;
    totalWeight = w1.get_weight() + w2.get_weight();
    kg = totalWeight / 1000;
    g = totalWeight - (kg * 1000);

    W.set_weight(kg, g);
    
    return W;
}

bool less_than(weight w1, weight w2){
    if(w1.get_weight() < w2.get_weight()) // w1 is bigger than w2
        return true; // true == 1
    else 
        return false; // false == 0
}

int main()
{
weight w1, w2, w3;
    w1.set_weight(3, 400);
    w2.set_weight(2, 700);
    w3 = add_weight(w1, w2);
    cout << w3.get_weight() << " grams\n";
    if(less_than(w1, w2))
        cout << "yes.\n";
    else   
        cout << "no. \n";
}

