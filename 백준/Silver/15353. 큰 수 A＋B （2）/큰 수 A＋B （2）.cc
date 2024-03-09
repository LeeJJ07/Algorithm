#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string string_add(string a, string b) {
	int sum = 0;
	string ret;
	while (a.size() || b.size() || sum) {
		if (a.size()) {
			sum += a.back() - '0';
			a.pop_back();
		}
		if (b.size()) {
			sum += b.back() - '0';
			b.pop_back();
		}
		ret += (sum % 10) + '0';
		sum /= 10;
	}
	reverse(ret.begin(), ret.end());
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string a, b;
	cin >> a >> b;
	cout << string_add(a, b);
}