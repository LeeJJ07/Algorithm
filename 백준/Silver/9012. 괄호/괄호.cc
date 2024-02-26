#include <iostream>
#include <stack>
using namespace std;

bool check(string input) {
	stack<char> s;
	for (int i = 0; i < input.size(); i++) {
		if (input[i] == '(') {
			s.push(input[i]);
		}
		else {
			if (s.empty())
				return false;
			if (s.top() == '(')
				s.pop();
			else return false;
		}
	}
	if (s.size())
		return false;
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string input;
		cin >> input;
		if (check(input)) cout << "YES\n";
		else cout << "NO\n";
	}
}