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
	ld x1, y1, x2, y2, x3, y3;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	
	int int_points = 0;
	
	int m1 = (y2 - y1);
	int m2 = (y3 - y1);
	int m3 = (y3 - y2);
	// print(m1, m2, m3);
	if (m1 != 0 and m2 != 0 and m3 != 0)
		cout << "0\n";
	else
	{
		if (m2 == 0)
			swap(m1, m2), swap(x3, x2), swap(y2, y3);
		if (m3 == 0)
			swap(m1, m3), swap(x1, x3), swap(y1, y3);
		
		// x1 y1, x2 y2
		if (y3 > y1)
			cout << "0\n";
		else
		{
			ld ans = (x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1);
			ans = sqrt(ans);
			cout << fps(ans, 9) << "\n";
		}
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