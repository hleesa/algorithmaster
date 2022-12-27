#include <string>
#include <vector>

using namespace std;

typedef long long ll;

ll getSum(const vector<int>& q)
{
	ll ret = 0;
	for(int v : q)
		ret += v;
	return ret;
}

int solution(vector<int> queue1, vector<int> queue2)
{
	ll q1Sum = getSum(queue1);
	ll q2Sum = getSum(queue2);
	int q1Idx = 0;
	int q2Idx = 0;
	int cnt = 0;
	int cntEnd = (queue1.size() + queue2.size()) * 2;
	while(q1Idx < queue1.size() && q2Idx < queue2.size() && cnt < cntEnd)
	{
		if (q1Sum < q2Sum)
		{
			int top = queue2[q2Idx];
			q1Sum += top;
			q2Sum -= top;
			queue1.push_back(top);
			++q2Idx;
		}
		else if (q2Sum < q1Sum)
		{
			int top = queue1[q1Idx];
			q2Sum += top;
			q1Sum -= top;
			queue2.push_back(top);
			++q1Idx;
		}
		else
			break;
		++cnt;
	}
	int answer = q1Sum == q2Sum ? q1Idx + q2Idx : -1;
	return answer;
}