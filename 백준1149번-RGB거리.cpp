#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;
int a[1001];
int b[1001];
int c[1001];

int r(int d[1001],int t,int x)
{
	if ((v.size()-1) / 3 == x)
	{
		return v[3 * x + t];
	}
	if (d[x] != 0)
	{
		return d[x];
	}
	if (t == 0)
	{
		int rb = r(b, 1, x + 1);
		int rc = r(c, 2, x + 1);
		int aaa = a[x] = v[3 * x + t] + min(rb, rc);
		return aaa;
	}
	if (t == 1)
	{
		int rb = r(a, 0, x + 1);
		int rc = r(c, 2, x + 1);
		int aaa = b[x] = v[3 * x + t] + min(rb, rc);
		return aaa;
	}
	if (t == 2)
	{
		int rb = r(b, 1, x + 1);
		int rc = r(a, 0, x + 1);
		int aaa = c[x] = v[3 * x + t] + min(rb, rc);
		return aaa;
	}
}

int main() {
	int k;
	cin >> k;
	k=k * 3;
	while (k--)
	{
		int i;
		cin >> i;
		v.push_back(i);
	}
	int aa = r(a, 0, 0);
	int bb = r(b, 1, 0);
	int cc = r(c, 2, 0);
	cout << min(a[0], min(b[0], c[0]));
	return 0;
}
