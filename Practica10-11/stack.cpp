#include<iostream>
#define MAXSIZE 100
using namespace std;
template <typename T>

class Stack{
public:
	T array[MAXSIZE];
	int size;
	int cur_size;
private:
	/*Stack<T>(){
		this->cur_size = 0;
		this->size = 100;
	}
	Stack<T>(int siz){
		if (siz > 100){
			siz = 100;
		}
		this -> size = siz;
		this->cur_size = 0;
	};*/
	void push(T val){
		int i;
		i = 0;
		for (i; i<cur_size; i++)
			 ;
		this->array[i] = val;
		this->cur_size++;
	};
	void pop(){	
	int i;
	i = 0;
	for (i; i<cur_size; i++)
		 ;
	array[i] = NULL;
	cur_size--;
	};
	T top(){
		int i;
		i = 0;
		for (i; i<cur_size; i++)
			 ;
		return array[i];
	};
	bool empty(){
		if (size == 0){
			return true;
		} else {
			return false;
		}
	}
	int getSize(){
		return cur_size;
	};
	
};

Stack<T> operator+(Stack<T> A, Stack<T> B){
	int size1 = A.getSize();
	int size2 = B.getSize();
	int i = 0;
	for (i; i<size1; i++){
		;
	}
	//terminar suma
}
int main () {
	Stack<int> A;
	A.push(5);
	A.top();
	return 0;
}
