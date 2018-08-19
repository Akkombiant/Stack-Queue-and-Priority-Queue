#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include "List.hpp"

using namespace std;

template<typename T>
class Queue
{
public:
	Queue();

	Element<T> front() const;
	Element<T> back() const;

	void printQueue() const;
	bool empty() const;
	int size() const;

	void push(const T& data);
	void pop();

	~Queue();
private:
	List<T> myList;
};

template<typename T>
Queue<T>::Queue() : myList()
{

}

template<typename T>
Element<T> Queue<T>::front() const
{
	myList.front();
}

template<typename T>
Element<T> Queue<T>::back() const
{
	myList.back();
}

template<typename T>
void Queue<T>::printQueue() const
{
	myList.showFromHead();
}

template<typename T>
bool Queue<T>::empty() const
{
	return	myList.isEmpty();
}

template<typename T>
int Queue<T>::size() const
{
	return myList.size();
}

template<typename T>
void Queue<T>::push(const T& data)
{
	myList.pushFront(data);
}

template<typename T>
void Queue<T>::pop()
{
	myList.popBack();
}

template<typename T>
Queue<T>::~Queue()
{
	myList.clear();
}
#endif