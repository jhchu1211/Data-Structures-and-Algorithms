#pragma once
#define CAPACITY 128
typedef char OPStackElement;
class OpStack
{
    OPStackElement stackArray[CAPACITY];
    int stack_top_index; //index starts from 0
public:
    OpStack();
    bool empty();
    OPStackElement check();
    void push(OPStackElement item);
    OPStackElement pop();
    void display();
};