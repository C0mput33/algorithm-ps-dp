#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
long long dp[10001];
const long long mod = 1000000007;
long long r(int n)
{
	if (n % 3 != 0)
		return 0;
	if (dp[n] != -1)
		return dp[n]% mod;
	dp[n] = 3 * r(n-3) % mod;
	for (int i = 6; i <= n; i += 3)
		dp[n] += i * 2 / 3 * r(n - i) % mod;
	return dp[n]% mod;
}
int main() {
	int c;
	cin >> c;
	vector<long long> v;
	while (c--)
	{
		
		fill(dp,dp+10001, -1);
		dp[0] = 1;
		int k;
		cin >> k;
		v.push_back(r(k));
	}
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << '\n';
	}

}