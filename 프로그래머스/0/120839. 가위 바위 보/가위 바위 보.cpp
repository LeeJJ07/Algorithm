#include <string>
#include <map>

using namespace std;

string solution(string rsp)
{
    map<char, string> m;
    m['2'] = "0"; m['0'] = "5"; m['5'] = "2";
    string answer = "";
    for (int i = 0; i < rsp.size(); i++)
        answer += m[rsp[i]];
    return answer;
}
