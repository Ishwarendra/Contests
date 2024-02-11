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
	vi a(n);
	for(auto &x : a)
		cin >> x;
	
	vi prefmax(n), suffmin(n);
	prefmax[0] = a[0];
	suffmin[n - 1] = a[n - 1]; 
	
	for(int i = 1; i < n; i++)
	{
		prefmax[i] = max(a[i], prefmax[i - 1]);
	}
	
	for(int i = n - 2; i >= 0; i--)
	{
		suffmin[i] = min(a[i], suffmin[i + 1]);
	}
	
	bool possible = false;
	
	for(int i = 0; i < n - 1; i++)
	{
		if (prefmax[i] > suffmin[i + 1])
			possible = true;
	}	
	
	cout << (possible ? "YES\n" : "NO\n");
}

int main()
{
    FIO;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
}