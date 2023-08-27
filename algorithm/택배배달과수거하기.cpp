/**

일렬로 나열된 n 개의 집

택배 상자에 물건을 담아 배달하고, 빈 상자를 수거한다.

트럭에는 상자를 최대 cap개 실을 수 있다.

각 집마다 배달할 상자 개수과 수거할 상자 개수를 알고 있을 때, 트럭 하나의 최소 이동 거리를 구한다.


8 7 7 3 2
    1   1
        
7 7 4 4 0
1   1

(5 + 3) * 2 = 16

**/

#include <string>
#include <vector>
#include <queue>

using namespace std;

queue<int> countMoving(int cap, int n, vector<int>& info) {
    queue<int> counter;
    for (int i = n - 1; i >= 0; --i) {
        while (info[i] > 0) {
            info[i] -= cap;
            counter.push(i+1);
        }
        if (i > 0 && info[i] < 0) {
            info[i - 1] += info[i];
        }
    }
    return counter;
}

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    queue<int> numOfDelivery = countMoving(cap, n, deliveries);
    queue<int> numOfPickup = countMoving(cap, n, pickups);
    while(!numOfDelivery.empty() && !numOfPickup.empty()) {
        answer += max(numOfDelivery.front(), numOfPickup.front());
        numOfDelivery.pop();
        numOfPickup.pop();
    }
    while(!numOfDelivery.empty()) {
        answer += numOfDelivery.front();
        numOfDelivery.pop();
    }
    while (!numOfPickup.empty()) {
        answer += numOfPickup.front();
        numOfPickup.pop();
    }
    return answer * 2;
}
