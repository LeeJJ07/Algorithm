#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
string str, res = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";

void check(int i, int j) {
	string tmp1 = str.substr(0, i);
	string tmp2 = str.substr(i , j - i);
	string tmp3 = str.substr(j, str.length());
	
	reverse(tmp1.begin(), tmp1.end());
	reverse(tmp2.begin(), tmp2.end());
	reverse(tmp3.begin(), tmp3.end());

	string tmp = tmp1 + tmp2 + tmp3;
	if (tmp < res) res = tmp;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> str;
	for (int i = 1; i < str.length() - 1; i++) {
		for (int j = i + 1; j < str.length(); j++) {
			check(i, j);
		}
	}
	cout << res << '\n';
}