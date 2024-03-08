#include <iostream>
#include <vector>
using namespace std;

int N;
vector<vector<char>> A;
int result = 100000;

int chk(int i, vector<vector<char>> a) {
	for (int j = 0; j < N; j++) {
		if (i & (1 << j)) {
			for (int k = 0; k < N; k++) {
				if (a[j][k] == 'T') a[j][k] = 'K';
				else a[j][k] = 'T';
			}
		}
	}
	int res = 0;
	for (int j = 0; j < N; j++) {
		int c1 = 0, c2 = 0;
		for (int k = 0; k < N; k++) {
			if (a[k][j] == 'T') c1++;
			else c2++;
		}
		res += min(c1, c2);
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> N;
	A.resize(N);
	for (int i = 0; i < N; i++) {
		A[i].resize(N);
		for (int j = 0; j < N; j++) {
			cin >> A[i][j];
		}
	}
	for (int i = 0; i < (1 << N); i++) {
		result = min(result, chk(i, A));
	}
	cout << result << '\n';
}