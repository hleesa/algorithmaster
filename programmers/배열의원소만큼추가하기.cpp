#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    for(vector<int>::iterator it = arr.begin(); it != arr.end(); ++it){
        answer.insert(answer.end(), *it, *it);
    }
    return answer;
}
