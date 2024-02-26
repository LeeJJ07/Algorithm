#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;
	getline(cin, str);
	int result = 1;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == ' ') {
			if (i == 0 || i == str.length() - 1)
				continue;
			result++;
		}
	}
	if (str == " ") cout << 0 << '\n';
	else cout << result << '\n';
}