/* This program implements a Queue data structure using templates. */

#include <iostream>
using namespace std;

#pragma once
template <typename T>
class Queue
{
private:
	struct Node
	{
		T data;
		Node* next;
		Node(T value) :data(value), next(NULL) {}
	};
	Node* head = NULL;
	Node* tail = NULL;
public:
	Queue();
	~Queue();

	void Enqueue(T data);
	T Dequeue();
	T frontElement() const;
	bool isEmpty() const;
	void deleteQueue();
	void printQueue() const;
};

/* Counstructor. */
template<typename T>
inline Queue<T>::Queue()
{
	head = NULL;
	tail = NULL;
}

/* Destructor. */
template<typename T>
inline Queue<T>::~Queue()
{
	deleteQueue();
}

/* Add element to the queue. */
template<typename T>
inline void Queue<T>::Enqueue(T data)
{
	Node* newNode = new Node(data);
	if (head == NULL)
		head = tail = newNode;
	else
	{
		tail->next = newNode;
		tail = tail->next;
	}
}

/* Remove the first element of the queue. */
template<typename T>
inline T Queue<T>::Dequeue()
{
	Node* removeHead = head;
	if (head != NULL)
	{
		head = head->next;
	}
	return removeHead->data;
}

/* Return the first element of the queue. */
template<typename T>
inline T Queue<T>::frontElement() const
{
	if (head != NULL)
		return head->data;
	else
		return NULL;
}

/* Check if the queue is empty. */
template<typename T>
inline bool Queue<T>::isEmpty() const
{
	return head == NULL;
}

/* Delete the queue. */
template<typename T>
inline void Queue<T>::deleteQueue()
{
	Node* temp = NULL;

	while (!isEmpty())
	{
		temp = head->next;
		delete head;
		head = NULL;
		head = temp;
	}
	tail = NULL;
}

/* Print the queue. */
template<typename T>
inline void Queue<T>::printQueue() const
{
	Node* temp = head;

	while (temp)
	{
		cout << temp->data << " -> ";
		temp = temp->next;
	}
	cout << "NULL";
}