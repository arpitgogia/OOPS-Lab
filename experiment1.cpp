#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
class Employee {
		int employee_number;
		string employee_name;
		float employee_basic;
	public :
		Employee(int number, string name, float basic) {
			this -> employee_number = number;
			this -> employee_name = name;
			this -> employee_basic = basic;
		}
		string getName() {
			return this -> employee_name;
		}
		int getNumber() {
			return this -> employee_number;
		}
		float getBasic() {
			return this -> employee_basic;
		}
		class Gross {
			public :
				float calculateDA(float basic) {
					return (0.5 * basic);
				}
				float calculateHRA(float basic) {
					return (0.3 * basic);
				}
				float getTA() {
					return 800.0;
				}
		};
		class Product {
			public :
				float calculatePF(float basic) {
					return (0.05 * basic);
				}
				float calculateIT(float gross) {
					return (0.3 * gross);
				}
		};
		void calculateSalary() {
			Gross gross;
			Product product;
			float basic = this -> getBasic();
			float total = basic;
			total += gross.calculateDA(basic) + gross.calculateHRA(basic) + gross.getTA();
			total -= product.calculatePF(basic);
			if(total >= 100000)
				total -= product.calculateIT(total);
			cout << "Total Salary : " << total << "\n";
		}
};
int main() {
	ios_base::sync_with_stdio(0);
	string name;
	int number;
	float basic;
	cout << "Enter Employee Number : " ;
	cin >> number;
	cout << "Enter Employee Name : " ;
	cin >> name;
	cout << "Enter Basic : " ;
	cin >> basic;
	Employee employee(number, name, basic);
	employee.calculateSalary();
}
