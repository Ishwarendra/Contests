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

int getBit(int num, int i)
{
	return ((num & (1 << i)) != 0);
}

int setBit(int num, int i)
{
	return (num | (1 << i));
}

int clearBit(int n, int k)
{
    return (n & (~(1 << (k))));
}

int third(int a, int b)
{
	int tmp = b;
	bool big = false;
	for(int i = 26; i >= 0; i--)
	{
		if (getBit(a, i) == 1 and getBit(b, i) == 1)
			continue;
		
		if (getBit(a, i) == 1){
			tmp = setBit(tmp, i);
			// print("A", tmp, i);
			big = true;
		}
		
		else if (big)
		{
			tmp = clearBit(tmp, i);	
			// print("B", tmp);
		}
		
		// if (getBit(a, i) == 0 and getBit(b, i) == 1){
		// 	big = true;
		// }
	}
	// print(tmp);
	int ans = tmp - b + 1;
	// print(tmp, b)
	return ans;
}

int fourth(int a, int b)
{
	// b ke jaise 1-bits a me
	int tmp = a;

	for(int i = 26; i >= 0; i--)
	{
		if (getBit(b, i) == 1)
			tmp = setBit(tmp, i);
		else if (tmp > b and getBit(b, i) == 0)
			tmp = clearBit(tmp, i);
	}
	
	int ans = tmp - b;
	ans += (tmp - a);
	return ans;
}

void solve()
{
	int a, b;
	cin >> a >> b;
	
	int ans1 = (a | b) - b + 1;
	int ans2 = (b - a);
	int ans3 = third(a, b);
	int ans4 = 1e9;
	// print(ans1, ans2, ans3, ans4);
	cout << min({ans1, ans2, ans3, ans4}) << "\n";
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