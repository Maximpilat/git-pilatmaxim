#pragma once
#include "mylist.h"

class MyStack : private MyList
{
public:
    MyStack() : MyList() {}
    MyStack(int x) : MyList(x) {}
    MyStack(int x, int y, int z) : MyList(x, y, z) {}
    ~MyStack() = default;
    int Pop();
    void Push(int);
    bool isEmpty();
    void PrintStack();
    void toVector(std::vector<int> &);
};
