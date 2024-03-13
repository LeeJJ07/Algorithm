#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	priority_queue<int> q1;
	priority_queue<int, vector<int>, greater<int>> q2;
	int n; cin >> n;
	int result = 0;
	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		if (num <= 0)q2.push(num);
		else if (num == 1) result += num;
		else q1.push(num);
	}
	while (q1.size() > 1) {
		int num1 = q1.top(); q1.pop();
		int num2 = q1.top(); q1.pop();
		result += num1 * num2;
	}
	if(q1.size()) result += q1.top();
	while (q2.size() > 1) {
		int num1 = q2.top(); q2.pop();
		int num2 = q2.top(); q2.pop();
		result += num1 * num2;
	}
	if (q2.size()) result += q2.top();
	
	cout << result << '\n';
}