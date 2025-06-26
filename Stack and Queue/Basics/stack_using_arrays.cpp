#include <iostream>
using namespace std;

class Stack
{
    int *arr;
    int capacity, top = -1;

public:
    Stack() {}
    Stack(int n)
    {
        capacity = n;
        arr = new int[n];
    }

    bool isfull()
    {
        return (top == capacity - 1);
    }

    bool isempty()
    {
        return (top == -1);
    }

    int push(int val)
    {
        top++;
        arr[top] = val;
        return arr[top];
    }

    int pop()
    {
        int data = arr[top];
        top--;
        return data;
    }

    int peek()
    {
        return arr[top];
    }

    void display()
    {
        for (int i = top; i >= 0; i--)
            cout << "|" << arr[i] << "|" << endl;
    }

    int size()
    {
        return top + 1;
    }
};

int main()
{
    int size;
    cout << "Enter stack capacity: ";
    cin >> size;
    Stack obj(size);

    while (true)
    {
        cout << "\n1.Push\n2.Pop\n3.Peek\n4.Display stack\n5.Display size of stack\n6.Exit\nEnter your choice: ";
        int ch;
        cin >> ch;

        switch (ch)
        {
        case 1:
        {
            if (!obj.isfull())
            {
                cout << "\nEnter the element to push: ";
                int ele;
                cin >> ele;
                cout << "Element " << obj.push(ele) << " pushed to stack successfully!!" << endl;
            }
            else
            {
                cout << "Stack is full!!!" << endl;
            }
            break;
        }

        case 2:
        {
            if (!obj.isempty())
            {
                obj.pop();
                cout << "Stack element popped successfully!!!" << endl;
            }
            else
            {
                cout << "Stack is empty!!!" << endl;
            }
            break;
        }

        case 3:
        {
            if (!obj.isempty())
            {
                cout << "The top element in the stack is: " << obj.peek() << endl;
            }
            else
            {
                cout << "Stack is empty!!!" << endl;
            }
            break;
        }

        case 4:
        {
            obj.display();
            break;
        }

        case 5:
        {
            cout << "Stack size is " << obj.size() << endl;
            break;
        }

        case 6:
        {
            cout << "Exiting the program";
            return 0;
        }

        default:
        {
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
        }
    }
    return 0;
}
