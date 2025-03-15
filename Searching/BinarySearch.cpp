#include <iostream>
using namespace std;

// Time Complexity -> O(log n)
int binarySearch(int arr[], int n, int key)
{
    int start = 0;
    int end = n - 1;
    // int mid = (start + end) / 2;
    int mid = start + (end - start) / 2; // to prevent overflow

    while (start <= end)
    {
        if (key == arr[mid])
            return mid;
        else if (key < arr[mid])
            end = mid - 1;
        else
            start = mid + 1;

        mid = start + (end - start) / 2;
    }

    return -1;
}

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    // taking input in array
    int arr[500];
    cout << "Enter the elements of array:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int key;
    cout << "Enter the element to search: ";
    cin >> key;

    int ans = binarySearch(arr, n, key);

    if (ans != -1)
        cout << "The element is present at index: " << ans;
    else
        cout << "The element is not present";

    return 0;
}