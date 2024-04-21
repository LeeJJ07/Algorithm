#include <iostream>
#include <map>
using namespace std;

int n;
string input1, input2;
map<string, int> temp;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	temp["ChongChong"] = 1;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input1 >> input2;
		if (temp[input1] || temp[input2]) {
			temp[input1] = 1;
			temp[input2] = 1;
		}
	}
	int sz = 0;
	for (auto now : temp) sz += now.second;
	cout << sz << '\n';
}