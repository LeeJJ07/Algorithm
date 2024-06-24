#include <string>
#include <map>

using namespace std;

string solution(string letter)
{
    map<string, string> m;
    m[".-"] = "a"; m["-..."] = "b"; m["-.-."] = "c";
    m["-.."] = "d"; m["."] = "e"; m["..-."] = "f";
    m["--."] = "g"; m["...."] = "h"; m[".."] = "i";
    m[".---"] = "j"; m["-.-"] = "k"; m[".-.."] = "l";
    m["--"] = "m"; m["-."] = "n"; m["---"] = "o";
    m[".--."] = "p"; m["--.-"] = "q"; m[".-."] = "r";
    m["..."] = "s"; m["-"] = "t"; m["..-"] = "u";
    m["...-"] = "v"; m[".--"] = "w"; m["-..-"] = "x";
    m["-.--"] = "y"; m["--.."] = "z";
    string answer = "";
    for (int i = 0; i < letter.size();)
    {
        int j;
        for (j = i; letter[j] != ' ' && j < letter.size(); j++);
        answer += m[letter.substr(i, j - i)];
        i = j + 1;
    }
    return answer;
}