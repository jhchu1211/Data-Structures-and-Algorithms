#pragma once

#include "Node.h"
typedef int StackElement;
class IntStack
{
public:
    Node* stack_top;
    int stack_size;

    IntStack();
    bool empty();
    void push(Node* item);
    Node* pop();
    void display();
};