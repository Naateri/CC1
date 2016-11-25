#include <iostream>
#define PI 3.1416
struct Point{
	int x;
	int y;
};
class CircleData{
private:
	double radius;
	Point origin;
	char* color;
public:
	CircleData(double r, Point p, char* c){
		this->radius = r; this->origin = p; this->color = c;
	}
	double getRadius(){return radius;}
	Point getOrigin(){return origin;}
	char* getColor(){return color;}
};
class Circle{
private:
	CircleData* myCircleData;
public:
	Circle(double r, Point p, char* c){
		myCircleData = new CircleData(r, p, c);
	}
	double getDiameter(){return myCircleData->getRadius()*2;}
	double getCircumference(){return 2*PI*myCircleData->getRadius();}
	
};

int main() {
	Point org; org.x = 0; org.y = 0;
	Circle myCircle(4.0, org, "blue");
	std::cout << "Diameter: " << myCircle.getDiameter() << std::endl;
	std::cout << "Circumference: " << myCircle.getCircumference() << std::endl;
	return 0;
}
