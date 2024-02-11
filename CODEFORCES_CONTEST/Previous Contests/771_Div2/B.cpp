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

void err(istream_iterator<string> it) {};
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

	for (int i = 0; i < n; i++)
		cin >> a[i];

	vi prefodd(n), prefeven(n);

	if (a[0] % 2)
		prefodd[0] = a[0];
	else
		prefeven[0] = a[0];

	for (int i = 1; i < n; i++)
	{
		if (a[i] % 2)
			prefodd[i] = max(prefodd[i - 1], a[i]);
		else
			prefeven[i] = max(prefeven[i - 1], a[i]);
	}

	for(int i = 1; i < n; i++)
	{
		prefodd[i] = max(prefodd[i], prefodd[i - 1]);
		prefeven[i] = max(prefeven[i], prefeven[i - 1]);
	}
	
	bool possible = true;

	for (int i = 1; i < n; i++)
	{
		if (a[i] % 2)
		{
			if (prefodd[i - 1] > a[i])
				possible = false;
		}
		else
		{
			if (prefeven[i - 1] > a[i])
				possible = false;
		}
	}
	

	
	if (possible) {
		print("YES");
	}
	else
		print("NO");
}

int main()
{
	FIO;
	int t = 1;
	cin >> t;
	while (t--)
		solve();
}