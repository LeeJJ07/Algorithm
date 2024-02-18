#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int check[1005][1005];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string first;
	string second;
	cin >> first >> second;
	for (int i = 1; i <= first.size(); i++) {
		for (int j = 1; j <= second.size(); j++) {
			if (second[j-1] == first[i-1]) {
				check[i][j] = check[i - 1][j - 1] + 1;
			}
			else {
				check[i][j] = max(check[i - 1][j], check[i][j - 1]);
			}
		}
	}
	cout << check[first.size()][second.size()] << '\n';
}