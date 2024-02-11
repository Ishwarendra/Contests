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

void err(istream_iterator<string> it){};
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cout << a << " ";
    err(++it, args...);
};

vi dp;

int operation(int x)
{
	if (x == 1)
		return 0;
	if (x == 2)
		return 1;
	
	
	int cnt = 0;
	int cur = 1;
	
	while(cur < x)
	{
		cnt++;
		cur *= 2;	
	}
	return cnt;
}

void preprocess()
{
	dp.resize(2010);
	fill(all(dp), 1e9);
	dp[0] = dp[1] = 0;
	
	for(int i = 1; i < 1005; i++)
	{
		for(int j = 1; j <= i; j++)
			dp[i + i/j] = min(1 + dp[i], dp[i + i/j]);
	}
	// for(int i = 7; i < 20; i++)
	// {
	// 	if (dp[i] != operation(i)){
	// 		print(i, dp[i], operation(i));
	// 	}
	// }
}

void solve()
{
	int n, k; cin >> n >> k;
	
	vi b(n), c(n);
	
	for(int i = 0; i < n; i++)
	{
		cin >> b[i];
	}	
	
	for(int i = 0; i < n; i++)
		cin >> c[i];
	
	int f[k + 1]{};
	
	for(int i = 0; i < n; i++)
	{
		for(int j = k; j >= dp[b[i]]; j--)
		{
			f[j] = max(f[j], f[j - dp[b[i]]] + c[i]);
		}
	}
	
	cout << f[k] << "\n";
	
}

int main()
{
    FIO;
    preprocess();
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}