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

map<int, int> div_freq;
void remove_all_div(int y)
{
	div_freq[1]--, div_freq[y]--;

	for (int i = 2; i * i <= y; i++)
	{
		if (y % i == 0)
		{
			div_freq[i]--;

			if (i != (y / i))
				div_freq[y / i]--;
		}
	}
}

void solve()
{
	int n; cin >> n;

	vi divisors(n);

	for (int i = 0; i < n; i++)
	{
		cin >> divisors[i];
		div_freq[divisors[i]]++;
	}

	sort(all(divisors));
	// log(divisors)
	int y = divisors.back();
	
	remove_all_div(y);

	int x = 1;

	for (auto i : div_freq)
	{
		if (i.second != 0)
		{
			x = max(i.first, x);
		}
	}

	print(x, y)
}

int main()
{
	FIO;
	int t = 1;
	// cin >> t;
	while (t--)
		solve();
}