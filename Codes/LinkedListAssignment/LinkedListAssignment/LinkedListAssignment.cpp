// LinkedListAssignment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Node.h"
#include "DLL.h"
using namespace std;


int main()
{ // R for poly1, G for poly2, C for poly3
    Node* R1 = new Node(2, 0);
    Node* R2 = new Node(5, 3);
    Node* R3 = new Node(3, 12);
    Node* R4 = new Node(8, 19);
    Node* R5 = new Node(9, 25);
    Node* R6 = new Node(10, 99);

    Node* G1 = new Node(2, 0);
    Node* G2 = new Node(6, 4);
    Node* G3 = new Node(4, 12);


    DLL poly1;
    DLL poly2;
    DLL polyT;

    poly1.insert(R1);
    poly1.insert(R2, R1);
    poly1.insert(R3, R2);
    poly1.insert(R4, R3);
    poly1.insert(R5, R4);
    poly1.insert(R6, R5);
    cout << "p1(x) = ";
    poly1.display();
    poly2.insert(G1);
    poly2.insert(G2, G1);
    poly2.insert(G3, G2);
    cout << "p2(x) = ";
    poly2.display();
    polyT = polyT.add(poly1, poly2);
    cout << "p_total(x) = ";
    polyT.display();

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
