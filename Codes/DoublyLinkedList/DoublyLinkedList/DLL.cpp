#include <iostream>
using namespace std;
#include "Node.h"
#include "DLL.h"

DLL::DLL() {
    first = nullptr;
    listsize = 0;
    last = nullptr;
}
bool DLL::empty()
{
    if (first == nullptr)
        return true;
    else
        return false;
}

void DLL::insert(Node* newnode) {
    if (first == nullptr)
    {
        first = newnode;
        listsize++;
    }
    else
    {
        first->prev = newnode;
        newnode->next = first;
        first = newnode;
        listsize++;
    }
}
void DLL::insert(Node* newnode, Node* pred)
{
    if (pred->next != nullptr)
    {
        pred->next->prev = newnode;
        newnode->next = pred->next;
        listsize++;
    }
    pred->next = newnode;
    newnode->prev = pred;
    listsize++;
}
void DLL::erase(Node* n) {
    if (n->prev == nullptr)
    {
        first = n->next;
    }
    else
    {
        n->prev->next = n->next;
    }
    if (n->next == nullptr)
    {
        n->prev->next = nullptr;
    }
    else
    {
        n->next->prev = n->prev;
    }
    n->prev = nullptr;
    n->next = nullptr;
    listsize--;
}
void DLL::display()
{
    Node* current;

    if (first != nullptr)
    {
        current = first;
        do
        {
            last = current;
            current = current->next;
        } while (current != nullptr);
        do
        {
            cout << last->coefficient << "x^" << last->exponent << " + ";
            last = last->prev;
        } while (last != nullptr);
        cout << "\b\b\n";
    }
    else
    {
        cout << "\n The list is empty\n";
    }
}

DLL DLL::addpolynomials(DLL p1, DLL p2)
{
    DLL temp;
    Node* current = temp.first;
    Node* current1 = p1.first;
    Node* current2 = p2.first;

    if (current1->exponent < current2->exponent)
    {
        temp.insert(new Node(current1->coefficient, current1->exponent));
        current = temp.first;
        current1 = current1->next;
    }
    else if (current1->exponent == current2->exponent)
    {
        temp.insert(new Node((current1->coefficient + current2->coefficient), current1->exponent));
        current = temp.first;
    }
    else if (current1->exponent > current2->exponent)
    {
        temp.insert(new Node(current2->coefficient, current2->exponent));
        current = temp.first;
    }
    do
    {
        if (current1->exponent < current2->exponent)
        {
            temp.insert(new Node(current1->coefficient, current1->exponent), current);
            current = current->next;
            current1 = current1->next;
        }
        else if (current1->exponent == current2->exponent)
        {
            temp.insert(new Node(current1->coefficient + current2->coefficient, current1->exponent), current);
            current = current->next;
            current1 = current1->next;
            current2 = current2->next;
        }
        else if (current1->exponent > current2->exponent)
        {
            temp.insert(new Node(current2->coefficient, current2->exponent), current);
            current = current->next;
            current2 = current2->next;
        }
    } while ((current2 != nullptr) && (current1 != nullptr));

    if (current1 != nullptr)
    {
        temp.insert(new Node(current1->coefficient, current1->exponent), current);
    }
    else if (current2 != nullptr)
    {
        temp.insert(new Node(current2->coefficient, current2->exponent), current);
    }
    return temp;
}