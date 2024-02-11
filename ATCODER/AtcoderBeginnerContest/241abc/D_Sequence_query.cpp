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

void err(istream_iterator<string> it){};
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cout << a << " ";
    err(++it, args...);
};


void solve()
{
	int q; cin >> q;
	
	multiset<int> a;
	
	while(q--)
	{
		int type; cin >> type;
		
		if (type == 1)
		{
			int x; cin >> x;
			a.insert(x);
		}
		
		else if (type == 2)
		{
			int x, k; cin >> x >> k;
			
			auto it = a.upper_bound(x);
			
			while(it != a.begin() and k--)
				it--;
			
			if (it == a.begin() and k > 0)
				cout << "-1\n";
			else
				cout << *it << "\n";
		}
		
		else
		{
			int x, k; cin >> x >> k;
			
			auto it = a.lower_bound(x);
			
			k--;
			
			while(it != a.end() and k--)
				it++;
			
			if (it == a.end() and k >= 0)
				cout << "-1\n";
			else
				cout << *it << "\n";
		}
	}
}

int32_t main()
{
	FIO;
	int t = 1; 
	// cin >> t;
	while(t--)
		solve();
	
	return 0;
}