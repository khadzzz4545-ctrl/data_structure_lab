
#include <iostream>
using namespace std;

const int SIZE = 5;

class Queue {
private:
    int arr[SIZE];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    void enqueue(int token) {
        if (rear == SIZE - 1) {
            cout << "Queue Overflow! No space available.\n";
            return;
        }

        if (front == -1) {
            front = 0;
        }

        rear++;
        arr[rear] = token;
        cout << "Customer " << token << " added.\n";
    }

    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue Underflow! No customers waiting.\n";
            return;
        }

        cout << "Customer " << arr[front] << " served.\n";
        front++;

        if (front > rear) {
            front = rear = -1;
        }
    }

    void display() {
        if (front == -1) {
            cout << "Queue is empty.\n";
            return;
        }

        cout << "Waiting customers: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void countCustomers() {
        if (front == -1) {
            cout << "Waiting customers: 0\n";
        } else {
            cout << "Waiting customers: "
                 << rear - front + 1 << endl;
        }
    }
};

int main() {
    Queue q;
    int choice, token;

    do {
        cout << "\n--- Bank Customer Service ---\n";
        cout << "1. Add customer\n";
        cout << "2. Serve customer\n";
        cout << "3. Display waiting customers\n";
        cout << "4. Count waiting customers\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter token number: ";
            cin >> token;
            q.enqueue(token);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.display();
            break;
        case 4:
            q.countCustomers();
            break;
        case 0:
            cout << "Program ended.\n";
            break;
        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    return 0;
}
