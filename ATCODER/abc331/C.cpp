#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >>  n;

    std::vector<std::pair<int, int>> a(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i].first;
        a[i].second = i;
    }

    std::sort(std::rbegin(a), std::rend(a));
    std::vector<i64> ans(n);
    i64 s = 0, cur = 0;
    i64 prev = a.front().first;

    for (auto [ele, id] : a)
    {
        if (prev != ele)
            cur = s; 
        ans[id] = cur;
        s += ele;
        prev = ele;             
    }

    for (int i = 0; i < n; i++)
        std::cout << ans[i] << " \n"[i == n - 1];
    
    return 0;
}