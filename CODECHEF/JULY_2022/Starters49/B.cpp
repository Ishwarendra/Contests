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
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i)  
        std::cin >> a[i];

    std::map<int, int> m;
    for (int i : a)
        m[i]++;

    std::vector<int> f;
    for (auto [num, freq] : m)
        f.emplace_back(freq);

    std::sort(std::begin(f), std::end(f));
    if (f.size() == 1)
    {
        std::cout << (f[0] + 1) / 2 << "\n";
        return;
    }

    int sz = f.size();
    int max = f[sz - 1], b = f[sz - 2];

    std::cout << std::max((max + 1) / 2, b) << "\n";
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