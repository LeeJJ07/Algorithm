#include <string>
#include <vector>

using namespace std;

int solution(string myString, string pat)
{
    int answer = 0;
    for (int i = 0; i < myString.size(); i++)
        myString[i] = toupper(myString[i]);
    for (int i = 0; i < pat.size(); i++)
        pat[i] = toupper(pat[i]);

    if (myString.find(pat) != string::npos)
        return 1;
    return 0;
}