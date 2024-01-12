#ifndef LINKEDLIST_H
#define LINKEDLIST_H

class DoublyLinkedList
{
public:
	DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {};
	~DoublyLinkedList();
	void push_front(int);
	void push_back(int);
	void insert(int, int);
	void remove(int);
	int get(int) const;
	void printList() const;
	void printReverse() const;

private:
struct Node{
	int value;
	Node* prev;
	Node* next;
	Node() : prev(nullptr), next(nullptr) {}
};
Node* head;
Node* tail;
int size;

};

#endif //LINKEDLIST_H
