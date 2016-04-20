/*
	In this program, static and dynamic polymorphism have been demonstrated.
	The area() function is inherited in both Rectangle and Triangle classes however, the compiler decides beforehand that the 
	area() function of the base class will be called. This is not the case with the perimeter() function which uses the virtual
	keyword that tells the compiler to decide which function is called at runtime. This is an example of dynamic polymorphism.
*/
#include <iostream>
#include <cmath>
using namespace std;
class Shape {
protected:
	int width, height;
public:
	Shape(int a = 0 , int b = 0) {
		width = a;
		height = b;
	}
	void area() {
		cout << "Parent class Area()\n";
	}
	virtual void perimeter() {
		cout << "Parent class Perimeter()\n";
	}
};
class Rectangle : public Shape {
public:
	Rectangle(int a = 0, int b = 0) : Shape(a, b) {}
	void area() {
		cout << "Rectangle's area : " << (width * height) << "\n";
	}
	void perimeter() {
		cout << "Rectangle's perimeter : " << (2 * (width + height)) << "\n";
	}
};
class Triangle : public Shape {
public:
	Triangle(int a = 0, int b = 0) : Shape(a, b) {}
	void area() {
		cout << "Triangle's area : " << (width * height / 2) << "\n";
	}
	void perimeter() {
		cout << "Triangle's perimeter : " << (width + height + (int)sqrt(pow(width, 2) + pow(height, 2))); 
	}
};
int main() {
	Shape *shape;
	Rectangle r(10, 7);
	Triangle t(3, 4);
	shape = &r;
	shape -> area();
	shape -> perimeter();
	shape = &t;
	shape -> area();
	shape -> perimeter();
	return 0;
}