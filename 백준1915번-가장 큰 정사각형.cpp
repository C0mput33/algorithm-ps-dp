#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
string input;
int dp[1001][1001];
int main() {
	int y, x,ret=0;
	cin >> y >> x;
	for (int i = 1; i <= y; i++)
	{
		cin >> input;
		for (int j = 1; j <= x; j++)
		{
			if (input[j-1] == '1')
				dp[i][j] = 1;
		}
	}
	
	for (int i = 1; i <= y; i++)
	{
		for (int j = 1; j <= x; j++)
		{
			if (dp[i][j] == 1)
			{
				dp[i][j] = (min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1);
				ret = max(ret, dp[i][j]);
			}	
		}
	}
	cout << ret * ret;
	return 0;
}
