/*

이번 달 선물 기록 => 다음 달 선물 예측

1. 선물 을 더 많이 준 사람이 하나 받는다.
2. [1.]이 아니면, 선물 지수가 더 큰 사람이 받는다.
    선물 지수: 친구들에게 준 선물의 수 - 친구들에게 받은 선물의 수
3. 선물지수도 같다면, 선물을 주고받지 않는다.

두 사람 사이.

선물 주고 받은것 관리, 선물 지수

인덱스로 관리

giftRowToCol[][]

0 , 1, 2, 3

*/

#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

const int MX = 52;
int giftRowToCol[MX][MX];
int giftIndex[MX];
map<string, int> nameToIdx;

void setNameToIdx(const vector<string>& friends)
{
    for(int i=0; i<friends.size(); ++i)
    {
        nameToIdx[friends[i]] = i;
    }
}

void getGiftInfo(const vector<string>& gifts)
{
    for(string gift : gifts){
        size_t idx = gift.find(" ");
        int from = nameToIdx[gift.substr(0, idx)];
        int to = nameToIdx[gift.substr(idx+1)];
        ++giftRowToCol[from][to];
        ++giftIndex[from];
        --giftIndex[to];
    }
}

int getMaxGift()
{
    int n = nameToIdx.size();
    vector<int> gifts(n);
    for(int y=0; y<n; ++y)
    {
        for(int x= y + 1; x<n; ++x)
        {
            if((giftRowToCol[y][x] == 0 && giftRowToCol[x][y] == 0) || giftRowToCol[y][x] == giftRowToCol[x][y])
            {
                if (giftIndex[y] > giftIndex[x])
                    ++gifts[y];
                else if (giftIndex[y] < giftIndex[x])
                    ++gifts[x];
            }
            else
            {
                if (giftRowToCol[y][x] > giftRowToCol[x][y])
                    ++gifts[y];
                else if (giftRowToCol[y][x] < giftRowToCol[x][y])
                    ++gifts[x];
            }
        }
    }
    return *max_element(gifts.begin(),gifts.end());
}

int solution(vector<string> friends, vector<string> gifts) {
    setNameToIdx(friends);
    getGiftInfo(gifts);
    int answer = getMaxGift();
    return answer;
}