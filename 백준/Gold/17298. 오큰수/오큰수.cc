#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	vector<int> A(n, 0);
	vector<int> result(n, -1);
	for (int i = 0; i < n; i++) cin >> A[i];
	
	stack<int> s;
	s.push(0);
	for (int i = 1; i < n; i++) {
		while (s.size() && A[s.top()] < A[i]) {
			result[s.top()] = A[i];
			s.pop();
		}
		s.push(i);
	}
	for (int i : result) cout << i << ' ';
}