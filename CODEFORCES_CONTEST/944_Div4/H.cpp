#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

struct TwoSat {
    int n;
    std::vector<std::vector<int>> e;
    std::vector<bool> ans;
    TwoSat(int n) : n(n), e(2 * n), ans(n) {}
    void addClause(int u, bool f, int v, bool g) 
    {
        e[2 * u + !f].push_back(2 * v + g);
        e[2 * v + !g].push_back(2 * u + f);
    }
    bool satisfiable() 
    {
        std::vector<int> id(2 * n, -1), dfn(2 * n, -1), low(2 * n, -1);
        std::vector<int> stk;
        int now = 0, cnt = 0;
        auto dfs = [&](auto &&tarjan, int u) -> void
        {
            stk.push_back(u);
            dfn[u] = low[u] = now++;
            for (auto v : e[u]) {
                if (dfn[v] == -1) 
                {
                    tarjan(tarjan, v);
                    low[u] = std::min(low[u], low[v]);
                } 
                else if (id[v] == -1)
                    low[u] = std::min(low[u], dfn[v]);
            }
            if (dfn[u] == low[u]) 
            {
                int v;
                do 
                {
                    v = stk.back();
                    stk.pop_back();
                    id[v] = cnt;
                } while (v != u);
                ++cnt;
            }
        };
        for (int i = 0; i < 2 * n; ++i) 
        {
            if (dfn[i] == -1) 
                dfs(dfs, i);
        }
        for (int i = 0; i < n; ++i) 
        {
            if (id[2 * i] == id[2 * i + 1]) return false;
            ans[i] = id[2 * i] > id[2 * i + 1];
        }
        return true;
    }
    std::vector<bool> answer() { return ans; }
};

void solve()
{
    int n;
    std::cin >> n;
    
    TwoSat ts(n);
    std::vector<int> a[3];
    for (int i = 0; i < 3; i++)     
    {
        a[i].resize(n);
        for (int j = 0; j < n; j++)
            std::cin >> a[i][j];
    }
    
    auto add = [&](int x, int y)
    {
        ts.addClause(std::abs(x) - 1, x > 0, std::abs(y) - 1, y > 0);
    };
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int next = j == 2 ? 0 : j + 1;
            add(a[j][i], a[next][i]);
        }
    }
    
    std::cout << (ts.satisfiable() ? "YES\n" : "NO\n");
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