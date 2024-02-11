#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;
using ull = unsigned long long;

void solve()
{
    ull x; cin >> x;
    ull left = 0, right = x;
    ull ans = 0;
    while(left < right)
    {
        ull n = left + (right - left)/2;
       
        if (n*(n + 1)*(n + 2) <= 6*x)
        {
            ans = n;
            left = n + 1;
        }
        else
            right = n - 1;
    }   
    cout << ans << "\n";
}

int main()
{
    int t = 1;
    cin >> t;
    while(t--)
          solve();
    return 0;
}