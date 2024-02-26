#include <iostream>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int result = 0;
	for (int i = 0; i < 5; i++) {
		int num;
		cin >> num;
		result += pow(num, 2);
	}
	cout << result % 10 << '\n';
}