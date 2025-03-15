#include <iostream>
using namespace std;

int checkPrime(int n)
{
    if (n <= 1)
        return false;

    if (n == 2)
        return true;

    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            return false;
            break;
        }
    }
    return true;
}

int main()
{
    int n;
    cout << "Enter the number:";
    cin >> n;
    if (checkPrime(n))
        cout << "Prime Number";
    else
        cout << "Not a prime Number";

    return 0;
}