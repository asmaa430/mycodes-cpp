#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nl "\n"
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define f first
#define s second
#define pb push_back
#define INF 1e9 + 7
#define int long long
void Fast_IO()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
struct Node
{
	int val;
	Node(int x = 0)
	{
		val = x;
	}
	void change(int x)
	{
		val = x;
	}
};
struct segTree
{
	int tree_size;
	vector<Node> seg_data;
	segTree(int n)
	{
		tree_size = 1;
		while (tree_size < n)
			tree_size *= 2;

		seg_data.assign(2 * tree_size, Node());
	}
	Node merge(const Node &lf, const Node &ri)
	{
		Node ans = Node();
		ans.val = lf.val + ri.val;
		return ans;
	}
	void Build(vector<int> &arr, int ni, int lx, int rx)
	{
		if (rx - lx == 1)
		{
			if (lx < (int)arr.size())
				seg_data[ni] = Node(arr[lx]);
			return;
		}
		int mid = (lx + rx) / 2;
		Build(arr, 2 * ni + 1, lx, mid);
		Build(arr, 2 * ni + 2, mid, rx);
		seg_data[ni] = merge(seg_data[2 * ni + 1], seg_data[2 * ni + 2]);
	}
	void Build(vector<int> &arr)
	{
		Build(arr, 0, 0, tree_size);
	}
	Node get_range(int l, int r, int ni, int lx, int rx)
	{
		if (lx >= l && rx <= r)
		{
			return seg_data[ni];
		}
		if (rx <= l || lx >= r)
		{
			return Node();
		}
		int mid = (lx + rx) / 2;
		return merge(get_range(l, r, 2 * ni + 1, lx, mid), get_range(l, r, 2 * ni + 2, mid, rx));
	}
	int get_range(int l, int r)
	{
		return get_range(l, r, 0, 0, tree_size).val;
	}
	void set(int idx, int v, int ni, int lx, int rx)
	{
		if (rx-lx == 1)
		{
			seg_data[ni].change(v);
			return;
		}
		int mid = (lx + rx) / 2;
		if (idx < mid)
			set(idx, v, 2 * ni + 1, lx, mid);
		else
			set(idx, v, 2 * ni + 2, mid, rx);
		seg_data[ni] = merge(seg_data[2 * ni + 1], seg_data[2 * ni + 2]);
	}
	void set(int idx, int v)
	{
		set(idx, v, 0, 0, tree_size);
	}
};

void solve()
{
	int n, q;
	cin >> n >> q;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	segTree st(n);
	st.Build(arr);
	while (q--)
	{
		int t;
		cin >> t;
		if (t == 1)
		{
			ll i, v;
			cin >> i >> v;
			st.set(i, v);
		}
		else
		{
			int l, r;
			cin >> l >> r;
			cout << st.get_range(l, r) << nl;
		}
	}
}

signed main()
{
	Fast_IO();

	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int t = 1;
	// cin >> t;
	while (t--)
		solve();
	return 0;
}