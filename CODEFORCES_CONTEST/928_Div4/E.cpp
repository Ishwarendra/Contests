#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

int count(int a, int d, int limit) { return (limit - a) / d + 1; }
int ith(int a, int d, int i) { return a + (i - 1) * d; }

void solve()
{
    int n, k;
    std::cin >> n >> k;

    int a = 1, d = 2;
    int cnt = count(a, d, n);

    while (k > cnt)
    {
        k -= cnt;
        a *= 2;
        d *= 2;
        cnt = count(a, d, n);
    }

    std::cout << ith(a, d, k) << "\n";
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