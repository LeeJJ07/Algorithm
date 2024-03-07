#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	string a;
	cin >> a;
	int result = 0;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] <= 'U') result += (a[i] - 'A') / 3 + 3;
		else if (a[i] == 'V') result += 9;
		else if (a[i] <= 'Z') result += 10;
		if (a[i] == 'S')result--;
	}
	cout << result;
}