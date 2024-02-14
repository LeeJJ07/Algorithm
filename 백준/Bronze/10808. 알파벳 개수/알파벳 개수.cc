#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;
	cin >> str;
	vector<int> A(26);
	for (int i = 0; i < str.length(); i++) {
		A[str[i] - 'a']++;
	}
	
	for (int i = 0; i < 26; i++) {
		cout << A[i] << " ";
	}
}