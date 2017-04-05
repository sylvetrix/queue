#include "src/Queue.hpp"
#include <cstdlib>

using namespace std;

template <class T>
Queue<T>::Queue()
{
	this->head = NULL;
	this->tail = NULL;
}

template <class T>
Queue<T>::~Queue()
{
	while (this->head != NULL)
	{
		QueueNode<T>* tempNode = this->head;

		if (this->head == this->tail)
		{
			this->head = NULL;
			this->tail = NULL;
		}
		else
		{
			this->head = this->head->next;
		}

		delete tempNode;
	}
}

template <class T>
T Queue<T>::dequeue()
{
	if (this->head != NULL)
	{
		T temp = this->head->value;
		QueueNode<T>* tempNode = this->head;

		if (this->head == this->tail)
		{
			this->head = NULL;
			this->tail = NULL;
		}
		else
		{
			this->head = this->head->next;
		}

		delete tempNode;
		return temp;
	}

	return T();
}

template <class T>
void Queue<T>::enqueue(T element)
{
	QueueNode<T>* tempNode = new QueueNode<T>();
	tempNode->value = element;

	if (this->head == NULL)
	{
		this->head = tempNode;
		this->tail = tempNode;
	}
	else
	{
		this->tail->next = tempNode;
		this->tail = this->tail->next;
	}
}

