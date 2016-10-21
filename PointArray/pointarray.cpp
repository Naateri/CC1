#include<iostream>
#include "point.h"
#include "pointarray.h"

using namespace std;
/*Element::Element(){
	 Element.next = NULL;
 }
Element::Element(Point n){
	 Element.P = n;
	 Element.next = NULL;
 }
Point Element::getVal(){
	 return Element.P;
 }
*/
PointArray::PointArray(Point points[], int size){
	int i;
	sizee = size;
	point = new Point[size];
	for (i = 0; i< size; i++){
		point[i] = points[i];
	}
}
/*PointArray::PointArray(PointArray &pv){
	pv.sizee = sizee;
	pv.point = &point;
}
*/
void PointArray::push_back(Point &p){
	int i;
	for (i = 0; i <sizee; i++)
		;
	point[i] =  p;
	sizee ++;
}
void PointArray::insert(int position, Point &p){
	int i, j, k;
	Point lista[sizee];
	if (position > sizee){
		position = sizee;
	}
	for (i = 0; i < position; i++)
		;
	if (i < sizee){
		j = i;
		for (j, k = 0; j < sizee; k++, i++){
			lista[k] = point[j];
		}
		j = i + 1;
		for (j, k = 0; j< sizee; i++, k++){
			point[j] = lista[k];
		}
	}
	point[i] = p;
	delete[ ] lista;
	sizee++;
}
void PointArray::remove(int position){
	int i, j, k;
	Point lista[sizee];
	if (position > sizee){
		position = sizee;
	}
	for (i = 0; i < position; i++)
		;
	if (i < sizee){
		j = i;
		for (j, k = 0; j < sizee; k++, i++){
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
	return sizee;
}
void PointArray::clear(){
	int i;
	Point A(0,0);
	for (i = 0; i < sizee; i++)
		;
	point[i] = A;
	sizee = 0;
	delete[] point;
}
