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

char f(int a)
{
	int offset = (a + 1) % 5;
	return 'a' + offset;
}

void solve()
{
	int n, m; string s, a;
	cin >> n >> m >> s >> a;

	int id = 0, i = 0;
	bool possible = true;

	while (i < m and id < n)
	{
		if (s[id] == a[i])
			id++, i++;
		else
			id++;
	}

	if (i == m)
		possible = false;

	if (!possible)
	{
		cout << "-1\n";
		return;
	}

	id = 0;

	for (i = 0; i < n; i++)
	{
		int cur_target = a[id] - 'a';

		if (s[i] == '?')
			s[i] = f(cur_target);
		else if (s[i] == a[id])
			id++;
	}

	id = 0, i = 0;

	cout << s << "\n";

	// for (int i = 1; i < m; i++)
	// {
	// 	auto start = lower_bound(all(pos[cur]), id);

	// 	if (start == pos[cur].end())
	// 	{
	// 		for (int j = id; j < n; j++)
	// 			if (s[j] == '?')
	// 				s[j] = f(cur);
	// 	}

	// 	auto end   = lower_bound(all(pos[s[i] - 'a']), start);
	// }
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