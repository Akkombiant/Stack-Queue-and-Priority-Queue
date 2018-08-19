#include <iostream>
#include <conio.h>

#include "stack.hpp"
#include "Queue.hpp"
#include "priorityQueue.hpp"

using namespace std;

int main()
{
	List<int> list;
	list.pushBack(100);
	std::cout<< reinterpret_cast<long>(&list.back())<<std::endl;

	Element<int>* tmp = &list.back();

	std::cout << reinterpret_cast<long>(tmp) << std::endl;

	Stack<int> stack;
	cout << "Stack isEmpty? ";
	cout << (stack.empty() ? "true" : "false");
	cout << "\n_____________________________________________" << endl;
	
	cout << "\nFirst 5 digits with a space:";
	stack.pushSec(1);
	stack.pushSec(2);
	stack.pushSec(3);
	stack.pushSec(4);
	stack.pushSec(5);
	
	cout << endl;

	stack.printStack();
	stack.getTop();

	cout << "\n\nDelete one element from stack\n";
	stack.popSec();
	stack.printStack();

	cout << "_____________________________________________\n";
	Queue<int> myQueue;
	cout << "Queue isEmpty? ";
	cout << (myQueue.empty() ? "true" : "false");
	cout << "\n_____________________________________________" << endl;

	cout << "\nFirst 6 digits with a space:\n";
	myQueue.push(1);
	myQueue.push(2);
	myQueue.push(3);
	myQueue.push(4);
	myQueue.push(5);
	myQueue.push(6);
	myQueue.printQueue();

	cout << "\nDelete one element from queue:\n";
	myQueue.pop();
	myQueue.printQueue();

	cout << "_____________________________________________\n";
	PriorityQueue<int> myPriorQueue;
	cout << "Priority Queue isEmpty? ";
	cout << (myPriorQueue.empty() ? "true" : "false");
	cout << "\n_____________________________________________" << endl;

	myPriorQueue.push(60);
	myPriorQueue.push(30);
	myPriorQueue.push(40);
	myPriorQueue.push(20);
	myPriorQueue.push(50);
	myPriorQueue.push(10);
	cout << "\nFirst 6 digits with a space:\n";

	myPriorQueue.printPriorityQueue();

	cout << "\nDelete one element from priority queue:\n";
	myPriorQueue.pop();
	myPriorQueue.printPriorityQueue();


	_getch();
	return 0;
}