#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{

    int n;
    cout << "Enter the number of elements:" << endl;
    cin >> n;

    // taking input in vector
    vector<int> arr(n);
    cout << "Enter the elements of array:" << endl;
    for (int i = 0; i < arr.size(); i++)
    {
        cin >> arr[i];
    }

    int target;
    cout << "Enter the target element:" << endl;
    cin >> target;

    int ans = binary_search(arr.begin(), arr.end(), target);

    if (ans)
        cout << "Element found";
    else
        cout << "Element not found";

    return 0;
}