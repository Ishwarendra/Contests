#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int k, n;
    std::cin >> k >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i)  
    {
        std::cin >> a[i];
        a[i]--;
    }

    std::vector<int> cnt(k);

    for (int i = 0; i < n; i++)
        cnt[a[i]]++;

    std::multiset<int> m;
    for (int i = 0; i < k; ++i)
        m.emplace(cnt[i]);

    bool can = m.size() > 1;
    int gap = 3;

    while (can)
    {
        can = false;
        int min = *std::begin(m), max = *(--std::end(m));

        if (max - min >= gap)
            can = true;

        // int q = (max - min) / gap;
        int q = std::min(1, (max - min) / gap);
        m.erase(std::begin(m));
        m.erase((--std::end(m)));

        min += q * 2;
        max -= q;
        m.emplace(max);
        m.emplace(min);
    }

    // print(cnt)
    std::cout << *(--std::end(m)) << "\n";
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