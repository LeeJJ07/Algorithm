#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;
	vector<pair<int,int>> A(N);
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		A[i].first = num;
		A[i].second = i;
	}
	sort(A.begin(), A.end());
	int index = 0;
	vector<int> check(N);
	for (int i = 1; i < N; i++) {
		if (A[i].first != A[i - 1].first) {
			index++;
		}
		check[i] = index;
	}

	vector<int> result(N);
	for (int i = 0; i < N; i++) {
		result[A[i].second] = check[i];
	}

	for (int i = 0; i < N; i++) {
		cout << result[i] << " ";
	}
}