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

constexpr int inf = 1e18;

void solve()
{
	int n, x; cin >> n >> x;
	
	vi a(n);
	
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	
	// where to place 1 and where to place x 
	// go for first step
	// find place for lower and upper limit if doesn't exist
	// a >= i >= b and we place i between a and b then value remains unaffected
	// a <= i <= b and we place i between a and b then value changes to (a + b - 2 * i) 
	
	int lower = *min_element(all(a));
	int upper = *max_element(all(a));
	
	int u = 0, l = 0;
	
	std::function<int(int, int)> get = [&](int low, int high)
	{
		int ans = inf;
		
		// place at beg
		ans = min({ans, abs(high - a[0]), abs(low - a[0])});
		
		// print("beg:", ans);
		
		// place at middle separated
		for (int i = 1; i < n; i++)
		{
			ans = min({ans, abs(high - a[i]) + abs(low - a[i - 1]), 
				abs(low - a[i]) + abs(high - a[i - 1])});
		}
		// print("mid", ans)
		
		// place at middle close
		for (int i = 0; i < n; i++)
			ans = min(ans, abs(a[i] - high) + abs(low - a[i]));
		
		
		//place at end
		ans = min({ans, abs(high - a.back()), abs(low - a.back())});
		// print("end:", ans);
		
		return ans + high - low;	
	};
	
	int ans = 0;
	
	for (int i = 1; i < n; i++)
		ans += abs(a[i] - a[i - 1]);
	
	if (lower > 1)
		l = get(1LL, min(x, lower));
	
	if (upper < x)
		u = get(max(upper, 1LL), x);
	// print(u, l);
	cout << ans + u + l << "\n";
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