//remove trabaja con índices empezando de 1, no de 0. Arreglar si posible.

#include <iostream>
#include "point.h"
#include "vector.h"
#include "vectorarray.h"

using namespace std; 

void VectorArray::resize(int x){
	Vector *a;
	int i;
	a = new Vector[x];
	this->_size = x;
	for (i = 0; i < x; i++){
		a[i] = vector[i];
	}
	delete [] vector;
	vector = a;
}

VectorArray::VectorArray(){
	this->_size = 0;
	this->vector = new Vector[0];
}
VectorArray::VectorArray(Vector vectors[], int size){
	int i;
	this->_size = size;
	this -> vector = new Vector[size];
	for (i = 0; i<size; i++){
		vector[i] = vectors[i];
	}
	
}
VectorArray::VectorArray(VectorArray &pv){
	int i;
	_size = pv._size;
	for (i = 0; i < pv.getSize(); i++){
		vector[i] = pv.vector[i];
	}
}
VectorArray::~VectorArray(){
	this->_size = 0;
	delete[] vector;
}
void VectorArray::push_back(Vector &p){
	resize(_size+1);
	vector[_size-1] = p;
}
void VectorArray::insert(int position, Vector &p){
	int i;
	Vector *a;
	resize(_size+1);
	a = new Vector[_size];
	if (position > _size){
		position = _size;
	}
	for (i = 0; i<position; i++){
		a[i] = vector[i];
	}
	a[position] = p;
	i++;
	for (i; i < _size; i++){
		a[i] = vector[i-1];
	}
	delete [] vector;
	vector = a;
}
void VectorArray::remove(int position){
	int i;
	Vector *a;
	a = new Vector[_size-1];
	for (i = 0; i< position; i++){
		a[i] = vector[i];
	}
	for (i+1; i<_size; i++){
		a[i-1] = vector[i];
	}
	delete [] vector;
	vector = a;
	resize(_size-1);
	
}
int VectorArray::getSize(){
	return _size;
}
void VectorArray::clear(){
	resize(0);
	delete [] vector;
}
void VectorArray::printVArray(){
	if (_size == 0){
		cout << "There is no list" << endl;
	} else {
		int i;
		cout << "Lista: " << endl;
		cout << "[" << '\n';
		for(i=0; i<_size; i++){
			vector[i].printVector();
		}
		cout << "]" << '\n';
	}
}
