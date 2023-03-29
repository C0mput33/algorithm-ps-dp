#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int dp[10002];
int main()
{
	dp[0] = 0;
	int n, k, s;
	cin >> n >> k;
	vector<int> v;
	fill(dp + 1, dp + 10002, 100000);
	while (n--)
	{
		int i;
		cin >> i;
		v.push_back(i);
	}
	//e.g 3원으로 만들때 그 전에 dp[3] 과 dp[0]+1 을 비교 최솟값을 구하므로 초기화는 큰값으로 그러나, d[0]=0으로 
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = v[i]; j <= k; j++)
		{
			dp[j] = min(dp[j], dp[j - v[i]] + 1);
		}
	}
	if (dp[k] == 100000)
		cout << -1;
	else
	    cout << dp[k];
	return 0;
}
