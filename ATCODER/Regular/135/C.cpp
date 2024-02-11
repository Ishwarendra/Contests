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

int getBit(ll x, int pos)
{
	return (x >> pos) & 1;
}

void solve()
{
	ll n; cin >> n;
	vll a(n);
	
	for(auto &x : a) cin >> x;
		
	sort(all(a));

	vi cnt[30];
	
	for(int i = 0; i < n; i++)
	{
		vi tmp(31);
		for(int j = 0; j < 31; j++)
		{
			tmp.push_back(getBit(a[i], j));
		}
	}
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < 31; j++)
		{
			for(int k = 0; k < n; k++)
			{
				if (getBit(a[k], j) and not getBit(a[i], j))
					a[i] ^= a[k];
			}
		}
	}
	
	ll sum = 0;
	for(auto &x : a)
		sum += x;
	
	cout << sum << "\n";
}

int main()
{
    FIO;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
}