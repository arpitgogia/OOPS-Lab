#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
using namespace std;
class Student {
	string name;
	int semester;
	int marks[6], total;
	void write_student(ofstream &fs) {
		fs << "Name : " << name << "\n";
		fs << "Semester : " << semester << "\n";
		fs << "Marks : (";
		for (int i = 0; i < 6; i++) {
			fs << marks[i];
			if (i == 5)
				fs << ")";
			else
				fs << ",";
		}
		fs << "\n";
		fs << "Total : " << total << "\n";
	}
public:
	void read() {
		cout << "Enter Name, semester and Marks in 6 subsjects\n";
		cin >> name;
		cin >> semester;
		total = 0;
		for(int i = 0 ; i < 6 ; i++)
			cin >> marks[i], total += marks[i];
	}
	void write() {
		ofstream fs;
		fs.open("Student.dat", ios::binary | ofstream::app);
		write_student(fs);
		fs.close();
		int min_marks = *min_element(marks, marks + 6);
		if (min_marks >= 40) {
			ofstream pass_fs;
			pass_fs.open("Passed.dat", ios::binary | ofstream::app);
			write_student(pass_fs);
			pass_fs.close();
		}
		else {
			ofstream fail_fs;
			fail_fs.open("Failed.dat", ios::binary | ofstream::app);
			write_student(fail_fs);
			fail_fs.close();
		}
	}
};
int main() {
	int number;
	cout << "Enter the number of students to enter : ";
	cin >> number;
	while(number--) {
		Student student;
		student.read();
		student.write();
	}
	return 0;
}