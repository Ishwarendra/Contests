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

    auto query = [&](int l, int r)
    {
        if (l >= r)
            return 0;

        std::cout << "? " << l << " " << r << std::endl;
        int inv;
        std::cin >> inv;

        return inv;
    };

    auto f = [&](auto self, int L, int R) -> int
    {
        if (L == R)
            return L;

        int M = (L + R) / 2;
        
        int left = self(self, L, M);
        int right = self(self, M + 1, R);

        if (query(left, right) == query(left, right - 1))
            return right;

        return left;
    };  

    int ans = f(f, 1, n);
    std::cout << "! " << ans << std::endl;
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