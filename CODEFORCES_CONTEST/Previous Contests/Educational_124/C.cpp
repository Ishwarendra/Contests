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

int get_min_diff(int x, vi &a)
{
	int minimum = 1e16;
	
	for(int i = 0; i < a.size(); i++)
		minimum = min(minimum, abs(x - a[i]));
	
	return minimum;
}

void amin(int &a, int b)
{
	a = min(a, b);
}

void solve()
{
	int n; cin >> n;
	
	vi a(n), b(n);
	
	for(int i = 0; i < n; i++)
		cin >> a[i];
	
	for(int i = 0; i < n; i++)
		cin >> b[i];
	
	int mini1 = get_min_diff(a[0], b);
	int mini2 = get_min_diff(a[n - 1], b);
	int mini3 = get_min_diff(b[0], a);
	int mini4 = get_min_diff(b[n - 1], a);
	
	// Case-1
	int sum = abs(a[0] - b[0]) + abs(a[n - 1] - b[n - 1]);
	
	// Case-2
	amin(sum, abs(a[0] - b[n - 1]) + abs(a[n - 1] - b[0]));
	
	// Case-3
	amin(sum, abs(a[0] - b[0]) + mini2 + mini4);
	
	// Case-4
	amin(sum, abs(a[0] - b[n - 1]) + mini2 + mini3);
	
	// Case-5
	amin(sum, abs(a[n - 1] - b[0]) + mini1 + mini4);
	
	// Case-6
	amin(sum, abs(a[n - 1] - b[n - 1]) + mini1 + mini3);
	
	// Case-7
	amin(sum, mini1 + mini2 + mini3 + mini4);
	
	std::cout << sum << "\n";
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