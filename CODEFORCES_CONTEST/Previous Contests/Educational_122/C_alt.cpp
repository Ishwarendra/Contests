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

ll Hc, Dc, Hm, Dm;

int good(ll mid)
{
	ll charHealth = (Hc/Dm - (mid - 1));
	ll monsHealth = (Hm/Dc - mid);
	
	if (charHealth > 0 and monsHealth > 0){
		// print(charHealth, monsHealth, mid);
		return 1;
	}
	if (charHealth < 0 and monsHealth < 0)
		return 2;
	if (charHealth > 0 and monsHealth > 0)
		return 3;
	else{
		return 4;
	}
}

void solve()
{
	ll hc, dc, hm, dm;
	cin >> hc >> dc >> hm >> dm;
	
	// k coin w attack beware a health
	ll k, w, a;
	cin >> k >> w >> a;
	
	bool possible = false;
	
	for(int i = 0; i <= k; i++)
	{
		Hc = hc + a*i;
		Dc = dc + (k - i)*w;
		Hm = hm, Dm = dm;
		
		possible = false;
		
		ll left = (Hm + Dc - 1)/Dc;
		ll right = (Hc % Dm == 1 ? Hc/Dm + 1 : (Hc + Dm - 1)/Dm);
		
		// print(left, right);
		if (left <= right)
			possible = true;
		
		if (possible)
		{
			cout << "YES\n";
			return;
		}
	}
	
	if (possible)
		cout << "YES\n";
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
    return 0;
}