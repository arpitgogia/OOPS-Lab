#include <iostream>
#include <vector>
using namespace std;
class Vector {
	int components;
public:
	vector<int> _vector;
	Vector(int components) {
		this->components = components;
		this->_vector.resize(components);
	}
	void Display() {
		cout << "(";
		for (int i = 0; i < components; i++) {
			cout << _vector[i];
			if (i != components - 1)
				cout << ",";
		}
		cout << ")\n";
	}
	Vector operator + (const Vector &v) {
		if (this->components != v.components) {
			cout << "Cannot add due to difference in dimension\n";
			return *new Vector(0);
		}
		Vector* added = new Vector(this->components);
		for (int i = 0; i < this->components; i++) 
			added->_vector[i] = (this->_vector[i] + v._vector[i]);
		return *added;
	}
};
int main() {
	ios_base::sync_with_stdio(0);
	int components;
	cout << "Enter number of components in vector A : ";
	cin >> components;
	Vector* a = new Vector(components);
	cout << "Enter the components\n";
	for (int i = 0; i < components; i++)
		cin >> a->_vector[i];
	cout << "Enter number of components in vector B : ";
	cin >> components;
	Vector* b = new Vector(components);
	cout << "Enter the components\n";
	for (int i = 0; i < components; i++)
		cin >> b->_vector[i]; 
	Vector c = *a + *b;
	if(c._vector.size() != 0)
		cout << "Addition Vector : ", c.Display();
	system("pause");
	return 0;
}