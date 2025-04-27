#pragma once
#include <string>

class Student {
private:
    std::string firstName;
    std::string lastName;
    std::string mNumber;

public:
    Student(std::string fn, std::string ln, std::string mn);
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getMNumber() const;
    std::string toString() const;

    // Conversion overload
    operator std::string() const;
};
