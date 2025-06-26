#include <iostream>
using namespace std;

class Queue
{
private:
    int *arr;
    int front;
    int rear;
    int size;

public:
    Queue(int capacity)
    {
        size = capacity;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    bool isFull()
    {
        return (rear == size - 1);
    }

    bool isEmpty()
    {
        return (front == -1 || front > rear);
    }

    void enqueue(int value)
    {
        if (isFull())
        {
            cout << "Queue is full!" << endl;
            return;
        }
        if (front == -1)
            front = 0;
        arr[++rear] = value;
        cout << "Enqueued: " << value << endl;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Dequeued: " << arr[front] << endl;
        front++;
    }

    int peek()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return arr[front];
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue: ";
        for (int i = front; i <= rear; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    int capacity;
    cout << "Enter the size of the queue: ";
    cin >> capacity;
    Queue q(capacity);

    int choice, value;
    do
    {
        cout << "\nMenu:" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Display" << endl;
        cout << "4. Peek" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to enqueue: ";
            cin >> value;
            q.enqueue(value);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.display();
            break;
        case 4:
            cout << "Front element: " << q.peek() << endl;
            break;
        case 5:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice, try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
