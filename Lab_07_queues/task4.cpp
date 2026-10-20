#include <iostream>
using namespace std;
const int SIZE = 5;
class Deque {
private:
    int arr[SIZE];
    int front, rear, count;
public:
    Deque() {
        front = 0;
        rear = -1;
        count = 0;
    }
    void insertFront(int id) {
        if (count == SIZE) {
            cout << "Deque is full!\n";
            return;
        }
        if (count == 0) {
            front = rear = 0;
        } else {
            front = (front - 1 + SIZE) % SIZE;
        }
        arr[front] = id;
        count++;
        cout << "Request " << id
             << " added at front.\n";
    }
    void insertRear(int id) {
        if (count == SIZE) {
            cout << "Deque is full!\n";
            return;
        }
        if (count == 0) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % SIZE;
        }
        arr[rear] = id;
        count++;
        cout << "Request " << id
             << " added at rear.\n";
    }
    void removeFront() {
        if (count == 0) {
            cout << "Deque is empty!\n";
            return;
        }
        cout << "Removed request: "
             << arr[front] << endl;

        front = (front + 1) % SIZE;
        count--;
        if (count == 0) {
            front = 0;
            rear = -1;
        }
    }
    void removeRear() {
        if (count == 0) {
            cout << "Deque is empty!\n";
            return;
        }
        cout << "Removed request: "
             << arr[rear] << endl;
        rear = (rear - 1 + SIZE) % SIZE;
        count--;
        if (count == 0) {
            front = 0;
            rear = -1;
        }
    }
    void display() {
        if (count == 0) {
            cout << "Deque is empty.\n";
            return;
        }

        cout << "Requests from front to rear: ";

        for (int i = 0; i < count; i++) {
            cout << arr[(front + i) % SIZE] << " ";
        }

        cout << endl;
    }
};
int main() {
    Deque d;
    int choice, id;
    do {
        cout << "\n--- Train Station Management ---\n";
        cout << "1. Insert at front\n";
        cout << "2. Insert at rear\n";
        cout << "3. Remove from front\n";
        cout << "4. Remove from rear\n";
        cout << "5. Display requests\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter request ID: ";
            cin >> id;
            d.insertFront(id);
            break;
        case 2:
            cout << "Enter request ID: ";
            cin >> id;
            d.insertRear(id);
            break;
        case 3:
            d.removeFront();
            break;
        case 4:
            d.removeRear();
            break;
        case 5:
            d.display();
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
