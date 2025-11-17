#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <string>
#include <iostream>
#include "Course.hpp"
#include "LinkedList.hpp"
using namespace std;

class Student {
private:
    int id;
    string name;
    double gpa;
    LinkedList<Course>* courses;  // list of this student's courses

public:
    Student();
    Student(int id, const string& name, double gpa);
    Student(const Student& other);
    Student& operator=(const Student& other);
    ~Student();

    int getId() const { return id; }
    const string& getName() const { return name; }
    double getGpa() const { return gpa; }

    void setId(int v) { id = v; }
    void setName(const string& v) { name = v; }
    void setGpa(double v) { gpa = v; }

    void addCourse(const Course& c);
    bool hasCourses() const;
    size_t courseCount() const;
    void printCourses(ostream& os = cout) const;
    void print(ostream& os = cout) const;

    bool operator==(const Student& other) const {
        return id == other.id;
    }
};

#endif // STUDENT_HPP

