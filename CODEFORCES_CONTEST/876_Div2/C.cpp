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
    for (int i = 0; i < n; i++)  
        std::cin >> a[i];

    if (a.back() == 1)
    {
        std::cout << "NO\n";
        return;
    }

    std::cout << "YES\n";
    std::vector<int> pos;

    for (int i = 0; i < n; i++)
    {
        if (i - 1 < 0 or (a[i - 1] == 0 and a[i] == 1))
            pos.emplace_back(i);
    }

    int cnt = 0;
    for (int i = n - 1, j = std::ssize(pos) - 1; i >= 0; i--)
    {
        cnt += a[i] == 1;
        if (i != pos[j])
            std::cout << 0 << " \n"[i == 0];
        else
        {
            std::cout << cnt << " \n"[i == 0];
            cnt = 0;
            j--;
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