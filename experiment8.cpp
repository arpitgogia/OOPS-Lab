#include <iostream>
#include <exception>
using namespace std;
struct ArrayIndexOutOfBoundsException : public exception {
	const char* what () const throw () {
		return "Invalid Array Index";
	}		
};
int main() {
	int n;
	cout << "Enter the size of the array to create : \n";
	cin >> n;
	int array[n];
	for(int i = 0 ; i < n ; i++)
		array[i] = (i + 1);
	cout << "Array initialised with 1 - " << n << "\n";
	try {
		cout << "Enter an index : ";
		int index;
		cin >> index;
		if(index < 0 || index >= n)
			throw ArrayIndexOutOfBoundsException();
		cout << "Element at " << index << " : " << array[index] << "\n";
	} catch (ArrayIndexOutOfBoundsException& e) {
		cout << e.what() << "\n";
	}
}