#include <iostream>
using namespace std;

int main()
{
    int n1, n2, n3;
    cout << "Enter the first number:" << endl;
    cin >> n1;
    cout << "Enter the second number:" << endl;
    cin >> n2;
    cout << "Enter the third number:" << endl;
    cin >> n3;

    if (n1 > n2 && n1 > n3)
        cout << "The maximum number among the three is " << n1;
    else if (n2 > n1 && n2 > n3)
        cout << "The maximum number among the three is " << n2;
    else if (n3 > n1 && n3 > n2)
        cout << "The maximum number among the three is " << n3;
    else
        cout << "All the numbers are equal";
    return 0;
}
