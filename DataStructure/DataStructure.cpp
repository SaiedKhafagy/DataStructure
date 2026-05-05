#include <iostream>
using namespace std;
// structure for patient data
struct Patient
{
    int id;
    Patient* next;
};
// 1. [QUEUE] - Normal Patient Waiting List 
struct NormalQueue {
    Patient* front = nullptr, * rear = nullptr;

    void enqueue(int id) {
        Patient* Add_Patient = new Patient{ id, nullptr };
        if (rear == nullptr) {
            front = rear = Add_Patient;
            return;
        }
        rear->next = Add_Patient;  // بنسجل ان المريض القديم ان الجديد مكانو في ال نكست
        rear = Add_Patient;
    }

    int dequeue() {
        if (front == nullptr) return -1;
        Patient* temp = front;
        int id = temp->id; // -> == .
        front = front->next; // علشان يجدد البيشانت الي ورا الي اتسحب يبقي هو الاولاني
        if (front == nullptr) rear = nullptr;
        delete temp;
        return id;
    }

    bool isEmpty() { return front == nullptr; }
};

// 2. [STACK] - Pushes critical patients to the front
struct EmergencyStack {
    Patient* top = nullptr;

    void push(int id) {
        Patient* Add_Emergency_Patient = new Patient{ id, top };
        top = Add_Emergency_Patient;
    }

    int pop() {
        if (top == nullptr) return -1;
        Patient* temp = top;
        int id = temp->id;  // -> == . 
        top = top->next;   // -> == .
        delete temp;
        return id;
    }

    bool isEmpty() { return top == nullptr; }
};

// 3. [LINKED LIST] - Record of Discharged Patients
// Logic: Permanent storage for hospital reporting
struct DischargedList {
    Patient* head = nullptr;

    void addRecord(int id) {
        Patient* Add_Record_Patient = new Patient{ id, head };
        head = Add_Record_Patient;
    }

    void display() {
        if (!head) {
            cout << "Record is empty.\n";
            return;
        }
        Patient* temp = head;
        while (temp) {
            cout << "[Patient ID: " << temp->id << "] -> ";
            temp = temp->next;
        }
        cout << "END\n";
    }
};

int main() {
    NormalQueue normalQ;
    EmergencyStack emergencyS;
    DischargedList history;
    int choice, id;

    while (true) {
        cout << "\n--- Hospital Triage System ---\n";
        cout << "1. Add Normal Patient (Queue)\n";
        cout << "2. Add Emergency Case (Stack)\n";
        cout << "3. Process Next Patient (Emergency First)\n";
        cout << "4. View Discharged Records (Linked List)\n";
        cout << "5. Exit\n";
        cout << "Selection: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter Patient ID: ";
            cin >> id;
            normalQ.enqueue(id);
            cout << "Added to Normal Queue.\n";
        }
        else if (choice == 2) {
            cout << "Enter Emergency ID: ";
            cin >> id;
            emergencyS.push(id);
            cout << "Added to Emergency Stack.\n";
        }
        else if (choice == 3) {
            // Check emergency stack first as per triage rules
            if (!emergencyS.isEmpty()) {
                id = emergencyS.pop();
                cout << "Processing Emergency: " << id << endl;
                history.addRecord(id);
            }
            else if (!normalQ.isEmpty()) {
                id = normalQ.dequeue();
                cout << "Processing Normal Case: " << id << endl;
                history.addRecord(id);
            }
            else {
                cout << "No patients in waiting area.\n";
            }
        }
        else if (choice == 4) {
            cout << "Hospital Discharge History:\n";
            history.display();
        }
        else if (choice == 5) {
            cout << "End";
            break;
        }
        else {
            cout << "Invalid selection.\n";
        }
    }
    return 0;
}