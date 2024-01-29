#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N, M;
	cin >> N >> M;

	vector<int> A(M + 1);
	for (int i = 2; i <= M; i++) {
		A[i] = i;
	}
	for (int i = 2; i <= sqrt(M); i++) {
		if (A[i] == 0)
			continue;
		for (int j = i + i; j <= M; j += i)
			A[j] = 0;
	}
	
	for (int i = N; i <= M; i++) {
		if (A[i] != 0)
			cout << A[i] << "\n";
	}
}