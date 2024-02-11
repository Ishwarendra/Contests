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

vector<char> cols {'R', 'G', 'B'};

int get_idx(char ch)
{
	if (ch == 'R')
		return 0;
		
	return (ch == 'G' ? 1 : 2);	
}

int get_col(int x, int y)
{
	if (x == y)
		return (x + 1)%3;
	else
		return 3 - x - y;
}

void solve()
{
	int n; string s;
	cin >> n >> s;
	
	int ans = 0;
	
	for(int i = 1; i < n; i++)
	{
		// Need to change
		if (s[i] == s[i - 1])
		{
			ans++;	
			int cur_col = get_idx(s[i]);
			if (i + 1 < n)
			{
				int next_col = get_idx(s[i + 1]);
				s[i] = cols[get_col(cur_col, next_col)];
			}
			else
				s[i] = cols[(cur_col + 1) % 3];
		}
	}
	
	print(ans);
	print(s);
}

int main()
{
    FIO;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
}