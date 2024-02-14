#include <iostream>
#include <vector>
#include <string>
using namespace std;

char bigROT(char c) {
	c += 13;
	if (c > 'Z') {
		c -= 26;
	}
	return c;
}
char smallROT(unsigned char c) {
	c += 13;
	if (c > 'z') {
		c -= 26;
	}
	return c;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	getline(cin, s);
	for (int i = 0; i < s.length(); i++) {
		if (s[i] >= 'a' && s[i] <= 'z') {
			cout << smallROT(s[i]);
		}else if (s[i] >= 'A' && s[i] <= 'Z') {
			cout << bigROT(s[i]);
		}
		else {
			cout << s[i];
		}
	}
}