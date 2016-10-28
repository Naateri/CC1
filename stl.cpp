#include <iostream>
#include <stack>
#include <queue>
#include <list>
#include <algorithm>
using namespace std;

void printList( list<int> h)
{
	for(list<int>::iterator i=h.begin(); i!=h.end(); i++)
		cout << *i << " ";
	cout << endl;
}

int main() {
	cout << "LIST: " << endl;
	list<int> l, l1;
	for (int i = 10; i > 0; i--)
		l.push_back(i);
	l.push_front(5);
	printList(l);
	cout << "front " << l.front() << endl; 
	cout << "back " << l.back() << endl;
	l.pop_back();
	l.pop_front();
	l.sort();
	printList(l);
	l.front() = 4;
	l.back() = 9;
	l.reverse();
	cout << "Reverse: ";
	printList(l);
	l1 = l;
	l.clear();
	printList(l1);
	cout << "1 if list is empty: " << l.empty() << endl; //1 = true
	cout << "size of copied list: " << l1.size() << endl;
	////////////////////////////////////////////////////////////////////////////
	cout << endl;
	cout << "Stack:" << endl;
	stack<int> myStack;
	for (int i = 1; i<=5; i++) //No se puede iterar un stack o un queue
		myStack.push(i);
	cout << "Size: " << myStack.size() << endl;
	while (!myStack.empty()){
		cout << myStack.top() << endl;
		myStack.pop();
	}
	cout << "1 if stack is empty: " << myStack.empty() << endl; //1
	//////////////////////////////////////////////////////////////////////////////
	cout << endl;
	cout << "Queue: " << endl;
	queue<int> myQueue;
	for (int i = 3; i<=9; i++)
		myQueue.push(i);
	cout << "Size: " << myQueue.size() << endl;
	while (!myQueue.empty()){
		cout << myQueue.front() << " ";
		myQueue.pop();
	}
	cout << '\n';
	cout << "1 if queue is empty: " << myQueue.empty() << endl; //1
	myQueue.push(6);
	myQueue.push(9);
	cout << "My Queue last element: " << myQueue.back() << endl; //9
	return 0;
}
