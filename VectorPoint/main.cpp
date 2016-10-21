#include<iostream>
#include "point.h"
#include "vector.h"
using namespace std;

int main () {
	int x, y;
	Point P(5, 3), J(3,2); //Definiendo Puntos P y J
	cout << "Punto P: " << endl;
	P.printPoint();
	Point Q(P); //Copiando P a Q
	Q.modifyPoint(2,5); //Sumando 2 y 5 a las coordenadas X y Y de Q
	Q.printPoint();
	Q.setx(3); //Coord x = 3
	Q.sety(2); //Coord y = 2
	cout << Q.getx() << " " << Q.gety() << endl;
	Vector Vec(P, Q); //Vector que va de P a Q
	cout << "Vector Vec: " << endl;
	Vec.printVector();
	cout << "Distancia: " << Vec.distancia() << endl;
	Vector Vec1(Vec); //Copiando Vec a Vec1
	cout << "Copiando Vec a Vec 1: " << endl;
	Vec1.printVector();
	Vec1.modifyVector(J, J); //Sumando (3,2) a cada punto del vector
	cout << Vec1.getStartX() << "," << Vec1.getStartY() << " ; " << Vec1.getEndX() << "," << Vec1.getEndY() << endl;
	Vec1.setStart(6, 9); //Haciendo que el primer punto sea (6,9)
	Vec1.setEnd(7,12); //Haciendo que el segundo punto sea (7,12)
	Vec1.printVector();
	Vec1.modifyVectorStart(1,1); //Sumando (1,1) al primer
	Vec1.modifyVectorEnd(1,1); //Y al segundo punto
	Vec1.printVector();
	return 0;
}
