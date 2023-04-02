#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;

int t,k;
vector<pair<int,int>> v; 
int dp[102][10002];

int main()
{
	cin >> t >> k;
	v.push_back(pair<int, int>(0, 0));
	for (int i = 0; i < k; i++)
	{
		int a1, a2;
		cin >> a1 >> a2;
		v.push_back(pair<int,int>(a1, a2));
	}
	dp[0][0] = 1;
	for (int i = 1; i < v.size(); i++)
	{
		for (int j = 0; j <= v[i].second; j++)
		{
			for (int h = v[i].first * j; h <= t; h++)
			{
				dp[i][h] += dp[i - 1][h - v[i].first * j];
			}
		}
	}
	cout <<dp[v.size()-1][t];
}
