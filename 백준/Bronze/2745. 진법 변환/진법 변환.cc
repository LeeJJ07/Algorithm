#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int a;
	string str;
	cin >> str >> a;
	int n = 0; int cnt = 1;
	for (int i = str.size() - 1; i >= 0; i--, cnt*=a) {
		if (str[i] >= 'A' && str[i] <= 'Z')
			n += (str[i] - 'A' + 10)* cnt;
		else n += (str[i] - '0') * cnt;
	}
	cout << n << '\n';
}