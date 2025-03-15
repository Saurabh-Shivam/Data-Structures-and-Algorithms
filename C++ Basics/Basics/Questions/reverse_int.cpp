#include <iostream>
using namespace std;

int reverseInt(int n)
{
    int rem;
    int revNum = 0;
    for (int i = 0; i < n; i++)
    {
        rem = n % 10;
        revNum = revNum * 10 + rem;
        n = n / 10;
    }

    return revNum;
}

int main()
{
    int n;
    cout << "Enter the number: ";
    cin >> n;

    int ans = reverseInt(n);

    cout << "The reversed number is " << ans;

    return 0;
}