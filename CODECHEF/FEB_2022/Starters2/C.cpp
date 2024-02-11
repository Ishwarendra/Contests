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

ll two_power_le(ll n)
{
	int res = 0;
	while((1 << res) <= n)
		res++;
	
	return --res;
}

bool power_of_two(int n)
{
	if (n == 0)
		return true;
	
	return (n & (n - 1)) == 0;
}

void solve()
{
	ll x, m; cin >> x >> m;
	
	if (m == 0)
		cout << "0\n";
	else
	{
		ll factor = (power_of_two(x) ? 1 : 2);
		ll y = two_power_le(x) + factor;
		ll ans = (y <= m);
		
		if (ans == 0)
		{
			cout << "0\n";
			return;
		}
		
		m -= (y);
		ans += max(m, 0LL);
		
		cout << ans << '\n';
	}
}

int main()
{
    FIO;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
}