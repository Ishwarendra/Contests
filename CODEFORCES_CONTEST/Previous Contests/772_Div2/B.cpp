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

bool maxima(vi &a, int i)
{
	int n = a.size();
	if (i <= 0 or i >= n - 1)
		return false;
	
	return (a[i] > a[i - 1] and a[i] > a[i + 1]);
}

void solve()
{
	int n; cin >> n;
	
	vi a(n);
	
	for(auto &x: a)
		cin >> x;
	
	int m = 0;
	
	for(int i = 0; i < n - 1; i++)
	{
		if (maxima(a, i))
		{
			m++;
			a[i + 1] = a[i];
			if (i + 2 < n)
				a[i + 1] = max(a[i + 1], a[i + 2]);
		}
	}
	
	print(m);
	log(a);
}

int32_t main()
{
    FIO;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
}