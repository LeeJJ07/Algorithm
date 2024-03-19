#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, num;
	stack<int> s;
	cin >> n;
	while (n--) {
		cin >> num;
		if (num == 0) s.pop();
		else s.push(num);
	}
	int result = 0;
	while (s.size()) {
		result += s.top();
		s.pop();
	}
	cout << result << '\n';
}