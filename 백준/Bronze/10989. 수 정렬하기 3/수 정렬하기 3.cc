#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector <int> A(10001, 0);
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		A[num]++;
	}

	for (int i = 1; i <= 10000; i++) {
		if (A[i] == 0)
			continue;
		for (int j = 0; j < A[i]; j++) {
			cout << i << "\n";
		}
	}
}