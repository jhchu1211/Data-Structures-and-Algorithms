#include <iostream>
using namespace std;
#include "IntStack.h"

IntStack::IntStack()
{
    stack_top_index = 0;
}

bool IntStack::empty()
{
    if (stack_top_index == 0)
        return true;
    else
        return false;
}

void IntStack::push(StackElement item)
{
    if (stack_top_index == CAPACITY)
        cout << "\nstack is full\n";
    else
    {
        stackArray[stack_top_index] = item;
        stack_top_index++;
    }
}