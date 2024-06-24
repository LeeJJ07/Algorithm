#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(int k, int d)
{
    long long answer = 0;
    for (long long x = 0; x <= d; x += k)
    {
        long long y = (long long)sqrt((long long)d * (long long)d - (long long)x * (long long)x);
        answer += y / k + 1;
    }
    return answer;
}