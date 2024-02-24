#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i128 = __int128;
using u128 = __uint128_t;
using i64 = i128;

std::ostream &operator<<(std::ostream &os, i128 x) 
{
    std::string s;
    bool neg = false;
    if (x < 0)
        neg = true, x = -x;
    if (x == 0)
        s = "0";
    
    while (x)
    {
        s += '0' + x % 10;
        x /= 10;
    }

    if (neg)
        s += '-';
    s = std::string(std::rbegin(s), std::rend(s));
    return os << s;
}

std::istream& operator >> (std::istream &is, i128 &T) 
{
    static char buffer[64];
    is >> buffer; 
    size_t len = strlen(buffer), index = 0; 
    T = 0; 
    int mul = 1;

    if (buffer[index] == '-') 
        ++index, mul *= -1; 
    for (; index < len; ++index) 
        T = T * 10 + static_cast<int>(buffer[index] - '0'); 
    T *= mul; 

    return is;
}

constexpr i64 inf = i64(1e18) + 1e9 + 100;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<std::array<i64, 5>>> adj(n);
    for (int i = 0; i < m; i++)
    {
        i64 l, d, k, c, a, b;
        std::cin >> l >> d >> k >> c >> a >> b;
        a--, b--;

        adj[b].push_back({a, l, d, k, c});
    }

    std::vector<i64> ans(n, 0);

    auto bfs = [&]()
    {
        std::priority_queue<std::pair<i64, int>> pq;
        ans[n - 1] = inf;
        pq.emplace(ans[n - 1], n - 1);

        while (!pq.empty())
        {
            auto [dist, u] = pq.top();
            pq.pop();

            for (auto [v, l, d, k, c] : adj[u])
            {
                i64 y = (dist - c - l) / d;
                if (dist - c - l < 0)
                    continue;

                y = std::min(k - 1, y);

                if (ans[v] < l + y * d)
                {
                    ans[v] = l + y * d;
                    pq.emplace(ans[v], v);
                }
            }
        }
    }; bfs();

    for (int i = 0; i < n - 1; i++)
    {
        if (ans[i] == 0)
            std::cout << "Unreachable\n";
        else
            std::cout << ans[i] << "\n";
    }

    return 0;
}