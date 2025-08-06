#include <iostream>
#include <stack>

using namespace std;

int n, res;
string str;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	while (n--) {
		cin >> str;
		stack<char> s;
		for (int i = 0;i < str.size();i++) {
			if (!s.empty() && s.top() == str[i])
				s.pop();
			else
				s.push(str[i]);
		}
		if (s.empty())
			res++;
	}
	cout << res;
}