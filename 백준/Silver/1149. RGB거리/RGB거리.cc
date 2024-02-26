#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	vector<vector<int>> A(N);
	for (int i = 0; i < N; i++) {
		A[i].resize(3);
		for (int j = 0; j < 3; j++) {
			cin >> A[i][j];
		}
		if (i == 0) continue;
		A[i][0] += min(A[i - 1][1], A[i - 1][2]);
		A[i][1] += min(A[i - 1][0], A[i - 1][2]);
		A[i][2] += min(A[i - 1][1], A[i - 1][0]);
	}
	cout << min(min(A[N - 1][0], A[N - 1][1]), A[N - 1][2]) << '\n';
}