#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


struct Student {
    int studentID;
    string name;
    int age;
    string grade;
};


class StudentManagementSystem {
private:
    vector<Student> studentDatabase;

public:
    void insertStudent() {
        Student newStudent;
        cout << "Enter student ID: ";
        cin >> newStudent.studentID;
        cout << "Enter student name: ";
        cin.ignore();
        getline(cin, newStudent.name);
        cout << "Enter student age: ";
        cin >> newStudent.age;
        cout << "Enter student grade: ";
        cin.ignore();
        getline(cin, newStudent.grade);

        studentDatabase.push_back(newStudent);
        cout << "Student record added successfully!\n";
    }

    void updateStudent() {
        int studentID;
        cout << "Enter student ID: ";
        cin >> studentID;

        auto it = find_if(studentDatabase.begin(), studentDatabase.end(), [studentID](const Student& student) {
            return student.studentID == studentID;
        });

        if (it != studentDatabase.end()) {
            cout << "Enter updated student name: ";
            cin.ignore();
            getline(cin, it->name);
            cout << "Enter updated student age: ";
            cin >> it->age;
            cout << "Enter updated student grade: ";
            cin.ignore();
            getline(cin, it->grade);
            cout << "Student record updated successfully!\n";
        } else {
            cout << "Student not found in the database.\n";
        }
    }

    void deleteStudent() {
        int studentID;
        cout << "Enter student ID to delete: ";
        cin >> studentID;

        auto it = find_if(studentDatabase.begin(), studentDatabase.end(), [studentID](const Student& student) {
            return student.studentID == studentID;
        });

        if (it != studentDatabase.end()) {
            studentDatabase.erase(it);
            cout << "Student record deleted successfully!\n";
        } else {
            cout << "Student not found in the database.\n";
        }
    }

    void showStudents() {
        cout << "Student Database:\n";
        cout << "Student ID\tName\t\tAge\tGrade\n";

        for (const auto& student : studentDatabase) {
            cout << student.studentID << "\t\t" << student.name << "\t" << student.age << "\t" << student.grade << endl;
        }
    }

    void searchStudent() {
        int studentID;
        cout << "Enter student ID to search: ";
        cin >> studentID;

        auto it = find_if(studentDatabase.begin(), studentDatabase.end(), [studentID](const Student& student) {
            return student.studentID == studentID;
        });

        if (it != studentDatabase.end()) {
            cout << "Student ID: " << it->studentID << endl;
            cout << "Name: " << it->name << endl;
            cout << "Age: " << it->age << endl;
            cout << "Grade: " << it->grade << endl;
        } else {
            cout << "Student not found in the database.\n";
        }
    }
};

int main() {
    StudentManagementSystem sms;
    int choice;

    do {
        cout << "Student Management System\n";
        cout << "1. Insert Student\n";
        cout << "2. Update Student\n";
        cout << "3. Delete Student\n";
        cout << "4. Show Students\n";
        cout << "5. Search Student\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                sms.insertStudent();
                break;
            case 2:
                sms.updateStudent();
                break;
            case 3:
                sms.deleteStudent();
                break;
            case 4:
                sms.showStudents();
                break;
            case 5:
                sms.searchStudent();
                break;
            case 6:
                cout << "Exiting Student Management System...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }

        cout << endl;
    } while (choice != 6);

    return 0;
}
