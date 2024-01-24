#include <iostream>

using namespace std;

int main(void) {

	int check[30] = { 0 };
	for (int i = 0; i < 28; i++) {
		int input;
		cin >> input;
		check[input - 1]++;
	}
	for (int i = 0; i < 30; i++) {
		if (check[i] == 0)
			cout << i + 1<<endl;
	}

	return 0;
}