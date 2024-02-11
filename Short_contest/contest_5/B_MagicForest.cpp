#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;
using ull = unsigned long long;

void solve()
{
    int n; cin >> n;
    int count = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = i; j <= n; j++)
        {
            int tmpxor = i ^ j;
            if ((tmpxor >= j) and (tmpxor <= n) and (tmpxor < i + j))
                count++;
        }
    }

    cout << count << "\n";
}

int main()
{
    FIO;
    int t = 1;
    // cin >> t;
    while(t--)
          solve();
    return 0;
}