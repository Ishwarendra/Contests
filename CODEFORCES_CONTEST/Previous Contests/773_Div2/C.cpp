#include <bits/stdc++.h>
using namespace std;

#define FIO        ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define all(a)     ((a).begin()), ((a).end())
#define printarr   (v, start, end)for (int _i = (start); _i < (end); _i++) cout << (v[_i]) << " ";cout << "\n";
#define log(v)     for(auto __i = ((v).begin()); __i != ((v).end()); __i++) cout << *(__i) << " "; cout << "\n";
#define int        long long
#define fps(x, y)  fixed<<setprecision((y))<<(x)
#define print(args...){string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s);istream_iterator<string> _it(_ss);err(_it, args);cout<<"\n";};

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
	int n, x; cin >> n >> x;
	
	multiset<int> a;
	
	for(int i = 0; i < n; i++)
	{
		int tmp; cin >> tmp;
		a.insert(tmp);
	}
	
	int ans = 0;
	
	if (x == 1)
	{		
		while(!a.empty())
		{
			int cur = *a.begin();
			
			if (a.count(cur) > 1)
			{
				a.erase(a.begin());
				a.erase(a.find(cur));
			}
			else
			{
				ans++;
				a.erase(a.begin());
			}
		}
		
		cout << ans << "\n";
		
		return;
	}
	
	while(!a.empty())
	{
		int cur = *a.begin();
		
		auto cur_broit = a.find(x * cur);
		
		if (cur_broit != a.end())
		{
			a.erase(cur_broit);
			a.erase(a.begin());
		}
		else
		{
			a.erase(a.begin());
			ans++;
		}
	}
	
	cout << ans << "\n";
}

int32_t main()
{
    FIO;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
}