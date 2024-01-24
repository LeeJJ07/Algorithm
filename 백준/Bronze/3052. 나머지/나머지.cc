#include <iostream>
#include <set>

using namespace std;

int main(void) {

	set<int> p;

	for (int i = 0; i < 10; i++) {
		int input;
		cin >> input;
		p.insert(input%42);
	}
	cout << p.size();

	return 0;
}