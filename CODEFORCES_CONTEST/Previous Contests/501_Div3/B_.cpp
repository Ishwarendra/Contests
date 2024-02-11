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
void err(istream_iterator<string> it){};
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{cout << a << " "; err(++it, args...);};

constexpr int inf = 7e18;

void solve()
{
	int n; string s, t;
	cin >> n >> s >> t;
	
	vi cnts(26), cntt(26);
	
	for (int i = 0; i < n; i++)
	{
		cnts[s[i] - 'a']++;
		cntt[t[i] - 'a']++;
	}
	
	if (cnts != cntt)
		cout << "-1\n";
	else
	{
		vi steps, vis(n);
		
		for (int i = 0; i < n; i++)
		{
			char to_find = t[i];
			
			if (s[i] == to_find)
				continue;
			
			for (int j = i + 1; j < n; j++)
			{
				// find to_find in s and bring it to i-th position
				if (s[j] == to_find)
				{
					for (int k = j - 1; k >= i; k--)
					{
						steps.push_back(k);
						swap(s[k], s[k + 1]);
					}
					
					break;
				}
			}
		}
		assert(s == t and steps.size() <= 1e4);
		
		cout << steps.size() << "\n";
		
		for (int i : steps)
			cout << i + 1 << " "; cout << "\n";
	}
}

int32_t main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int t = 1;
	// std::cin >> t;
	
	for(int i = 1; i <= t; i++)
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