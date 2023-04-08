#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
string s;
vector<int> v;
int dp[5002][102];
int cb;
int r(int a, int b)
{
	if (b > 26||b==0)
		return 0;
	if (a >= v.size()-1)
		return 0;
	if (dp[a][b] != -1)
		return dp[a][b];
	if (a == v.size() - 2)
		return 1;
	dp[a][b] = r(a + 1, v[a + 1]) % 1000000;
	if (v[a + 1] != 0)
	{
		dp[a][b] += r(a + 2, v[a + 1] * 10 + v[a + 2]) % 1000000;
	}
	return dp[a][b];
}
int main() {
	cin >> s;
	v.push_back(0);
	for (int i = 0; i < s.size(); i++)
	{
		v.push_back(s[i] - '0');
	}
	v.push_back(0);
	for (int i = 0; i < 5002; i++)
	{
		for (int j = 0; j < 102; j++)
			dp[i][j] = -1;
	}
	cout << r(0, 1)%1000000;

	return 0;
}
