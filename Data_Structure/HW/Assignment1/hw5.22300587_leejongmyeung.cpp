#include<iostream>
#include<string>
using namespace std;

#define SIZE 100

string reverse(string a)
{
    char rever = a[0];
    string newrev = a.erase(0, 1);
    // cout << rever << " and " << newrev << endl;
    if(a.size() < 1)
        return std::string(1, rever); // char를 string으로 / 근데 왜 a로 했을 때는 안되는걸까...
    else
        return reverse(newrev) + rever;

}
int main() {

    string input, r_input;
    cout << "Input a string : ";
    cin >> input;

    r_input = reverse(input);

    cout << r_input  << endl;

    return 0;
}