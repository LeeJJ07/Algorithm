#include <iostream>
#include <deque>
#include <sstream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		string input;
		cin >> input;
		int N;
		cin >> N;
		deque<int>A;
		string str;
		cin >> str;
		str = str.substr(1, str.size() - 2);
		istringstream ss(str);
		string subs;
		while (getline(ss, subs, ',')) {
			A.push_back(stoi(subs));
		}

		bool isError = false;
		bool isR = false;
		int cur = 0;
		for (int j = 0; j < input.size(); j++) {
			if (input[j] == 'R') { //뒤집기
				if (!isR)
					cur = A.size() - 1;
				else
					cur = 0;
				isR = !isR;
			}
			else if (input[j] == 'D') { //버리기
				if (A.empty()) {
					cout << "error";
					isError = true;
					break;
				}
				if (isR) {
					A.pop_back();
				}
				else {
					A.pop_front();
				}
			}
		}if (!isError) {
			cout << "[";
			while (!A.empty()) {
				if (!isR) {
					cout << A.front();
					A.pop_front();
				}
				else {
					cout << A.back();
					A.pop_back();
				}
				if (!A.empty())
					cout << ",";
			}
			cout << "]";
		}
		cout << "\n";
	}
}