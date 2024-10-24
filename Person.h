#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>

class Person {
public:
    std::string category;
    std::string fullName;

    Person();
    Person(const std::string& category, const std::string& fullName);

    void printQueue() const;
    int getPriority() const;  // Method to get the priority of a person
};

#endif // PERSON_H
