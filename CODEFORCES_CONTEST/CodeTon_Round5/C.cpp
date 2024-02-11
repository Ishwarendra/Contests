#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr int inf = 1e9;

template<class Info>
struct SegmentTree
{
    int n;
    std::vector<Info> info;
    SegmentTree(int n = 0) : n(n), info(4 << std::__lg(n), Info()) {}
 
    template <typename T>
    SegmentTree(const std::vector<T> a) 
    {
        n = std::size(a);
        info.assign(4 << std::__lg(n), Info());
        std::function<void(int, int, int)> build;
        build = [&](int l, int r, int id)
        {
            if (l > r)
                return;
            if (l == r)
            {
                info[id] = Info(a[l]);
                return;
            }
 
            int m = (l + r) >> 1;
            build(l, m, id * 2 + 1);
            build(m + 1, r, id * 2 + 2);
            merge(id);
        }; 
        build(0, n - 1, 0);
    } 
    void merge(int id)
    {
        info[id] = info[id * 2 + 1] + info[id * 2 + 2];
    }
    void update(int id, int x, int nl, int nr, const Info &v)
    {
        if (nl > nr)
            return;
        if (nl == nr)
        {
            info[id] = info[id] + v;
            return;
        }
 
        int m = (nl + nr) >> 1;
        if (x <= m)
            update(2 * id + 1, x, nl, m, v);
        else
            update(2 * id + 2, x, m + 1, nr, v);
        merge(id);
    }
    void update(int x, const Info &v)
    {
        update(0, x, 0, n - 1, v);
    }
    Info get(int id, int l, int r, int nl, int nr)
    {
        if (r < nl or l > nr)
            return Info();
        if (l >= nl and r <= nr)
            return info[id];
 
        int m = (l + r) >> 1;
        return get(2 * id + 1, l, m, nl, nr) + get(2 * id + 2, m + 1, r, nl, nr);
    }
    Info get(int l, int r)
    {
        return get(0, 0, n - 1, l, r);
    };
};

struct Info
{
    int sum;
    Info(int sum = -inf) : sum(sum) {}
};

Info operator+(Info a, Info b)
{
    if (a.sum > b.sum)
        return a;
    return b;
}

void solve()
{
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> pos(n);
    for (int i = 0; i < n; i++)  
    {
        int x;
        std::cin >> x;

        pos[x - 1].emplace_back(i + 1);
    }

    std::vector<std::array<int, 2>> a;
    for (int i = 0; i < n; i++)
    {
        int sz = std::size(pos[i]);
        for (int j = 1; j < sz; j++)
            a.push_back({pos[i][j - 1], pos[i][j]});
    }

    std::sort(std::begin(a), std::end(a), [&](auto &x, auto &y)
    {
        return x[1] < y[1];
    });

    std::vector<int> dp(n + 1, -inf);
    dp[0] = 0;
    SegmentTree<Info> st(dp);

    for (int i = 1; i <= std::size(a); i++)
    {
        auto [start, end] = a[i - 1];
        int len = end - start + 1;

        int sum = st.get(0, start - 1).sum;
        
        if (dp[start] != -inf)
            dp[end] = dp[start] + len - 1;

        if (sum != -inf)
            dp[end] = std::max(dp[end], sum + len);

        st.update(end, Info(dp[end]));
    }

    std::cout << *std::max_element(std::begin(dp), std::end(dp)) << "\n";
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