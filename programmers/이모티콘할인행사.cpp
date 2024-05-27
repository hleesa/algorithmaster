/**

1. 가입자 수를 최대한 늘린다.

2. 판매액을 최대한 늘린다.

1번 목표가 우선이며, 2번 목표가 그 다음이다.


n명의 사용자들에게 m개를 할인 판매한다.

할인율은 10%, 20%, 30%, 40% 중 하나로 설정된다.


사용자는 기준에 따라 일정 비율 이상 할인하는 이모티콘을 모두 구매한다.

사용자는 이모티콘 구매 비용의 합이 일정 가격 이상이 되면, 이모티콘 플러스 서비스에 가입한다.


time complexity: O(n(4^m)) = 100*16,000 = 1,600,000 // n : 가입자 수, m : 이모티콘 개수

**/

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> ans = {0, 0};
    for (int i = 0; i < 1 << (2 * emoticons.size()); ++i) {
        vector<int> candi = {0, 0};
        for (vector<vector<int>>::iterator user = users.begin(); user != users.end(); ++user) {
            int priceSumPerUser = 0;
            for (int j = 0; j < emoticons.size(); ++j) {
                int discountRate = (((i >> (j * 2)) % 4) + 1) * 10;
                if (discountRate >= (*user)[0]) {
                    priceSumPerUser += emoticons[j] / 100 * (100 - discountRate);
                }
            }
            if (priceSumPerUser >= (*user)[1])
                ++candi[0];
            else
                candi[1] += priceSumPerUser;
        }
        if (candi[0] > ans[0] || (candi[0] == ans[0] && candi[1] > ans[1]))
            ans = candi;
    }
    return ans;
}
