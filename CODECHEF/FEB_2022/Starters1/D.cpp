#pragma GCC optimize("O3")

#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define all(a) ((a).begin()), ((a).end())
#define printarr(v, start, end)for (int _i = (start); _i < (end); _i++) cout << (v[_i]) << " ";cout << "\n";
#define log(v) for(auto __i = ((v).begin()); __i != ((v).end()); __i++) cout << *(__i) << " "; cout << "\n";
#define print(args...){string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s);istream_iterator<string> _it(_ss);err(_it, args);cout<<"\n";};

using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<long long>;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
using ull = unsigned long long;

void err(istream_iterator<string> it){};
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cout << a << " ";
    err(++it, args...);
};

ll countDivisors(ll n, ll x)
{
    ll cnt = 0;
    
    for (int i = 2; i*i <= n; i++) {
        if (n % i == 0) {
        	
            if (n / i == i)
                cnt += i;
 
            else 
                cnt += (i + n/i);
            
            if (cnt > x)
            	return 1e9;
        }
    }
    return cnt;
}


void solve(int t)
{
	ll x, a, b;
	cin >> x >> a >> b;
	
	ll num = x*b;
	ll den = a;
	
	int possible = 1;
	
	if (num % den != 0)
		cout << "-1\n";
	else
	{
		ll n = num/den;
		ll c = 0;
		
		for(int i = 1; i*i <= n; i++)
		{
			if (n % i == 0)
			{
				if (n/i != i)
					c += n/i;
				c += i;
			}
			
			if (c > x)
			{
				cout << "-1\n";
				return;
			}
		}
		
		if (c == x)
			cout << n << "\n";
		else
			cout << "-1\n";
	}
}

int main()
{
    FIO;
    int t = 1;
    cin >> t;
    while(t--)
        solve(t);
}