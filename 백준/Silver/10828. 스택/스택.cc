#include <iostream>
#include <stack>
using namespace std;

int n, x;
string str;
stack<int> s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	while (n--) {
		cin >> str;
		if (str[0] == 'p' && str[1] == 'u') {
			cin >> x; s.push(x);
		}
		else if (str[0] == 'p' && str[1] == 'o') {
			if (s.size()) {
				cout << s.top() << '\n';
				s.pop();
			}
			else {
				cout << -1 << '\n';
			}
		}
		else if (str[0] == 's') {
			cout << s.size() << '\n';
		}
		else if (str[0] == 'e') {
			cout << s.empty() << '\n';
		}
		else if (str[0] == 't') {
			if (s.size()) cout << s.top() << '\n';
			else cout << -1 << '\n';
		}
	}
}