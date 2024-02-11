#include <bits/stdc++.h>
using namespace std;

#define FIO       ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define all(a)    ((a).begin()), ((a).end())
#define printarr  (v, start, end)for (int _i = (start); _i < (end); _i++) cout << (v[_i]) << " ";cout << "\n";
#define log(v)    for(auto __i = ((v).begin()); __i != ((v).end()); __i++) cout << *(__i) << " "; cout << "\n";
#define int       long long
#define print(args...){string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s);istream_iterator<string> _it(_ss);err(_it, args);cout<<"\n";};

using vi       =    vector<int>;
using vvi      =    vector<vector<int>>;
using ld       =    long double;
using pii      =    pair<int, int>;
using mii      =    map<int, int>;
using umii     =    unordered_map<int, int>;
using maxheap  =    priority_queue<int>;
using minheap  =    priority_queue<int, vector<int>, greater<int>>;

void err(istream_iterator<string> it) {};
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
	cout << a << " ";
	err(++it, args...);
};

vi *adj;
vi expdeg, actualdeg;
int n, m;
bool possible = true;

void solve()
{
	int sum = 0LL, mx = -1e9;
	set<pii> a;

	for (int i = 1; i <= n; i++)
	{
		if (actualdeg[i] > expdeg[i])
		{
			cout << "-1a\n";
			return;
		}
		else if (actualdeg[i] == expdeg[i])
			continue;

		a.insert({expdeg[i] - actualdeg[i], i});
		sum += expdeg[i] - actualdeg[i];
		mx = max(mx, expdeg[i] - actualdeg[i]);
	}
	
	int remSum = sum - mx;
	
	if (sum % 2 == 1 or remSum < mx or sum > 2*(n - 1))
	{
		cout << "-1b\n";
		return;
	}
	
	vector<pii> ans;

	// until max = remSum remSum me pairs banao
	while (mx != remSum)
	{
		auto fi = *a.begin();
		auto se = *(++a.begin());
				
		fi.first--;
		se.first--;

		remSum -= 2;

		a.erase(fi), a.erase(se);

		ans.push_back({fi.second, se.second});

		if (fi.first != 0)
			a.insert(fi);
		if (se.first != 0)
			a.insert(se);
	}

	while (remSum != 0)
	{
		auto fi = *a.begin();
		auto se = *(--a.end());
		
		print("A", fi.first, se.first);
		
		
		fi.first--;
		se.first--;

		remSum -= 2;

		a.erase(fi), a.erase(se);

		ans.push_back({fi.second, se.second});

		if (fi.first != 0)
			a.insert(fi);
		if (se.first != 0)
			a.insert(se);
	}
	
	if (a.size() > 0 or 1 == n - m - 1)
	{
		for(auto i : ans)
		{
			print(i.first, i.second);
		}
	}
	else
		cout << "-1c\n";
}

int32_t main()
{
	FIO;
	cin >> n >> m;

	adj = new vi[n + 1];
	actualdeg.resize(n + 1);
	expdeg.resize(n + 1);

	for (int i = 1; i <= n; i++)
		cin >> expdeg[i];

	for (int i = 0; i < m; i++)
	{
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);

		actualdeg[u]++, actualdeg[v]++;
	}

	solve();
}