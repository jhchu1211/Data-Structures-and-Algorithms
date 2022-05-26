#include <iostream>
using namespace std;
#include "Node.h"
#include "DLL.h"

DLL::DLL() {
    first = nullptr;
    last = nullptr;
    listsize = 0;
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
        first = newnode;
    else
    {
        first->prev = newnode;
        newnode->next = first;
        first = newnode;
    }
}

void DLL::insert(Node* newnode, Node* pred)
{
    if (pred->next != nullptr)
    {
        pred->next->prev = newnode;
        newnode->next = pred->next;
    }
    pred->next = newnode;
    newnode->prev = pred;
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
            cout << last->data << "x^" << last->exp;
            last = last->prev;
            if (last != nullptr)
                cout << " + ";
        } while (last != nullptr);
        cout << endl;
    }
    else
    {
        cout << "\n The list is empty\n";
    }
}

DLL DLL::add(DLL p1, DLL p2)
{
    DLL ijk;
    Node* holdplace = ijk.first;
    Node* currentPoly1 = p1.first;
    Node* currentPoly2 = p2.first;
    //initalize 
    if (currentPoly1->exp < currentPoly2->exp)
    {
        ijk.insert(new Node(currentPoly1->data, currentPoly1->exp));
        holdplace = ijk.first;
        currentPoly1 = currentPoly1->next;
    } else
    if (currentPoly1->exp == currentPoly2->exp)
    {
        ijk.insert(new Node(currentPoly1->data + currentPoly2->data, currentPoly1->exp));
        holdplace = ijk.first;
        currentPoly1 = currentPoly1->next;
        currentPoly2 = currentPoly2->next;
    } else
    if (currentPoly1->exp > currentPoly2->exp)
    {
        ijk.insert(new Node(currentPoly2->data, currentPoly2->exp));
        holdplace = ijk.first;
        currentPoly2 = currentPoly2->next;
    }

    //sort in ascending order based on exponent 
    do
    { 
    if (currentPoly1->exp < currentPoly2->exp)
    {
        ijk.insert(new Node(currentPoly1->data, currentPoly1->exp), holdplace);
        holdplace = holdplace->next;
        currentPoly1 = currentPoly1->next;
    } else
    if (currentPoly1->exp == currentPoly2->exp)
    {
        ijk.insert(new Node(currentPoly1->data + currentPoly2->data, currentPoly1->exp), holdplace);
        holdplace = holdplace->next;
        currentPoly1 = currentPoly1->next;
        currentPoly2 = currentPoly2->next;
    } else
    if (currentPoly1->exp > currentPoly2->exp)
    {
        ijk.insert(new Node(currentPoly2->data, currentPoly2->exp), holdplace);
        holdplace = holdplace->next;
        currentPoly2 = currentPoly2->next;
    }
    } while ((currentPoly1 != nullptr) && (currentPoly2 != nullptr));

    //after one polynomial is finished being sorted, this next do/while adds the remainder of polynomial
    //sorting not required due to presorting in main()
    do
    {
        if (currentPoly1 != nullptr)
        {
            ijk.insert(new Node(currentPoly1->data, currentPoly1->exp), holdplace);
            holdplace = holdplace->next;
            currentPoly1 = currentPoly1->next;
        }
        else if (currentPoly2 != nullptr)
        {
            ijk.insert(new Node(currentPoly2->data, currentPoly2->exp), holdplace);
            holdplace = holdplace->next;
            currentPoly2 = currentPoly2->next;
        }
    } while ((currentPoly1 != nullptr) || (currentPoly2 != nullptr));

    return ijk;
}