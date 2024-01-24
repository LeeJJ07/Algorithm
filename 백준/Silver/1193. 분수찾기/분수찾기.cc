#include <iostream>

using namespace std;

int main(void) {

	int N;
	cin >> N;

	int count = 1;
	while (1) {
		if (N - count <= 0)
			break;
		N -= count;
		count++;
	}
	int a, b;
	if (count % 2 == 0) {
		a = count; b = 1;
		for (int i = 0; i < N - 1; i++) {
			a--;
			b++;
		}
		
	}
	else {
		a = 1; b = count;
		for (int i = 0; i < N - 1; i++) {
			a++;
			b--;
		}
	}
	cout << b << "/" << a;

	return 0;
}