
#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student {
private:
    std::string firstName;
    std::string lastName;
    std::string mNumber;
    std::string major;

public:
    Student(std::string fn, std::string ln, std::string mn, std::string maj);
    std::string getMNumber() const;
    std::string toString() const;

    // Conversion overload
    operator std::string() const;
};

#endif