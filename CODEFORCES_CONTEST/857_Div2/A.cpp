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

    std::sort(std::rbegin(a), std::rend(a));

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > 0)
            count++;
        else
            count--;

        std::cout << count << " \n"[i == n - 1];
    }

    count = n - count;
    int turn = 1;
    for (int i = 0; i < n; i++)
    {
        std::cout << turn << " \n"[i == n - 1];
        if (count)
            count--, turn ^= 1;
        else
            turn++;
    }
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