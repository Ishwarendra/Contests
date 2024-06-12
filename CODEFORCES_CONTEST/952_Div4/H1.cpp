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

        for (auto &[_, cnt] : s)
                sum += cnt;
        ans = std::max(ans, sum);
    }

    return ans;
}

void solve()
{
    int n, m;
    std::cin >> n >> m;
    
    std::vector<std::string> a(n);
    std::vector b(m, std::string(n, '.'));
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
        for (int j = 0; j < m; j++)
            b[j][i] = a[i][j];
    }

    std::cout << std::max(solve(a), solve(b)) << "\n";
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