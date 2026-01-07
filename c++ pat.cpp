#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;
struct Student {
    string name;
    double quiz;
    double midterm;
    double finalExam;
    double finalGrade;
};

vector<Student> students;

double computeGrade(double q, double m, double f);
char getLetterGrade(double grade);
string getStatus(double grade);

void addStudent();
void viewStudents();
void searchStudent();
void editStudent();
void deleteStudent();
void classStatistics();

void saveToFile();
void loadFromFile();


double computeGrade(double q, double m, double f) {
    return (q * 0.3) + (m * 0.3) + (f * 0.4);
}

char getLetterGrade(double grade) {
    if (grade >= 90) return 'A';
    else if (grade >= 80) return 'B';
    else if (grade >= 70) return 'C';
    else if (grade >= 60) return 'D';
    else return 'F';
}

string getStatus(double grade) {
    return (grade >= 75) ? "PASSED" : "FAILED";
}


void addStudent() {
    Student s;
    cin.ignore();

    cout << "\nEnter student name: ";
    getline(cin, s.name);

    do {
        cout << "Enter Quiz Grade (0-100): ";
        cin >> s.quiz;
    } while (s.quiz < 0 || s.quiz > 100);

    do {
        cout << "Enter Midterm Grade (0-100): ";
        cin >> s.midterm;
    } while (s.midterm < 0 || s.midterm > 100);

    do {
        cout << "Enter Final Exam Grade (0-100): ";
        cin >> s.finalExam;
    } while (s.finalExam < 0 || s.finalExam > 100);

    s.finalGrade = computeGrade(s.quiz, s.midterm, s.finalExam);
    students.push_back(s);

    cout << "\nStudent successfully added! "<< endl;
}


void viewStudents() {
    if (students.empty()) {
        cout << "\nNo student records found."<< endl;
        return;
    }

    cout << "\n========== STUDENT RECORDS =========="<< endl;

    for (int i = 0; i < students.size(); i++) {
        cout << "\nName        : " << students[i].name;
        cout << "\nQuiz        : " << students[i].quiz;
        cout << "\nMidterm     : " << students[i].midterm;
        cout << "\nFinal Exam  : " << students[i].finalExam;
        cout << "\nFinal Grade : " << fixed << setprecision(2)
             << students[i].finalGrade;
        cout << "\nLetter Grade: " << getLetterGrade(students[i].finalGrade);
        cout << "\nStatus      : " << getStatus(students[i].finalGrade);
        cout << "\n------------------------------------"<< endl;
    }
}

void searchStudent() {
    string name;
    cin.ignore();

    cout << "\nEnter student name to search: ";
    getline(cin, name);

    for (int i = 0; i < students.size(); i++) {
        if (students[i].name == name) {
            cout << "\nStudent Found!"<< endl;
            cout << "Final Grade: " << students[i].finalGrade << endl;
            return;
        }
    }

    cout << "\nStudent not found!!."<< endl;
}

void editStudent() {
    string name;
    cin.ignore();

    cout << "\nEnter student name to edit: ";
    getline(cin, name);

    for (int i = 0; i < students.size(); i++) {
        if (students[i].name == name) {

            cout << "\nRe-enter grades:\n";
            cout << "Quiz: ";
            cin >> students[i].quiz;
            cout << "Midterm: ";
            cin >> students[i].midterm;
            cout << "Final Exam: ";
            cin >> students[i].finalExam;

            students[i].finalGrade =
                computeGrade(students[i].quiz,
                             students[i].midterm,
                             students[i].finalExam);

            cout << "\nRecord updated successfully!\n";
            return;
        }
    }

    cout << "\nStudent not found.\n";
}

void deleteStudent() {
    string name;
    cin.ignore();

    cout << "\nEnter student name to delete: ";
    getline(cin, name);

    for (int i = 0; i < students.size(); i++) {
        if (students[i].name == name) {
            students.erase(students.begin() + i);
            cout << "\nStudent deleted successfully!\n";
            return;
        }
    }

    cout << "\nStudent not found.\n";
}

void classStatistics() {
    if (students.empty()) {
        cout << "\nNo records available.\n";
        return;
    }

    double total = 0;
    double highest = students[0].finalGrade;
    double lowest  = students[0].finalGrade;

    for (int i = 0; i < students.size(); i++) {
        total += students[i].finalGrade;

        if (students[i].finalGrade > highest)
            highest = students[i].finalGrade;

        if (students[i].finalGrade < lowest)
            lowest = students[i].finalGrade;
    }

    cout << "\nClass Average: " << total / students.size();
    cout << "\nHighest Grade: " << highest;
    cout << "\nLowest Grade : " << lowest << endl;
}

void saveToFile() {
    ofstream file("students.txt");

    for (int i = 0; i < students.size(); i++) {
        file << students[i].name << endl;
        file << students[i].quiz << endl;
        file << students[i].midterm << endl;
        file << students[i].finalExam << endl;
        file << students[i].finalGrade << endl;
    }

    file.close();
    cout << "\nRecords saved successfully!\n";
}

void loadFromFile() {
    ifstream file("students.txt");

    if (!file) return;

    Student s;
    while (getline(file, s.name)) {
        file >> s.quiz;
        file >> s.midterm;
        file >> s.finalExam;
        file >> s.finalGrade;
        file.ignore();
        students.push_back(s);
    }

    file.close();
}

int main() {
    loadFromFile();
    
    string username, password, user, pass, name, instructor, block;
    bool loggedIn = false;
    int choice;

 cout << "=========== FILL UP FIRST =========="<< endl;
    cout << "Enter your name: ";
    getline(cin, name);
    cout << "Enter your instructor name: ";
    getline(cin, instructor);
    cout << "Enter your block/year: ";
    getline(cin, block);

    cout << "\n============================"<< endl;
    cout << " STUDENT FINAL GRADE TRACKER"<< endl;
    cout << "============================"<< endl;
    cout << "Submitted by : " << name << endl;
    cout << "Submitted to : " << instructor << endl;
    cout << "Course/Block : " << block << endl;
    cout << "Date         : December 15, 2025"<< endl;
    cout << "----------------------------"<< endl;
    
    
    cout << "===== CREATE ACCOUNT ===== " << endl;
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;

    for (int i = 1; i <= 3; i++) {
        cout << "\nLogin Attempt " << i << endl;
        cout << "Username: ";
        cin >> user;
        cout << "Password: ";
        cin >> pass;

        if (user == username && pass == password) {
            loggedIn = true;
            break;
        }
    }

    if (!loggedIn) return 0;

    do {
        cout << "\n==== MENU ==== " << endl;
        cout << "1. Add Student" << endl;
        cout << "2. View Students"<< endl;
        cout << "3. Search Student"<< endl;
        cout << "4. Edit Student"<< endl;
        cout << "5. Delete Student"<< endl;
        cout << "6. Class Statistics"<< endl;
        cout << "7. Save Records"<< endl;
        cout << "8. Exit "<< endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addStudent(); break;
            case 2: viewStudents(); break;
            case 3: searchStudent(); break;
            case 4: editStudent(); break;
            case 5: deleteStudent(); break;
            case 6: classStatistics(); break;
            case 7: saveToFile(); break;
            case 8: saveToFile(); break;
            default: cout << "Invalid choice!\n";
        }

    } while (choice != 8);

    return 0;
}
