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
	int n; cin >> n;
	
	string a; cin >> a;
	
	if (a.back() == '0' or a[1] == '0' or a[0] == '0')
	{
		cout << "NO\n";
		return;
	}
	
	vi ans(n), onePos;
	
	for(int i = 1; i <= n; i++)
	{
		if (a[i] == '1')
			onePos.push_back(i);
	}
	
	int pos = 0, zero = 0;
	
	for(int i = 1; i <= n; i++)
	{
		if (a[i] == '0')
			zero++;
		else if (a[i] == '1' and zero == 0)
		{
			ans[pos] = i - 1;
			pos++;
		}	
		else if (a[i] == '1')
		{
			ans[pos++] = i - 1;
			 
			while (zero != 0)
			{
				ans[pos] = ans[pos - 1] - 1;
				pos++;
				zero--;
			}
		}
		
		// cout << i << " : ";
		// log(ans);
	}
	print("YES");
	log(ans);
}

int32_t main()
{
    FIO;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
}