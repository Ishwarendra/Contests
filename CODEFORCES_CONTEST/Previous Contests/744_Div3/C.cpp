#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;

bool positive(int a, int b, int c)
{
    return (a >= 0 and b >= 0 and c >= 0);
}

bool painted(char a, char b)
{
    return (a == '*') and (b == '*');
}

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<string> grid;
    for (int i = 0; i < n; i++)
    {
        string tmp;
        cin >> tmp;
        grid.push_back(tmp);
    }

    set<pair<int, int>> visited;
    set<pair<int, int>> old;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '*')
            {
                visited.insert({i, j});
                int x1 = i - 1, y1 = j - 1, x2 = i - 1, y2 = j + 1;
                int cnt = 0;
                // check i++, j++ and i--, j-- if they are star and reaches threshold then add in visited set
                while (positive(x1, x2, y1) and y2 < m and painted(grid[x1][y1], grid[x2][y2]))
                    cnt++, visited.insert({x1, y1}), visited.insert({x2, y2}), x1--, y1--, x2--, y2++;

                if (cnt < k) // revert back
                    visited = old;
                else // update old
                    old = visited;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '*' and visited.find({i, j}) == visited.end())
            {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}