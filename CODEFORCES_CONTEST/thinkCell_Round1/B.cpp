#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

bool ok(std::vector<int> a)
{
    int n = std::size(a);
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (i != j and a[i] % a[j] == 0)
                assert(a[i + 1] != a[j + 1]);
        }
    }

    return true;
}

void solve()
{
    int n;
    std::cin >> n;

    int max = n, min = 1;
    std::vector<int> a;
    for (int i = 0; i < n; i++)
        std::cout << (i % 2 ? max-- : min++) << " \n"[i == n - 1];
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