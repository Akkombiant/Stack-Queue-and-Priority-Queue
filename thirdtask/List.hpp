#ifndef LIST_H
#define LIST_H

#include "Element.hpp"
#include <iostream>

using namespace std;

template<typename T>
class List
{
public:
	List();

	List(const List<T>& obj);
	List<T> &operator=(const List<T>& obj);

	~List();

	bool isEmpty() const;

	void showFromTail() const;
	void showFromHead() const;

	void pushBack(const T& data);
	void pushFront(const T& data);
	void insert(const int& pos, const T& value);

	void deleteFrom(const int& pos);
	void popBack();
	void popFront();
	void clear();

	Element<T> front() const;
	Element<T> back() const;

	void increaseSize();
	void decreaseSize();
	int getSize() const;

private:
	Element<T>* Head;
	Element<T>* Tail;
	unsigned int size;

};

template<typename T>
List<T>::List():Head(nullptr), Tail(nullptr), size(0)
{

}

template<typename T>
void List<T>::popBack()
{
	if (1 == size)
	{
		delete Tail;
		Tail = nullptr;
	}
	else
	{
		Tail = Tail->prev;
		delete Tail->next;
		Tail->next = nullptr;
	}
	decreaseSize();
}

template<typename T>
void List<T>::popFront()
{
	if (1 == size)
	{
		delete Head;
		Head->prev = nullptr;
	}
	else
	{
		Head = Head->next;
		delete Head->prev;
		Head->prev = nullptr;
	}
	decreaseSize();
}

template<typename T>
inline void List<T>::clear()
{
	while (0 != size)
	{
		popBack();
	}
}

template<typename T>
inline Element<T> List<T>::front() const
{
	return *Head;
}

template<typename T>
inline Element<T> List<T>::back() const
{
	return *Tail;
}

template<typename T>
inline void List<T>::increaseSize()
{
	++size;
}

template<typename T>
inline void List<T>::decreaseSize()
{
	--size;
}

template<typename T>
int List<T>::getSize() const
{
	return size;
}

template<typename T>
inline List<T>::List(const List<T>& obj)
{
	Element<T> * temp = &obj.front();
	while (nullptr != temp)
	{
		pushBack(temp->data);
		temp = temp->next;
	}
}

template<typename T>
inline List<T>& List<T>::operator=(const List<T>& obj)
{
	if (this != &obj)
	{
		clear();
		Element<T>* temp = &obj.front();
		while (nullptr != temp)
		{
			pushBack(temp->data);
			temp = temp->next;
		}
	}
	return *this;
}

template<typename T>
List<T>::~List()
{
	clear();
}

template<typename T>
bool List<T>::isEmpty() const
{
	return Head == nullptr;
}

template<typename T>
void List<T>::showFromTail() const
{
	Element<T> *temp = Tail;
	while (nullptr != temp)
	{
		cout << temp->data << " ";
		temp = temp->prev;
	}
	cout << "\n";
}

template<typename T>
void List<T>::showFromHead() const
{
	Element<T>* temp = Head;
	while (nullptr != temp)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << "\n";
}

template<typename T>
void List<T>::pushBack(const T& data)
{
	Element<T>* temp = new Element<T>();
	temp->next = nullptr;
	temp->data = data;

	if (0 == size)
	{
		Tail = temp;
		Head = Tail;
	}
	else
	{
		temp->prev = Tail;
		Tail->next = temp;
		Tail = temp;
	}
	increaseSize();
}

template<typename T>
void List<T>::pushFront(const T& data)
{
	Element<T>* temp = new Element<T>();
	temp->next = Head;
	temp->prev = nullptr;
	temp->data = data;

	if (0 == size)
	{
		Head = temp;
		Tail = Head;
	}
	else
	{
		temp->next = Head;
		Head->prev = temp;
		Head = temp;
	}
	increaseSize();
}

template<typename T>
void List<T>::insert(const int& pos, const T& value)
{
	if (pos > (size - 1))
	{
		cout << "out of range" << endl;
		return;
	}
	Element<T>* temp = Head;
	int tempPos = 0;
	while (nullptr != temp)
	{
		if (pos == tempPos)
		{
			Element<T>* element = new Element<T>;
			if (0 == tempPos)
			{
				element->prev = nullptr;
				element->next = Head;
				element->data = value;
				element->next->prev = Head;
				Head = element;
			}
			else if (tempPos == (size - 1))
			{
				element->prev = Tail;
				element->next = nullptr;
				element->data = value;

				element->prev->next = element;

				Tail = element;
			}
			else
			{
				element->next = temp;
				element->prev = temp->prev;
				element->data = value;

				element->prev->next = element;
				element->next->prev = element;
			}
			++size;

			break;
		}
		else
		{
			temp = temp->next;
			++tempPos;
		}
	}
}

template<typename T>
void List<T>::deleteFrom(const int& pos)
{
	Element<T>* temp = Head;
	int tempPos = 0;
	while (nullptr != temp)
	{
		if (pos == tempPos)
		{
			if (0 == tempPos)
			{
				temp->next->prev = nullptr;
				Head = temp->next;
				--size;
				delete temp;

				break;
			}
			else if (tempPos == (size - 1))
			{
				temp->prev->next = nullptr;
				Tail = temp->prev;
				delete temp;

				break;
			}
			else
			{
				temp->prev->next = temp->next;
				temp->next->prev = temp->prev;
				delete temp;

				break;
			}
		}
		else {
			temp = temp->next;
			++tempPos;
		}
	}
}

#endif // !LIST_H