#include <bits/stdc++.h>

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

template <typename T>
struct Fenwick 
{
    const int n;
    std::vector<T> a;
    
    Fenwick(int n) : n(n), a(n) {}
    template<typename G>
    Fenwick(const std::vector<G> in) : Fenwick((int)std::size(in))
    {
        for (int i = 1; i <= n; i++)
        {
            a[i - 1] += in[i - 1];
            if (i + (i & -i) <= n)
                a[i - 1 + (i & -i)] += a[i - 1];
        }
    }
    void add(int x, T v) 
    {
        for (int i = x + 1; i <= n; i += i & -i) {
            a[i - 1] += v;
        }
    }
    T sum(int x)  
    {
        T ans = 0;
        x++;
        for (int i = x; i > 0; i -= i & -i) {
            ans += a[i - 1];
        }
        return ans;
    }
    T rangeSum(int l, int r) 
    {
        if (l - 1 < 0)
            return sum(r);
        
        return sum(r) - sum(l - 1);
    }
};

void solve()
{
    std::string s;
    std::cin >> s;

    int n = std::size(s);
    Fenwick<int> ft(n);
    for (int i = 0; i < n; ++i)
        ft.add(i, s[i] - '0');

    int w, q;
    std::cin >> w >> q;  

    // store all w len substr values 
    std::vector<int> adj[9];

    for (int i = 0; i < n - w + 1; i++)
    {
        int sum = ft.rangeSum(i, i + w - 1);
        sum %= 9;
        adj[sum].emplace_back(i);
    }

    // for (int i = 0; i < 9; ++i)
    //     std::sort(std::begin(adj[i]), std::end(adj[i]));

    while (q--)
    {
        int l, r, k;
        std::cin >> l >> r >> k;
        l--, r--;

        int s2 = (ft.rangeSum(l, r)) % 9;

        std::pair<int, int> ans {1e9, 1e9};
        for (int s1 = 0; s1 <= 8; s1++)
        {
            int s3 = (k - (s1 * s2) % 9 + 18) % 9;
            if (adj[s1].empty() or adj[s3].empty())
                continue;

            // take first of adj[s3]
            if (s1 != s3)
            {
                std::pair<int, int> temp = {adj[s1][0], adj[s3][0]};
                ans = std::min(ans, temp);
                continue;
            }

            // s1 == s3
            if (std::size(adj[s3]) <= 1)
                continue;

            std::pair<int, int> temp = {adj[s1][0], adj[s3][1]};
            ans = std::min(ans, temp);
        }

        if (ans.first != 1e9)
            std::cout << ans.first + 1 << " " << ans.second + 1 << "\n";
        else
            std::cout << "-1 -1\n";
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