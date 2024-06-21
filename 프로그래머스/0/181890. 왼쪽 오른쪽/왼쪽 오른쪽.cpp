#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> str_list)
{
    int i; vector<string> answer;
    for (i = 0; i < str_list.size() && str_list[i].compare("l") != 0 && str_list[i].compare("r") != 0; i++);
    if (str_list.size() == i) return answer;
    if (str_list[i].compare("l")==0)
    {
        for (int j = 0; j < i; j++) answer.push_back(str_list[j]);
    }
    else
    {
        for (int j = i + 1; j < str_list.size(); j++) answer.push_back(str_list[j]);
    }
    return answer;
}