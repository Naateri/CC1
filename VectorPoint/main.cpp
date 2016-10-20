#include<iostream>
#include "point.h"
#include "vector.h"
using namespace std;

int main () {
	int x, y;
	Point P(5, 3);
	P.printPoint();
	Point Q(P);
	Q.modifyPoint(2,5);
	Q.printPoint();
	Q.setx(3);
	Q.sety(2);
	cout << Q.getx() << " " << Q.gety() << endl;
	Vector Vec(P, Q);
	Vec.printVector();
	return 0;
}

