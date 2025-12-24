#include <iostream>
#include <vector>
using namespace std;

struct Student {
    string name;
    double quiz, midterm, finalExam, finalGrade;
};

vector<Student> students;

double computeGrade(double q, double m, double f) {
    return (q * 0.3) + (m * 0.3) + (f * 0.4);
}

void addStudent() {
    Student s;
    cin.ignore();
    cout << "\nEnter student name: ";
    getline(cin, s.name);

    cout << "Enter Quiz Grade: ";
    cin >> s.quiz;
    cout << "Enter Midterm Grade: ";
    cin >> s.midterm;
    cout << "Enter Final Exam Grade: ";
    cin >> s.finalExam;

    s.finalGrade = computeGrade(s.quiz, s.midterm, s.finalExam);
    students.push_back(s);

    cout << "\nStudent added successfully!\n\n";
}

void viewStudents() {
    if (students.empty()) {
        cout << "\nNo students recorded yet.\n\n";
        return;
    }
     cout << "\n================================\n";
    cout << "\n--- Student List ---\n";
    for (int i = 0; i < students.size(); i++) {
        cout << "\nName: " << students[i].name;
        cout << "\n-------------------------------" << endl;
        cout << "Final Grade:  [ " << students[i].finalGrade << " )\n";
          cout << "-------------------------------" << endl;
          cout << "\n================================\n";
    }
    cout << endl;
}

int main() {
    string name, instructor, block;
    string user, pass;
    string username, password;
    bool LogIn = false;
    int choice;

    cout << "=========== FILL UP FIRST ==========\n";
    cout << "Enter your name: ";
    getline(cin, name);
    cout << "Enter your instructor name: ";
    getline(cin, instructor);
    cout << "Enter your block/year: ";
    getline(cin, block);

    cout << "\n============================\n";
    cout << " STUDENT FINAL GRADE TRACKER\n";
    cout << "============================\n";
    cout << "Submitted by : " << name << endl;
    cout << "Submitted to : " << instructor << endl;
    cout << "Course/Block : " << block << endl;
    cout << "Date         : December 15, 2025\n";
    cout << "----------------------------\n";

    cout << "\n===== Create your account ======\n";
    cout << "Set Username: ";
    cin >> username;
    cout << "Set Password: ";
    cin >> password;

    for (int i = 1; i <= 3; i++) {
        cout << "\nLogin Attempt " << i << endl;
        cout << "Username: ";
        cin >> user;
        cout << "Password: ";
        cin >> pass;

        if (user == username && pass == password) {
            LogIn = true;
            cout << "\n==== Login successful! =====\n";
            break;
        } else {
            cout << "====== Login failed!! =====\n";
        }
    }

    if (!LogIn) {
        cout << "\n==== Too many attempts. Program terminated ====\n";
        return 0;
    }

    do {
        cout << "\n==== STUDENT FINAL GRADE TRACKER ====\n";
        cout << "1. Add Student\n";
        cout << "2. View Students\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addStudent(); break;
            case 2: viewStudents(); break;
            case 3: cout << "\n===== Exiting program...Thankk you! =====\n"; break;
            default: cout << "\nInvalid choice.\n";
        }
    } while (choice != 3);

    return 0;
}
