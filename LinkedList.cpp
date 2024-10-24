#include "LinkedList.h"
#include <iostream>
using namespace std;

LinkedList::LinkedList() {
    List = nullptr;
}

LinkedList::~LinkedList() {
    while (!isEmpty()) {
        dAS();
    }
}

bool LinkedList::isEmpty() const {
    return List == nullptr;
}

// Insert at the start (iAS)
void LinkedList::iAS(const Person& x) {
    Node* p = new Node;
    p->info = x;
    p->pre = nullptr;
    p->next = List;
    if (List != nullptr) {
        List->pre = p;
    }
    List = p;
}

// Delete from the start (dAS)
int LinkedList::dAS() {
    if (List == nullptr) {
        return -999;
    }
    Node* p = List->next;
    int x = List->info.getPriority();  // Return priority value instead of info

    if (p != nullptr) {
        p->pre = nullptr;
    }

    delete List;
    List = p;
    return x;
}

// Traverse the list and print all persons
void LinkedList::traverse() const {
    Node* p = List;
    while (p != nullptr) {
        p->info.printQueue();
        p = p->next;
    }
    cout << endl;
}

// Insert at the end (iAE)
void LinkedList::iAE(const Person& x) {
    if (List == nullptr) {
        iAS(x);
    }
    else {
        Node* q = nullptr;
        Node* p = List;
        while (p->next != nullptr) {
            p = p->next;
        }
        q = new Node;
        q->info = x;
        p->next = q;
        q->pre = p;
        q->next = nullptr;
    }
}

// Delete from the end (dAE)
int LinkedList::dAE() {
    if (List == nullptr) {
        return -999;
    }

    if (List->next == nullptr) {
        return dAS();
    }
    else {
        Node* p = List;
        while (p->next != nullptr) {
            p = p->next;
        }

        int x = p->info.getPriority();  // Return priority value instead of info

        p->pre->next = nullptr;
        delete p;
        return x;
    }
}

// Find a person by name
Node* LinkedList::find(const std::string& name) {
    for (Node* p = List; p != nullptr; p = p->next) {
        if (p->info.fullName == name) {
            return p;
        }
    }
    return nullptr;
}

// Insert in the middle based on priority (iAM)
void LinkedList::iAM(const Person& x) {
    Node* p = List;
    Node* q = nullptr;

    // Traverse the list and find the correct insertion point
    while (p != nullptr && x.getPriority() >= p->info.getPriority()) {
        q = p;
        p = p->next;
    }

    // If q is NULL, insert at the start
    if (q == nullptr) {
        iAS(x);
    }
    else if (p == nullptr) {
        iAE(x);  // Insert at the end if no next node
    }
    else {
        // Inserting between q and p
        Node* newNode = new Node;
        newNode->info = x;
        newNode->next = p;
        newNode->pre = q;
        q->next = newNode;
        p->pre = newNode;
    }
}

// Delete a person by name (dAM)
int LinkedList::dAM(const std::string& name) {
    Node* p = find(name);

    if (p == nullptr) {
        return -999;  // Person not found
    }

    if (p == List) {
        return dAS();  // Person is at the start
    }

    if (p->next == nullptr) {
        return dAE();  // Person is at the end
    }

    // Person is in the middle
    p->pre->next = p->next;
    p->next->pre = p->pre;
    delete p;
    return 1;  // Success
}
