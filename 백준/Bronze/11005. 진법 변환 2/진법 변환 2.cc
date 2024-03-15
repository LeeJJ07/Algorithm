#include <iostream>
using namespace std;

int n, a;
void dfs(int num) {
	if (num == 0)return;
	dfs(num / a);
	if (num % a > 9) {
		char c = (num % a - 10) + 'A';
		cout << c;
	}
	else cout << num % a;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> a;
	dfs(n);
}