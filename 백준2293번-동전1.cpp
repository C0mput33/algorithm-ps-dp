#include<iostream>
#include<vector>
#include<vector>

using namespace std;
int dp[10002]; //dp[i]= 가치가 i원인 동전을 만드는 경우의 수
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
			dp[j] += dp[j - v[i]];  //e.g. 3원일 때 k원 짜리를 만드는 경우의 수는 k-3원을 만드는 경우의 수+k원을 만드는 
		}
	}
	cout << dp[k];
	return 0;
}
