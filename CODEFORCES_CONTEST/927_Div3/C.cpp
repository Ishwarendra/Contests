#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, m;
    std::cin >> n >> m;

    const int mod = m;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)  
        std::cin >> a[i];

    std::string s;
    std::cin >> s;
    int st = 0, en = n - 1;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'L')
            st++;
        else
            en--;
    }

    int prod = 1;
    std::vector<int> ans(n);
    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] == 'L')
        {
            st--;
            prod = (prod * a[st]) % mod;
        }
        else
        {
            en++;
            prod = (prod * a[en]) % mod;
        }

        ans[i] = prod;
    }

    for (int i = 0; i < n; i++)
        std::cout << ans[i] << " \n"[i == n - 1];
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}