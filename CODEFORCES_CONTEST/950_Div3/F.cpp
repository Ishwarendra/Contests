#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

void chmin(auto &a, auto b)
{
    if (a > b)
        a = b;
}

template <typename T1, typename T2, typename T3>
struct tuple
{
    T1 first;
    T2 second;
    T3 third;
    tuple(T1 first, T2 second, T3 third) : first(first), second(second), third(third) {}

    bool operator<(const tuple &other)
    {
        if (first != other.first)
            return first < other.first;
        if (second != other.second)
            return second < other.second;
        
        return third < other.third;
    }
};

void solve()
{
    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector a(k, std::tuple<int, int, int>());
    for (int i = 0; auto &[x, y, id] : a)
    {
        std::cin >> x >> y;
        id = i++;
    }

    std::sort(std::begin(a), std::end(a));

    std::map<int, std::vector<tuple<int, int, int>>> suff_min;
    suff_min[n].emplace_back(m + 1, k, m + 1);

    int min = m + 1;
    for (int i = k - 1; i >= 0; i--)
    {
        auto [x, y, id] = a[i];
        min = std::min(min, y);
        suff_min[x].emplace_back(min, id, y);
    }

    i64 ans = 0;
    for (auto &[_, p] : suff_min)
        std::sort(std::begin(p), std::end(p));

    int cur = 1;
    for (auto &[row, p] : suff_min)
    {
        int smin = p.front().first;
        int length = row - cur + 1;
        int width = smin - 1;
        cur = row + 1;
        ans += 1LL * length * width;
    }

    std::cout << ans << '\n';
    std::vector<i64> res(k);

    for (auto it = std::begin(suff_min); it != std::end(suff_min); it++)
    {
        auto &[row, p] = *it;
        int sz = std::ssize(p);
    }

    for (int i = 0; i < k; i++)
        std::cout << res[i] << " \n"[i == k - 1];
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