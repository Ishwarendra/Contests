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

void solve()
{
	int n; cin >> n;
	
	vll a(n), parity(n);
	ll sum = 0LL, life = 0LL;
	int odd = 0;	
	bool only_1 = true;
	
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		
		if (i > 0 and i < n - 1)
		{
			if (a[i] > 1)
				only_1 = false;
			
			if (a[i] % 2 == 0)
				life += a[i]/2;
			else
				odd++;
			sum += a[i];
		}
	}
	
	ll ans = 0;
	
	if (odd == 0)
		cout << sum/2 << "\n";
	else if ((n - 2 == 1 and odd == 1) or only_1)
		cout << "-1\n";
	else
	{
		if (life > 0 and odd >= life*2)
			odd -= life*2, ans += life, life = 0;
		if (life > 0 and odd < life*2)
			ans += (odd + 1)/2, life -= (odd + 1)/2, odd = 0; 
		
		for(int i = 1; i < n - 1; i++)
		{
			if (a[i] % 2 == 1)
				life += (a[i] + 1)/2;
		}

		ans += life;
		
		cout << ans << "\n";
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