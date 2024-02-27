#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	string str;
	cin >> str;
	vector<char> v;
	for (int i = 0; i < str.length(); i++) v.push_back(str[i]);
	sort(v.begin(), v.end(), greater<>());
	for (int i = 0; i < str.length(); i++)cout << v[i];
}