#include<iostream>
#include "point.h"
#include "vector.h"
using namespace std;
Vector::Vector(){
	Start.setx(0); End.setx(0);
	Start.sety(0); End.sety(0);
}
Vector::Vector(Point Start1, Point End1){
	Start = Start1;
	End = End1;
}
Vector::Vector(Vector &vec){
	Start = vec.Start;
	End = vec.End;
}
void Vector::printVector(){
	cout << "Start: ";
	Start.printPoint();
	cout << "End: ";
	End.printPoint();
}
void modifyVectorStart(int nx, int ny){
	;
}
void modifyVectorEnd(int nx, int ny){
	;
}
double distancia(Point Start1, Point End1){
	double x, y, x1, y1, x2, y2;
}
