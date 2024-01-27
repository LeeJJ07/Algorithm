#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N;
	vector<int>A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	sort(A.begin(), A.end());

	cin >> M;
	for (int i =0; i <M ; i++) {
		int findNum;
		cin >> findNum;
		int s = 0, e = N-1;
		bool find = false;

		while (s<=e) {
			int midI = (s + e) / 2;
			int midV = A[midI];
			if (midV == findNum) {
				find = true;
				break;
			}
			else if (midV > findNum) {
				e = midI - 1;
			}
			else {
				s = midI + 1;
			}
		}
		if (!find)
			cout << "0" << "\n";
		else
			cout << "1" << "\n";
	}
}