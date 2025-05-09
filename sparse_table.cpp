#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nl "\n"
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define f first
#define s second
#define pb push_back

void Fast_IO()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
const int N = 2e5 + 5, SQ = 460;


int a[N];
map<int, int> mp[SQ];

const int N = 2e5 + 5, SQ = 460;
ll n, q, s[N], t[N][22];
ll merge(ll a, ll b)
{
	return min(a, b);
}
void bulid()
{
	for (int i = 0; i < n; i++)
	{
		t[i][0] = s[i];
	}
	for (int pw = 1; (1 << pw) <= n; pw++)
	{
		for (int i = 0; i + (1 << pw) <= n; i++)
		{
			t[i][pw] = merge(t[i][pw - 1], t[i + (1 << (pw - 1))][pw - 1]);
		}
	}
}
ll query(int l, int r)
{
	int sz = (r - l) + 1;
	ll ret = LLONG_MAX;
	for (int i = 21; i >= 0; i--)
	{
		if ((sz >> i) & 1)
		{
			ret = merge(ret, t[l][i]);
			l += (1 << i);
		}
	}
	return ret;
}

void solve() {
   
    
}
int main()
{
	//Fast_IO();
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int t = 1;
	// cin >> t;
	while (t--)
		solve();
	return 0;
}
