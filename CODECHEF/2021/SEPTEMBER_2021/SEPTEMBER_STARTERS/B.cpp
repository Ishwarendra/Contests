#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;

void solve()
{
    int n;
    cin >> n;

    if (n & 1)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if (i == j)
                    cout << 1 << " ";
                else    
                    cout << -1 << " ";
            }
            cout << "\n";
        }
    }

    else
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
                cout << -1 << " ";
            cout << "\n";
        }
        return;
    }
}

int main()
{
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}