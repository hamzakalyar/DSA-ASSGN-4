#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Person.h"

struct Node {
    Person info;  // Changed from int to Person
    Node* next;
    Node* pre;
};

class LinkedList {
private:
    Node* List;

public:
    LinkedList();
    ~LinkedList();

    void traverse() const;      // Traverse the list
    Node* find(const std::string& name);  // Find a person by name
    void iAS(const Person& x);  // Insert at the start
    int dAS();                  // Delete from the start
    void iAE(const Person& x);  // Insert at the end
    int dAE();                  // Delete from the end
    void iAM(const Person& x);  // Insert in the middle (priority insertion)
    int dAM(const std::string& name);     // Delete a specific person
    bool isEmpty() const;       // Check if the list is empty
};

#endif // LINKEDLIST_H
