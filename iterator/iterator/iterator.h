#pragma once
#include <iostream>
#include <vector>

struct SElement
{
    int data;
    SElement* next;
    SElement(int data_, SElement* next_)
        : data{ data_ }, next{ next_ } {};
    ~SElement() = default;
};

class MyList
{
private:
    SElement* first;

public:
    MyList();
    MyList(int x);
    MyList(int x, int y, int z);
    ~MyList();
    bool Empty();
    void AddFirst(int value);
    int DeleteElement();
    void Print();
    int Count();
    int Get(int);
    void ToVector(std::vector<int>&);
};

class Iterator
{
public:
    virtual void First() = 0;
    virtual void Next() = 0;
    virtual bool IsDone() = 0;
    virtual int CurrentItem() = 0;
protected:
    Iterator() = default;
};

class ListIterator : public Iterator
{
public:
    ListIterator(MyList* aList);
    virtual void First();
    virtual void Next();
    virtual bool IsDone();
    virtual int CurrentItem();

private:
    MyList* _list;
    int _current;
};