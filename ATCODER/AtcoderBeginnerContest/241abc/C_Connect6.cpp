#include <bits/stdc++.h>
using namespace std;

#define FIO        ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define all(a)     ((a).begin()), ((a).end())
#define printarr   (v, start, end)for (int _i = (start); _i < (end); _i++) cout << (v[_i]) << " ";cout << "\n";
#define log(v)     for(auto __i = ((v).begin()); __i != ((v).end()); __i++) cout << *(__i) << " "; cout << "\n";
#define int        long long
#define fps(x, y)  fixed<<setprecision((y))<<(x)
#define print(args...){string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s);istream_iterator<string> _it(_ss);err(_it, args);cout<<"\n";};

using ll       =    long long;
using vi       =    vector<int>;
using vvi      =    vector<vector<int>>;
using ld       =    long double;
using pii      =    pair<int, int>;
using mii      =    map<int, int>;
using umii     =    unordered_map<int, int>;
using maxheap  =    priority_queue<int>;
using minheap  =    priority_queue<int, vector<int>, greater<int>>;

void err(istream_iterator<string> it){};
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cout << a << " ";
    err(++it, args...);
};

void solve()
{
	int n; cin >> n;
	
	vector<string> grid(n);
	
	for(int i = 0; i < n; i++)
		cin >> grid[i];
	
	bool possible = false;
	
	// Horizontal
	for(int row = 0; row < n; row++)
	{
		int i = 0, j = 0;
		int count = 0;
		
		while(j < n)
		{
			if (grid[row][j] == '#')
				count++;
			
			if (j - i + 1 == 6)
			{
				if (count >= 4)
					possible = true;
				
				count -= (grid[row][i] == '#');
				i++;
			}
			
			j++;
		}
	}
	
	// Vertical
	for(int col = 0; col < n; col++)
	{
		int i = 0, j = 0;
		int count = 0;
		
		while(j < n)
		{
			if (grid[j][col] == '#')
				count++;
							
			if (j - i + 1 == 6)
			{
				if (count >= 4)
					possible = true;
				count -= (grid[i][col] == '#');
				i++;
			}
			
			j++;
		}
	}
	
	// Diagonal
	for(int i = 0; i < n - 5; i++)
	{
		for(int j = 0; j < n - 5; j++)
		{
			// 6 * 6 (i,j) (i, j + 6) (i + 6, j) (i + 6, j + 6)
			int count_right = 0, count_left = 0;
			
			int x = i, y = j;
			
			for(int _ = 0; _ < 6; _++)
			{
				// assert(y + 5 - _ < n);
				
				count_right += grid[x + _][y + _] == '#';
				count_left += grid[x + _][y + 5 - _] == '#';
			}
			
			if (count_left >= 4 or count_right >= 4)
			{
				// for(int r = i; r < i + 6; r++)
				// {
				// 	for(int c = j; c < j + 6; c++)
				// 		cout << grid[r][c];
				// 	cout << "  n\n";
				// }
				possible = true;
			}
		}
	}
	
	if (possible)
		cout << "Yes\n";
	else
		cout << "No\n";
}

int32_t main()
{
	FIO;
	int t = 1; 
	// cin >> t;
	while(t--)
		solve();
	
	return 0;
}