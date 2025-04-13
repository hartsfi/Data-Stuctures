#include "Student.h"

Student::Student(std::string fn, std::string ln, std::string mn, std::string maj)
    : firstName(fn), lastName(ln), mNumber(mn), major(maj) {}

std::string Student::getMNumber() const {
    return mNumber;
}

std::string Student::toString() const {
    return firstName + " " + lastName + " - " + mNumber + " - " + major;
}

Student::operator std::string() const {
    return mNumber;
}
