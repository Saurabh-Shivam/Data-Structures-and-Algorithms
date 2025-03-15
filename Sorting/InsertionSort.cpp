#include <iostream>
#include <vector>
using namespace std;

void display(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
}

// Time Complexity -> O(n^2)
// Space Complexity -> O(1)
void insertionSort(vector<int> arr)
{
    int n = arr.size();
    for (int i = 1; i < n; i++)
    {
        // Step 1 -> Store Value
        int storedValue = arr[i];

        // Step 2 -> Compare
        int j = i - 1;
        for (; j >= 0; j--)
        {
            if (arr[j] > storedValue)
                // Step 3 -> Shift
                arr[j + 1] = arr[j];
            else
                break;
        }
        // Step 4 -> Copy
        arr[j + 1] = storedValue;
    }

    display(arr);
}

int main()
{

    int n;
    cout << "Enter the number of elements:" << endl;
    cin >> n;

    // taking input in vector
    vector<int> arr(n);
    cout << "Enter the elements of array:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Vector elements before sorting" << endl;
    display(arr);

    cout << endl
         << "Vector elements after sorting" << endl;
    insertionSort(arr);
    return 0;
}