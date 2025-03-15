#include <iostream>
using namespace std;

int sumEven(int n, int sum)
{

    for (int i = 1; i <= n; i++)
    {
        if (i % 2 == 0)
        {
            sum += i;
        }
    }
    return sum;
}

int main()
{
    int n;
    int sum = 0;
    cout << "Enter the range of your number:";
    cin >> n;

    int res = sumEven(n, sum);
    cout << "Sum of all numbers is " << res;

    return 0;
}