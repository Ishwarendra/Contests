#include <bits/stdc++.h>
using namespace std;

#define FIO       ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define all(a)    ((a).begin()), ((a).end())
#define printarr  (v, start, end)for (int _i = (start); _i < (end); _i++) cout << (v[_i]) << " ";cout << "\n";
#define log(v)    for(auto __i = ((v).begin()); __i != ((v).end()); __i++) cout << *(__i) << " "; cout << "\n";
#define print(args...){string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s);istream_iterator<string> _it(_ss);err(_it, args);cout<<"\n";};

using vi   =  vector<int>;
using vvi  =  vector<vector<int>>;
using vll  =  vector<long long>;
using vvll =  vector<vector<long long>>;
using ll   =  long long;
using ld   =  long double;
using ull  =  unsigned long long;
using pii  =  pair<int, int>;
using pll  =  pair<long long, long long>;

void err(istream_iterator<string> it) {};
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
	cout << a << " ";
	err(++it, args...);
};
class DSU
{
	int *par, *rnk;
	int _connected;

public:
	DSU(int n)
	{
		par = new int[n];
		rnk = new int[n];
		_connected = n;

		for (int i = 0; i < n; i++)
			par[i] = i, rnk[i] = 1;
	}

	~DSU()
	{
		delete[] par;
		delete[] rnk;
	}

	int get(int x)
	{
		if (par[x] == x)
			return x;
		return par[x] = get(par[x]);
	}

	void unite(int x, int y)
	{
		int p1 = get(x), p2 = get(y);
		if (p1 != p2)
		{
			if (rnk[p1] > rnk[p2])
			{
				par[p2] = p1;
				rnk[p1] += rnk[p2];
				rnk[p2] = 0;
			}
			else
			{
				par[p1] = p2;
				rnk[p2] += rnk[p1];
				rnk[p1] = 0;
			}
			_connected--;
		}
	}

	int connected_comp()
	{
		return _connected;
	}

};

void solve()
{
	int n, q; cin >> n >> q;
	DSU d(n + 1);

	for (int i = 0; i < q; i++)
	{
		int l, r;
		cin >> l >> r;

		l--, r--;
		d.unite(l, r + 1);
	}

	if (d.get(0) == d.get(n))
		cout << "Yes\n";
	else
		cout << "No\n";
}

int main()
{
	FIO;
	int t = 1;
	// cin >> t;
	while (t--)
		solve();
}