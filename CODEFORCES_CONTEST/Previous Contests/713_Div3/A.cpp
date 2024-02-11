#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::map<int, int> m;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i)  
    {
        std::cin >> a[i];
        m[a[i]]++;
    }

    for (auto [num, f] : m)
    {
        if (f == 1)
        {
            for (int i = 0; i < n; i++)
            {
                if (a[i] == num)
                {
                    std::cout << i + 1 << "\n";
                    return;
                }
            }
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}