#include <bits/stdc++.h>
using namespace std;

#define FIO        ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define all(a)     ((a).begin()), ((a).end())
#define printarr   (v, start, end)for (int _i = (start); _i < (end); _i++) cout << (v[_i]) << " ";cout << "\n";
#define log(v)     for(auto __i = ((v).begin()); __i != ((v).end()); __i++) cout << *(__i) << " "; cout << "\n";
#define int        long long
#define fps(x, y)  fixed<<setprecision((y))<<(x)
#define print(args...){string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s);istream_iterator<string> _it(_ss);err(_it, args);cout<<"\n";};

using ll       =    long long;
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

int n, k;
vi a;

int solve()
{
	vi seq(1), vis(a.size());

	int cur_id = 0, x = 0;

	while (!vis[cur_id])
	{
		vis[cur_id] = 1;
		x += a[cur_id];

		cur_id = x % n;
		seq.push_back(cur_id);
	}
	
	x = 0;
	seq.pop_back();

	for (int i = 0; i < seq.size(); i++)
	{
		if (seq[i] == cur_id)
		{
			cur_id = i;
			break;
		}
	}
	
	for(int i = 0; i < cur_id; i++)
	{
		x += a[seq[i]], k--;
		if (k == 0)
			return x;
	}
		
	int cycle_sum = 0, cycle_len = seq.size() - cur_id;

	for (int i = cur_id; i < seq.size(); i++)
		cycle_sum += a[seq[i]];
		
	// print(k, cycle_len)
	// log(seq)

	x += cycle_sum * (k / cycle_len);
	k -= (k / cycle_len) * cycle_len;

	for (int i = cur_id; i < seq.size() and k--; i++)
		x += a[seq[i]];
	
	return x;
}

int32_t main()
{
	FIO;
	cin >> n >> k;

	a.resize(n);

	for (auto &_ : a)
		cin >> _;

	int x = solve();

	cout << x << "\n";

	return 0;
}