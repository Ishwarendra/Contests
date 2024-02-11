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

void solve()
{
	int n; string s;
	cin >> n >> s;
	
	set<pii, greater<pii>> st; 
	vi cnt(26);
	
	for(char ch : s)
		cnt[ch - 'a']++;
	for(int i = 0; i < 26; i++)
	{
		if (cnt[i])
			st.insert({cnt[i], i});
	}
	
	if (n % 2 == 1)
	{
		cout << "NO\n";
		return;
	}
	
	// Pick two max and place in answer
	vector<char> ans(n, '!');

	for(int i = 0; i < n/2; i++)
	{
		if (st.size() < 2)
			break;
		
		else
		{
			pii cur = *(st.begin()), next = *(++st.begin());
			st.erase(cur), st.erase(next);
			
			ans[i] = (char)(cur.second + 'a');
			ans[n - i - 1] = (char)(next.second + 'a');
			
			// print(ans[i], ans[n - i - 1]);
			
			cur.first--, next.first--;
			if (cur.first != 0)
				st.insert(cur);
			if (next.first != 0)
				st.insert(next);
		}			
	}
	
	int start = 0, end = n - 1;
	int possible = 1;
	while(start <= end)
	{
		if (ans[start] == ans[end] or ans[start] == '!' or ans[end] == '!')
			possible = 0;
		start++, end--;
	}
	
	if (possible)
	{
		cout << "YES\n";
		for(char ch : ans)
			cout << ch;
		
		cout << "\n";
	}
	else
		cout << "NO\n";
}

int main()
{
    FIO;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
}