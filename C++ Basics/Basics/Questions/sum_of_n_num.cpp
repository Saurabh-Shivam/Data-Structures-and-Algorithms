#include <iostream>
using namespace std;

int sum_till_n(int n, int sum)
{

    for (int i = 1; i <= n; i++)
    {
        sum += i;
    }
    return sum;
}

int main()
{
    int n;
    int sum = 0;
    cout << "Enter the range of your number:";
    cin >> n;

    int res = sum_till_n(n, sum);
    cout << "Sum of all numbers is " << res;

    return 0;
}