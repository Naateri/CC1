#include<iostream>
#include "point.h"
#include "pointarray.h"

//*point = class var
//points = parameter

using namespace std;

void PointArray::resize(int x){
	Point *a;
	int i;
	a = new Point[x];
	this->_size = x;
	for(i = 0; i< x; i++){
		a[i] = point[i];
	}
	delete [] point;
	point = a;
}

PointArray::PointArray(){
	this->_size = 0;
	this->point = new Point[0];
	//this->point = NULL;
}

PointArray::PointArray(Point points[], int size){
	int i;
	_size = size;
	point = new Point[size];
	for (i = 0; i< size; i++){
		point[i] = points[i];
	}
}
PointArray::PointArray(PointArray &pv){
int i;
_size = pv._size;
for (i = 0; i<pv.getSize(); i++){
	point[i] = pv.point[i];
}
}

PointArray::~PointArray(){
	_size = 0;
	delete [] point;
}
void PointArray::push_back(Point &p){
	/*if(_size < 0){
		;
	}
	
	int i;
	for (i = 0; i <_size; i++)
		 ;
	point[i] =  p;
	_size++;*/
	resize(_size+1);
	point[_size-1] = p;
}
void PointArray::insert(int position, Point &p){
	/*int i, j, k;
	Point lista[_size];
	if (position > _size){
		position = _size;
	}
	for (i = 0; i < position; i++)
		 ;
	if (i < _size){
		j = i;
		for (j, k = 0; j < _size; k++, i++){
			lista[k] = point[j];
		}
		j = i + 1;
		for (j, k = 0; j< _size; i++, k++){
			point[j] = lista[k];
		}
	}
	point[i] = p;
	delete[ ] lista;
	_size++;
	*/
	int i;
	resize(_size+1);
	for (i = 0; i<position; i++)
		 ;
	
}
void PointArray::remove(int position){
	int i, j, k;
	Point lista[_size];
	if (position > _size){
		position = _size;
	}
	for (i = 0; i < position; i++)
		 ;
	if (i < _size){
		j = i;
		for (j, k = 0; j < _size; k++, i++){
			lista[k] = point[j];
			point[j] = lista[k];
		}
		//j = i;
		//for (j, k = 0; j< sizee; i++, k++){
		//	point[j] = lista[k];
		//}
	}
	delete[ ] lista;
	
}
int PointArray::getSize(){
	return _size;
}
void PointArray::clear(){
	int i;
	Point A(0,0);
	for (i = 0; i < _size; i++)
		 ;
	point[i] = A;
	_size = 0;
	delete[] point;
}
void PointArray::printArray(){
	if (_size == 0){
		cout << "There is no list" << endl;
	} else {
		int i;
		//Point P(0,0);
		cout << "Lista: " << endl;
		for (i=0; i<_size; i++){
			Point P(point[i]);
			//cout << "[ ";
			P.printPoint();
			//cout << ", ";
		}
	}
}
