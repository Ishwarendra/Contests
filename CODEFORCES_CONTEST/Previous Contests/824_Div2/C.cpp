#include <bits/stdc++.h>

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

class DSU
{
    std::vector<int> rnk, par;
public:
    DSU(int n) : rnk(n, 1), par(n) { std::iota(par.begin(), par.end(), 0); }
    int get(int x)
    {
        while (x != par[x]) x = par[x] = par[par[x]];
        return x;
    }
    bool unite(int x, int y)
    {
        int p1 = get(x), p2 = get(y);
        if (p1 == p2)
            return false;
        else
        {
            if (rnk[p2] > rnk[p1])
                std::swap(p1, p2);
                
            par[p2] = p1, rnk[p1] += rnk[p2], rnk[p2] = 0;                
            return true;
        }
    }
    bool same(int x, int y)
    {
        return get(x) == get(y);
    }
    int size(int x)
    {
        return rnk[get(x)];
    }
}; 

void solve()
{
    int n;
    std::string s;
    std::cin >> n >> s;

    DSU dsu(26);
    std::vector<int> indeg(26, 0), outdeg(26, 0), next(26, -1);

    auto done = [&]()
    {
        return std::accumulate(std::begin(indeg), std::end(indeg), 0) == 25
            and std::accumulate(std::begin(outdeg), std::end(outdeg), 0) == 25;
    };  

    auto connect = [&](int x)
    {
        if (outdeg[x])
            return next[x];

        for (int i = 0; i < 26; ++i)
        {
            if (i == x)
                continue;

            if (dsu.same(x, i) and done())
            {
                for (int j = 0; j < 26; ++j)
                {
                    if (!indeg[j])
                        return j;
                }
            }
            else if (!dsu.same(x, i) and indeg[i] == 0)
                return i;
        }

        return -1;
    };

    for (int i = 0; i < n; ++i)
    {
        int cur = s[i] - 'a';
        int s = connect(cur);
        dsu.unite(cur, s);

        indeg[s] = 1;
        outdeg[cur] = 1;
        next[cur] = s;
    }

    for (int i = 0; i < n; ++i)
        std::cout << char(next[s[i] - 'a'] + 'a');
    std::cout << "\n";
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