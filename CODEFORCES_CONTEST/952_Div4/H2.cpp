#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

class DSU
{
    std::vector<int> rnk, par;
public:
    DSU() {}
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

std::vector<std::pair<int, int>> dirs {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

int solve(std::vector<std::string> &a)
{
    int n = std::size(a), m = std::size(a[0]);
    DSU dsu(n * m);
    
    auto f = [&](int i, int j) { return i * m + j; };
    auto safe = [&](int i, int j)
    {
        return 0 <= i and i < n and 0 <= j and j < m;
    };
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == '.')
                continue;
            
            for (auto &[dx, dy] : dirs)
            {
                if (!safe(i + dx, j + dy))
                    continue;
                
                if (a[i + dx][j + dy] == '#')
                    dsu.unite(f(i, j), f(i + dx, j + dy));
            }
        }
    }
    
    int ans = 0;
    std::vector comp(n, std::set<std::pair<int, int>>());
    std::vector<int> extra(n), dots(n);
    
    for (int i = 0; i < n; i++)
    {
        std::set<std::pair<int, int>> s;
        int sum = 0;
        for (int j = 0; j < m; j++)
        {   
            if (i > 0)
            {
                if (a[i - 1][j] == '#')
                    s.emplace(dsu.get(f(i - 1, j)), dsu.size(f(i - 1, j)));
            }
            
            if (a[i][j] == '#')
                s.emplace(dsu.get(f(i, j)), dsu.size(f(i, j)));
            sum += a[i][j] == '.';
            
            if (i + 1 < n)
            {
                if (a[i + 1][j] == '#')
                    s.emplace(dsu.get(f(i + 1, j)), dsu.size(f(i + 1, j)));
            }
        }
        
        comp[i] = s;
        dots[i] = sum;
        for (auto &[p, cnt] : s)
            extra[i] += cnt;
    }
    
    for (int j = 0; j < m; j++)
    {
        std::set<std::pair<int, int>> s;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (j > 0)
            {
                if (a[i][j - 1] == '#')
                    s.emplace(dsu.get(f(i, j - 1)), dsu.size(f(i, j - 1)));
            }
            
            if (a[i][j] == '#')
                s.emplace(dsu.get(f(i, j)), dsu.size(f(i, j)));
            sum += a[i][j] == '.';
            
            if (j + 1 < m)
            {
                if (a[i][j + 1] == '#')
                    s.emplace(dsu.get(f(i, j + 1)), dsu.size(f(i, j + 1)));
            }
        }
        
        for (int i = 0; i < n; i++)
        {
            int res = extra[i] + sum + dots[i];         
            // if (i == 3 and j == 3)
            //     print(extra[i], dots[i], sum, s)

            res -= a[i][j] == '.';
            for (auto &[p, cnt] : s)
            {
                if (!comp[i].count({p, cnt}))
                    res += cnt;
            }
            
            ans = std::max(ans, res);
        }
    }

    return ans;
}

void solve()
{
    int n, m;
    std::cin >> n >> m;
    
    std::vector<std::string> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    std::cout << solve(a) << "\n";
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