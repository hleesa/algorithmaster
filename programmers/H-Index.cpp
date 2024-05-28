#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    vector<int> cts = citations;
    sort(cts.begin(), cts.end(), greater<int>());

    int h = 0;
    for (int i = 0; i < cts.size(); ++i) {
        if (cts[i] >= i + 1) {
            h = i + 1;
        } else {
            break;
        }
    }
    return h;
}