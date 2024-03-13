#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	string str; cin >> str;
	vector<int> a;
	vector<char> b;
	int idx = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '-' || str[i] == '+') {
			b.push_back(str[i]);
			a.push_back(atoi(str.substr(idx, i).c_str()));
			idx = i + 1;
		}
	}
	a.push_back(atoi(str.substr(idx).c_str()));
	int result = a[0];
	int sum = 0; bool chk = false;
	for (int i = 0; i < b.size(); i++) {
		if (b[i] == '-') {
			chk = true;
			result -= sum;
			sum = 0;
			sum += a[i + 1];
		}
		else if (!chk)result += a[i + 1];
		else {
			sum += a[i + 1];
		}
	}
	result -= sum;
	cout << result << '\n';
}