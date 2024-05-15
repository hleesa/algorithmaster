#include <string>
#include <algorithm>

using namespace std;

string solution(string my_string) {
    string charsToRemove = "aeiou";
    string ans(my_string);
    ans.erase(remove_if(ans.begin(), ans.end(),
                        [&charsToRemove](char c) {
                            return charsToRemove.find(c) != string::npos;
                        }), ans.end());
    return ans;
}