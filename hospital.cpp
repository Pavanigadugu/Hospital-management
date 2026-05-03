#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct Patient {
    string name;
    int age;
    bool emergency;
};

class Hospital {
private:
    queue<Patient> normalQueue;
    queue<Patient> emergencyQueue;

public:
    void registerPatient(string name, int age) {
        Patient p = {name, age, false};
        normalQueue.push(p);
        cout << "Normal patient registered: " << name << endl;
    }

    void registerEmergency(string name, int age) {
        Patient p = {name, age, true};
        emergencyQueue.push(p);
        cout << "Emergency patient registered: " << name << endl;
    }

    void assignDoctor() {
        if (!emergencyQueue.empty()) {
            Patient p = emergencyQueue.front();
            emergencyQueue.pop();
            cout << "Doctor assigned to emergency patient: " << p.name << endl;
        } else if (!normalQueue.empty()) {
            Patient p = normalQueue.front();
            normalQueue.pop();
            cout << "Doctor assigned to normal patient: " << p.name << endl;
        } else {
            cout << "No patients waiting." << endl;
        }
    }
};

int main() {
    Hospital h;
    int choice;
    string name;
    int age;

    while (true) {
        cout << "\nHospital Management System\n";
        cout << "1. Register Patient\n";
        cout << "2. Register Emergency\n";
        cout << "3. Assign Doctor\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter name: ";
                cin >> name;
                cout << "Enter age: ";
                cin >> age;
                h.registerPatient(name, age);
                break;
            case 2:
                cout << "Enter name: ";
                cin >> name;
                cout << "Enter age: ";
                cin >> age;
                h.registerEmergency(name, age);
                break;
            case 3:
                h.assignDoctor();
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid choice." << endl;
        }
    }
}
