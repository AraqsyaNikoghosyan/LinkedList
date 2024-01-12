#include "linkedList.h"
#include <iostream>

DoublyLinkedList::~DoublyLinkedList() {
    Node* current = head;
    while (current) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

void DoublyLinkedList::push_front(int value) {
    Node* newNode = new Node;
    newNode->value = value;

    if (!head) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    size++;
}

void DoublyLinkedList::push_back(int value) {
    Node* newNode = new Node;
    newNode->value = value;

    if (!tail) {
        head = tail = newNode;
    } else {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }

    size++;
}

void DoublyLinkedList::insert(int index, int value) {
    if (index < 0 || index > size) {
        std::cout << "Error: Index out of bounds." << std::endl;
        return;
    }

    if (index == 0) {
        push_front(value);
        return;
    } else if (index == size) {
        push_back(value);
        return;
    }

    Node* newNode = new Node;
    newNode->value = value;

    Node* current = head;
    for (int i = 0; i < index - 1; i++) {
        current = current->next;
    }

    newNode->prev = current;
    newNode->next = current->next;
    current->next->prev = newNode;
    current->next = newNode;

    size++;
}

void DoublyLinkedList::remove(int index) {
    if (index < 0 || index >= size) {
        std::cout << "Error: Index out of bounds." << std::endl;
        return;
    }

    Node* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }

    if (current->prev) {
        current->prev->next = current->next;
    } else {
        head = current->next;
    }

    if (current->next) {
        current->next->prev = current->prev;
    } else {
        tail = current->prev;
    }

    delete current;
    size--;
}

int DoublyLinkedList::get(int index) const {
    if (index < 0 || index >= size) {
        std::cout << "Error: Index out of bounds." << std::endl;
        return -1;
    }

    Node* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }

    return current->value;
}

void DoublyLinkedList::printList() const {
    Node* current = head;
    while (current) {
        std::cout << current->value << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

void DoublyLinkedList::printReverse() const {
    Node* current = tail;
    while (current) {
        std::cout << current->value << " ";
        current = current->prev;
    }
    std::cout << std::endl;
}

