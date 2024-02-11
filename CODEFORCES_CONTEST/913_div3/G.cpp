#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    std::vector<std::vector<int>> adj(n);
    std::vector<int> indeg(n);
    for (int i = 0; i < n; i++)
    {
        int a;
        std::cin >> a;
        adj[i].emplace_back(a - 1);
        indeg[a - 1]++;
    }

    std::queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (indeg[i] == 0)
            q.emplace(i);
    }

    std::set<int> ans;
    while (!q.empty())
    {
        auto u = q.front();
        q.pop();

        for (auto v : adj[u])
        {
            if (s[u] == '1')
            {
                s[u] = '0';
                s[v] ^= '1' ^ '0';
                ans.emplace(u);
            }

            indeg[v]--;
            if (indeg[v] == 0)
                q.emplace(v);
        }
    }

    auto work = [&](auto &p, auto &ps, int ok = 0)
    {
        std::set<int> nodes;
        for (int i = 0; i < std::size(p); i++)
        {
            if ((ok and i == 0) || ps[i])
            {
                nodes.emplace(p[i]);
                ps[i] ^= 1;
                ps[(i + 1) % std::size(p)] ^= 1;
            }
        }

        return nodes;
    };

    for (int i = 0; i < n; i++)
    {
        if (indeg[i] == 0)
            continue;

        int u = i;
        std::set<int> done;
        std::vector<int> p, ps;
        int cnt = 0;

        while (!done.count(u))
        {
            p.emplace_back(u);
            ps.emplace_back(s[u] - '0');
            cnt += s[u] - '0';
            done.emplace(u);
            u = adj[u][0];
        }

        if (cnt % 2)
        {
            std::cout << "-1\n";
            return;
        }

        auto p1 = p;
        auto p2 = p;
        auto ps1 = ps;
        auto ps2 = ps;

        std::rotate(std::begin(p2), std::begin(p2) + 1, std::end(p2));
        std::rotate(std::begin(ps2), std::begin(ps2) + 1, std::end(ps2));

        auto temp1 = work(p1, ps1, 1);
        auto temp2 = work(p2, ps2);

        p = p1, ps = ps1;
        if (std::size(temp2) < std::size(temp1))
        {
            std::swap(temp1, temp2);
            std::swap(ps, ps2);
        }

        ans.insert(std::begin(temp1), std::end(temp1));
        for (int i = 0; i < std::size(p); i++)
        {
            indeg[p[i]] = 0;
            s[p[i]] = '0' + ps[i];
        }
    }

    assert(s == std::string(n, '0'));
    std::cout << std::size(ans) << "\n";
    for (auto &x : ans)
        std::cout << x + 1 << " ";
    std::cout << "\n";
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