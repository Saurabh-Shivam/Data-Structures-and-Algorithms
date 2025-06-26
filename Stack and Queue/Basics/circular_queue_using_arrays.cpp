#include <iostream>
using namespace std;

class CircularQueue
{
private:
    int *arr;
    int front;
    int rear;
    int size;

public:
    CircularQueue(int capacity)
    {
        size = capacity;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    bool isFull()
    {
        return ((rear + 1) % size == front);
    }

    bool isEmpty()
    {
        return (front == -1);
    }

    void enqueue(int value)
    {
        if (isFull())
        {
            cout << "Queue is full! Cannot enqueue " << value << endl;
            return;
        }
        if (isEmpty())
        {
            front = 0;
        }
        rear = (rear + 1) % size;
        arr[rear] = value;
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
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % size;
        }
    }

    void peek()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!" << endl;
        }
        cout << "Front element:" << arr[front] << endl;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue: ";
        int i = front;
        while (true)
        {
            cout << arr[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % size;
        }
        cout << endl;
    }
};

int main()
{
    int capacity;
    cout << "Enter the size of the circular queue: ";
    cin >> capacity;
    CircularQueue q(capacity);

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
            if (!q.isFull())
            {
                cout << "Enter value to enqueue: ";
                cin >> value;
                q.enqueue(value);
            }
            else
                cout << "Queue is full! Cannot enqueue " << value << endl;
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.display();
            break;
        case 4:
            q.peek();
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