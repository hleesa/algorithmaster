#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> rank, vector<bool> attendance) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    for(size_t i = 0; i< rank.size(); ++i){
        if(!attendance[i]) continue;
        pq.push({rank[i], i});
    }
    vector<int> abc;
    for(int i = 0; i < 3; ++i){
        abc.push_back(pq.top().second);
        pq.pop();
    }
    int answer = abc[0] * 10000 + abc[1] * 100 + abc[2];
    return answer;
}