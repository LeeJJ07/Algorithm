#include <iostream>
using namespace std;

static int D[30][30];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < 30; i++) {
		D[i][i] = 1;
		D[i][0] = 1;
		D[0][i] = i;
	}
	for (int i = 2; i < 30; i++) {
		for (int j = 1; j < i; j++) {
			D[i][j] = D[i - 1][j] + D[i - 1][j - 1];
		}
	}

	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int N, M;
		cin >> N >> M;
		cout << D[M][N] << "\n";
	}
}