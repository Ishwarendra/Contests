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
	int n, m;
	cin >> n >> m;
	
	vector<string> grid(n);
	
	for (int i = 0; i < n; ++i)
		cin >> grid[i];
	
	vector<vector<int>> vis(n, vi(m));
	vector<vector<int>> ans;
	
	auto bound = [&](int i, int j)
	{
		return i >= 0 and j >= 0 and i < n and j < m;
	};
	
	auto perform_op = [&](int i, int j)
	{
		// up down left right
		vi cnt(4);
		
		int x = i - 1, y = j - 1;
		
		while (x >= 0 and grid[x][j] == '*')
			cnt[0]++, x--;
		
		x = i + 1;
		
		while (x < n and grid[x][j] == '*')
			cnt[1]++, x++;
		
		while (y >= 0 and grid[i][y] == '*')
			cnt[2]++, y--;
		
		y = j + 1;
		while (y < m and grid[i][y] == '*')
			cnt[3]++, y++;
		
		int size = *min_element(all(cnt));
		
		if (size == 0)
			return;
		
		vis[i][j] = 1;
		
		x = i, y = j;
		
		for (int up = 1; up <= size; up++)
			vis[x - up][j] = 1;
		
		for (int down = 1; down <= size; down++)
			vis[x + down][j] = 1;
		
		for (int left = 1; left <= size; left++)
			vis[i][j - left] = 1;
		
		for (int right = 1; right <= size; right++)
			vis[i][j + right] = 1;
		
		ans.push_back({i, j, size});
		return;
	};
	
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (grid[i][j] == '*')
			{
				// check if you can make a star 
				//considering it to be central star
				perform_op(i, j);
			}
		}
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (grid[i][j] == '*' and !vis[i][j])
			{
				cout << "-1\n";
				return;
			}
			
		}
	}
	
	cout << ans.size() << "\n";
	
	for (auto i : ans)
		cout << i[0] + 1 << " " << i[1] + 1 << " " << i[2] << '\n';
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