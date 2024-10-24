#include "Person.h"

// Default constructor
Person::Person() : category(""), fullName("") {}

// Parameterized constructor
Person::Person(const std::string& category, const std::string& fullName)
    : category(category), fullName(fullName) {}

// Print the person's category and full name
void Person::printQueue() const {
    std::cout << category << ": " << fullName << std::endl;
}

// Get the priority based on the category
int Person::getPriority() const {
    if (category == "Teacher") return 1;
    if (category == "Parent") return 2;
    if (category == "Student") return 3;
    return 4;  // Default priority for unknown categories
}
