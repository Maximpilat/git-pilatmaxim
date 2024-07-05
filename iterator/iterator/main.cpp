#include <iostream>
#include "iterator.h"

int main()
{
    MyList list;
    list.AddFirst(30);
    list.AddFirst(29);
    list.AddFirst(28);
    list.AddFirst(27);
    list.AddFirst(31);
    for (ListIterator iterator(&list); iterator.IsDone(); iterator.Next())
    {
        std::cout << iterator.CurrentItem() << std::endl;
    }
    return 0;
}