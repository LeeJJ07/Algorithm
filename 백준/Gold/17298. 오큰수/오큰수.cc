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
	vector <int> A(N, 0);
	stack <int> myStack;
	vector <int> result(N, -1);

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	myStack.push(0);
	for (int i = 1; i < N; i++) {
		while (!myStack.empty() && A[myStack.top()] < A[i]) {
			result[myStack.top()] = A[i];
			myStack.pop();
		}
		myStack.push(i);
	}
	for (int i = 0; i < N; i++) {
		cout << result[i] << " ";
	}
}