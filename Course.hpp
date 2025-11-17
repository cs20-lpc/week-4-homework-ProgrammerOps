#ifndef COURSE_HPP
#define COURSE_HPP

#include <string>
#include <iostream>
using namespace std;

class Course {
private:
    string name;
    string location;

public:
    Course() = default;
    Course(const string& n, const string& loc) : name(n), location(loc) {}

    const string& getName() const { return name; }
    const string& getLocation() const { return location; }

    void setName(const string& n) { name = n; }
    void setLocation(const string& loc) { location = loc; }

    void print(ostream& os = cout) const {
        os << name << " " << location;
    }

    bool operator==(const Course& rhs) const {
        return name == rhs.name && location == rhs.location;
    }
};

#endif // COURSE_HPP
