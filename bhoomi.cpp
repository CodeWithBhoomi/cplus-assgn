//Bhoomi Sharma 231103011
#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    int age, rollNo, classesAttended;
    string name;
    float marks;
    static const int totalClasses = 32;

    void showDetails() {
        cout << "Name: " << name << ", Roll No: " << rollNo << ", Age: " << age << endl;
        cout << "Attendance: " << classesAttended << "/" << totalClasses << ", Marks: " << marks << "/100" << endl;
    }

    float getAttendancePercentage() {
        return (float)classesAttended / totalClasses * 100;
    }
};

class StudentData {
public:
    Student studentList[5];
    int studentCount = 0;

    void addStudent(Student s) {
        if (studentCount < 5) {
            studentList[studentCount] = s;
            studentCount++;
        } else {
            cout << "Max student limit reached.\n";
        }
    }

    void showAllDetails() {
        for (int i = 0; i < studentCount; i++) {
            studentList[i].showDetails();
            cout << "--------------------------" << endl;
        }
    }

    void showAttendance() {
        for (int i = 0; i < studentCount; i++) {
            cout << "Roll No: " << studentList[i].rollNo << ", Name: " << studentList[i].name
                 << ", Attendance: " << studentList[i].classesAttended << endl;
        }
    }

    void showShortage() {
        cout << "Students with less than 75% attendance:" << endl;
        for (int i = 0; i < studentCount; i++) {
            if (studentList[i].getAttendancePercentage() < 75) {
                cout << "Roll No: " << studentList[i].rollNo << ", Name: " << studentList[i].name
                     << ", Attendance Percentage: " << studentList[i].getAttendancePercentage() << "%" << endl;
            }
        }
    }

    void showTop5() {
        for (int i = 0; i < studentCount - 1; i++) {
            for (int j = i + 1; j < studentCount; j++) {
                if (studentList[i].marks < studentList[j].marks) {
                    Student temp = studentList[i];
                    studentList[i] = studentList[j];
                    studentList[j] = temp;
                }
            }
        }
        cout << "Top 5 Students by Marks:" << endl;
        for (int i = 0; i < 5 && i < studentCount; i++) {
            cout << "Roll No: " << studentList[i].rollNo << ", Name: " << studentList[i].name
                 << ", Marks: " << studentList[i].marks << endl;
        }
    }

    void showHighAttendance() {
        cout << "Students with 90% or higher attendance:" << endl;
        for (int i = 0; i < studentCount; i++) {
            if (studentList[i].getAttendancePercentage() >= 90) {
                cout << "Roll No: " << studentList[i].rollNo << ", Name: " << studentList[i].name
                     << ", Attendance Percentage: " << studentList[i].getAttendancePercentage() << "%" << endl;
            }
        }
    }
};

int main() {
    StudentData studentData;
    int numStudents = 5;
    for (int i = 0; i < numStudents; i++) {
        Student s;
        cout << "\nEnter details for Student " << i + 1 << ":\n";
        cout << "Name: "; cin >> ws; getline(cin, s.name);
        cout << "Roll Number: "; cin >> s.rollNo;
        cout << "Age: "; cin >> s.age;
        cout << "Classes Attended: "; cin >> s.classesAttended;
        cout << "Marks (out of 100): "; cin >> s.marks;
        studentData.addStudent(s);
    }
    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Show All Student Details\n";
        cout << "2. Show Attendance Details\n";
        cout << "3. Show Students with Attendance Shortage (<75%)\n";
        cout << "4. Show Top 5 Students by Marks\n";
        cout << "5. Show Students with 90% or Higher Attendance\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: "; cin >> choice;

        switch (choice) {
            case 1: studentData.showAllDetails(); break;
            case 2: studentData.showAttendance(); break;
            case 3: studentData.showShortage(); break;
            case 4: studentData.showTop5(); break;
            case 5: studentData.showHighAttendance(); break;
            case 0: cout << "Exiting program.\n"; break;
            default: cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}
