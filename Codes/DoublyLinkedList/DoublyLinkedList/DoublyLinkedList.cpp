#include <iostream>
using namespace std;
#include "Node.h"
#include "DLL.h"


int main()
{
    Node* p1n1 = new Node(4, 0);
    Node* p1n2 = new Node(7, 2);
    Node* p1n3 = new Node(12, 10);
    Node* p1n4 = new Node(1, 25);
    Node* p1n5 = new Node(5, 50);
    Node* p2n1 = new Node(3, 2);
    Node* p2n2 = new Node(8, 7);
    Node* p2n3 = new Node(19, 25);

    DLL p1;
    DLL p2;
    DLL p3;

    p1.insert(p1n1);
    p1.insert(p1n2, p1n1);
    p1.insert(p1n3, p1n2);
    p1.insert(p1n4, p1n3);
    p1.insert(p1n5, p1n4);
    cout << "\t\tP1(x) = ";
    p1.display();

    p2.insert(p2n1);
    p2.insert(p2n2, p2n1);
    p2.insert(p2n3, p2n2);
    cout << "\t\tP2(x) = ";
    p2.display();

    p3 = p3.addpolynomials(p1, p2);
    cout << "P3(x) = P1(x) + P2(x) = ";
    p3.display();
    return 0;
}