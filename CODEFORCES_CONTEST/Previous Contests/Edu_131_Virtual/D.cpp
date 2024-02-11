#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> b(n + 1), vis(n + 1);  
    for (int i = 1; i <= n; ++i)
        std::cin >> b[i];

    std::vector<std::pair<int, int>> range(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        if (b[i] == 0) // b[n] == 0 not allowed
            range[i] = {i + 1, n};
        else
            range[i] = {i / (b[i] + 1) + 1, (i / b[i])};
    }

    // if there are more than one candidate available for l[i]
    // then choose the one with minimum r[i];
    std::vector<std::vector<std::pair<int, int>>> adj(n + 2);    
    for (int i = 1; i <= n; ++i)
        adj[range[i].first].push_back({range[i].second, i});

    std::vector<int> a(n + 1);
    std::set<std::pair<int, int>> choices; 

    for (int i = 1; i <= n; ++i)
    {
        for (auto [r, id] : adj[i])
            choices.emplace(r, id);

        a[choices.begin()->second] = i;
        choices.erase(choices.begin());
    }

    for (int i = 1; i <= n; ++i)
        std::cout << a[i] <<  " \n"[i == n];
    for (int i = 1; i <= n; ++i)
    {
        assert(a[i] != 0 and (i / a[i]) == b[i]);
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