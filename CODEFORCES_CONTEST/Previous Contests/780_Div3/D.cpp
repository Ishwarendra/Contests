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

// (2 ^ x) * ((-2) ^ x)  
int get(vi &a, int l, int r, vvi &cnt)
{
	int minus_2 = (cnt[r - 1][0] - cnt[l - 1][0]);
	int minus_1 = (cnt[r - 1][1] - cnt[l - 1][1]);
	int plus_2 = (cnt[r - 1][4] - cnt[l - 1][4])
	int plus_1 = (cnt[r - 1][3] - cnt[l - 1][3])
	
	int neg_cnt = minus_2 + minus_1;
	
	if (neg_cnt % 2 == 0)
		return (cnt[r - 1][0] + cnt[r - 1][4] - cnt[l - 1][0] - cnt[l - 1][4]);
	
	vvi pos(r - l - 1, vi(2));
	
	for (int i = l + 1; i < r; i++)
	{
		if (a[i] == -1 or a[i] == -2)
			pos[a[i] + 2].push_back(i);
	}
	
	if (pos[1] % 2 == 0) // remove -2
	{
		// remove start -2
		for (int i = 0; i < )
	}
}

void solve()
{
	int n; cin >> n;
	
	vi a(n + 2);
	vvi cnt(n + 2, vi(5));
	
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	
	vi zero;
	
	for (int i = 0; i <= n + 1; i++)
	{
		if (a[i] == 0)
			zero.push_back(i);
		cnt[i][a[i] + 2]++;
	}
			
	
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
/* credits: harasees_singh :maaf_karo:
*think brute force first.
*try proving the algorithm on pen n paper first.
*floating point precision errors ?
*implementation too lengthy ? logic might be incorrect.
*read the question again.
*/