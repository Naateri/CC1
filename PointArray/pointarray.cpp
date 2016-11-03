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

PointArray::PointArray(){ //FIX
	this->_size = 0;
	Point *a;
	a = new Point[0];
	this->point = a;
	//this->point = NULL;
}

PointArray::PointArray(Point points[], int size){
	int i;
	this->_size = size;
	this->point = new Point[size];
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
	this->_size = 0;
	delete [] point;
}
void PointArray::push_back(Point &p){
	resize(_size+1);
	point[_size-1] = p;
}
void PointArray::insert(int position, Point &p){
	int i;
	Point *a;
	resize(_size+1);
	a = new Point[_size];
	if (position>_size)
		position = _size;
	for (i = 0; i<position; i++)
		a[i] = point[i];
	//i++;
	a[position] = p;
	i++;
	for (i; i<_size; i++){
		a[i] = point[i-1];
	}
	delete [] point;
	point = a;
	
}
void PointArray::remove(int position){
	Point *a;
	int i;
	//resize(_size-1);
	a = new Point[_size-1];
	for (i = 0; i<position; i++)
		a[i] = point[i];
	for (i+1; i<_size; i++)
		a[i-1] = point[i];
	delete [] point;
	point = a;
	resize(_size-1);
	
}
int PointArray::getSize(){
	return _size;
}
void PointArray::clear(){
	resize(0);
	delete [] point;
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
void PointArray::getList(Point list[]){
	int i;
	for (i = 0; i<_size; i++){
		list[i] = point[i];
	}
}

Point* PointArray::get(int position){
	int i = 0;
	for (i; i<position; i++, point++){
		;
	}
	return point;
}
void PointArray::modifyList(Point points[]){ //modify current list with one that you have that is the same size of current list
	int i;
	Point *a;
	a = new Point[_size];
	for (i = 0; i<_size; i++){
		a[i] = point[i];
	}
	delete [] point;
	point = a;
}

