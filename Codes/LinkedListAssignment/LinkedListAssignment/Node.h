#pragma once

class Node
{
public:
    int data, exp;
    Node* next;
    Node* prev;
    Node(int d, int e);
};