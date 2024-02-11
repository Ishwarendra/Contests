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

const ll mod = 998244353;

long long binary_exponentiation(long long a, long long b, const long long mod = 998244353)
{
    long long ans = 1;
    while(b > 0)
    {
        if (b % 2 == 1)
            ans = (ans * a) % mod;
        b >>= 1;
        a = (a * a) % mod;  
    }

    return ans;
} 

ll inverse(ll n, const ll MOD)
{
	return binary_exponentiation(n, MOD - 2);
}

void solve()
{
	ll n; cin >> n;
	ll left = 1, right = min(n, 9LL);
	
	ll ans = 0;
	ll cnt = 1;
	ll cur_limit = 100;
	while(cnt <= n)
	{
		ll x = right - left + 1;
		
		int len = x;
		if (x % 2 != 0)
			ans += ((x % mod)*( (((x + 1)/2))% mod ))%mod;
		else
			ans += (((x/2) % mod)*((x + 1) % mod))%mod;
		
		cnt += x;
		left = right + 1;
		right = min(n, cur_limit - 1);
		
		cur_limit *= 10;
	}
	cout << (ans % mod) << "\n";
}

int main()
{
    FIO;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
}