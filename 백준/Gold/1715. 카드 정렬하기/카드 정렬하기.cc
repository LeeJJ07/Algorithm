#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;
	priority_queue <int, vector<int>, greater<int>> q;
	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		q.push(num);
	}
	int result = 0;
	while (q.size() > 1) {
		int num1 = q.top();
		q.pop();
		int num2 = q.top();
		q.pop();
		result += num1 + num2;
		q.push(num1 + num2);
	}
	cout << result << '\n';
}