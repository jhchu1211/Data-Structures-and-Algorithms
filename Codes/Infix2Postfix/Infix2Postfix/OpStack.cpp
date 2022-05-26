#include <iostream>
using namespace std;
#include "OpStack.h"
#include "IntStack.h"


OpStack::OpStack()
{
    stack_top_index = 0;
}

bool OpStack::empty()
{
    if (stack_top_index == 0)
        return true;
    else
        return false;
}

OPStackElement OpStack::check()
{
    return stackArray[stack_top_index - 1];
}

void OpStack::push(OPStackElement item)
{
    if (stack_top_index == CAPACITY)
        cout << "\nstack is full\n";
    else
    {
        stackArray[stack_top_index] = item;
        stack_top_index++;
    }
}

OPStackElement OpStack::pop()
{
    OPStackElement item = 0;
    stack_top_index--;
    if (stack_top_index >= 0)
        item = stackArray[stack_top_index];
    else
        cout << "\nstack is empty\n";
    return item;
}

void OpStack::display()
{
    int current_index = stack_top_index - 1;
    for (int i = current_index; i >= 0; i--)
    {
        cout << stackArray[i] << ", ";
    }
}

StackElement IntStack::pop()
{
    StackElement item = 0;
    stack_top_index--;
    if (stack_top_index >= 0)
        item = stackArray[stack_top_index];
    else
        cout << "\n stack is empty\n";
    return item;
}

void IntStack::display()
{
    int current_index = stack_top_index - 1;
    for (int i = current_index; i >= 0; i--)
    {
        cout << stackArray[i] << ", ";
    }
}