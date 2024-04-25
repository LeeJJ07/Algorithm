#include <iostream>
#include <algorithm>
using namespace std;

int n, cnt; string input;
int isPalindrome() {
	cnt = input.length() / 2 + 1;
	string tmp = input;
	reverse(input.begin(), input.end());
	if (tmp == input) return 1;
	else {
		cnt = 1;
		for (int i = 0; i < tmp.length() / 2 && tmp[i] == input[i]; i++) 
			cnt++;
		return 0;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	while (n--) {
		cnt = 0;
		cin >> input;
		cout << isPalindrome() << " ";
		cout << cnt << "\n";
	}
}