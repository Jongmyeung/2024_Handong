#include <iostream>

using namespace std;


int main() {
    int num1, num2;

    // 사용자로부터 두 개의 정수를 입력받음
    cout << "Enter the first number: ";
    cin >> num1;

    cout << "Enter the second number: ";
    cin >> num2;

    // 두 수를 더함
    int sum = num1 + num2;

    // 결과를 출력
    cout << "The sum of " << num1 << " and " << num2 << " is: " << sum << std::endl;

    return 0;
}
