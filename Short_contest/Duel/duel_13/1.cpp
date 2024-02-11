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

    std::multiset<int> a, b;
    i64 asum = 0, bsum = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        std::cin >> x;
        a.emplace(x);
        asum += x;
    }

    for (int i = 0; i < n; i++)
    {
        int x;
        std::cin >> x;
        b.emplace(x);
        bsum += x;
    }

    int k = n - n / 4;
    std::vector<int> miss;
    while (std::size(a) > k)
    {
        asum -= *std::begin(a);
        bsum -= *std::begin(b);
        a.erase(std::begin(a));
        miss.emplace_back(*std::begin(b));
        b.erase(std::begin(b));
    }

    std::sort(std::begin(miss), std::end(miss));

    if (asum >= bsum)
    {
        std::cout << "0\n";
        return;
    }

    int cnt = 0;
    while (true)
    {
        cnt++;
        n++;
        a.emplace(100);
        asum += 100;

        int k = n - n / 4;
        while (std::size(a) > k)
        {
            asum -= *std::begin(a);
            a.erase(std::begin(a));
        }

        while (!miss.empty() and std::size(b) < k)
        {
            b.emplace(miss.back());
            bsum += miss.back();
            miss.pop_back();
        }

        assert(a.size() == k);
        if (asum >= bsum)
        {
            std::cout << cnt << '\n';
            return;
        }
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