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

template<typename T>
using pbds     =    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
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

void solve()
{
	int n; cin >> n;

	vi odd, even;

	for (int i = 0; i < n; ++i)
	{
		int x; cin >> x;

		if (x % 2)
			odd.push_back(x);
		else
			even.push_back(x);
	}

	if (even.empty() and (odd.size() % 2 == 1))
		std::cout << "-1\n";
	else if (even.empty() and odd.size() % 2 == 0)
	{
		for (int i : even)
			std::cout << i << " ";
		for (int i : odd)
			std::cout << i << " ";

		std::cout << "\n";
	}
	else if (odd.empty() or odd.size() == 1)
		std::cout << "-1\n";
	else
	{
		if (odd.size() % 2 == 0)
		{
			for (int i : even)
				std::cout << i << " ";
			for (int i : odd)
				std::cout << i << " ";

			std::cout << "\n";
		}
		else
		{
			for (int i = 0; i < even.size() - 1; i++)
				std::cout << even[i] << " ";

			for (int i = 0; i < odd.size() - 1; i++)
				std::cout << odd[i] << " ";

			cout << even.back() << " " << odd.back() << "\n";
		}
	}
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