#include<iostream>
#define MAXSIZE 100
using namespace std;
template <class T> class Stack{
private:
	T array[MAXSIZE];
	int size;
public:
	Stack(){
		this->size = 0;
	};
	void push(T val);
	void pop();
	T top();
	bool empty(){
		if (size == 0){
			return true;
		} else {
			return false;
		}
	}
	int getSize(){
		return size;
	};
	/*Stack<T> operator+(Stack<T> A, Stack<T> B){
		Stack<T> Temp;
		int i, sizeA, sizeB;
		sizeA = A.getSize();
		sizeB = B.getSize();
		for (i = 0; i<sizeA; i++)
			Temp.push(A.top());
		for (i = 0; i<sizeB; i++)
			Temp.push(B.top());
		return Temp;
	};*/
	
};

/*template <class T> Stack<T>::Stack(){
	int i;
	this->size = 0;
	T *myarray;
	myarray = new T[MAXSIZE];
	for (i = 0; i<MAXSIZE; i++)
		array[i] = myarray[i];
	delete [] myarray;
}*/
template <class T> void Stack<T>::push(T val){
	int i;
	i = 0;
	for (i; i<size; i++)
		;
	array[i] = val;
	size++;
}
template <class T> void Stack<T>::pop(){
	int i;
	//i = 0;
	for (i = 0; i<size; i++)
		;
	array[i] = NULL;
	size--;	
}
template <class T> T Stack<T>::top(){
	int i;
	//i = 0;
	for (i = 0; i<size-1; i++)
		;
	return array[i];
}

template <class T> Stack<T> operator+(Stack<T> A, Stack<T> B){
	Stack<T> Temp, Temp1, Temp2;
	int i, sizeA, sizeB;
	sizeA = A.getSize();
	sizeB = B.getSize();
	for (i = 0; i<sizeA; i++){ //debería tomarme en cuenta pero no pues
		Temp1.push(A.top()); //el operador + te odia Stack<T> A
		A.pop();
	}
	for (i = 0; i<sizeA; i++){
		Temp.push(Temp1.top());
		Temp1.pop();
	}
	for (i = 0; i<sizeB; i++){ //Y te ama a ti Stack<T> B
		Temp2.push(B.top());
		B.pop();
	}
	for (i = 0; i<sizeB; i++){
		Temp.push(Temp2.top());
		Temp2.pop();
	}
	return Temp;
}

int main () {
	int c;
	Stack<int> A;
	//cout << A.top() << endl;
	A.push(6);
	A.push(69);
	A.push(5);
	/*cout << A.top() << endl;
	A.pop();
	A.pop();
	A.pop();
	cout << A.top() << endl;*/
	Stack<int> B;
	B.push(3);
	B.push(24);
	B.push(76);
	B.push(420);
	Stack<int> C;
	C = A+B;
	int i;
	c= C.getSize(); 
	for (i=0; i<c; i++){
		cout << C.top() << endl;
		C.pop();
	}
	return 0;
}
