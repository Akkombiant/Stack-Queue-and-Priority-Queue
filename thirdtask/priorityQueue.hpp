#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include "list.hpp"

template<typename T>
class PriorityQueue
{
public:
	PriorityQueue();
	~PriorityQueue();

	Element<T> getTop() const;
	bool empty() const;
	int getSize() const;

	void push(const T& data);
	void pop();
	void printPriorityQueue() const;

private:
	List<T> myList;
};


template<typename T>
PriorityQueue<T>::PriorityQueue() : myList()
{

}

template<typename T>
PriorityQueue<T>::~PriorityQueue()
{
	myList.clear();
}

template<typename T>
Element<T> PriorityQueue<T>::getTop() const
{
	return myList.front();
}

template<typename T>
bool PriorityQueue<T>::empty() const
{
	return myList.isEmpty();
}

template<typename T>
int PriorityQueue<T>::getSize() const
{
	return myList.getSize();
}

template<typename T>
void PriorityQueue<T>::push(const T & newData)
{
	/*
	if (true == myList.isEmpty())
	{
		myList.pushBack(newData);
	}
	else
	{
		for (int i = 0; nullptr != temp; i++) {

		}
	}
	*/
}

template<typename T>
void PriorityQueue<T>::pop()
{
	myList.popFront();
}

template<typename T>
void PriorityQueue<T>::printPriorityQueue() const
{
	myList.showFromHead();
}

#endif // !PRIORITYQUEUE_H