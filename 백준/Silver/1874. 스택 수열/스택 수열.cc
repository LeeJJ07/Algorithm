#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	vector<int> A(N, 0);
	vector<char> result;

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	stack <int> myStack;
	int num = 1;
	bool answer = true;

	for (int i = 0; i < N; i++) {
		int cur = A[i];
		if (cur >= num) {
			while (cur >= num) {
				myStack.push(num++);
				result.push_back('+');
			}
			myStack.pop();
			result.push_back('-');
		}
		else {
			int n = myStack.top();
			myStack.pop();
			if (n > cur) {
				cout << "NO";
				answer = false;
				break;
			}
			else {
				result.push_back('-');
			}
		}
	}
	if (answer) {
		for (int i = 0; i < result.size(); i++) {
			cout << result[i] << "\n";
		}
	}
}