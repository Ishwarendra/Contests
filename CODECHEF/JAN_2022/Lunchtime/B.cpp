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

int good(int mid, string &s)
{
	int cur_sum = 0;
	for(int i = mid; i >= 0; i--)
	{
		int cur = s[i] - '0';
		if (cur == 0)
			continue;
		cur = (cur + cur_sum) % 10;
		cur_sum += (10 - cur);  
	}
	return cur_sum;	
}

// right to left TLE
// try moving left to right

void solve()
{
	int n, k;
	cin >> n >> k;

	string a;
	for(int i = 0; i < n; i++)
	{
		char ch; cin >> ch;
		int cur = 10 - (int)(ch - '0'); 
		a += (char)('0' + cur);
	}
	
	int prev = (a[0] - '0')%10; 
	int ans = prev;

	int id = 0;
	for(int i = 1; i < n; i++)
	{
		if (ans > k)
			break;
		
		int cur = (a[i] - '0') % 10;
		if (prev - cur < 0)
			ans += 10;
		
		prev = cur;
		id++;
	}
	
	if (ans <= k)
		id++;
	
	cout << id << "\n";
}

int32_t main()
{
    FIO;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}