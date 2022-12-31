#include <stdio.h>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

const int MX = 5002;
typedef long long ll;
vector<pair<int, ll>> adj[MX];

void input(int& N)
{
	scanf("%d", &N);
	int A, B;
	ll C;
	for (int i = 1; i < N; ++i)
	{
		scanf("%d %d %lld", &A, &B, &C);
		adj[A].push_back({B, C});
		adj[B].push_back({A, C});
	}
}

void getDist(vector<ll>& dist)
{
	queue<pair<int, int>> q;
	q.push({1, 0});
	dist[1] = 0;
	while (!q.empty())
	{
		int cur, before;
		tie(cur, before) = q.front();
		q.pop();
		for (auto next: adj[cur])
		{
			if (next.first == before)
				continue;
			if (dist[cur] + next.second >= dist[next.first])
			{
				dist[next.first] = dist[cur] + next.second;
				q.push({next.first, cur});
			}
		}
	}
}

ll getAns(const int& N)
{
	vector<ll> dist(N + 2, -1);
	getDist(dist);
	ll ret = -1;
	for (int i = 1; i <= N; ++i)
	{
		if (dist[i] > ret)
			ret= dist[i];
	}
	return ret;
}

int main()
{
	int N;
	input(N);
	printf("%lld\n", getAns(N));
	return 0;
}