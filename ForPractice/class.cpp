#include<iostream>
using namespace std;

class Student {
    private:
        string name;
        string sid;
        int score[3]; // kor, eng, math
    public:
        // Student(string s1, string s2);
        void  print();
        void setData();
        int getSum();
        double getAvg();
};

// Student::Student(string s1, string s2)
// {   
//     name = s1;
//     sid = s2;
// }

void Student::setData()
{
    cout << "Enter a id, score, and name" << endl;
    cin >> sid >> score[0] >> score[1] >> score[2];
    cin.ignore(); // 입력 버퍼 비우기
    getline(cin, name);
}

int Student::getSum()
{
    int sum = 0;
    sum = score[0] + score[1] + score[2];

    return sum;
}

double Student::getAvg()
{
    double avg = getSum() / 3.0;

    return avg;
}


void Student::print()
{
    cout << "[" << sid << "]" << " " << name << endl;
    cout << "The Average score is " << getAvg();
}


int main(){

    Student s;
    s.setData();
    s.print();

    return 0;
}

