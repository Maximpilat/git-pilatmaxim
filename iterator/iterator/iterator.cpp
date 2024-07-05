#include "iterator.h"

void MyList::AddFirst(int value)
{
    SElement* NEW = new SElement(value, first);
    first = NEW;
}

void MyList::Print()
{
    for (SElement* temp = first; temp != nullptr; temp = temp->next)
        std::cout << temp->data << " ";
}

int MyList::DeleteElement()
{
    if (first == nullptr)
        return -1;
    SElement* temp = first;
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
    SElement* temp = new SElement(y, nullptr);
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

void MyList::ToVector(std::vector<int>& Vec)
{
    Vec.clear();
    for (SElement* temp = first; temp != nullptr; temp = temp->next)
        Vec.push_back(temp->data);
}

int MyList::Count() {
    if (Empty())
        return 0;
    SElement* temp = first;
    int count = 1;
    while (temp->next != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

int MyList::Get(int n) {
    SElement* el = first;
    for (int i = 1; i <= n; i++)
        el = el->next;
    return el->data;
}

ListIterator::ListIterator(
    MyList* aList) : _list(aList), _current(0) {}

void ListIterator::First()
{
    _current = 0;
}

void ListIterator::Next()
{
    _current++;
}

bool ListIterator::IsDone() {
    return _current <= _list->Count();  
}

int ListIterator::CurrentItem() {
    return _list->Get(_current);
}