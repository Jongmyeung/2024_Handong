#include<iostream>
#include<string>
using namespace std;

#define SIZE 100
#define YES 1
#define NO 0

int check(string input, int a, int b) // a, b는 index의 처음과 마지막을 의미 -> palindrome이니까!
{
    if(b - a < 1)
        return 1;
    else {
        if(input[a] == input[b])
            return 1 * check(input, a+1, b-1);
        else
            return 0 * check(input, a+1, b-1); // 만약 같지 않으면 0을 곱한다. 그렇게 하면 결과값이 0이 나오게 되어 있다.
    }
}


int main() {

    string input;
    int len;
    cout << "Input a string : ";
    cin >> input;

    len = input.size();
    if(check(input, 0, len-1) == YES)
        cout << "Yes, it is a palindrome. \n";
    else 
        cout << "No, it is not a palindrome. \n";

    return 0;
}