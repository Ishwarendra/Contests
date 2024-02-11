#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

struct DS
{
    std::multiset<int> m, diff;
    void erase(std::multiset<int> &a, int x)
    {
        assert(a.find(x) != std::end(a));
        a.erase(a.find(x));
    }

    void add(int x)
    {
        auto it = m.emplace(x);
        if (it != std::begin(m) and std::next(it) != std::end(m))
        {
            auto prev = std::prev(it), next = std::next(it);
            erase(diff, *next - *prev);
        }

        if (it != std::begin(m))
        {
            auto prev = std::prev(it);
            diff.emplace(*it - *prev);
        }

        if (std::next(it) != std::end(m))
        {
            auto next = std::next(it);
            diff.emplace(*next - *it);
        }
    }

    void remove(int x)
    {
        auto it = m.find(x);
        if (it != std::begin(m))
        {
            auto prev = std::prev(it);
            erase(diff, *it - *prev);
        }

        if (std::next(it) != std::end(m))
        {
            auto next = std::next(it);
            erase(diff, *next - *it);
        }

        if (it != std::begin(m) and std::next(it) != std::end(m))
        {
            auto prev = std::prev(it), next = std::next(it);
            diff.emplace(*next - *prev);
        }

        erase(m, x);
    }

    int get() { return (diff.empty() ? 0 : *std::prev(std::end(diff))); }
    int max() { return (m.empty() ? 0 : *std::prev(std::end(m))); }
};

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    DS ds;

    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
        ds.add(a[i]);
    }

    int q;
    std::cin >> q;

    while (q--)
    {
        int id, x;
        std::cin >> id >> x;
        id--;

        if (a[id] != x)
        {
            ds.remove(a[id]);
            a[id] = x;
            ds.add(a[id]);
        }

        std::cout << (ds.max() + ds.get()) << " \n"[q == 0];
    }
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