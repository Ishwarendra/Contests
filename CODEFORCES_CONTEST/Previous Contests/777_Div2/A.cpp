#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define all(a)     ((a).begin()), ((a).end())
#define log(v)     for(auto __i = ((v).begin()); __i != ((v).end()); __i++) cout << *(__i) << " "; cout << "\n";
#define int        long long
#define fps(x, y)  fixed<<setprecision((y))<<(x)

#define printarr(v, start, end) for(int _i = (start); _i < (end); _i++) cout << (v[_i]) << " ";cout << "\n";
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
using pbds     =    tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

template<typename T1, typename T2> istream &operator >> (istream& in, pair<T1, T2> &a)
{in >> a.first >> a.second; return in;}
template<typename T1, typename T2> ostream &operator << (ostream& out, pair<T1, T2> &a)
{out << a.first << " " << a.second; return out;}
void err(istream_iterator<string> it){};
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{cout << a << " "; err(++it, args...);};

void solve()
{
	int n; cin >> n;
	
	vi nums;
		
	int x1 = (n + 2)/3, y1 = (n - 1)/3;
	int x2 = (n - 2)/3, y2 = (n + 1)/3;
	int x3 = n/3, y3 = n/3;
	
	if (x1 + 2 * y1 == n)
	{
		while(x1 > 0 or y1 > 0)
		{
			if (x1 > 0)
				cout << 1;
			if (y1 > 0)
				cout << 2;
			
			x1--, y1--;
		}
	}
	
	else if (x2 + 2 * y2 == n)
	{
		while(x2 > 0 or y2 > 0)
		{
			if (y2 > 0)
				cout << 2;
			if (x2 > 0)
				cout << 1;
			
			x2--, y2--;
		}
	}
	
	else
	{
		while(x3 > 0 or y3 > 0)
		{
			if (y3 > 0)
				cout << 2;
			if (x3 > 0)
				cout << 1;
			
			x3--, y3--;
		}
	}
	
	cout << "\n";
}

int32_t main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int t = 1;
	cin >> t;
	
	for(int i = 1; i <= t; i++)
	{
		// cout << "Case #" << i << ": ";
		solve();
	}
	
	return 0;
}