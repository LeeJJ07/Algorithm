#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	priority_queue<int, vector<int>, greater<int>>pq;
	int data;
	for (int i = 0; i < N; i++) {
		cin >> data;
		pq.push(data);
	}

	int result = 0;
	while (pq.size() > 1) {
		int num1 = pq.top();
		pq.pop();
		int num2 = pq.top();
		pq.pop();
		result += num1 + num2;
		pq.push(num1 + num2);
	}

	cout << result << "\n";
}