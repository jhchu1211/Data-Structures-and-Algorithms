#include <iostream>
using namespace std;
#include "Node.h"

Node::Node(int c, int e)
{
    coefficient = c;
    exponent = e;
    next = nullptr;
    prev = nullptr;
}