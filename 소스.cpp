#include<iostream>
#include<vector>
#include<vector>

using namespace std;
int dp[10002];
int main()
{
	dp[0] = 1;
	int n, k;
	cin >> n >> k;
	vector<int> v;
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
			dp[j] += dp[j - v[i]];
		}
	}
	cout << dp[k];
	return 0;
}