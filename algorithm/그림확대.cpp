#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> picture, int k) {
    size_t ySize = k * picture.size();
    size_t xSize = k * picture.front().size();
    vector<string> answer;
    answer.reserve(ySize);
    for (size_t y = 0; y < ySize; ++y) {
        string line;
        line.reserve(xSize);
        for (size_t x = 0; x < xSize; ++x) {
            line.push_back(picture[y / k][x / k]);
        }
        answer.push_back(line);
    }
    return answer;
}
