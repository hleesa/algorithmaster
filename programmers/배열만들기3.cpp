#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> intervals) {
    vector<int> answer;
    answer.reserve(arr.size());
    for(vector<vector<int>>::iterator interval = intervals.begin(); interval != intervals.end(); ++interval){
        answer.insert(answer.end(), arr.begin() + interval->front(), arr.begin() + interval->back() + 1);
    }
    return answer;
}
