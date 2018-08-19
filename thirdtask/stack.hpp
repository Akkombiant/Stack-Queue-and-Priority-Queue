#ifndef STACK_H
#define STACK_H

#include <iostream>

#include "List.hpp"

using namespace std;

template <typename T>
class Stack
{
public:
	Stack();

	Element<T> front();
	Element<T> back();

	void pushSec(const T& data);
	void popSec();

	bool empty() const;
	void printStack() const;

	int getStackSize() const;
	Element<T> getTop() const;

	~Stack();

private:
	List<T> myList;
};

template <typename T>
Stack<T>::Stack() : myList()
{
	
}

template<typename T>
Element<T> Stack<T>::front()
{
	myList.front();
}

template<typename T>
Element<T> Stack<T>::back()
{
	myList.back();
}

template<typename T>
void Stack<T>::pushSec(const T& data)
{
	myList.pushBack(data);
}

template<typename T>
void Stack<T>::popSec()
{
	myList.popBack();
}

template<typename T>
bool Stack<T>::empty() const
{
	return myList.isEmpty();
}

template <typename T>
void Stack<T>::printStack() const
{
	myList.showFromHead();
}

template <typename T>
int Stack<T>::getStackSize() const
{
	return myList.size();
}

template <typename T>
Element<T> Stack<T>::getTop() const
{
	return myList.back();
}

template <typename T>
Stack<T>::~Stack()
{
	myList.clear();
}

#endif