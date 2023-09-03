#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string myString) {
    string answer;
    transform(myString.begin(), myString.end(), back_inserter(answer), ::toupper);
    return answer;
}
