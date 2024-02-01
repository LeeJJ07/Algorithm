#include <iostream>
using namespace std;

static int D[15][15];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i <= 14; i++) {
		D[0][i] = i;
		D[i][1] = 1;
		D[i][0] = 0;
	}

	for (int i = 1; i <= 14; i++) {
		for (int j = 2; j <= 14; j++) {
			D[i][j] = D[i - 1][j] + D[i][j - 1];
		}
	}

	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int k, n;
		cin >> k >> n;
		cout << D[k][n] << "\n";
	}
}