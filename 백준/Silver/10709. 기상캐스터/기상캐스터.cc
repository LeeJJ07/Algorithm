#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	vector<vector<int>> m(N);
	for (int i = 0; i < N; i++) {
		m[i].resize(M, -1);
		string str;
		cin >> str;
		int clo = -1;
		for (int j = 0; j < M; j++) {
			if (str[j] == 'c') {
				clo = 0;
			}
			if (clo != -1) {
				m[i][j] = clo++;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << m[i][j] << ' ';
		}
		cout << '\n';
	}
}