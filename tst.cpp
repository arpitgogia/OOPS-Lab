#include <iostream>
using namespace std;
class Time {
	int hrs, mins;
	public :
		void setTime(int hrs, int mins) {
			this -> hrs = hrs;
			this -> mins = mins;
		}
		void getTime() {
			cout << "Hours : " << this -> hrs << "\n";
			cout << "Minutes : " << this -> mins << "\n";
		}
		friend Time add(Time time1, Time time2);
};
Time add(Time time1, Time time2) {
	Time temp;
	temp.hrs = time1.hrs + time2.hrs;
	temp.mins = time1.mins + time2.mins;
	temp.hrs += (temp.mins / 60);
	temp.mins %= 60;
	return temp;
}
int main() {
	Time t1, t2, t3;
	t1.setTime(1, 20);
	t2.setTime(2, 30);
	t3 = add(t1, t2);
	t3.getTime();
}
