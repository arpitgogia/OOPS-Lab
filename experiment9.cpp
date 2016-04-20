#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Student {
	string name;
	int semester;
	int marks[6], total = 0;
public:
	void read() {
		cout << "Enter Name, semester and Marks in 6 subsjects\n";
		cin >> name;
		cin >> semester;
		for(int i = 0 ; i < 6 ; i++)
			cin >> marks[i], total += marks[i];
	}
	void write(fstream fs) {
		fs << "Name : " << name << "\n";
		fs << "Semester : " << semester << "\n";
		fs << "Marks : (";	
		for(int i = 0 ; i < 6 ; i++) { 
			fs << marks[i];
			if(i == 5) 
				fs << ")";
			else 
				fs << ",";
		}
		fs << "\n";
		fs << "Total : " << total;
	}
};
int main() {
	fstream fs;
	fs.open("Student.dat", ios::binary | fstream::app);
	int number;
	cout << "Enter the number of students to enter";
	cin >> number;
	while(number--) {
		Student student;
		student.read();
		student.write(fs);
	}
	return 0;
}