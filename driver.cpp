#include <iostream>
#include <limits>
#include <string>
#include "LinkedList.hpp"
#include "Student.hpp"
#include "Course.hpp"
using namespace std;

template <typename T>
T read(const string& prompt) {
    T value{};
    while (true) {
        cout << prompt;
        if (cin >> value) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        } else {
            cout << " Invalid input. Please try again.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

string readLine(const string& prompt) {
    cout << prompt;
    string s;
    getline(cin, s);
    return s;
}

int main() {
    LinkedList<Student> students; // our class roster

    // Lambda: Insert a new student
    auto insertStudent = [&]() {
        int id = read<int>("Enter Student ID: ");
        string name = readLine("Enter Student Name: ");
        double gpa = read<double>("Enter Student GPA: ");

        Student* existing = students.find_if([&](const Student& s) {
            return s.getId() == id;
        });

        if (existing) {
            cout << "A student with that ID already exists.\n";
            return;
        }

        students.push_back(Student(id, name, gpa));
        cout << " Student added successfully!\n";
    };

    // Lambda: Delete a student
    auto deleteStudent = [&]() {
        int id = read<int>("Enter Student ID to delete: ");
        bool removed = students.remove_by_id(id);
        if (removed)
            cout << " Student removed successfully.\n";
        else
            cout << " Student not found.\n";
    };

    // Lambda: Search student
    auto searchStudent = [&]() {
        int id = read<int>("Enter Student ID to search: ");
        Student* s = students.find_if([&](const Student& st) {
            return st.getId() == id;
        });

        if (s) {
            cout << "\n🎓 Student found:\n";
            s->print();
            cout << "\n";
        } else {
            cout << " Student not found.\n";
        }
    };

    // Lambda: Display all
    auto displayAll = [&]() {
        if (students.empty()) {
            cout << " No students in the list yet.\n";
            return;
        }

        cout << "\n All Students:\n";
        students.for_each([&](const Student& s) {
            s.print();
            cout << "\n";
        });
    };

    // Lambda: Count
    auto countStudents = [&]() {
        cout << " Total students: " << students.size() << "\n";
    };

    // Lambda: Add course to student
    auto addCourseToStudent = [&]() {
        int id = read<int>("Enter Student ID: ");
        Student* s = students.find_if([&](const Student& st) {
            return st.getId() == id;
        });

        if (!s) {
            cout << " Student not found.\n";
            return;
        }

        string cname = readLine("Enter Course Name: ");
        string lloc = readLine("Enter Course Location: ");
        s->addCourse(Course(cname, lloc));

        cout << " Course added to " << s->getName() << "'s record.\n";
    };

    // Lambda: Insert front
    auto insertFront = [&]() {
        int id = read<int>("Enter Student ID: ");
        string name = readLine("Enter Student Name: ");
        double gpa = read<double>("Enter Student GPA: ");
        students.insert_front(Student(id, name, gpa));
        cout << " Student inserted at the front.\n";
    };

    // Lambda: Pop front
    auto popFront = [&]() {
        Student popped;
        if (students.pop_front(popped)) {
            cout << "Removed student from front:\n";
            popped.print();
            cout << "\n";
        } else {
            cout << "List is empty. Nothing to remove.\n";
        }
    };

    // ===============================
    // Main Menu
    // ===============================
    while (true) {
        cout << "\n============================\n";
        cout << " STUDENT MANAGEMENT MENU\n";
        cout << "============================\n";
        cout << "1️ Insert Student\n";
        cout << "2️ Delete Student\n";
        cout << "3️ Search Student\n";
        cout << "4️ Display All Students\n";
        cout << "5️ Count Students\n";
        cout << "6️ Add a Course to a Student\n";
        cout << "7️ Insert Student at Front\n";
        cout << "8️ Pop Front Student\n";
        cout << "9️ Exit Program\n";

        int choice = read<int>("Choose an option (1-9): ");
        cout << "\n";

        switch (choice) {
            case 1: insertStudent(); break;
            case 2: deleteStudent(); break;
            case 3: searchStudent(); break;
            case 4: displayAll(); break;
            case 5: countStudents(); break;
            case 6: addCourseToStudent(); break;
            case 7: insertFront(); break;
            case 8: popFront(); break;
            case 9:
                cout << " Goodbye! Have a great day.\n";
                return 0;
            default:
                cout << " Invalid choice. Try again.\n";
        }
    }
}
