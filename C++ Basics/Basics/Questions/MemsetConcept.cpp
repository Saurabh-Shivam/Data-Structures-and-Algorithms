#include <iostream>
#include <cstring>
using namespace std;

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{

    int n;
    cout << "Enter the number of elements:" << endl;
    cin >> n;

    int arr1[n], arr2[n];

    // This is used to fill a block of memory with a particular value, i.e. 0 and -1
    memset(arr1, -1, sizeof(arr1));
    memset(arr2, 0, sizeof(arr2));
    display(arr1, n);
    cout << endl;
    display(arr2, n);

    return 0;
}