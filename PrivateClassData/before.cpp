#include <iostream>
#define PI 3.1416
struct Point{
	int x;
	int y;
};
class Circle{
private:
	double radius;
	Point origin;
	char* color;
public:
	Circle (double r, Point p, char* c){
		this->radius = r; this->origin = p; this->color = c;
	}
	double getDiameter(){return 2*radius;}
	double getCircumference(){return 2*PI*radius;}
};


int main() {
	Point org; org.x = 0; org.y = 0;
	Circle myCircle(4.0, org, "blue");
	std::cout << "Diameter: " << myCircle.getDiameter() << std::endl;
	std::cout << "Circumference: " << myCircle.getCircumference() << std::endl;
	return 0;
}
