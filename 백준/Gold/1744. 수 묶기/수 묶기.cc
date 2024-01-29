#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	priority_queue<int> plus;
	priority_queue<int, vector<int>, greater<int>> minus;
	int one = 0;
	int zero = 0;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		if (num == 0) {
			zero++;
		}
		else if (num == 1) {
			one++;
		}
		else if (num < 0) {
			minus.push(num);
		}
		else {
			plus.push(num);
		}
	}
	int result = one;
	while (plus.size() > 1) {
		int num1 = plus.top(); plus.pop();
		int num2 = plus.top(); plus.pop();
		result += num1 * num2;
	}
	if (!plus.empty()) {
		result += plus.top();
	}
	while (minus.size() > 1) {
		int num1 = minus.top(); minus.pop();
		int num2 = minus.top(); minus.pop();
		result += num1 * num2;
	}
	if (!minus.empty() && zero == 0) {
		result += minus.top();
	}

	cout << result << "\n";
}