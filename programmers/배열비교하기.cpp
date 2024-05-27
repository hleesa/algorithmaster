#include <vector>
#include <numeric>

using namespace std;

int solution(vector<int> arr1, vector<int> arr2) {
    int diff;
    if(arr1.size() != arr2.size())
        diff = arr1.size() - arr2.size();
    else
        diff = accumulate(arr1.begin(), arr1.end(), 0) - accumulate(arr2.begin(), arr2.end(), 0);
    int answer = 0;
    if (diff > 0)
        answer = 1;
    else if (diff < 0)
        answer = -1;
    return answer;
}
