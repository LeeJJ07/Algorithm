#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N; cin >> N; int i = 666;
	while (N != 0) if (to_string(i++).find("666") != string::npos)N--;
	cout << i-1 << '\n';
}