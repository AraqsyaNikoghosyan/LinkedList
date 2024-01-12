#include "linkedList.h"
#include <iostream>

int main() {
    DoublyLinkedList myList;

    myList.push_back(2);
    myList.push_back(4);
    myList.push_front(1);
    myList.insert(2, 3);

    myList.printList();
    myList.printReverse();

    int value = myList.get(3);
    std::cout << "Value at index 3: " << value << std::endl;

    myList.remove(1);
    myList.printList();

    return 0;
}

