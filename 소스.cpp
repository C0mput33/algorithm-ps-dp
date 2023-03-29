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