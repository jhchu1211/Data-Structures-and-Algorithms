#include <iostream>
using namespace std;
#include "Node.h"

Node::Node(int d, int e)
{
    data = d; //coefficent
    exp = e; // exponent
    next = nullptr;
    prev = nullptr;
}