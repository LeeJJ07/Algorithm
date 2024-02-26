#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int A, B, C;
	cin >> A >> B >> C;
	int num = A * B * C;
	int count[10] = {};
	while (num > 0) {
		count[num % 10]++;
		num /= 10;
	}
	for (int i = 0; i < 10; i++) cout << count[i] << '\n';
}