// StackNodes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "IntStack.h"
#include "Node.h"
using namespace std;

int main()
{
    int n = 0;
    int quotient = 0;
    int remainder = 0;
    //int counter = 0;
    cout << "\nEnter an integer to convert to binary \n";
    cin >> n;
    quotient = n;
    IntStack my_stack;
    while (quotient > 1)
    {
        remainder = quotient % 2;
        quotient = quotient / 2;
        Node* R = new Node(remainder);
        my_stack.push(R);
        
        //cout << remainder->data << "  ";
        //counter++;
    }
    Node* Q = new Node(quotient);
    my_stack.push(Q);
    //cout << quotient->data << "\n";
    //counter++;
    //cout << "\nThe binary number for " << n->data << " is ";
    my_stack.display();
    /*do
    {
        cout << my_stack.pop();
        counter--;
    } while (counter > 0);
    */
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
