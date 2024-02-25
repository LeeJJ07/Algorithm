#include <iostream>
#include <vector>
using namespace std;

int N;
vector<vector<int>> m;

// 0은 1 반환, 1은 2반환
int check(int y, int x, int n) {

	int start = m[y][x];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (m[i+y][j+x] != start)
				return 0;
		}
	}
	return start + 1;
}
void Re(int y, int x, int n) {
	if (check(y, x, n) == 0) {
		cout << '(';
		Re(y, x, n / 2);
		Re(y, x + n / 2, n / 2);
		Re(y + n / 2, x, n / 2);
		Re(y + n / 2, x + n / 2, n / 2);
		cout << ')';
	}
	else {
		cout << check(y, x, n) - 1;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	m.resize(N);
	for (int i = 0; i < N; i++) {
		string input;
		cin >> input;
		m[i].resize(N);
		for (int j = 0; j < N; j++) {
			m[i][j] = input[j] - '0';
		}
	}
	Re(0, 0, N);
}