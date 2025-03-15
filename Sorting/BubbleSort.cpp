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
void bubbleSort(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        bool swapCount = false;
        for (int j = 0; j < arr.size() - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swapCount = true;
                swap(arr[j], arr[j + 1]);
            }
        }

        // optimising the code if the array is already sorted before the complete traversal of first loop
        if (swapCount == false)
            break;
    }

    display(arr);
}

int main()
{

    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    // taking input in vector
    vector<int> arr(n);
    cout << "Enter the elements of array: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Vector elements before sorting" << endl;
    display(arr);

    cout << endl
         << "Vector elements after sorting" << endl;
    bubbleSort(arr);

    return 0;
}