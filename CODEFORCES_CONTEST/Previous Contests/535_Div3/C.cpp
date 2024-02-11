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

bool checky(vi &a)
{
	for(int i = 1; i < a.size(); i++)
	{
		if ((a[i] - a[i - 1]) % 3 != 0)
			return false;
	}
	
	return true;
}

// 6-patterns (Find min of 6)

void solve()
{
	int n; string s;
	cin >> n >> s;
	
	// 6-options
	string pat = "BGR";
	string best_pat;
	int ans = 1e9;
	do
	{
		int cur = 0;
		for	(int i = 0; i < n; i++)
		{
			if (s[i] != pat[i % 3])
				cur++;
		}
		
		if (cur < ans)
		{
			ans = cur;
			best_pat = pat;
		}
	}
	while (next_permutation(all(pat)));
	
	cout << ans << "\n";
	
	for(int i = 0; i < n; i++)
		cout << best_pat[i % 3];
	cout << "\n";
}

int main()
{
    FIO;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
}