// using my template because of lack of time :)
#include <iostream>
#include <algorithm>
#include <utility>
#include <cstring>
#include <string.h>
#include <set>
#include <map>
#include <math.h>
#include <stdio.h>
#include <stack>
#include <vector>
#include <functional>
#include <bitset>
#include <iomanip>
#define ll long long
#define gr greater<ll>()
#define pi acos(-1.0)
#define pb push_back
#define MS0(ar) memset(ar,0,sizeof ar)
#define MS1(ar) memset(ar,-1,sizeof ar)
#define f first
#define s second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define ind(a) scanf("%d",&a)
#define inl(a) scanf("%lld",&a)
using namespace std;
const int sz = 100100;
int dp[sz][22], lev[sz];
vector<int>vec[sz];
ll S[sz];
ll val[sz];
ll node[sz];
//stack<int>s;
void dfs(int src)
{
	stack<int>s;
	lev[src] = 0;
	s.push(src);
	while (!s.empty())
	{
		int cur = s.top();
		s.pop();
		for (int i = 0; i < vec[cur].size(); i++)
		{
			int tmp = vec[cur][i];
			if (tmp != dp[cur][0])
			{
				lev[tmp] = lev[cur] + 1;
				s.push(tmp);
				dp[tmp][0] = cur;
			}
		}
	}
 
}
void dfs_0(int x , int p) {
	for (int cur : vec[x]) {
		if (cur == p)
			continue;
		if (S[cur] > val[x]) {
			val[cur] = S[cur];
			node[cur] = cur;
		}
		else {
			val[cur] = val[x];
			node[cur] = node[x];
		}
		dfs_0(cur, x);
	}
}
int query(int p, int q)
{
	int lg;
	if (lev[p] < lev[q])
		swap(p, q);
	for (lg = 1; 1 << lg <= lev[p]; lg++);
	lg--;
	for (int i = lg; i >= 0; i--)
	{
		if (lev[p] - (1 << i) >= lev[q])
			p = dp[p][i];
	}
	if (p == q)
		return p;
	for (int i = lg; i >= 0; i--)
		if (dp[p][i] != -1 && dp[p][i] != dp[q][i])
			p = dp[p][i], q = dp[q][i];
	return dp[p][0];
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
#endif
	int p, q, qu, a, b, n, t;
	ind(n);
	for (int i = 1 ; i <= n ; i ++) {
		inl(S[i]);
	}
 
	for (int i = 2; i <= n ; i ++) {
		ind(p);
		vec[p].push_back(i);
		//vec[i].push_back(p);
	}
 
	MS1(dp);
	dfs(1);
	val[1] = S[1];
	for (int j = 1; 1 << j <= n; j++)
	{
		for (int i = 1; i <= n; i++)
		{
			if (dp[i][j - 1] != -1)
				dp[i][j] = dp[dp[i][j - 1]][j - 1];
		}
	}
	val[1] = S[1];
	node[1] = 1;
	dfs_0(1, 0);
	ind(qu);
	for (int k = 1; k <= qu; k++)
	{
		ind(p);
		ind(q);
		//if(ty==1)
		int x = query(p, q);
		printf("%lld\n", node[x]);
	}
	return 0;
}
