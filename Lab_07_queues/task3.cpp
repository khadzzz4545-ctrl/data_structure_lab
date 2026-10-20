#include <iostream>
using namespace std;
const int SIZE = 5;
class PriorityQueue {
private:
    int patientID[SIZE];
    int priority[SIZE];
    int count;
public:
    PriorityQueue() {
        count = 0;
    }
    void insert(int id, int p) {
        if (count == SIZE) {
            cout << "Queue is full!\n";
            return;
        }

        if (p < 1) {
            cout << "Priority must be 1 or greater.\n";
            return;
        }
        patientID[count] = id;
        priority[count] = p;
        count++;

        cout << "Patient " << id << " added.\n";
    }
    void treatPatient() {
        if (count == 0) {
            cout << "No patients waiting!\n";
            return;
        }
        int highest = 0;

        for (int i = 1; i < count; i++) {
            if (priority[i] < priority[highest]) {
                highest = i;
            }
        }
        cout << "Treating patient " << patientID[highest]
             << " with priority " << priority[highest]
             << ".\n";

        for (int i = highest; i < count - 1; i++) {
            patientID[i] = patientID[i + 1];
            priority[i] = priority[i + 1];
        }

        count--;
    }
    void display() {
        if (count == 0) {
            cout << "No patients waiting.\n";
            return;
        }
        cout << "Waiting patients (ID - Priority):\n";

        for (int i = 0; i < count; i++) {
            cout << "P" << patientID[i]
                 << " - " << priority[i] << endl;
        }
    }
};
int main() {
    PriorityQueue q;
    int choice, id, p;

    do {
        cout << "\n--- Hospital Emergency Department ---\n";
        cout << "1. Add patient\n";
        cout << "2. Treat highest-priority patient\n";
        cout << "3. Display patients\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter patient ID: ";
            cin >> id;
            cout << "Enter priority (1 = highest): ";
            cin >> p;
            q.insert(id, p);
            break;
        case 2:
            q.treatPatient();
            break;
        case 3:
            q.display();
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
