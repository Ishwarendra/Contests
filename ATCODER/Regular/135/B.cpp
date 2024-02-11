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

#define int long long

void solve()
{
	int n; cin >> n;

	vll s(n);

	for (auto &x : s) cin >> x;

	vll a(n + 2);

	for (int i = 3; i < n + 2; i++)
	{
		a[i] = a[i - 3] + s[i - 2] - s[i - 3];
	}

	int xmin = 0, ymin = 0, zmin = 0;
	
	for (int i = 3; i < n + 2; i += 3)
	{
		if (i < n + 2)
			xmin = min(xmin, a[i]);
		if (i < n + 1)
			ymin = min(ymin, a[i + 1]);
		if (i < n)
			zmin = min(zmin, a[i + 2]);
	}
	
	(xmin < 0 ? xmin *= -1 : xmin *= 1);
	(ymin < 0 ? ymin *= -1 : xmin *= 1);
	(zmin < 0 ? zmin *= -1 : xmin *= 1);
	
	int x = 0, y = 0, z = 0;
	// print(xmin, ymin, zmin);
	// x + y + z = s[0];
	if (xmin + ymin + zmin > s[0])
		cout << "No\n";
	else
	{
		cout << "Yes\n";
		x = xmin, y = ymin, z = s[0] - xmin - ymin;
		
		a[0] = x, a[1] = y, a[2] = z;
		
		for (int i = 3; i < n + 2; i += 3)
		{
			if (i < n + 2)
				a[i] += x;
			if (i < n + 1)
				a[i + 1] += y;
			if (i < n)
				a[i + 2] += z;
		}
		
		for(auto i : a)
			cout << i << " ";
		cout << "\n";
	}
}

int32_t main()
{
	FIO;
	int t = 1;
	// cin >> t;
	while (t--)
		solve();
}