#include <bits/stdc++.h>
using namespace std;

#define FIO       ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define all(a)    ((a).begin()), ((a).end())
#define printarr  (v, start, end)for (int _i = (start); _i < (end); _i++) cout << (v[_i]) << " ";cout << "\n";
#define log(v)    for(auto __i = ((v).begin()); __i != ((v).end()); __i++) cout << *(__i) << " "; cout << "\n";
#define print(args...){string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s);istream_iterator<string> _it(_ss);err(_it, args);cout<<"\n";};

using vi   =  vector<int>;
using vvi  =  vector<vector<int>>;
using vll  =  vector<long long>;
using vvll =  vector<vector<long long>>;
using ll   =  long long;
using ld   =  long double;
using ull  =  unsigned long long;
using pii  =  pair<int, int>;
using pll  =  pair<long long, long long>;

void err(istream_iterator<string> it){};
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cout << a << " ";
    err(++it, args...);
};

int get_mex(vi &a, int st, int end)
{
	int ans = 0;
	vi tmp(101);
	for(int i = st; i < end; i++)
	{
		tmp[a[i]] = 1;
	}
	
	for(int i = 0; i < 101; i++)
	{
		if (tmp[i] == 0)
			return i;
	}
	
	return 100;
}

void solve()
{
	int n; cin >> n;
	vi a(n);
	
	// vvi pos(101);
	
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		// pos[a[i]].push_back(i);
	}
	

	int ans = 0;
	
	for(int len = 1; len <= n; len++)
	{
		for(int i = 0; i < n - len + 1; i++)
		{
			int j = (i + len);
			
			ans += len;
			
			for(int k = i; k < j; k++)
			{
				ans += (a[k] == 0);	
				// print(len, k, a[k] == 0);
			}
		}
		
		// print(len, ans);
	}
	
	cout << ans << "\n";
}

int main()
{
    FIO;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
}