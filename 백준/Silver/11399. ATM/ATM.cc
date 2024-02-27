#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N;
	cin >> N;
	vector<int> A(N+1);
	int sum = 0;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}
	sort(A.begin(), A.end());
	for (int i = 1; i <= N; i++) {
		A[i] += A[i - 1];
		sum += A[i];
	}
	cout << sum << '\n';
}