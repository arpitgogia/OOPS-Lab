#include <iostream>
using namespace std;
class Coordinate {
	int x, y;	
public:
	static int test;
	Coordinate() {
		cout << "Default Constructor\n";
		x = 0;
		y = 0;
	}
	Coordinate(int x, int y) {
		this -> x = x;
		this -> y = y;
		cout << "Initialised Coordinate object with (" << x << ", " << y << ")\n";
	}
};
int main() {
	Coordinate c1, *c2 = new Coordinate(10, 12);
	cout << "The above objects have been initialised using a dynamic constructor\n";
	return 0;
}