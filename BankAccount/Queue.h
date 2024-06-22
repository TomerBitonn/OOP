#include "Account.h"

#pragma once
class Queue
{
	friend ostream& operator<<(ostream& output, const Queue& q);
private:
	Account* head; // point to the first element
	Account* tail; // point to the last element
public:
	Queue() : head(NULL), tail(NULL) {}; // Composition. Using "member initializer" format.
	void addNode(Account& new_costumer);
	Account& getNode(); // return reference
	Account& topNode() const;
	bool isEmpty() const;
	void printQueue() const;
};