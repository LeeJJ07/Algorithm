#include <string>
#include <vector>
#include <map>

using namespace std;

int adj[54][54];
int present[54];

vector<string> split(string s)
{
    vector<string> res(2); int i;
    for (i = 0; s[i] != ' '; i++);
    res[0] = s.substr(0, i);
    res[1] = s.substr(i + 1);
    return res;
}

int solution(vector<string> friends, vector<string> gifts) {
    
    map<string, int> m;


    for (int i = 0;i < friends.size();i++)
        m[friends[i]] = i;

    for (int i = 0; i < gifts.size();i++) {
        vector<string> temp = split(gifts[i]);
        adj[m[temp[0]]][m[temp[1]]]++;
    }
    for (int i = 0;i < friends.size(); i++) {
        for (int j = 0;j < friends.size();j++) {
            if (i == j) continue;
            present[i] += adj[i][j];
            present[j] -= adj[i][j];
        }
    }
    int answer = 0;
    for (int i = 0;i < friends.size();i++) {
        int temp = 0;
        for (int j = 0;j < friends.size();j++) {
            if (i == j) continue;
            if (adj[i][j] > adj[j][i]) temp++;
            else if (adj[i][j] == adj[j][i] && present[i] > present[j])
                temp++;
        }
        answer = max(answer, temp);
    }

    return answer;
}