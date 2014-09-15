// h2o simulation
#include <thread>
using namespace std;

void H(int id) {
	cout<<"H "<<id<<endl;
}
void O(int id) {
	cout<<"O "<<id<<endl;
}
void H2O() {
	thread t1(H, 1);
}