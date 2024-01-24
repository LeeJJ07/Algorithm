#include <iostream>
#include <vector>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long result = 0;
	int N, M;
	cin >> N >> M;
	
	vector <long>arr(N + 1, 0);
	vector <long>reminder(M, 0);
	for (int i = 1; i <= N; i++) {
		long num;
		cin >> num;
		arr[i] = arr[i - 1] + num;
	}
	for (int i = 1; i <= N; i++) {
		arr[i] %= M;
		if (arr[i] == 0)
			result++;
		reminder[arr[i]]++;
	}
	for (int i = 0; i < M; i++) {
		if (reminder[i] > 1) {
			result += (reminder[i] * (reminder[i] - 1)/2);
		}
	}
	cout << result <<"\n";
	return 0;
}