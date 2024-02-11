#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)  
        std::cin >> a[i];

    int st = -1, en = n;
    std::array<int, 2> cnt{};
    while (st < n and cnt[0] < k)
    {
        st++;
        if (a[st] == a.front())
            cnt[0]++;
    }

    while (a.front() != a.back() and en >= 0 and cnt[1] < k)
    {
        en--;
        if (a[en] == a.back())
            cnt[1]++;
    }

    if (st < en and cnt[0] == k and (cnt[1] == k or a.back() == a.front())) 
        std::cout << "YES\n";
    else
        std::cout << "NO\n";
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