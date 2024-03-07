#include <iostream>
using namespace std;

int n;

bool checkso(int num) {
	for (int i = 2; i * i <= num; i++) {
		if (num % i == 0) return false;
	}
	return true;
}

void DFS(int num, int depth) {
	if (!checkso(num))return;
	if (depth == n - 1) {
		cout << num << '\n';
		return;
	}
	for (int i : {1, 3, 7, 9}) {
		DFS(num * 10 + i, depth + 1);
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	
	for (int i : {2, 3, 5, 7}) {
		DFS(i, 0);
	}
}