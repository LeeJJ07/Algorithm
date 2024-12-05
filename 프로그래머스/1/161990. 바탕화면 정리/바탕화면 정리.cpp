#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;

    int lux = wallpaper[0].size(), luy = wallpaper.size(), rdx = 0, rdy = 0;

    for (int y = 0; y < wallpaper.size();y++) {
        for (int x = 0;x < wallpaper[y].size();x++) {
            if (wallpaper[y][x] != '#')
                continue;
            if (x < lux) lux = x;
            if (x > rdx) rdx = x;
            if (y < luy) luy = y;
            if (y > rdy) rdy = y;
        }
    }

    answer.push_back(luy);
    answer.push_back(lux);
    answer.push_back(rdy + 1);
    answer.push_back(rdx + 1);
    return answer;
}