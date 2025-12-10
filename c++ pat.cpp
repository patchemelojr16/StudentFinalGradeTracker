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
    cout << "\nEnter student name: ";
    cin.ignore();
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

    cout << "\n--- Student List ---\n";
    for (int i = 0; i < students.size(); i++) {
        cout << "\nName: " << students[i].name;
        cout << "\nFinal Grade: " << students[i].finalGrade << "\n";
    }
    cout << endl;
}

int main() {
    int choice, year;
    float pass, password,user, username;
    string name,name2,block;
    
    cout << "\nEnter your name: ";
    getline (cin,name);
    cout << "Enter your instructor name: ";
    getline (cin,name2);
    cout <<"Enter your black/year: ";
    getline (cin,block);
    cin.ignore();
    
    cout << "\n============================" << endl;
    cout << " STUDENT FINAL GRADE TRUCKER " << endl;
    cout <<"=============================" <<endl;
    cout << "Submitted by: " << name << endl;
    cout << "submitted to: " << name2 << endl;
    cout << "Course/code : " << block << endl;
    cout << "Date        : " << "December 15, 2025 " << endl;
    cout << "------------------------------------" << endl;
    
    cout << "Enter your username: ";
    cin >> user;
    cout << "Enter your password: ";
    cin >> pass;
    
    for (int i = 0; i <= 3; i++) {
        cout << "Enter your setUsername: ";
        cin >> username;
        cout << "Enter your SetPassword: ";
        cin >> password;
        
        if (pass == password || user == username) {
            cout << "\nLog-in successfully!!" << endl;
            break;
            
        } else {
            cout << "Sorry log-in failed..pleaseee try again!!" << endl;
        }
    }
    

    do {
        cout << "==== STUDENT FINAL GRADE TRACKER ====\n";
        cout << "1. Add Student\n";
        cout << "2. View Students\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addStudent(); break;
            case 2: viewStudents(); break;
            case 3: cout << "\nExiting program...\n"; break;
            default: cout << "\nInvalid choice.\n";
        }
    } while (choice != 3);

    return 0;
}

