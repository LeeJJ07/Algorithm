#include <string>
#include <vector>

using namespace std;

int solution(vector<int> arr)
{
    int answer = 0;
    for (int i : arr)
    {
        int count = 0;
        while (true)
        {
            if ((i % 2) && (i >= 50)) break;
            if (!(i % 2) && (i < 50)) break;
            if (i % 2) i = 2 * i + 1;
            else i /= 2;
            count++;
        }
        answer = max(answer, count);
    }

    return answer;
}