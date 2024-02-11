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

int n, m;
set<int> cols;
vi dx {1, -1, 0, 0};
vi dy {0, 0, 1, -1};

bool bound(int i, int j)
{
	return i >= 0 and i < n and j >= 0 and j < m;
}

bool uncolored(vvi &col, int i, int j, int c)
{
	if (col[i][j] != 0)
		return false;

	for (int k = 0; k < 4; k++)
	{
		int x = i + dx[k];
		int y = j + dy[k];

		if (bound(x, y) and col[x][y] == c)
			return false;
	}

	return true;
}

void solve()
{
	cin >> n >> m;

	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;

	x1--, x2--, y1--, y2--;

	vvi col1(n, vi(m)), col2(n, vi(m));

	col1[x1][y1] = 1, col1[x2][y2] = 2;
	col2[x1][y1] = 1, col2[x2][y2] = 2;

	queue<pii> q;
	q.emplace(x1, y1);
	q.emplace(x2, y2);

	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();

		int x = cur.first, y = cur.second;

		for (int k = 0; k < 4; k++)
		{
			int x_n = x + dx[k], y_n = y + dy[k];

			if (bound(x_n, y_n) and not col1[x_n][y_n])
			{
				for (int c : cols)
				{
					if (uncolored(col1, x_n, y_n, c)) {
						col1[x_n][y_n] = c;
						q.emplace(x_n, y_n);
						break;
					}
				}
			}
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (col2[i][j] == 0)
			{
				for (int c : cols)
				{
					if (uncolored(col2, i, j, c)) {
						col2[i][j] = c;
						break;
					}
				}
			}
		}
	}

	set<int> col1_cnt, col2_cnt;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			col1_cnt.insert(col1[i][j]);
			col2_cnt.insert(col2[i][j]);
		}
	}

	if (col1_cnt.size() <= col2_cnt.size())
	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				cout << col1[i][j] << " ";
			}
			cout << "\n";
		}
	}
	else
	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				cout << col2[i][j] << " ";
			}
			cout << "\n";
		}
	}
}

int32_t main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t = 1;
	std::cin >> t;

	for (int i = 1; i <= 100; i++)
		cols.insert(i);

	for (int i = 1; i <= t; i++)
	{
		// std::cout << "Case #" << i << ": ";
		solve();
	}

	return 0;
}