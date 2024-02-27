#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> m;
int result[2];

int check(int sy, int sx, int n) {
	int res = m[sy][sx];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (res != m[sy + i][sx + j]) return -1;
		}
	}
	return res;
}

void merge(int y, int x, int n) {
	int res = check(y, x, n);
	if (res == -1) {
		merge(y, x, n / 2);
		merge(y, x + n / 2, n / 2);
		merge(y + n / 2, x, n / 2);
		merge(y + n / 2, x + n / 2, n / 2);
	}
	else {
		result[res]++;
		return;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N;
	cin >> N;
	m.resize(N);
	for (int i = 0; i < N; i++) {
		m[i].resize(N);
		for (int j = 0; j < N; j++) {
			cin >> m[i][j];
		}
	}
	merge(0, 0, N);

	for (int i : result) cout << i << '\n';
}