#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define all(a)      ((a).begin()), ((a).end())
#define log(v)      for(auto __i = ((v).begin()); __i != ((v).end()); __i++) cout << *(__i) << " "; cout << "\n";
#define int         long long
#define fps(x, y)   fixed<<setprecision((y))<<(x)

#define printarr(v, start, end) for(int _i = (start); _i < (end); _i++) cout << (v[_i]) << " ";cout << "\n";
#define print(args...){string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s);istream_iterator<string> _it(_ss);err(_it, args);cout<<"\n";};

using ll       =    long long;
using vi       =    vector<int>;
using vvi      =    vector<vector<int>>;
using ld       =    long double;
using pii      =    pair<int, int>;
using mii      =    map<int, int>;
using umii     =    unordered_map<int, int>;
using pbds     =    tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

template<typename T>
using maxheap  =    priority_queue<T>;
template<typename T>
using minheap  =    priority_queue<T, vector<T>, greater<T>>;

template<typename T1, typename T2> istream &operator >> (istream& in, pair<T1, T2> &a)
{in >> a.first >> a.second; return in;}
template<typename T1, typename T2> ostream &operator << (ostream& out, pair<T1, T2> &a)
{out << a.first << " " << a.second; return out;}
void err(istream_iterator<string> it){};
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{cout << a << " "; err(++it, args...);};

int f(int x, int y, int z)
{
	return max({x, y, z}) - min({x, y, z});
}

int optimal(vi &a, vi &b, vi &c)
{
	int ans = 1e9;
	for (int i = 0; i < a.size(); i++)
	{
		int x = a[i];
		auto y = upper_bound(all(b), x) - b.begin();
		auto z = lower_bound(all(c), x) - c.begin();
		
		y--;
		
		if (y < 0)
			y = 0;
		if (z == c.size())
			z--;
		
		ans = min(ans, f(x, b[y], c[z]));
	}
	
	return ans;
}

void solve()
{
	string s; cin >> s;
	
	vvi cnt(3);
	
	for(int i = 0; i < s.length(); i++)
		cnt[s[i] - '1'].push_back(i);
	
	for(int i = 0; i < 3; i++)
	{
		if (cnt[i].empty())
		{
			std::cout << "0\n";
			return;
		}
	}
	
	vi id = {0, 1, 2};
	
	int ans = 1e9;
	
	do
	{
		ans = min(ans, optimal(cnt[id[0]], cnt[id[1]], cnt[id[2]]));
	}
	while (next_permutation(all(id)));
	
	std::cout << ans + 1 << "\n";
}

int32_t main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int t = 1;
	std::cin >> t;
	
	for(int i = 1; i <= t; i++)
	{
		// std::cout << "Case #" << i << ": ";
		solve();
	}
	
	return 0;
}