#include <string>
#include <algorithm>

using namespace std;

string solution(string a, string b) {
    int aLen = a.length();
    int bLen = b.length();
    int len = max(aLen, bLen);
    string answer = "";
    answer.reserve(len);
    int carry = 0;
    for (int i = 0; i < len; ++i) {
        int aInt = i < aLen ? a[aLen - i - 1] - '0' : 0;
        int bInt = i < bLen ? b[bLen - i - 1] - '0' : 0;
        int sum = aInt + bInt + carry;
        if (sum >= 10) carry = 1;
        else carry = 0;
        answer.push_back(sum % 10 + '0');
    }
    if (carry)
        answer.push_back(carry + '0');
    reverse(answer.begin(), answer.end());
    return answer;
}
