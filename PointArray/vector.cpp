#include<iostream>
#include<math.h>
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
void Vector::modifyVectorStart(int nx, int ny){
	Start.setx(Start.getx() + nx);
	Start.sety(Start.gety()+ny);
}
void Vector::modifyVectorEnd(int nx, int ny){
	End.setx(End.getx() + nx);
	End.sety(End.gety()+ny);
}
double Vector::distancia(){
	double x, y, dist;
	x = Start.getx() - End.getx();
	y = Start.gety() - End.gety();
	dist = sqrt((x*x)+(y*y));
	return dist;	
}
void Vector::setStart(int nx, int ny){
	Start.setx(nx);
	Start.sety(ny);
}
void Vector::setEnd(int nx, int ny){
	End.setx(nx);
	End.sety(ny);
}
int Vector::getStartX(){
	return Start.getx();
}
int Vector::getStartY(){
	return Start.gety();
}
int Vector::getEndX(){
	return End.getx();
}
int Vector::getEndY(){
	return End.gety();
}
void Vector::modifyVector(Point Start1, Point End1){
	Start.setx(Start.getx() + Start1.getx());
	Start.sety(Start.gety() + Start1.gety());
	End.setx(End.getx() + End1.getx());
	End.sety(End.gety() + End1.gety());
}
