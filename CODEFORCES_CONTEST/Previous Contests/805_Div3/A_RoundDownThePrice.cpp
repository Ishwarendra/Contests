#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

std::vector<int> a;

void solve()
{
    int m;
    std::cin >> m;

    int cost = 1e9;

    for (int i = 0; i < std::size(a); i++)
    {
        if (m >= a[i])
            cost = std::min(cost, m - a[i]);
    }

    std::cout << cost << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    long cur = 1L;
    for (int i = 0; i < 10; i++)
        a.push_back(cur), cur *= 10;

    int t = 1;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}