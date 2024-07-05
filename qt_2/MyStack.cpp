#include "mystack.h"

int MyStack::Pop()
{
    return DeleteElement();
}

void MyStack::Push(int x)
{
    AddFirst(x);
}

bool MyStack::isEmpty()
{
    return Empty();
}

void MyStack::PrintStack()
{
    Print();
}

void MyStack::toVector(std::vector<int> &Vec)
{
    ToVector(Vec);
}
