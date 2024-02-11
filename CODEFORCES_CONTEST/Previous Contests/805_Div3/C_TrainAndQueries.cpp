#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

void solve()
{
    int n, k;
    std::cin >> n >> k;

    std::map<int, int> focc, locc;

    std::vector<int> u(n);
    for (int i = 0; i < n; ++i)  
    {
        std::cin >> u[i];
        if (focc.find(u[i]) == std::end(focc))
            focc[u[i]] = locc[u[i]] = i + 1;
        else
            locc[u[i]] = i + 1;
    }

    while (k--)
    {
        int a, b;
        std::cin >> a >> b;

        if (focc.find(a) == std::end(focc) or locc.find(b) == std::end(locc))
            std::cout << "NO\n";
        else
            std::cout << (focc[a] < locc[b] ? "YES\n" : "NO\n");
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