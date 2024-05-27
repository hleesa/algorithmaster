#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<string> s1, vector<string> s2) {
    set<string> elements(s1.begin(), s1.end());
    int ans = 0;
    for (auto s: s2) {
        if (elements.find(s) != elements.end()) {
            ++ans;
        }
    }
    return ans;
}

/*
 * set range constructor
 */