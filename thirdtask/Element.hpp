#ifndef ELEMENT_H
#define ELEMENT_H

template<typename T>
struct Element
{
	T data;
	Element<T> *next;
	Element<T> *prev;
	Element();
};

template<typename T>
Element<T>::Element() : next(nullptr), prev(nullptr), data(0)
{

}
#endif // !ELEMENT_H

