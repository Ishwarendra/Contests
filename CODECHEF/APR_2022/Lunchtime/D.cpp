#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define all(a)      ((a).begin()), ((a).end())
#define log(v)      for(auto __i = ((v).begin()); __i != ((v).end()); __i++) cout << *(__i) << " "; cout << "\n";
#define int         long long
#define fps(x, y)   fixed<<setprecision((y))<<(x)

#define printarr(v, start, end) for(int _i = (start); _i < (end); _i++) cout << (v[_i]) << " ";cout << "\n";
#define print(args...){string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s);istream_iterator<string> _it(_ss);err(_it, args);cout<<"\n";};

using ll       =    long long;
using vi       =    vector<int>;
using vvi      =    vector<vector<int>>;
using ld       =    long double;
using pii      =    pair<int, int>;
using mii      =    map<int, int>;
using umii     =    unordered_map<int, int>;
using pbds     =    tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

template<typename T>
using maxheap  =    priority_queue<T>;
template<typename T>
using minheap  =    priority_queue<T, vector<T>, greater<T>>;

template<typename T1, typename T2> istream &operator >> (istream& in, pair<T1, T2> &a)
{in >> a.first >> a.second; return in;}
template<typename T1, typename T2> ostream &operator << (ostream& out, pair<T1, T2> &a)
{out << a.first << " " << a.second; return out;}
void err(istream_iterator<string> it) {};
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{cout << a << " "; err(++it, args...);};

map<int, int> primeFactors(int n)
{
	map<int, int> pf;

	while (n % 2 == 0)
	{
		// cout << 2 << " ";
		pf[2]++;
		n = n / 2;
	}

	for (int i = 3; i <= sqrt(n); i = i + 2)
	{
		while (n % i == 0)
		{
			// cout << i << " ";
			pf[i]++;
			n = n / i;
		}
	}

	if (n > 2)
		pf[n]++;
	// cout << n << " ";

	return pf;
}

constexpr int MOD = 7e18;

template<class T>
T power(T a, int b, int mod = MOD) {
	T res = 1;
	for (; b; b /= 2, a = (a * a) % mod) {
		if (b % 2) {
			res = (res % mod) * (a % mod) % mod;
		}
	}
	return (res % mod);
}

int g(int a, int b)
{
	return __gcd(a, b);
}

int l(int a, int b)
{
	return (a * b) / g(a, b);
}

void solve()
{
	int x, c;
	cin >> x >> c;

	if (c == 1 or x == 1)
	{
		cout << "1\n";
		return;
	}

	map<int, int> m = primeFactors(x);
	
	int loss = 1;
	
	for (auto i : m)
	{
		int num = i.first, raised = i.second;
		raised %= c;
		// c = 4
		// 2*3 -> either 2*0 with loss of 2**3 else 2*4 with loss of 2**1
		
		loss *= power(num, min(raised, c - raised));
	}
	
	cout << loss << "\n";
}

int32_t main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t = 1;
	std::cin >> t;

	for (int i = 1; i <= t; i++)
	{
		// std::cout << "Case #" << i << ": ";
		solve();
	}

	return 0;
}
/* credits: harasees_singh :maaf_karo:
*think brute force first.
*try proving the algorithm on pen n paper first.
*floating point precision errors ?
*implementation too lengthy ? logic might be incorrect.
*read the question again.
*/