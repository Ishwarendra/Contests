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

int dx[] {1, -1, 0, 0};
int dy[] {0, 0, 1, -1};

bool within_bound(int row1, int col1, int n)
{
     bool cond1 = (row1 >= 0 and col1 >= 0 and row1 < n and col1 < n);
     // bool cond2 = (row2 >= 0 and col2 >= 0 and row2 < n and col2 < n);
     return cond1;
}

void perform_op(vvi &grid, vvi &vis, int &ans, int row, int col)
{
     int n = grid.size();
     bool done = false;
     for(int i = 0; i < 4; i++)
     {
          if (within_bound(row + dx[i], col + dy[i], n)){
               if (vis[row + dx[i]][col + dy[i]])
                    return;
          }
     }

     for(int i = 0; i < 4; i++)
     {
          if (within_bound(row + dx[i], col + dy[i], n)){
               if (not done)
                    ans ^= grid[row][col], done = true;
               vis[row + dx[i]][col + dy[i]] = 1;
          }
     }
}

void solve()
{
     int n; cin >> n;
     vector<vi> grid(n, vi(n)), vis(n, vi(n));
     for(int i = 0; i < n; i++)
     {
          for(int j = 0; j < n; j++)
               cin >> grid[i][j];
     }

     int ans = 0;
     for(int i = 0; i < n; i++)
     {
          for(int j = 0; j < n; j++)
          {
               perform_op(grid, vis, ans, i, j);
          }
     }

     cout << ans << "\n";
     for(int i = 0; i < n; i++){
          log(vis[i]);
     }
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