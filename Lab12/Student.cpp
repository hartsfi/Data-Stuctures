#include "Student.h"

Student::Student(std::string fn, std::string ln, std::string mn)
    : firstName(fn), lastName(ln), mNumber(mn) {}

std::string Student::getFirstName() const {
    return firstName;
}

std::string Student::getLastName() const {
    return lastName;
}

std::string Student::getMNumber() const {
    return mNumber;
}

std::string Student::toString() const {
    return firstName + " " + lastName + " - " + mNumber;
}

Student::operator std::string() const {
    return mNumber;
}
