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

	stack<int> s;
	bool result = true;
	vector<char> ans;

	int idx = 1;
	for (int i = 0; i < n; i++) {
		int now;
		cin >> now;
		if (now >= idx) {
			while (now >= idx) {
				s.push(idx++);
				ans.push_back('+');
			}
			s.pop();
			ans.push_back('-');
		}
		else {
			if (s.top() > now) {
				cout << "NO";
				result = false;
				break;
			}
			else {
				ans.push_back('-');
			}
			s.pop();
		}
	}
	if (result) {
		for (char i : ans) cout << i << '\n';
	}
}