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
	int n, k; cin >> n >> k;
	
	vi a(n);
	
	for(int i = 0; i < n; i++)
		a[i] = i + 1;
	
	int destroy = n - k;
	
	int swapPos = 1, possible = 1;
	
	while(destroy != 0 and destroy != 1)
	{
		if (swapPos + 1 >= n)
		{
			possible = 0;
			break;	
		}
		
		swap(a[swapPos], a[swapPos + 1]);
		destroy -= 2;
		swapPos += 2;
	}
	
	if (not possible)
	{
		cout << "-1\n";
	}
	
	else if (destroy == 0)
	{
		log(a);
	}	
	
	else
	{
		swap(a[0], a[swapPos]);
		log(a);
	}
}

int32_t main()
{
    FIO;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
}