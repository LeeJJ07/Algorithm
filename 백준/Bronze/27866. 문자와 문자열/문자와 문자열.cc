#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	string str;
	int i;
	cin >> str >> i;
	cout << str[i - 1] << '\n';
}