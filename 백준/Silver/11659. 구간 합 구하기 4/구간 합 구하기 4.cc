#include <iostream>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	int arr[100001] = {};
	for (int i = 1; i <= N; i++) {
		int num;
		cin >> num;
		arr[i] = arr[i - 1] + num;
	}
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;

		cout << arr[b] - arr[a - 1] << "\n";
	}
}