#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;
using ull = unsigned long long;

bool possible(int x1, int y1, int x2, int y2, int a, int b)
{
    bool cond_1 = (x1 <= a and y1 <= b);
    bool cond_2 = (x2 <= a and y2 <= b);
    bool cond_3 = x1 + x2 <= a or y1 + y2 <= b;

    return (cond_1 and cond_2 and cond_3);
}

void solve()
{
    int n, a, b;
    cin >> n >> a >> b;

    vector<pair<int, int>> p(n);

    for(int i = 0; i < n; i++)
        cin >> p[i].first >> p[i].second;
    
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            int x1 = p[i].first, x2 = p[j].first, y1 = p[i].second, y2 = p[j].second;
            if (possible(x1, y1, x2, y2, a, b)) // swap none
            {
                ans = max(ans, x1*y1 + x2*y2);
            }
            else if (possible(x1, y1, y2, x2, a, b)) // swap second
            {
                ans = max(ans, x1*y1 + x2*y2);
            }

            else if (possible(y1, x1, x2, y2, a, b)) // swap first
            {
                ans = max(ans, x1*y1 + x2*y2);
            }
            else if (possible(y1, x1, y2, x2, a, b)) // swap both
            {
                ans = max(ans, x1*y1 + x2*y2);
            }
        }
    }

    cout << ans << "\n";

}

int main()
{
    int t = 1;
    // cin >> t;
    while(t--)
          solve();
    return 0;
}