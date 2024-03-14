#include <iostream>
#include <stack>
using namespace std;

int n, cnt, ret;
string str;
stack<int> s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> str;
	s.push(-1);
	for (int i = 0; i < n; i++) {
		if (str[i] == '(') s.push(i);
		if (str[i] == ')') {
			s.pop();
			if (!s.empty()) ret = max(ret, i - s.top());
			else s.push(i);
		}
	}
	cout << ret << '\n';
}