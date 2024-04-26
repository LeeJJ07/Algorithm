#include <iostream>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int t, start, target;
int visited[10001];
char check[10001];
pair<int, char> nt(int num, int i) {
	if (i == 0) {
		return { (num * 2) % 10000, 'D' };
	}
	else if (i == 1) {
		num -= 1;
		if (num < 0) return { 9999, 'S' };
		return { num, 'S'};
	}
	else if (i == 2) {
		string tmp = to_string(num);
		if (tmp.length() != 4) {
			while (tmp.length() != 4) tmp = '0' + tmp;
		}
		tmp += tmp[0];
		tmp = tmp.substr(1, tmp.length() - 1);
		return { atoi(tmp.c_str()), 'L' };
	}
	else if (i == 3) {
		string tmp = to_string(num);
		if (tmp.length() != 4) {
			while (tmp.length() != 4) tmp = '0' + tmp;
		}
		tmp = tmp[tmp.length() - 1] + tmp;
		tmp = tmp.substr(0, tmp.length() - 1);
		return { atoi(tmp.c_str()), 'R' };
	}
}
void bfs() {
	queue<int> q;
	q.push(start);
	visited[start] = target;
	while (q.size()) {
		int now = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			pair<int, char> next = nt(now, i);
			if (visited[next.first] != -1) continue;
			visited[next.first] = now;
			check[next.first] = next.second;
			if (next.first == target) return;
			q.push(next.first);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> t;
	while (t--) {
		cin >> start >> target;
		memset(visited, -1, sizeof(visited));
		bfs();
		vector<char> res;
		for (int i = target; visited[i] != target; i = visited[i]) {
			res.push_back(check[i]);
		}
		reverse(res.begin(), res.end());
		for (char c : res) cout << c;
		cout << "\n";
	}
}