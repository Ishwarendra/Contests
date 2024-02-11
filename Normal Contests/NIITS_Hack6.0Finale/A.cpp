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

    std::vector<int> a(n);
    std::map<int, int> m;
    for (int i = 0; i < n; i++)  
    {
        std::cin >> a[i];
        m[a[i]]++;
    }

    std::sort(std::begin(a), std::end(a));
    if (n == 1 || (a.back() == a.front() and a.front() == 0))
    {
        if (n == 1)
            std::cout << "1 0\n";
        else
            std::cout << "1 " << n + 1 << "\n";
        return;
    }

    auto get = [&](std::vector<int> &a, int unique, int add = 0)
    {
        int n = std::size(a);
        int miss = a.back() - unique + 1;

        i64 ans = miss * 2;
        ans += n - 1 + add;
        return ans;
    };

    i64 ans = get(a, std::size(m));
    if (std::size(m) > 1)
    {
        m[a.back()]--;
        if (m[a.back()] == 0)
            m.erase(a.back());

        a.pop_back();
        ans = std::min(ans, get(a, std::size(m), 1));
    }

    std::cout << "1 " << ans << "\n";
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