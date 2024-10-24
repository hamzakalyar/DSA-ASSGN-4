#include "Person.h"
using namespace std;

struct Node {
    Person info;  
    Node* next;
    Node* pre;
};

class LinkedList {
private:
    Node* List;

public:
    LinkedList();
    ~LinkedList();

    void traverse() const;      
    Node* find(const string& name);  
    void iAS(const Person& x);  
    int dAS();                  
    void iAE(const Person& x);  
    int dAE();                  
    void iAM(const Person& x);  
    int dAM(const string& name);   
    bool isEmpty() const;       
};

