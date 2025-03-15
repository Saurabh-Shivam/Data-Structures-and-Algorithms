#include <iostream>
#include <vector>
using namespace std;

int binarySearch(int arr[], int start, int end, int target)
{
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] > target)
            end = mid - 1;
        else
            start = mid + 1;
    }

    return -1;
}

// Time Complexity: O(log(2^logm-1))
int exponentialBS(int arr[], int n, int target)
{
    if (arr[0] == target)
        return 0;
    int i = 1;
    while (i < n && arr[i] <= target)
        i = i * 2;
    return binarySearch(arr, i / 2, min(i, n - 1), target);
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

    int target;
    cout << "Enter the element to search: ";
    cin >> target;

    int ans = exponentialBS(arr, n, target);

    if (ans != -1)
        cout << "The element is present at index: " << ans;
    else
        cout << "The element is not present";

    return 0;
}