#include <iostream>
using namespace std;

int checkPrime(int num)
{
    if (num <= 1)
        return false;
    if (num == 2)
        return true;
    for (int i = 2; i < num; i++)
    {
        if (num % i == 0)
            return false;
    }

    return true;
}

void printPrime(int n)
{
    for (int i = 0; i < n; i++)
    {
        if (checkPrime(i))
            cout << i << " ";
    }
}

int main()
{
    int n;
    cout << "Enter the range of your number:";
    cin >> n;

    printPrime(n);
    return 0;
}