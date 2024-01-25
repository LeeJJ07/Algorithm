#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	queue <int> result;
	for (int i = 1; i <= N; i++) {
		result.push(i);
	}
	while (result.size() > 1) {
		result.pop();
		result.push(result.front());
		result.pop();
	}
	cout << result.front();
}