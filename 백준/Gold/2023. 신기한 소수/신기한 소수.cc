#include <iostream>
#include <cmath>
using namespace std;

void DFS(int number, int n);
bool isPrime(int num);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	for (int i = 2; i < 10; i++) {
		if (i == 2 || i == 3 || i == 5 || i == 7) {
			DFS(i, N - 1);
		}
	}

}
void DFS(int number, int n) {
	if (n == 0) {
		if (isPrime(number)) {
			cout << number << "\n";
		}
		return;
	}
	for (int i = 1; i < 10; i++) {
		if (i % 2 == 0)
			continue;
		if (isPrime(number * 10 + i)) {
			DFS(number * 10 + i, n - 1);
		}
	}
}
bool isPrime(int num) {
	for (int i = 2; i <= (int)sqrt(num); i++) {
		if (num % i == 0)
			return false;
	}
	return true;
}