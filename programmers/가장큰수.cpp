#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> numbers) {
    vector<string> strs(numbers.size());
    for (int i = 0; i < numbers.size(); ++i) {
        strs[i] = to_string(numbers[i]);
    }
    sort(strs.begin(), strs.end(), [](const string &lhs, const string &rhs) {
        string lSum = lhs + rhs;
        string rSum = rhs + lhs;
        return lSum > rSum;
    });
    string ans = "";
    bool zeros = true;
    for (auto s: strs) {
        ans += s;
        if (s != "0")
            zeros = false;
    }
    if (zeros)
        ans = "0";
    return ans;
}

/*
 * 문자열 붙인 값으로 비교할 수 있다.
 */