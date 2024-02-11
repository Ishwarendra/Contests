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

void printpr(vector<pii> &a)
{
	for(int i = 0; i < a.size(); i++)
		cout << a[i].first + 1 << " " << a[i].second + 1 << "\n";
}

void solve()
{
	int n; cin >> n;
	
	vi a(n), one;
	
	for(int i = 0; i < n; i++)
	{
		int x; cin >> x;
		a[i] = x % 2;
		
		if (a[i])
			one.push_back(i);
	}
	
	if (one.size() == 0)
	{
		cout << "-1\n";
		return;
	}
	
	int cur = 0;
	
	// Two sequencce 010101 or 101010
	// Case-1; 0101...
	vector<pii> ans1;
	bool possible1 = true;
	
	for(int i = 0; i < n; i++)
	{
		if (a[i] != cur)
		{
			if (one.size() == 1 and i == one[0])
			{
				possible1 = false;
				break;
			}
			
			else if (i == one[0])
				ans1.push_back({i, one[1]});
			else
				ans1.push_back({i, one[0]});
		}
		
		cur = 1 - cur;
	}
	
	// Case-2: 1010...
	vector<pii> ans2;
	
	cur = 1;
	bool possible2 = true;
	
	for(int i = 0; i < n; i++)
	{
		if (a[i] != cur)
		{
			if (one.size() == 1 and i == one[0])
			{
				possible2 = false;
				break;
			}
			else if (i == one[0])
				ans2.push_back({i, one[1]});
			else
				ans2.push_back({i, one[0]});
		}
		
		cur = 1 - cur;
	}
	
	
	if (possible1 and possible2)
	{
		if (ans1.size() <= ans2.size())
		{
			cout << ans1.size() << "\n";
			// printpr(ans1);
			for(auto i : ans1)
		{
			print(i.first, i.second);
		}
		}
		
		else
		{
			cout << ans2.size() << "\n";
			printpr(ans2);
		}
	}
	
	else if (possible1)
	{
		cout << ans1.size() << "\n";
		
	}
	
	else if (possible2)
	{
		cout << ans2.size() << "\n";
		printpr(ans2);
	}
	
	else
		cout << "-1\n";
}

int main()
{
    FIO;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
}