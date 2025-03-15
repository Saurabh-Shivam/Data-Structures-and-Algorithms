#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number:" << endl;
    cin >> n;

    int fact = 1;

    for (int i = 1; i <= n; i++)
    {
        fact *= i;
    }

    cout << "Factorial of " << n << " is " << fact;

    return 0;
}