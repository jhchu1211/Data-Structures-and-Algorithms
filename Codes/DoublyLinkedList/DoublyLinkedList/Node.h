#pragma once

class Node
{
public:
    int coefficient, exponent;
    Node* next;
    Node* prev;
    Node(int c, int e);
};