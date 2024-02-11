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


vi preprocess(string &a, string &b)
{
	int n = a.length();
	
	vi inc(n);
	
	for(int i = 0; i < n; i++)
		inc[i] =  (b[i] - a[i] + 26) % 26;
	
	return inc;
}

vi get_alternate_diff(vi &inc, int sign = 1)
{
	int n = inc.size();
	
	vi alt_diff(n);
	
	for(int i = 0; i < n; i++)
	{
		alt_diff[i] = sign * inc[i];
		sign *= -1;
	}
	
	return alt_diff;
}

void solve()
{
	int n, q;
	string a, b;
	
	cin >> n >> q >> a >> b;
	
	vi inc = preprocess(a, b);

	vi diff(n);
	diff[0] = inc[0];
		
	for(int i = 1; i < n; i++)
		diff[i] = inc[i] - diff[i - 1];
	
	// log(diff)
	
	while(q--)
	{
		int l, r;
		cin >> l >> r;
		
		l--, r--;
		
		if (l == r)
			cout << (a[l] == b[l] ? "Yes\n" : "No\n");
		else if (r - l == 1)
		{
			cout << (inc[r] == inc[l] ? "Yes\n" : "No\n");
		}
		else
		{
			int sign = (r - l + 1) % 2 ? 1 : -1;
			
			int ans = diff[r] + sign * (l - 1 >= 0 ? diff[l - 1] : 0);
			
			if (ans % 26 == 0)
				cout << "Yes\n";
			else
			{
				// print(ans)
				cout << "No\n";
			}
		}
	}
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