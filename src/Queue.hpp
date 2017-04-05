#ifndef STACK_H
#define STACK_H

#include <cstdlib>

template <class T>
struct QueueNode
{
	T value;
	QueueNode<T>* next;
};

template <class T>
class Queue
{
	public:
		Queue();
		~Queue();
		bool isEmpty() { return head == NULL; }
		T dequeue();
		void enqueue(T);

	private:
		QueueNode<T>* head;
		QueueNode<T>* tail;
};

#endif

