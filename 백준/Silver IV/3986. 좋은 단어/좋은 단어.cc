#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	int result = 0;
	for (int i = 0; i < N; i++) {
		stack<char> al;
		string str;
		cin >> str;
		for (int j = 0; j < str.length(); j++) {
			if (al.empty()) {
				al.push(str[j]);
			}
			else {
				if (al.top() == str[j]) {
					al.pop();
				}
				else {
					al.push(str[j]);
				}
			}
		}
		if (al.empty())
			result++;
	}
	cout << result << '\n';
}