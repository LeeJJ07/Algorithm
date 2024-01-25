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
	bool th = true;
	for (int i = 1; i <= N; i++) {
		result.push(i);
	}
	while (result.size() > 1) {
		if (th) {
			result.pop();
			th = false;
		}
		else {
			int num = result.front();
			result.pop();
			result.push(num);
			th = true;
		}
	}
	cout << result.front() << "\n";
}