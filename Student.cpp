#include "Student.hpp"
#include <iomanip>
using namespace std;

// Default constructor
Student::Student() : id(0), name(""), gpa(0.0) {
    courses = new LinkedList<Course>();
}

// Regular constructor
Student::Student(int id_, const string& name_, double gpa_)
    : id(id_), name(name_), gpa(gpa_) {
    courses = new LinkedList<Course>();
}

// Copy constructor
Student::Student(const Student& other)
    : id(other.id), name(other.name), gpa(other.gpa) {
    courses = new LinkedList<Course>(*other.courses);
}

// Assignment operator
Student& Student::operator=(const Student& other) {
    if (this != &other) {
        id = other.id;
        name = other.name;
        gpa = other.gpa;
        delete courses;
        courses = new LinkedList<Course>(*other.courses);
    }
    return *this;
}

// Destructor
Student::~Student() {
    delete courses;
    courses = nullptr;
}

// Add a course
void Student::addCourse(const Course& c) {
    courses->push_back(c);
}

bool Student::hasCourses() const {
    return !courses->empty();
}

size_t Student::courseCount() const {
    return courses->size();
}

void Student::printCourses(ostream& os) const {
    if (!hasCourses()) {
        os << "None";
        return;
    }

    bool first = true;
    courses->for_each([&](const Course& c) {
        if (!first) os << "\n           ";
        os << "  ";
        c.print(os);
        first = false;
    });
}

void Student::print(ostream& os) const {
    os << id << " " << name << " " << fixed << setprecision(2) << gpa;
    os << "\n  Courses: ";
    printCourses(os);
}
