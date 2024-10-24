#include <string>
#include <iostream>
using namespace std;

class Person 
{
public:
    std::string category;
    std::string fullName;

    Person();
    Person(const string& category, const string& fullName);

    void printQueue() const;
    int getPriority() const;  
};


