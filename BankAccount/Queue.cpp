#define _CRT_SECURE_NO_WARNINGS
#include "Queue.h"

void Queue::addNode(Account& new_costumer)
{
	if (this->head == NULL)
	{
		this->head = this->tail = &new_costumer;
	}
	else
	{
		this->tail->SetNext(new_costumer);
		this->tail = this->tail->GetNext();
	}
}

Account& Queue::getNode()
{
	Account* temp = head;
	if (!isEmpty())
	{
		this->head = this->head->GetNext();
	}
	return *temp;
}

Account& Queue::topNode() const
{
	return *head;
}

bool Queue::isEmpty() const
{
	return head == NULL;
}

void Queue::printQueue() const
{
	Account* temp = head;
	cout << "Start of Queue:" << endl << endl;
	while (temp)
	{
		temp->print();
		temp = temp->GetNext();
	}
	cout << "End of Queue" << endl << endl;
}

ostream& operator<<(ostream& output, const Queue& q) 
{
	Account* temp = q.head;
	while (temp)
	{
		output << (*temp);
		temp = temp->GetNext();
	}
	return output;
}
