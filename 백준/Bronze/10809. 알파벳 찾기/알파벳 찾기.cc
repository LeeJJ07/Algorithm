#include <iostream>
#include <string.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	string str;
	cin >> str;
	int a[26];
	memset(a, -1, sizeof(a));
	for (int i = 0; i < str.size(); i++) {
		if (a[str[i] - 'a'] == -1) a[str[i]-'a'] = i;
	}
	for (int i = 0; i < 26; i++) cout << a[i] << ' ';
}