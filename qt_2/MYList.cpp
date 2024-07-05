#include "mylist.h"

void MyList::AddFirst(int value)
{
    SElement *NEW = new SElement(value, first);
    first = NEW;
}

void MyList::Print()
{
    for (SElement *temp = first; temp != nullptr; temp = temp->next)
        std::cout << temp->data << " ";
}

int MyList::DeleteElement()
{
    if(first == nullptr)
        return -1;
    SElement *temp = first;
    first = first->next;
    int value = temp->data;
    delete temp;
    return value;
}

MyList::MyList()
{
    first = nullptr;
}

MyList::MyList(int x)
{
    first = new SElement(x, nullptr);
}

MyList::MyList(int x, int y, int z)
{
    first = new SElement(x, nullptr);
    SElement *temp = new SElement(y, nullptr);
    first->next = temp;
    temp = new SElement(z, nullptr);
    first->next->next = temp;
}

MyList::~MyList()
{
    while (first != nullptr)
        this->DeleteElement();
}

bool MyList::Empty()
{
    return (nullptr == first);
}

void MyList::ToVector(std::vector<int> &Vec)
{
    Vec.clear();
    for (SElement *temp = first; temp != nullptr; temp = temp->next)
        Vec.push_back(temp->data);
}
