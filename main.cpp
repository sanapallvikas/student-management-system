#include<iostream>
#include<fstream>
using namespace std;

class Student {
public:
    int id;
    string name;
    float marks;

    void input() {

        cout << "Enter ID: ";
        cin >> id;

        cout << "Enter Name: ";
        cin >> name;

        cout << "Enter Marks: ";
        cin >> marks;
    }

    void display() {

        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Marks: " << marks << endl;
    }
};

void addStudent() {

    Student s;

    ofstream file("students.txt", ios::app);

    s.input();

    file << s.id << " "
         << s.name << " "
         << s.marks << endl;

    file.close();

    cout << "\nStudent Added Successfully\n";
}

void displayStudents() {

    Student s;

    ifstream file("students.txt");

    while(file >> s.id >> s.name >> s.marks) {

        cout << "\n-------------------\n";

        s.display();
    }

    file.close();
}

int main() {

    int choice;

    while(true) {

        cout << "\n===== STUDENT MANAGEMENT SYSTEM =====\n";

        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Exit\n";

        cout << "Enter Choice: ";
        cin >> choice;

        switch(choice) {

            case 1:
                addStudent();
                break;

            case 2:
                displayStudents();
                break;

            case 3:
                exit(0);

            default:
                cout << "Invalid Choice\n";
        }
    }
}