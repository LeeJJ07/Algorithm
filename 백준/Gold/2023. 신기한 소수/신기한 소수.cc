#include <iostream>
#include <vector>
using namespace std;

void DFS(int number, int n);

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
		cout << number << "\n";
		return;
	}
	for (int i = 1; i < 10; i++) {
		if (i == 2 || i == 4 || i == 6 || i == 8)
			continue;
		int num = number * 10 + i;
		int count = 0;
		for (int j = 3; j < num; j++) {
			if (num % j == 0) {
				count++;
				break;
			}
		}
		if (count == 0) {
			DFS(num, n - 1);
		}
	}
}