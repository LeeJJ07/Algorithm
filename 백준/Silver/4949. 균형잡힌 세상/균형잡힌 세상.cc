#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool check(string input) {
	stack<char> s;
	for (char c : input) {
		if (c == '(' || c == '[') s.push(c);
		else if (c == ')'||c==']') {
			if (s.empty()) return false;
			else if (c == ')' && s.top() == '[') return false;
			else if (c == ']' && s.top() == '(') return false;
			else s.pop();
		}
	}
	return s.empty();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true) {
		string str;
		getline(cin, str);
		if (str == ".")
			break;
		if (check(str)) cout << "yes\n";
		else cout << "no\n";
	}
}