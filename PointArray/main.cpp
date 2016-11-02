#include<iostream>
#include "point.h"
#include "pointarray.h"
#include "vector.h"
#include "vectorarray.h"
#include "polygon.h"
using namespace std;

int main () {
	Point A(2,3);
	Point B(3,1);
	Point C(8,3);
	Point D(2,5);
	Point E(5,2);
	Point F(6,3);
	Point G(7,1);
	Vector AB(A, B);
	Vector CD(C, D);
	Vector EF(E, F);
	Vector CG(C, G);
	Vector BE(B, E);
	Point list[] = {A,B,C};
	Vector vlist[] = {AB, CD, EF};
	PointArray L1(list, 3);
	VectorArray V1(vlist, 3);
	cout << L1.getSize() << endl;
	L1.push_back(D);
	//cout << L1.getSize() << endl;
	L1.printArray();
	L1.remove(2);
	//cout << L1.getSize() << endl; 
	L1.printArray();
	L1.insert(2, G);
	L1.printArray();
	L1.clear();
	L1.printArray();
	V1.printVArray();
	V1.push_back(CG);
	V1.printVArray();
	V1.insert(2,BE);
	V1.printVArray();
	V1.remove(2);
	V1.printVArray();
	cout << "Size: " <<  V1.getSize() << endl;
	V1.clear();
	V1.printVArray();
	
	
	return 0;
}
