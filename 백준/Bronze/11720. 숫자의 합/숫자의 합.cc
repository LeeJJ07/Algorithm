#include <iostream>

using namespace std;

int main() {

	int num;
	cin >> num;

	string numbers;
	cin >> numbers;

	int sum = 0;

	for (int i = 0; i < numbers.length(); i++) {
		sum += numbers[i] - '0';
	}
	cout << sum << endl;

	return 0;
}