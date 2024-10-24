#include "LinkedList.h"
#include <iostream>
using namespace std;

LinkedList::LinkedList() 
{
    List = nullptr;
}

LinkedList::~LinkedList()
{
    while (!isEmpty())
    {
        dAS();
    }
}

bool LinkedList::isEmpty() const 
{
    return List == nullptr;
}


void LinkedList::iAS(const Person& x) 
{
    Node* p = new Node;
    p->info = x;
    p->pre = nullptr;
    p->next = List;
    if (List != nullptr) {
        List->pre = p;
    }
    List = p;
}


int LinkedList::dAS()
{
    if (List == nullptr) 
    {
        return -999;
    }
    Node* p = List->next;
    int x = List->info.getPriority();  

    if (p != nullptr)
    {
        p->pre = nullptr;
    }

    delete List;
    List = p;
    return x;
}


void LinkedList::traverse() const 
{
    Node* p = List;
    while (p != nullptr)
    {
        p->info.printQueue();
        p = p->next;
    }
    cout << endl;
}


void LinkedList::iAE(const Person& x) 
{
    if (List == nullptr)
    {
        iAS(x);
    }
    else {
        Node* q = nullptr;
        Node* p = List;
        while (p->next != nullptr)
        {
            p = p->next;
        }
        q = new Node;
        q->info = x;
        p->next = q;
        q->pre = p;
        q->next = nullptr;
    }
}


int LinkedList::dAE() 
{
    if (List == nullptr) 
    {
        return -999;
    }

    if (List->next == nullptr) 
    {
        return dAS();
    }
    else {
        Node* p = List;
        while (p->next != nullptr)
        {
            p = p->next;
        }

        int x = p->info.getPriority();  

        p->pre->next = nullptr;
        delete p;
        return x;
    }
}


Node* LinkedList::find(const std::string& name) 
{
    for (Node* p = List; p != nullptr; p = p->next) 
    {
        if (p->info.fullName == name) 
        {
            return p;
        }
    }
    return nullptr;
}


void LinkedList::iAM(const Person& x)
{
    Node* p = List;
    Node* q = nullptr;

    
    while (p != nullptr && x.getPriority() >= p->info.getPriority()) 
    {
        q = p;
        p = p->next;
    }

    if (q == nullptr)
    {
        iAS(x);
    }
    else if (p == nullptr) 
    {
        iAE(x); 
    }
    else 
    {
        Node* newNode = new Node;
        newNode->info = x;
        newNode->next = p;
        newNode->pre = q;
        q->next = newNode;
        p->pre = newNode;
    }
}

int LinkedList::dAM(const string& name) 
{
    Node* p = find(name);

    if (p == nullptr)
    {
        return -999;  
    }

    if (p == List)
    {
        return dAS();  
    }

    if (p->next == nullptr)
    {
        return dAE();  
    }

    p->pre->next = p->next;
    p->next->pre = p->pre;
    delete p;
    return 1;  
}
