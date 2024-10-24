#include "Person.h"
using namespace std;

Person::Person() : category(""), fullName("") {}


Person::Person(const string& category, const string& fullName)
    : category(category), fullName(fullName) {}


void Person::printQueue() const 
{
    std::cout << category << ": " << fullName << std::endl;
}


int Person::getPriority() const 
{
    if (category == "Teacher") return 1;
    if (category == "Parent") return 2;
    if (category == "Student") return 3;
    return 4;  
}
