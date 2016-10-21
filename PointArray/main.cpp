#include<iostream>
#include "point.h"
#include "pointarray.h"
using namespace std;

int main () {
	Point A(2,3);
	Point B(3,1);
	Point C(8,3);
	Point D(2,5);
	Point E(5,2);
	Point F(6,3);
	Point G(7,1);
	Point list[] = {A,B,C};
	PointArray L1(list, 3);
	cout << L1.getSize() << endl;
	L1.push_back(D);
	cout << L1.getSize() << endl;
	L1.insert(2, E); // FIX
	//cout << L1.getSize() << endl; 
	return 0;
}

